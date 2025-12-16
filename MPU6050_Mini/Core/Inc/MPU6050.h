/*
 * MPU6050.h
 *
 *  Created on: Dec 15, 2025
 *  Author: Andrew Lana
 */

#ifndef INC_MPU6050_H_
#define INC_MPU6050_H_

#include "stdio.h"
#include "stm32f3xx_hal.h" //Include hardware interface libraries

HAL_StatusTypeDef MPU6050_init(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR);
HAL_StatusTypeDef MPU6050_getGyro(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR, float *buf);
HAL_StatusTypeDef MPU6050_getAccel(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR, float *buf);

#endif /* INC_MPU6050_H_ */
