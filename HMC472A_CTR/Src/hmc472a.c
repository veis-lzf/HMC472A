#include "hmc472a.h"
#include "usart.h"
// Insertion Loss��
// DC - 1.5 GHz     1.4 ~ 1.8 dB
// 1.5 - 3.0 GHz    1.7 ~ 2.3 dB
// 3.0 - 3.8 GHz    1.9 ~  3  dB
// ��dBΪ��λ����˥��������0.5dB��������Χ0~31.5dB�����Ʋ�����ģ�
// �������Ʒ���0�������������̷�Χ����1��
uint8_t HMC472_Ctr ( float _db )
{
    __IO uint8_t db = ( uint8_t ) ( _db * 2 );
    
    // �ж��Ƿ񳬳�����
    if((_db < MIN_MULTIPLE) || (db > MAX_MULTIPLE))
    {
        printf("---------------Out of range!---------------\r\n");
        return 1;
    }
    // 0.5dB����λ
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V6_GPIO_Port, V6_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V6_GPIO_Port, V6_Pin, GPIO_PIN_SET );
    }
    // 1dB����λ
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V5_GPIO_Port, V5_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V5_GPIO_Port, V5_Pin, GPIO_PIN_SET );
    }
    // 2dB����λ
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V4_GPIO_Port, V4_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V4_GPIO_Port, V4_Pin, GPIO_PIN_SET );
    }
    // 4dB����λ
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V3_GPIO_Port, V3_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V3_GPIO_Port, V3_Pin, GPIO_PIN_SET );
    }
    // 8dB����λ
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V2_GPIO_Port, V2_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V2_GPIO_Port, V2_Pin, GPIO_PIN_SET );
    }
    // 16dB����λ
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V1_GPIO_Port, V1_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V1_GPIO_Port, V1_Pin, GPIO_PIN_SET );
    }
    return 0;
}

