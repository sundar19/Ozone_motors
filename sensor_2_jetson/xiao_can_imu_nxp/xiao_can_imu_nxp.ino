#include <SPI.h>
#include <mcp_can.h>
#include "Wire.h"


const int spiCSPin = 7;
const int MPU6050_addr=0x68;
int16_t AccX,AccY,AccZ,Temp,GyroX,GyroY,GyroZ;

unsigned char ax1,ay1,az1;
unsigned char gx1,gy1,gz1;

//#define LED_PIN 13
//bool blinkState = false;
//int ledHIGH    = 1;
//int ledLOW     = 0;

MCP_CAN CAN(spiCSPin);



void recv()
{
  unsigned char len = 0;
  unsigned char buf[8];
  unsigned char a,b,c;
  int a1,b1,c1;
  if(CAN_MSGAVAIL == CAN.checkReceive())
    {
        CAN.readMsgBuf(&len, buf);

        unsigned long canId = CAN.getCanId();

        //Serial.println("-----------------------------");
        Serial.print("Data from ID: 0x");
        Serial.println(canId, HEX);

        for(int i = 0; i<len; i++)
        {
            Serial.print(buf[i]);
            Serial.print("\t");
            

         }
    }
}

void setup()
{
  Serial.begin(115200);
  Wire.begin();      // join I2C bus
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
    

    while (CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
    //pinMode(LED_PIN, OUTPUT);  // configure LED pin
}
unsigned char stmp[8]= {0,1,2,3,4,5,6,7};

void loop()
{   
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr,14,true);
  AccX=Wire.read()<<8|Wire.read();
  AccY=Wire.read()<<8|Wire.read();
  AccZ=Wire.read()<<8|Wire.read();
  //Temp=Wire.read()<<8|Wire.read();
  GyroX=Wire.read()<<8|Wire.read();
  GyroY=Wire.read()<<8|Wire.read();
  GyroZ=Wire.read()<<8|Wire.read();
  
  ax1 = (unsigned char)AccX;
  ay1 = (unsigned char)AccY;
  az1 = (unsigned char)AccZ;
  gx1 = (unsigned char)GyroX;
  gy1 = (unsigned char)GyroY;
  gz1 = (unsigned char)GyroZ;
  stmp[0] = ax1;
  stmp[1]= ay1;
  stmp[2]= az1;
  stmp[3]= gx1;
  stmp[4]= gy1;
  stmp[5]= gz1;
  stmp[6]= 0;
  stmp[7]= 0;
  recv();
  //Serial.print("data sent:");
  Serial.print(stmp[0]);
  Serial.print("\t");
  Serial.print(stmp[1]);
  Serial.print("\t");
  Serial.print(stmp[2]);
  Serial.print("\t");
  Serial.print(stmp[3]);
  Serial.print("\t");
  Serial.print(stmp[4]);
  Serial.print("\t");
  Serial.print(stmp[5]);
  Serial.print("\t");
 /* 
  Serial.print("a/g:\t");
  Serial.print(ax);
  Serial.print("\t");
  Serial.print(ay);
  Serial.print("\t");
  Serial.print(az);
  Serial.print("\t");
  Serial.print(gx);
  Serial.print("\t");
  Serial.print(gy);
  Serial.print("\t");
  Serial.print(gz);
  Serial.print("\t");
  */
  Serial.println("In loop");
  CAN.sendMsgBuf(0x01, 0, 8, stmp); 
  delay(1000);
  /*int state = Serial.parseInt();
  if(state == 1)
  {
  CAN.sendMsgBuf(0x01, 0, 1, stmp);
  Serial.println("led command sent...");
  state = 2;
  }
  if (state == 3)
  {
  CAN.sendMsgBuf(0x01, 0, 1, stmps);
  Serial.println("led command sent...");
  state = 2;
  }
  if (state == 2)
  {
    Serial.println("send command ...");
  }*/

    // blink LED to indicate activity
  //blinkState = !blinkState;
  //digitalWrite(LED_PIN, blinkState);
}
