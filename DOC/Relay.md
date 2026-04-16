# Relay

极简继电器驱动：

- 文件：`BSP/Relay/Relay.h`、`BSP/Relay/Relay.c`
- 默认引脚：`PC4`
- 接口：`Relay_init()`、`Relay_on()`、`Relay_off()`、`Relay_status(status)`

---

## 1. CubeMX 配置

- `PC4`：`Output Push Pull`

---

## 2. 接线

| Relay 模块 | STM32 |
|---|---|
| IN | PC4 |
| VCC | 5V 或模块要求电压 |
| GND | GND |

---

## 3. 使用

```c
#include "Relay.h"

Relay_init();
Relay_on();
Relay_off();
```

第一次测试时你应该看到：

- 初始化后默认断开
- 调用 `Relay_on()` 吸合，`Relay_off()` 释放

---

## 4. 注意事项

- 当前逻辑是高电平有效
- 若无动作，优先检查 `PC4` 是否已配置为输出
