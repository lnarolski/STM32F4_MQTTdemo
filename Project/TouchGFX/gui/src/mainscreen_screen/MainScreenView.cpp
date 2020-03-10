#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <string.h>
#include "stm32f4xx_hal_uart.h"

#include <gui/rgbscreen_screen/RGBScreenView.hpp>

#define BUFFER_SIZE 2001

UART_HandleTypeDef huart7;
uint8_t ReceivedChar;

extern uint32_t BlueDuty;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	
}

void MainScreenView::handleTickEvent()
{
//	if (huart7.RxState == HAL_UART_STATE_READY)
//	{
//		ReceivedChar = huart7.Instance
//		
//		static bool inited = false;
//		static char buffer[BUFFER_SIZE];
//		static uint32_t i = 0;
//		
//		if (!inited)
//		{
//			memset(buffer, '\0', BUFFER_SIZE);
//		}
//		
//		buffer[i] = ReceivedChar;
//		++i;
//		
//		if (strstr(buffer, "TEST") != NULL)
//		{
//			BlueDuty = 100;
//			memset(buffer, '\0', BUFFER_SIZE);
//		}
//		if (i > BUFFER_SIZE -1)
//		{
//			i = 0;
//			memset(buffer, '\0', BUFFER_SIZE);
//		}
//	}
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
		HAL_UART_MspInit(&huart7);
		HAL_UART_Transmit(&huart7,(uint8_t*) "SUBS$demo\n", strlen("SUBS$demo\n"), 1000);
		HAL_UART_Receive_IT(&huart7, &ReceivedChar, 1);
		
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
