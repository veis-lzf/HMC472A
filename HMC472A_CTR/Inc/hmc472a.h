#ifndef __HMC472A_H
#define __HMC472A_H

#include "main.h"

#define MAX_MULTIPLE 63
#define MIN_MULTIPLE 0
// 0.5dB步进控制衰减倍数（不考虑插入损耗）
uint8_t HMC472_Ctr ( float _db );

#endif
