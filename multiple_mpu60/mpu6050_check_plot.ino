#include<Wire.h>
unsigned long mytime;
float time1 , time2 , time3;
const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;
int16_t AccY1,AccY2,AccY3,AccY4;
int16_t AccZ1,AccZ2,AccZ3,AccZ4;
void setup(){
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  Wire.begin();
  Serial.begin(115200);
}
void loop(){
  
 imu1();
 
 imu2();

 imu3();

 imu4();
}
void imu1()
{
  digitalWrite(0,LOW);// 1st MPU6050
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  //time1 = micros();
  AccX=Wire.read()<<8|Wire.read();
  AccY1=Wire.read()<<8|Wire.read();
  AccZ1=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
 // Serial.println("data from 1nd imu");
 // Serial.print("AccX = "); Serial.print(AccX);
 // Serial.print(" || AccY = ");
 Serial.println();
 Serial.print(AccZ1);Serial.print(",");
 // Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
 // Serial.print(" || GyroX = "); Serial.print(GyroX);
 // Serial.print(" || GyroY = "); Serial.print(GyroY);
 // Serial.print(" || GyroZ = "); Serial.println(GyroZ);
  //delay(10);
  digitalWrite(0,HIGH);
}
void imu2()
{
  digitalWrite(1,LOW);// 2nd MPU6050
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  //time1 = micros();
  AccX=Wire.read()<<8|Wire.read();
  AccY2=Wire.read()<<8|Wire.read();
  AccZ2=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
 // Serial.println("data from 2nd imu");
 // Serial.print("AccX = "); Serial.print(AccX);
 // Serial.print(" || AccY = ");
 Serial.print(AccZ2);Serial.print(",");
 // Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
 // Serial.print(" || GyroX = "); Serial.print(GyroX);
 // Serial.print(" || GyroY = "); Serial.print(GyroY);
 // Serial.print(" || GyroZ = "); Serial.println(GyroZ);
  //delay(10);
  digitalWrite(1,HIGH);
}
void imu3()
{
  digitalWrite(2,LOW);// 3rd MPU6050
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  //time1 = micros();
  AccX=Wire.read()<<8|Wire.read();
  AccY3=Wire.read()<<8|Wire.read();
  AccZ3=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
  //Serial.println("data from 3rd imu");
  //Serial.print("AccX = "); Serial.print(AccX);
  //Serial.print(" || AccY = "); 
  Serial.print(AccZ3);Serial.print(",");
  //Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  //Serial.print(" || GyroX = "); Serial.print(GyroX);
  //Serial.print(" || GyroY = "); Serial.print(GyroY);
  //Serial.print(" || GyroZ = "); Serial.println(GyroZ);
  //delay(10);
  digitalWrite(2,HIGH);
}
void imu4()
{
  digitalWrite(3,LOW);// 4th MPU6050
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  //time1 = micros();
  AccX=Wire.read()<<8|Wire.read();
  AccY4=Wire.read()<<8|Wire.read();
  AccZ4=Wire.read()<<8|Wire.read();
  Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
  //Serial.println("data from 4th imu");
//  Serial.print("AccX = "); Serial.print(AccX);
 // Serial.print(" || AccY = ");
 Serial.print(AccZ4);
 // Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
 // Serial.print(" || GyroX = "); Serial.print(GyroX);
 // Serial.print(" || GyroY = "); Serial.print(GyroY);
 // Serial.print(" || GyroZ = "); Serial.println(GyroZ);
 // delay(10);
  digitalWrite(3,HIGH);
}
