/*
 * lsm6dsox.h
 *
 *  Created on: Mar 15, 2023
 *      Author: jed
 */

#ifndef INC_LSM6DSOX_H_
#define INC_LSM6DSOX_H_

#include <stdbool.h>
#include "stm32f0xx_hal.h"

#define LSM6DSOX_POWER_UP_MS					(20)
#define LSM6DSOX_ADDR_BASE					(0x6a) // Append READ or WRITE bit for full 8-bit address.
#define LSM6DSOX_ADDR_SA0                   (0x6b) // Alternate address (SA0).
#define LSM6DSOX_ADDR_READ_BIT				(0x1)
#define LSM6DSOX_ADDR_WRITE_BIT				(0x0)
#define LSM6DSOX_DEVICE_ID					(0x6c) // Contents of WHO_AM_I register.

#define REG_FUNC_CFG_ACCESS					(0x01) // RW. Default 0.
#define REG_PIN_CTRL						(0x02) // RW. Default 00111111 (0x3f).
#define REG_S4S_TPH_L						(0x04) // RW. Default 0.
#define REG_S4S_TPH_H						(0x05) // RW. Default 0.
#define REG_S4S_RR							(0x06) // RW. Default 0.
#define REG_FIFO_CTRL1						(0x07) // RW. Default 0.
#define REG_FIFO_CTRL2						(0x08) // RW. Default 0.
#define REG_FIFO_CTRL3						(0x09) // RW. Default 0.
#define REG_FIFO_CTRL4						(0x0a) // RW. Default 0.
#define REG_COUNTER_BDR_REG1					(0x0b) // RW. Default 0.
#define REG_COUNTER_BDR_REG2					(0x0c) // RW. Default 0.
#define REG_INT1_CTRL						(0x0d) // RW. Default 0.
#define REG_INT2_CTRL						(0x0e) // RW. Default 0.
#define REG_WHO_AM_I						(0x0f) // R. Default 01101100 (0x6c).
#define REG_CTRL1_XL						(0x10)
#define REG_CTRL2_G							(0x11)
#define REG_CTRL3_C							(0x12)
#define REG_CTRL4_C							(0x13)
#define REG_CTRL5_C							(0x14)
#define REG_CTRL6_C							(0x15)
#define REG_CTRL7_G							(0x16)
#define REG_CTRL8_XL						(0x17)
#define REG_CTRL9_XL						(0x18)
#define REG_CTRL10_C						(0x19)
#define REG_ALL_INT_SRC						(0x1a)
#define REG_WAKE_UP_SRC						(0x1b)
#define REG_TAP_SRC							(0x1c)
#define REG_D6D_SRC							(0x1d)
#define REG_STATUS_REG						(0x1e)
#define REG_OUT_TEMP_L						(0x20) // R. Output.
#define REG_OUT_TEMP_H						(0x21) // R. Output.
#define REG_OUTX_L_G						(0x22) // R. Output.
#define REG_OUTX_H_G						(0x23) // R. Output.
#define REG_OUTY_L_G						(0x24) // R. Output.
#define REG_OUTY_H_G						(0x25) // R. Output.
#define REG_OUTZ_L_G						(0x26) // R. Output.
#define REG_OUTZ_H_G						(0x27) // R. Output.
#define REG_OUTX_L_A						(0x28) // R. Output.
#define REG_OUTX_H_A						(0x29) // R. Output.
#define REG_OUTY_L_A						(0x2a) // R. Output.
#define REG_OUTY_H_A						(0x2b) // R. Output.
#define REG_OUTZ_L_A						(0x2c) // R. Output.
#define REG_OUTZ_H_A						(0x2d) // R. Output.
#define REG_EMB_FUNC_STATUS_MAINPAGE			(0x35) // R. Output.
#define REG_FSM_STATUS_A_MAINPAGE			(0x36) // R. Output.
#define REG_FSM_STATUS_B_MAINPAGE			(0x37) // R. Output.
#define REG_MLC_STATUS_MAINPAGE				(0x38) // R. Output.
#define REG_STATUS_MASTER_MAINPAGE			(0x39) // R. Output.
#define REG_FIFO_STATUS1						(0x3a) // R. Output.
#define REG_FIFO_STATUS2						(0x3b) // R. Output.
#define REG_TIMESTAMP0						(0x40) // R. Output.
#define REG_TIMESTAMP1						(0x41) // R. Output.
#define REG_TIMESTAMP2						(0x42) // R. Output.
#define REG_TIMESTAMP3						(0x43) // R. Output.
#define REG_UI_STATUS_REG_OIS				(0x49) // R. Output.
#define REG_UI_OUTX_L_G_OIS					(0x4a) // R. Output.
#define REG_UI_OUTX_H_G_OIS					(0x4b) // R. Output.
#define REG_UI_OUTY_L_G_OIS					(0x4c) // R. Output.
#define REG_UI_OUTY_H_G_OIS					(0x4d) // R. Output.
#define REG_UI_OUTZ_L_G_OIS					(0x4e) // R. Output.
#define REG_UI_OUTZ_H_G_OIS					(0x4f) // R. Output.
#define REG_UI_OUTX_L_A_OIS					(0x50) // R. Output.
#define REG_UI_OUTX_H_A_OIS					(0x51) // R. Output.
#define REG_UI_OUTY_L_A_OIS					(0x52) // R. Output.
#define REG_UI_OUTY_H_A_OIS					(0x53) // R. Output.
#define REG_UI_OUTZ_L_A_OIS					(0x54) // R. Output.
#define REG_UI_OUTZ_H_A_OIS					(0x55) // R. Output.
#define REG_TAP_CFG0						(0x56) // RW. Default 0.
#define REG_TAP_CFG1						(0x57) // RW. Default 0.
#define REG_TAP_CFG2						(0x58) // RW. Default 0.
#define REG_TAP_THS_6D						(0x59) // RW. Default 0.
#define REG_INT_DUR2						(0x5a) // RW. Default 0.
#define REG_WAKE_UP_THS						(0x5b) // RW. Default 0.
#define REG_WAKE_UP_DUR						(0x5c) // RW. Default 0.
#define REG_FREE_FALL						(0x5d) // RW. Default 0.
#define REG_MD1_CFG							(0x5e) // RW. Default 0.
#define REG_MD2_CFG							(0x5f) // RW. Default 0.
#define REG_S4S_ST_CMD_CODE					(0x60) // RW. Default 0.
#define REG_S4S_DT_REG						(0x61) // RW. Default 0.
#define REG_I3C_BUS_AVB						(0x62) // RW. Default 0.
#define REG_INTERNAL_FREQ_FINE				(0x63) // R. Output.
#define REG_UI_INT_OIS						(0x6f) // R/RW. Default 0.
#define REG_UI_CTRL1_OIS						(0x70) // R/RW. Default 0.
#define REG_UI_CTRL2_OIS						(0x71) // R/RW. Default 0.
#define REG_UI_CTRL3_OIS						(0x72) // R/RW. Default 0.
#define REG_X_OFS_USR						(0x73) // R/RW. Default 0.
#define REG_Y_OFS_USR						(0x74) // R/RW. Default 0.
#define REG_Z_OFS_USR						(0x75) // R/RW. Default 0.
#define REG_FIFO_DATA_OUT_TAG				(0x78) // R. Output.
#define REG_FIFO_DATA_OUT_X_L				(0x79) // R. Output.
#define REG_FIFO_DATA_OUT_X_H				(0x7a) // R. Output.
#define REG_FIFO_DATA_OUT_Y_L				(0x7b) // R. Output.
#define REG_FIFO_DATA_OUT_Y_H				(0x7c) // R. Output.
#define REG_FIFO_DATA_OUT_Z_L				(0x7d) // R. Output.
#define REG_FIFO_DATA_OUT_Z_H				(0x7e) // R. Output.

typedef struct lsm6dsox {
	/* 8-bit read and write I2C address. */
	uint8_t i2c_addr_r;
	uint8_t i2c_addr_w;

	/* Buffer for data read from the device. */
	uint8_t bufsize;
	uint8_t *buf;

	/* The HAL I2C_HandleTypeDef */
	void *i2c;

	/* Data supported by the sensor. */
	int x;
	int y;
	int z;
	int gx;
	int gy;
	int gz;
	int dir;
} lsm6dsox_t;

HAL_StatusTypeDef lsm6dsox_init(lsm6dsox_t *lsm6dsox, I2C_HandleTypeDef *i2c, uint8_t *buf, uint8_t bufsize);

bool lsm6dsox_data_available(lsm6dsox_t *lsm6dsox);

HAL_StatusTypeDef lsm6dsox_read(lsm6dsox_t *lsm6dsox, uint8_t reg, uint8_t bufsize);

HAL_StatusTypeDef lsm6dsox_write(lsm6dsox_t *lsm6dsox, uint8_t reg, uint8_t data);

#endif /* INC_LSM6DSOX_H_ */
