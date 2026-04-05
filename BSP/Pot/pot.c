#include "stm32f4xx.h"
#include "AD.h"
#include <math.h>
#include "adc.h"

#define LDR_READ_TIMES	10  //光照传感器ADC循环读取次数

// 电位器模块



// 得到电位器的AD通道值
uint16_t Pot_GetData(void)
{
	return AD_Value[1];
}

//得到电位器的模拟电压值
float Pot_GetVoltage(void)
{
	return Pot_GetData() * 3.3f / 4095;
}
