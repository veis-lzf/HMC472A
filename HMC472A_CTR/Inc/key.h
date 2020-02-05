#ifndef __KEY_H
#define __KEY_H

#include "main.h"

// 定义按键读入状态的宏
#define SW3_IN HAL_GPIO_ReadPin(SW3_GPIO_Port, SW3_Pin)
#define SW4_IN HAL_GPIO_ReadPin(SW4_GPIO_Port, SW4_Pin)

#define SW3_PRESS 1
#define SW4_PRESS 2

// 按键检测函数
uint8_t key_scan(uint8_t mode);

#endif /* __KEY_H */
