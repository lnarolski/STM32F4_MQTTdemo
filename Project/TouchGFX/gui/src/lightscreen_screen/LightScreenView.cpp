#include <gui/lightscreen_screen/LightScreenView.hpp>
#include <string.h>
#include <stdio.h>

extern ADC_HandleTypeDef hadc2;
extern DMA_HandleTypeDef hdma_adc2;

extern uint32_t lightValue;
static bool isVisiblePage = false;
touchgfx::BoxProgress* windowLightBar;
touchgfx::TextArea* windowTextArea1;
touchgfx::TextArea* windowLightText;

extern UART_HandleTypeDef huart7;

void LightScreenView::handleTickEvent()
{
	if (isVisiblePage)
	{
			volatile HAL_StatusTypeDef status = HAL_ADC_PollForConversion(&hadc2, 300);
			lightValue = HAL_ADC_GetValue(&hadc2);
		
			double valD = (double) lightValue / 4095.0 * 100.0;
			valD -= 20.0;
			valD /= 0.7;
			valD = valD < 0.0 ? 0.0 : valD > 100.0 ? 100.0 : valD;
			int valI = (int) valD;
			uint32_t widgetValue = valI;
		
			Unicode::snprintf(LightTextBuffer, LIGHTTEXT_SIZE, "%d", widgetValue);
			//LightText.resizeToCurrentText();
			LightText.invalidate();
			windowLightBar->setValue(widgetValue);
		
			static size_t i = 0;
			if (i > 50)
			{
				char buffer[17] = {'\0'};
				snprintf(buffer, sizeof(buffer), "SEND$light$%d%%\n", valI);
				HAL_UART_Transmit(&huart7,(uint8_t*) buffer, strlen(buffer), 1000);
				
				i = 0;
			}
			else
				++i;
			
			HAL_ADC_Start(&hadc2);
	}
}

static void MX_ADC2_Init(void)
{

  /* USER CODE BEGIN ADC2_Init 0 */

  /* USER CODE END ADC2_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC2_Init 1 */

  /* USER CODE END ADC2_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
  */
  hadc2.Instance = ADC2;
  hadc2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
  hadc2.Init.Resolution = ADC_RESOLUTION_12B;
  hadc2.Init.ScanConvMode = DISABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc2.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 1;
  hadc2.Init.DMAContinuousRequests = DISABLE;
  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    //Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
  */
  sConfig.Channel = ADC_CHANNEL_15;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    //Error_Handler();
  }
  /* USER CODE BEGIN ADC2_Init 2 */

  /* USER CODE END ADC2_Init 2 */

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

void ADC2_Init()
{			
			MX_ADC2_Init();
			
			HAL_ADC_Start(&hadc2);
}

LightScreenView::LightScreenView()
{
		windowLightBar = &LightBar;
		windowTextArea1 = &textArea1;
		windowLightText = &LightText;
	
		static bool inited = false;

		if (!inited)
		{
			ADC2_Init();

			inited = true;
		}
}

void LightScreenView::setupScreen()
{
		isVisiblePage = true;
	
    LightScreenViewBase::setupScreen();
}

void LightScreenView::tearDownScreen()
{
    LightScreenViewBase::tearDownScreen();
	
		isVisiblePage = false;
}
