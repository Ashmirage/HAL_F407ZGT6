#include "stm32f4xx.h"
#include "adc.h"

volatile uint16_t AD_Value[4];

// 启动AD转换
void AD_init(void)
{
	HAL_ADC_Start(&hadc3);
	HAL_ADC_Start_DMA(&hadc3, (uint32_t*)AD_Value, 1); // 开启dma转运
}







