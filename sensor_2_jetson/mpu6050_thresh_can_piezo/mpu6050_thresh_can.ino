#include<Wire.h>
  
#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 7;

unsigned long mytime;
float time1 , time2 , time3;
const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;
int16_t AccY1,AccY2,AccY3,AccY4;
int16_t AccZ1,AccZ2,AccZ3,AccZ4;
unsigned char Z1,Z2,Z3,Z4,piezo;
int piezo_thresh;

MCP_CAN CAN(spiCSPin);


void setup(){
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  Wire.begin();
  Serial.begin(115200);
  while (CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
}
unsigned char stmp[8] = {0,0,0,0,0,0,0};
void loop(){
 piezo_thresh = analogRead(6);
 //Serial.println(piezo_thresh);
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
 /*Serial.println();
 Serial.print(AccZ1);Serial.print(",");*/
 // Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
 // Serial.print(" || GyroX = "); Serial.print(GyroX);
 // Serial.print(" || GyroY = "); Serial.print(GyroY);
 // Serial.print(" || GyroZ = "); Serial.println(GyroZ);
  //delay(10);
  if ((AccZ1 > -15000) || (AccZ1 < -16700))
  {
    push1();
  }
  else
  {
    Serial.println("Body stable");
  }
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
 /*Serial.print(AccZ2);Serial.print(",");*/
  //Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
 // Serial.print(" || GyroX = "); Serial.print(GyroX);
 // Serial.print(" || GyroY = "); Serial.print(GyroY);
 // Serial.print(" || GyroZ = "); Serial.println(GyroZ);
  //delay(10);
    if ((AccZ2 > -18000) || (AccZ2 < -18900))
  {
    push2();
  }
  else
  {
    Serial.println("Body stable");
  }
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
  /*Serial.print(AccZ3);Serial.print(",");*/
  //Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  //Serial.print(" || GyroX = "); Serial.print(GyroX);
  //Serial.print(" || GyroY = "); Serial.print(GyroY);
  //Serial.print(" || GyroZ = "); Serial.println(GyroZ);
  //delay(10);
 if ((AccZ3 > -16000) || (AccZ3 < -17500))
  {
    push3();
  }
  else
  {
    Serial.println("Body stable");
  }
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
 /*Serial.print(AccZ4);*/
 // Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
 // Serial.print(" || GyroX = "); Serial.print(GyroX);
 // Serial.print(" || GyroY = "); Serial.print(GyroY);
 // Serial.print(" || GyroZ = "); Serial.println(GyroZ);
 // delay(10);
  if ((AccZ4 > -16000) || (AccZ4 < -17000))
  {
    push4();
  }
  else
  {
    Serial.println("Body stable");
  }
  digitalWrite(3,HIGH);
}
int push1()
{
  Serial.println("body unstable 1");
  Z1 = (unsigned char)AccZ1;
  Z2 = (unsigned char)AccZ2;
  Z3 = (unsigned char)AccZ3;
  Z4 = (unsigned char)AccZ4;
  piezo = (unsigned char)piezo_thresh;
  stmp[0] = Z1;
  stmp[1] = Z2;
  stmp[2] = Z3;
  stmp[3] = Z4;
  stmp[4] = piezo;
  CAN.sendMsgBuf(0x01,0,8,stmp);
  Serial.println("push1");
}
int push2()
{
  Serial.println("body unstable 2");
  Z1 = (unsigned char)AccZ1;
  Z2 = (unsigned char)AccZ2;
  Z3 = (unsigned char)AccZ3;
  Z4 = (unsigned char)AccZ4;
  piezo = (unsigned char)piezo_thresh;
  stmp[0] = Z1;
  stmp[1] = Z2;
  stmp[2] = Z3;
  stmp[3] = Z4;
  stmp[4] = piezo;
  CAN.sendMsgBuf(0x01,0,8,stmp);
  Serial.println("push2");
}
int push3()
{
  Serial.println("body unstable 3");
  Z1 = (unsigned char)AccZ1;
  Z2 = (unsigned char)AccZ2;
  Z3 = (unsigned char)AccZ3;
  Z4 = (unsigned char)AccZ4;
  piezo = (unsigned char)piezo_thresh;
  stmp[0] = Z1;
  stmp[1] = Z2;
  stmp[2] = Z3;
  stmp[3] = Z4;
  stmp[4] = piezo;
  CAN.sendMsgBuf(0x01,0,8,stmp);
  Serial.println("push3");
}
int push4()
{
  Serial.println("body unstable 4");
  Z1 = (unsigned char)AccZ1;
  Z2 = (unsigned char)AccZ2;
  Z3 = (unsigned char)AccZ3;
  Z4 = (unsigned char)AccZ4;
  piezo = (unsigned char)piezo_thresh;
  stmp[0] = Z1;
  stmp[1] = Z2;
  stmp[2] = Z3;
  stmp[3] = Z4;
  stmp[4] = piezo;
  CAN.sendMsgBuf(0x01,0,8,stmp);
  Serial.println("push4");
}
