#ifndef __MT6701_SPI2_H__
#define __MT6701_SPI2_H__

#include "stm32f1xx_hal.h"
#include "spi.h"
#include "gpio.h"
#include <stdio.h>


#define SPI2_CS_Enable() 			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET)
#define SPI2_CS_Disable() 		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET)


#define MT6701_SLAVE_ADDR			    0x06 << 1
#define MT6701_Timeout            50

#define MT6701_REG_ANGLE_14b      0x03    // 14Bit角度信息，存储在0x03[13:6]、0x04[5:0]两个寄存器中，高位在前，原始读数0~16383

#define mt6701_log		printf



void mt6701_spi2_get_angle(int16_t *angle, float *angle_f);

#endif
