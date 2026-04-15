#include "stm32f4xx.h"                  // Device header
#include "CountSensor.h"

volatile uint16_t CountSensor_Count;				//全局变量，用于计数



/**
  * 函    数：计数传感器初始化
  * 参    数：无
  * 返 回 值：无
  */
void CountSensor_Init(void)
{			
	
}

/**
  * 函    数：获取计数传感器的计数值
  * 参    数：无
  * 返 回 值：计数值，范围：0~65535
  */
uint16_t CountSensor_Get(void)
{
	return CountSensor_Count;
}

/**
  * 函    数：EXTI15_10外部中断函数
  * 参    数：无
  * 返 回 值：无
  * 注意事项：此函数为中断函数，无需调用，中断触发后自动执行
  *           函数名为预留的指定名称，可以从启动文件复制
  *           请确保函数名正确，不能有任何差异，否则中断函数将不能进入
  */
void CountSensor_callback(void)
{
	/*如果出现数据乱跳的现象，可再次判断引脚电平，以避免抖动*/
	if (HAL_GPIO_ReadPin(COUNT_SENSOR_PORT, COUNT_SENSOR_PIN) == 0)
	{
		CountSensor_Count ++;					//计数值自增一次
	}
}
