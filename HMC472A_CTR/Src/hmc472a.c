#include "hmc472a.h"
#include "usart.h"
// Insertion Loss：
// DC - 1.5 GHz     1.4 ~ 1.8 dB
// 1.5 - 3.0 GHz    1.7 ~ 2.3 dB
// 3.0 - 3.8 GHz    1.9 ~  3  dB
// 以dB为单位控制衰减倍数，0.5dB步进，范围0~31.5dB（不计插入损耗）
// 正常控制返回0；超出控制量程范围返回1。
uint8_t HMC472_Ctr ( float _db )
{
    __IO uint8_t db = ( uint8_t ) ( _db * 2 );
    
    // 判断是否超出量程
    if((_db < MIN_MULTIPLE) || (db > MAX_MULTIPLE))
    {
        printf("---------------Out of range!---------------\r\n");
        return 1;
    }
    // 0.5dB控制位
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V6_GPIO_Port, V6_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V6_GPIO_Port, V6_Pin, GPIO_PIN_SET );
    }
    // 1dB控制位
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V5_GPIO_Port, V5_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V5_GPIO_Port, V5_Pin, GPIO_PIN_SET );
    }
    // 2dB控制位
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V4_GPIO_Port, V4_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V4_GPIO_Port, V4_Pin, GPIO_PIN_SET );
    }
    // 4dB控制位
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V3_GPIO_Port, V3_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V3_GPIO_Port, V3_Pin, GPIO_PIN_SET );
    }
    // 8dB控制位
    db = db >> 1;
    if ( 1 == ( db & 0x01 ) )
    {
        HAL_GPIO_WritePin ( V2_GPIO_Port, V2_Pin, GPIO_PIN_RESET );
    }
    else
    {
        HAL_GPIO_WritePin ( V2_GPIO_Port, V2_Pin, GPIO_PIN_SET );
    }
    // 16dB控制位
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

