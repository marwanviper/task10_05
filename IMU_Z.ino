#include <Wire.h>

// MPU6050 I2C address
int MPU6050_ADDR = 0x68;

// Registers
int PWR_MGMT_1 = 0x6B;
int GYRO_ZOUT_H = 0x47;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  
  // Wake up the MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission(true);
}

void loop() {
  int16_t gyro_z = readIMU(GYRO_ZOUT_H);
  // Convert the raw gyroscope value to degrees per second
  float yaw = gyro_z / 131.0;
  Serial.println(yaw);
  delay(100);
}

int16_t readIMU(int address) {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(address);
  Wire.endTransmission(false);
  
  Wire.requestFrom(MPU6050_ADDR, 2, true);
  
  int16_t high_byte = Wire.read();
  int16_t low_byte = Wire.read();

  return (high_byte << 8) | low_byte;
}
