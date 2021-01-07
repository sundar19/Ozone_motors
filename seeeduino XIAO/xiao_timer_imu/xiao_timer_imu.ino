#include <TimerTCC0.h>
#include<Wire.h>
const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;
bool isLEDOn = false;
char time = 0;

void setup() 
{
    //SerialUSB.begin(115200);
    //while(!SerialUSB);
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(115200);
   // pinMode(13, OUTPUT);    

    TimerTcc0.initialize(1000000);
    TimerTcc0.attachInterrupt(timerIsr);
}
 
void loop()
{
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  Serial.print("AccX = "); Serial.print(AccX);
  Serial.print(" || AccY = "); Serial.print(AccY);
  Serial.print(" || AccZ = "); Serial.print(AccZ);
  //Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  Serial.print(" || GyroX = "); Serial.print(GyroX);
  Serial.print(" || GyroY = "); Serial.print(GyroY);
  Serial.print(" || GyroZ = "); Serial.println(GyroZ);
    /*
    time ++;
    if(time == 10)TimerTcc0.detachInterrupt();
    else if(time == 20)
    {
       TimerTcc0.attachInterrupt(timerIsr);
       time = 0;
    }
    delay(1000);
    */
}

void timerIsr()
{    
    //digitalWrite(13, isLEDOn);
    //isLEDOn = !isLEDOn;
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  //Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
}
