#include "key.h"

// û�а������·���0��
// ����sw3���·��ؼ�ֵ1��
// ����sw4���·��ؼ�ֵ2
// mode��0��ʾ��֧��������1��ʾ֧��������
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



