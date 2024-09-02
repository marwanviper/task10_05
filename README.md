# Task 10_05: Implement MPU6050 IMU Sensor to Read Yaw Axis Using Arduino

**Objective:**
- To interface the MPU6050 IMU sensor with an Arduino to read the yaw (z-axis rotation) value.
- The task should be completed using only the `Wire.h` library for I2C communication, without relying on additional libraries dedicated to the MPU6050.

**Steps:**

1. **Understanding the MPU6050 Datasheet:**
   - Read and understand the MPU6050 datasheet to identify necessary register addresses and configurations.
   - Determine the I2C address for the MPU6050, which is `0x68` by default.
   - Identify the register address for the gyroscope's Z-axis output, which is `0x47`.

2. **Arduino Setup:**
   - Initialize I2C communication using the `Wire.h` library.
   - Wake up the MPU6050 by writing to the power management register (register address `0x6B`).

3. **Reading the Yaw (Z-axis) Data:**
   - Access the Z-axis gyroscope data by reading from register `0x47`.
   - Combine the high and low bytes of data to get the 16-bit signed integer representing the gyroscope's output for the Z-axis.

4. **Calculating Yaw:**
   - Convert the raw gyroscope value to degrees per second using the appropriate sensitivity scale factor (e.g., `131.0` for ±250°/s full scale).

5. **Output the Yaw Data:**
   - Print the calculated yaw value to the serial monitor for observation.

**Outcome:**
- Successfully read and display the yaw axis value from the MPU6050 IMU sensor using Arduino and only the `Wire.h` library.
