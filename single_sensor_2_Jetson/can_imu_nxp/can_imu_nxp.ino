#include <SPI.h>
#include <mcp_can.h>
#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"

const int spiCSPin = 10;
int16_t ax, ay, az;  // define accel as ax,ay,az
int16_t gx, gy, gz;  // define gyro as gx,gy,gz

unsigned char ax1,ay1,az1;
unsigned char gx1,gy1,gz1;

//#define LED_PIN 13
//bool blinkState = false;
//int ledHIGH    = 1;
//int ledLOW     = 0;

MCP_CAN CAN(spiCSPin);
MPU6050 accelgyro; 


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
    Wire.begin();      // join I2C bus
    Serial.begin(115200);
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();
     // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

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
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  // read measurements from device
  ax1 = (unsigned char)ax;
  ay1 = (unsigned char)ay;
  az1 = (unsigned char)az;
  gx1 = (unsigned char)gx;
  gy1 = (unsigned char)gy;
  gz1 = (unsigned char)gz;
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
