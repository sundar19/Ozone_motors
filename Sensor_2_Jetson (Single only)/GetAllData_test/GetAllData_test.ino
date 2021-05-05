
#include <MPU6050_tockn.h>
#include <TimerTCC0.h>
#include <TimerTC3.h>
#include <Wire.h>
float ax , ay , az;
float ax1[1000] , ay1[1000] ,az1[1000];
MPU6050 mpu6050(Wire);

long timer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  TimerTcc0.initialize(100000); //100 millisecond
  TimerTcc0.attachInterrupt(timerIsr);
}

void loop() {
  

  //if(millis() - timer > 1000){
    
  //  Serial.println("=======================================================");
   // Serial.print("temp : ");Serial.println(mpu6050.getTemp());
   for (int j=0;j<=999;j++)
   {
    Serial.println();
    Serial.print(ax1[j]);Serial.print(",");
    Serial.print(ay1[j]);Serial.print(",");
    Serial.print(az1[j]); 
   }
  /*  Serial.println();
    Serial.print(mpu6050.getAccX());Serial.print(",");
    Serial.print(mpu6050.getAccY());Serial.print(",");
    Serial.print(mpu6050.getAccZ()); */
  
 /*   Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());*/
  
   /* Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("\taccAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    
    Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    Serial.print("\tangleY : ");Serial.print(mpu6050.getAngleY());
    Serial.print("\tangleZ : ");Serial.println(mpu6050.getAngleZ());
    Serial.println("=======================================================\n");
    timer = millis(); */
    
 // }

}
void timerIsr()
{ 
  mpu6050.update();
/*  ax = mpu6050.getAccX();
  ay = mpu6050.getAccY();
  az = mpu6050.getAccZ(); */
  for (int i=0;i<=999;i++)
  {
    ax1[i]= mpu6050.getAccX();
    ay1[i]= mpu6050.getAccY();
    az1[i]= mpu6050.getAccZ();
  }
}
