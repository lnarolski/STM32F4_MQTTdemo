#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <string.h>
#include "stm32f4xx_hal_uart.h"

#include <gui/rgbscreen_screen/RGBScreenView.hpp>

#define BUFFER_SIZE 2001

UART_HandleTypeDef huart7;
uint8_t ReceivedChar[15];

extern uint32_t BlueDuty;

static HAL_StatusTypeDef UART_WaitOnFlagUntilTimeout(UART_HandleTypeDef *huart, uint32_t Flag, FlagStatus Status, uint32_t Tickstart, uint32_t Timeout)
{
  /* Wait until flag is set */
  while((__HAL_UART_GET_FLAG(huart, Flag) ? SET : RESET) == Status) 
  {
    /* Check for the Timeout */
    if(Timeout != HAL_MAX_DELAY)
    {
      if((Timeout == 0U)||((HAL_GetTick() - Tickstart ) > Timeout))
      {
        /* Disable TXE, RXNE, PE and ERR (Frame error, noise error, overrun error) interrupts for the interrupt process */
        CLEAR_BIT(huart->Instance->CR1, (USART_CR1_RXNEIE | USART_CR1_PEIE | USART_CR1_TXEIE));
        CLEAR_BIT(huart->Instance->CR3, USART_CR3_EIE);
        
        huart->gState  = HAL_UART_STATE_READY;
        huart->RxState = HAL_UART_STATE_READY;
        
        /* Process Unlocked */
        __HAL_UNLOCK(huart);
        
        return HAL_TIMEOUT;
      }
    }
  }
  
  return HAL_OK;
}

void MainScreenView::handleTickEvent()
{
	// My implementation of HAL_UART_Receive() function
	if (huart7.RxState == HAL_UART_STATE_READY)
	{		
		/* Process Locked */
    do{                                        \
			if(huart7.Lock == HAL_LOCKED)   \
			{                                      \
				 return;		                  \
			}                                      \
			else                                   \
			{                                      \
				 huart7.Lock = HAL_LOCKED;    \
			}                                      \
		} while (0U);
    
    huart7.ErrorCode = HAL_UART_ERROR_NONE;
    huart7.RxState = HAL_UART_STATE_BUSY_RX;
		
		static bool inited = false;
		static char buffer[BUFFER_SIZE];
		static uint32_t i = 0;
		
		if (!inited)
		{
			memset(buffer, '\0', BUFFER_SIZE);
		}
		
		/* Init tickstart for timeout managment */
    uint32_t tickstart = HAL_GetTick();
		uint32_t timeout = 100;
		
		while (UART_WaitOnFlagUntilTimeout(&huart7, UART_FLAG_RXNE, RESET, tickstart, timeout) == HAL_OK)
		{
			buffer[i] = (uint8_t)(huart7.Instance->DR & (uint8_t)0x00FF);
			inited = true;
			
			if (strstr(buffer, "TEST") != NULL)
			{
				BlueDuty = 100;
				memset(buffer, '\0', BUFFER_SIZE);
				i = 0;
				inited = false;
			}
			else if (i > BUFFER_SIZE -1 || buffer[i] == '\n')
			{
				i = 0;
				memset(buffer, '\0', BUFFER_SIZE);
				inited = false;
			}
			else
			{
				++i;
			}
		}
		
		/* At end of Rx process, restore huart->RxState to Ready */
    huart7.RxState = HAL_UART_STATE_READY;
		
		do {                                       \
			huart7.Lock = HAL_UNLOCKED;    \
		} while (0U);
	}
}

static void MX_UART7_Init(void)
{

  /* USER CODE BEGIN UART7_Init 0 */

  /* USER CODE END UART7_Init 0 */

  /* USER CODE BEGIN UART7_Init 1 */

  /* USER CODE END UART7_Init 1 */
  huart7.Instance = UART7;
  huart7.Init.BaudRate = 115200;
  huart7.Init.WordLength = UART_WORDLENGTH_8B;
  huart7.Init.StopBits = UART_STOPBITS_1;
  huart7.Init.Parity = UART_PARITY_NONE;
  huart7.Init.Mode = UART_MODE_TX_RX;
  huart7.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart7.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart7) != HAL_OK)
  {
    //Error_Handler();
  }
  /* USER CODE BEGIN UART7_Init 2 */

  /* USER CODE END UART7_Init 2 */

}

void HAL_UART_MspInit(UART_HandleTypeDef* huart)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(huart->Instance==UART7)
  {
  /* USER CODE BEGIN UART7_MspInit 0 */

  /* USER CODE END UART7_MspInit 0 */
    /* Peripheral clock enable */
    __HAL_RCC_UART7_CLK_ENABLE();
  
    __HAL_RCC_GPIOF_CLK_ENABLE();
    /**UART7 GPIO Configuration    
    PF6     ------> UART7_RX
    PF7     ------> UART7_TX 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_6|GPIO_PIN_7;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = GPIO_AF8_UART7;
    HAL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    /* UART7 interrupt Init */
    HAL_NVIC_SetPriority(UART7_IRQn, 0, 0);
    HAL_NVIC_EnableIRQ(UART7_IRQn);
  /* USER CODE BEGIN UART7_MspInit 1 */

  /* USER CODE END UART7_MspInit 1 */
  }

}

MainScreenView::MainScreenView()
{
	static bool inited = false;
	
	if (!inited)
	{
		MX_UART7_Init();
		//HAL_UART_MspInit(&huart7);
		HAL_UART_Transmit(&huart7,(uint8_t*) "SUBS$demo\n", strlen("SUBS$demo\n"), 1000);
		//HAL_UART_Receive_IT(&huart7, &ReceivedChar, 1);
		
		inited = true;
	}
}

void MainScreenView::setupScreen()
{
    MainScreenViewBase::setupScreen();
}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}
