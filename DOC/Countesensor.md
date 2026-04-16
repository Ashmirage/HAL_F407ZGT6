# Countesensor

极简对射式红外传感器(计数)驱动（对应 `BSP/Countsensor`）：

- 文件：`BSP/Countsensor/CountSensor.h`、`BSP/Countsensor/CountSensor.c`
- 默认引脚：`PB14`（EXTI）
- 接口：`CountSensor_Init()`、`CountSensor_Get()`

---

## 1. CubeMX 配置

- `PB14`：`GPIO_MODE_IT_FALLING`（下降沿中断）
- `PB14`：上拉输入（代码中有低电平有效判断）
- 使能 `EXTI15_10_IRQn`

---

## 2. 接线

| CountSensor | STM32 |
|---|---|
| OUT | PB14 |
| VCC | 3.3V 或模块要求电压 |
| GND | GND |

---

## 3. 使用

```c
#include "CountSensor.h"

CountSensor_Init();
uint16_t cnt = CountSensor_Get();
```

第一次测试时你应该看到：

- 每次产生一次有效下降沿，`CountSensor_Get()` 计数增加

---

## 4. 注意事项

- 计数逻辑依赖中断回调链路：`HAL_GPIO_EXTI_Callback()` -> `CountSensor_callback()`
- `CountSensor_Init()` 当前为空实现，配置主要依赖 CubeMX
