# MPU6050_Mini
Lightweight STM32-compatible library for the MPU6050 IMU. This library contains the following functions, which all function similarly. MPU6050_init() must be called prior to sensor usage in order to being the sensor out of sleep mode. The library consists of a single header and .c file, which can be included in a project with `#include "MPU6050.h"`


`HAL_StatusTypeDef MPU6050_init(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR)`  
Initializes the MPU6050 by writing 0x00 to the sleep bit  

* `I2C_HandleTypeDef *hi2c` - STM32 HAL I2C Handle
* `uint8_t MPU6050_ADDR` - MPU6050 I2C address, usually 0x68 or 0x69
 

`HAL_StatusTypeDef MPU6050_getAccel(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR, float *buf)`  
Reads out x, y, and z acceleration registers into a buffer, scaled to g.  

 
* `I2C_HandleTypeDef *hi2c` - STM32 HAL I2C Handle
* `uint8_t MPU6050_ADDR` - MPU6050 I2C address, usually 0x68 or 0x69
* `float *buf` - Pointer to a float array where acceleration data will be stored

 
`HAL_StatusTypeDef MPU6050_getGyro(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR, float *buf)`  
Reads out x, y, and z gyroscope registers into a buffer, scaled to deg/s.  

* `I2C_HandleTypeDef *hi2c` - STM32 HAL I2C Handle
* `uint8_t MPU6050_ADDR` - MPU6050 I2C address, usually 0x68 or 0x69
* `float *buf` - Pointer to a float array where gyroscope data will be stored

`HAL_StatusTypeDef MPU6050_getTemperature(I2C_HandleTypeDef *hi2c, uint8_t MPU6050_ADDR, float *buf)`  
Reads out temperature register into a buffer  

* `I2C_HandleTypeDef *hi2c` - STM32 HAL I2C Handle
* `uint8_t MPU6050_ADDR` - MPU6050 I2C address, usually 0x68 or 0x69
* `float *buf` - Pointer to a float where temperature data will be stored 

