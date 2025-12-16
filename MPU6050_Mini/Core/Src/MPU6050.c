/*
 * MPU6050.c
 *
 *  Created on: Dec 15, 2025
 *  Author: Andrew Lana
 *
 */
#include "MPU6050.h" //Include hardware interface libraries

//MPU6050 Data Registers
#define MPU6050_ACCEL_XOUT_H 0X3B
#define MPU6050_GYRO_XOUT_H 0X3C
#define MPU6050_TEMP_OUT_H 0x41

HAL_StatusTypeDef MPU6050_init(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR) {

	uint8_t data = 0x00; //0x00 to clear sleep bit
	HAL_StatusTypeDef status;

	status = HAL_I2C_Mem_Write(hi2c,MPU6050_ADDR,0x6B,I2C_MEMADD_SIZE_8BIT,&data,1,HAL_MAX_DELAY);

    return status;
}


HAL_StatusTypeDef MPU6050_getAccel(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR, float *buf) {
	uint8_t accel_raw[6]; //Probably a more efficient way to allocate data

	HAL_StatusTypeDef status; //Status handle

	status = HAL_I2C_Mem_Read(hi2c,MPU6050_ADDR,MPU6050_ACCEL_XOUT_H,I2C_MEMADD_SIZE_8BIT,accel_raw,6, HAL_MAX_DELAY);

	buf[0] = (int16_t)(accel_raw[0] << 8 | accel_raw[1]); //Separate raw data for each axis into buffer
	buf[1] = (int16_t)(accel_raw[2] << 8 | accel_raw[3]);
	buf[2] = (int16_t)(accel_raw[4] << 8 | accel_raw[5]);

	buf[0] = buf[0] / 16384.0f; //Divide by scaling factors to g
	buf[1] = buf[1] / 16384.0f;
	buf[2] = buf[2] / 16384.0f;

	return status;
}

HAL_StatusTypeDef MPU6050_getGyro(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR, float *buf) {
	uint8_t gyro_raw[6]; //Probably a more efficient way to allocate data

	HAL_StatusTypeDef status; //Status handle

	status = HAL_I2C_Mem_Read(hi2c,MPU6050_ADDR,MPU6050_GYRO_XOUT_H,I2C_MEMADD_SIZE_8BIT,gyro_raw,6, HAL_MAX_DELAY);

	buf[0] = (int16_t)(gyro_raw[0] << 8 | gyro_raw[1]); //Separate raw data for each axis into buffer
	buf[1] = (int16_t)(gyro_raw[2] << 8 | gyro_raw[3]);
	buf[2] = (int16_t)(gyro_raw[4] << 8 | gyro_raw[5]);

	buf[0] = buf[0] / 131.0f; //Divide by scaling factors to deg/s
	buf[1] = buf[1] / 131.0f;
	buf[2] = buf[2] / 131.0f;

	return status;
}

HAL_StatusTypeDef MPU6050_getTemperature(I2C_HandleTypeDef *hi2c,uint8_t MPU6050_ADDR,float *temperature_c) {
    uint8_t temp_raw[2];
    int16_t temp_counts;
    HAL_StatusTypeDef status;

    status = HAL_I2C_Mem_Read(hi2c,MPU6050_ADDR,MPU6050_TEMP_OUT_H,I2C_MEMADD_SIZE_8BIT,temp_raw,2,HAL_MAX_DELAY);

    temp_counts = (int16_t)((temp_raw[0] << 8) | temp_raw[1]);

    *temperature_c = (temp_counts / 340.0f) + 36.53f;

    return status;
}




