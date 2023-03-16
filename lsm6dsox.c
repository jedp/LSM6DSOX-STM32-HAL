/*
 * lsm6dsox.c
 *
 *  Created on: Mar 15, 2023
 *      Author: jed
 */

#include "lsm6dsox.h"

#define TIMEOUT_MS      (50)

HAL_StatusTypeDef lsm6dsox_init(lsm6dsox_t *lsm6dsox, I2C_HandleTypeDef *i2c, uint8_t *buf, uint8_t bufsize) {
	HAL_StatusTypeDef status;

	lsm6dsox->i2c_addr_r = (LSM6DSOX_ADDR_BASE << 1) | LSM6DSOX_ADDR_READ_BIT;
	lsm6dsox->i2c_addr_w = (LSM6DSOX_ADDR_BASE << 1) | LSM6DSOX_ADDR_WRITE_BIT;
	lsm6dsox->i2c = i2c;
	lsm6dsox->buf = buf;
	lsm6dsox->bufsize = bufsize;

	// Wake up.
	HAL_Delay(LSM6DSOX_POWER_UP_MS);

	status = HAL_I2C_IsDeviceReady(lsm6dsox->i2c, LSM6DSOX_ADDR_BASE << 1, 1, TIMEOUT_MS);
	if (status != HAL_OK) return status;

	// I am who I am.
	status = lsm6dsox_read(lsm6dsox, REG_WHO_AM_I, 1);
	if (status != HAL_OK) return status;
	if (lsm6dsox->buf[0] != LSM6DSOX_DEVICE_ID) return HAL_ERROR;

	return HAL_OK;
}

bool lsm6dsox_data_available(lsm6dsox_t *lsm6dsox) {
	return false;
}

HAL_StatusTypeDef lsm6dsox_read(lsm6dsox_t *lsm6dsox, uint8_t reg, uint8_t bufsize) {
	if (bufsize > lsm6dsox->bufsize) return HAL_ERROR;

	return HAL_I2C_Mem_Read(lsm6dsox->i2c, lsm6dsox->i2c_addr_r, reg, 1, lsm6dsox->buf, bufsize, TIMEOUT_MS);
}

HAL_StatusTypeDef lsm6dsox_write(lsm6dsox_t *lsm6dsox, uint8_t reg, uint8_t data) {
	return HAL_I2C_Mem_Write(lsm6dsox->i2c, lsm6dsox->i2c_addr_w, reg, 1, &data, 1, TIMEOUT_MS);
}

