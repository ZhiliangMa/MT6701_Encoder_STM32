#include "MT6701_SPI2.h"

void mt6701_spi2_read(unsigned char* buf, unsigned short len)
{
	HAL_SPI_Receive(&hspi2, buf, len, MT6701_Timeout);
}

//HAL_SPI_Receive(SPI_HandleTypeDef *hspi, uint8_t *pData, uint16_t Size, uint32_t Timeout)
//HAL_SPI_TransmitReceive(SPI_HandleTypeDef *hspi, const uint8_t *pTxData, uint8_t *pRxData, uint16_t Size, uint32_t Timeout)

// 14Bit角度信息，存储在0x03[13:6]、0x04[5:0]两个寄存器中，高位在前，原始读数0~16383，对应0-360°
void mt6701_spi2_get_angle(int16_t *angle, float *angle_f)
{
	uint8_t temp[3], tx[3];
	
	SPI2_CS_Enable();
	mt6701_spi2_read(temp, 3);
	//HAL_SPI_TransmitReceive(&hspi2, tx, temp, 3, MT6701_Timeout);
	SPI2_CS_Disable();
	*angle = ((int16_t)temp[0] << 6) | (temp[1] >> 2);
	*angle_f = (float)*angle * 360 / 16384;
}
