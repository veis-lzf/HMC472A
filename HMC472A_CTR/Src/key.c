#include "key.h"

// 没有按键按下返回0；
// 按键sw3按下返回键值1；
// 按键sw4按下返回键值2
// mode：0表示不支持连按；1表示支持连按。
uint8_t key_scan(uint8_t mode)
{
    static uint8_t flag = 1;
    if(1 == mode)
    {
        flag = 1;
    }
    if(flag && ((0 == SW3_IN) || (0 == SW4_IN)))
    {
        HAL_Delay(10);
        flag = 0;
        if((0 == SW3_IN) || (0 == SW4_IN))
        {
            flag = 0;
            if(SW3_IN == 0)
            {
                return SW3_PRESS;
            }
            if(SW4_IN == 0)
            {
                return SW4_PRESS;
            }
        }
    }
    else if ((1 == SW3_IN) && (1 == SW4_IN))
    {
        flag = 1;
    }
    return 0;
}



