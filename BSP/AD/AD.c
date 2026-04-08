#include "stm32f4xx.h"
#include "adc.h"

//#define ADC_CHANNEL1_PORT GPIOC
//#define ADC_CHANNEL1_PIN  GPIO_Pin_5
//#define ADC_CHANNEL1_NAME ADC_Channel_15
//#define ADC_CHANNEL2_PORT GPIOF
//#define ADC_CHANNEL2_PIN  GPIO_Pin_6
//#define ADC_CHANNEL2_NAME ADC_Channel_4
//#define ADC_CHANNEL_NUM 1
//#define DMA_CHANNEL_NUM 1


// 注意f103系列的芯片的dma外设只有一个dma1 
// dma转运时通道对应关系是硬件定死的,不可以随便选择,比如ADC采样结果转运就只能使用通道一


// f103系列的只有ADC1才支持DMA,不要使用ADC3和ADC2
// 扫描模式注意修改结构体配置


volatile uint16_t AD_Value[4];

#define ADC_DATA_READ_ADDRESS AD_Value

// 启动AD转换
void AD_init(void)
{
	HAL_ADC_Start(&hadc3);
	HAL_ADC_Start_DMA(&hadc3, (uint32_t*)AD_Value, 1); // 开启dma转运
}







