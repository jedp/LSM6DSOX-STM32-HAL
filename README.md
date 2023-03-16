# LSM6DSOX (3-axis accelerometer and gyroscope): STM32 CubeMX HAL-based library.

A bare-bones library for interacting with the LSM6DSOX accelerometer using STM32 HAL in CubeMX.

I've tested it with my [LSM6DSOX breakout board](https://github.com/jedp/LSM6DSOX-breakout) connected
to my [STM32F04 debug board](https://github.com/jedp/STM32F042-board-v2) via I2C.

I have not yet needed the SPI interface, so that is *not yet implemented* in this library!

Place the `.h` and `.c` files in your `Core/Inc` and `Core/Src`.

1. Include the library.

```
/* USER CODE BEGIN Includes */
#include "lsm6dsox.h"
/* USER CODE END Includes */
```

2. Allocate storage.

```
/* USER CODE BEGIN PV */

// Allocate a buffer for reading data from the sensor.
uint8_t lsm6dsox_buf[6] = { 0 };

// New instance of the lsm6dsox convenience object.
lsm6dsox_t lsm6dsox;

// lis3dh calls return this HAL status type.
HAL_StatusTypeDef status;
/* USER CODE END PV */
```

3. Initialize the device.

Assumes you have configured your project to use I2C. This will generate `I2C_HandleTypeDef hi2c1;`.

The `init` function is not very clever. It only does things I've so far had a use for.

One important detail is that there's no way to configure the alternate I2C address.
So definitely fix that if you need it.

```
  /* USER CODE BEGIN 2 */

  status = lis3dh_init(&lis3dh, &hi2c1, xyz_buf, 6);

  if (status != HAL_OK) {
    // Unable to communicate with device!
  }

  /* USER CODE END 2 */
```

4. Etc.

