#include <Adafruit_ISM330DHCX.h>
#include <Adafruit_LIS3MDL.h>

Adafruit_ISM330DHCX state;
Adafruit_LIS3MDL compass;

void setup(void) {
  Serial.begin(115200);
  
  while (!Serial)
    delay(10);

  bool stateSuccess = state.begin_I2C();
  bool compassSuccess = compass.begin_I2C();

  if (!stateSuccess){
    Serial.println("Failed to find State chip");
  } else{
    Serial.println("Found State chip");
  }
  
  if (!compassSuccess){
    Serial.println("Failed to find Compass");
  } else {
    Serial.println("Found Compass");
  }
  
  if (!(stateSuccess && compassSuccess)) {
    while (1) {
      delay(10);
    }
  }

  Serial.println("State and Compass Found!");

  Setup(LSM6DS_ACCEL_RANGE_16_G, LSM6DS_RATE_6_66K_HZ, ISM330DHCX_GYRO_RANGE_4000_DPS, LSM6DS_RATE_6_66K_HZ, LIS3MDL_RANGE_16_GAUSS, LIS3MDL_DATARATE_1000_HZ, LIS3MDL_ULTRAHIGHMODE, LIS3MDL_CONTINUOUSMODE, 500, true, true, true, true, true, true);
}

void loop() {

  sensors_event_t accel, gyro, mag, temp;

  //  /* Get new normalized sensor events */
  lsm6ds.getEvent(&accel, &gyro, &temp);
  lis3mdl.getEvent(&mag);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print("\t\tAccel X: ");
  Serial.print(accel.acceleration.x, 4);
  Serial.print(" \tY: ");
  Serial.print(accel.acceleration.y, 4);
  Serial.print(" \tZ: ");
  Serial.print(accel.acceleration.z, 4);
  Serial.println(" \tm/s^2 ");

  /* Display the results (rotation is measured in rad/s) */
  Serial.print("\t\tGyro  X: ");
  Serial.print(gyro.gyro.x, 4);
  Serial.print(" \tY: ");
  Serial.print(gyro.gyro.y, 4);
  Serial.print(" \tZ: ");
  Serial.print(gyro.gyro.z, 4);
  Serial.println(" \tradians/s ");

  /* Display the results (magnetic field is measured in uTesla) */
  Serial.print(" \t\tMag   X: ");
  Serial.print(mag.magnetic.x, 4);
  Serial.print(" \tY: ");
  Serial.print(mag.magnetic.y, 4);
  Serial.print(" \tZ: ");
  Serial.print(mag.magnetic.z, 4);
  Serial.println(" \tuTesla ");

  Serial.print("\t\tTemp   :\t\t\t\t\t");
  Serial.print(temp.temperature);
  Serial.println(" \tdeg C");
  Serial.println();
  delay(1000);
}

public void Setup(lsm6ds_accel_range_t accelRange, lsm6ds_data_rate_t accelDataRate, lsm6ds_gyro_range_t gyroRate, lsm6ds_data_rate_t gyroDataRate, lis3mdl_range_t magRange, lis3mdl_dataRate_t magDataRate, lis3mdl_performancemode_t magPerformanceMode, lis3mdl_operationmode_t magOperationMode, uint16_t magInterrupt, bool magEnableX, bool magEnableY, bool magEnableZ, bool magPolarity, bool magLatch, bool magEnableInt){
  state.setAccelRange(accelRange);
  state.setAccelDataRate(accelDataRate);
  state.setGyroRange(gyroRange);
  state.setGyroDataRate(gyroDataRate);
  compass.setRange(magRange);
  compass.setDataRate(magDataRate);
  compass.setPerformanceMode(magPerformanceMode);
  compass.setOperationMode(magOperationMode);
  compass.setIntThreshold(magInterrupt);
  compass.configInterrupt(magEnableX, magEnableY, magEnableZ, magPolarity, magLatch, magEnableInt);
}
