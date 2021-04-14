#include <Wire.h>
#include <SPI.h>
#include <mcp_can.h>
#include "DFRobot_CCS811.h"
#include <Adafruit_MPL3115A2.h>
#include "SparkFun_Si7021_Breakout_Library.h"


/*
 * IIC address default 0x5A, the address becomes 0x5B if the ADDR_SEL is soldered.
 */
//DFRobot_CCS811 sensor(&Wire, /*IIC_ADDRESS=*/0x5A);
int co2,tvoc;
float pascals,altm,tempC,inches;
float humidity = 0;
float tempc = 0;
const int spiCSPin = 10;

MCP_CAN CAN(spiCSPin);
DFRobot_CCS811 sensor;
Weather sensor1;
Adafruit_MPL3115A2 baro = Adafruit_MPL3115A2();

void setup()
{
      Serial.begin(115200);
      while (CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
    /*Wait for the chip to be initialized completely, and then exit*/
    Serial.println("Adafruit_MPL3115A2 test!");
    while(sensor.begin() != 0){
        Serial.println("failed to init CCS811 chip, please check if the chip connection is fine");
        delay(1000);
    }
    /**
     * @brief Set measurement cycle
     * @param cycle:in typedef enum{
     *                  eClosed,      //Idle (Measurements are disabled in this mode)
     *                  eCycle_1s,    //Constant power mode, IAQ measurement every second
     *                  eCycle_10s,   //Pulse heating mode IAQ measurement every 10 seconds
     *                  eCycle_60s,   //Low power pulse heating mode IAQ measurement every 60 seconds
     *                  eCycle_250ms  //Constant power mode, sensor measurement every 250ms
     *                  }eCycle_t;
     */
    sensor.setMeasCycle(sensor.eCycle_250ms);
    sensor1.begin();
}
unsigned char stmp[8] = {0, 0, 0, 0, 0, 0, 0, 0};
void loop()
{
  airq();
  pressure();
  getWeather();
  printInfo();
  stmp[0] = (unsigned char)co2;
  stmp[1] = (unsigned char)tvoc;
  stmp[2] = (unsigned char)inches;
  stmp[3] = (unsigned char)altm;
  stmp[4] = (unsigned char)humidity;
  stmp[5] = (unsigned char)tempc;
  CAN.sendMsgBuf(0x01,0,8,stmp);
  
}
void airq()
{
   if(sensor.checkDataReady() == true){
    //int co2,tvoc;
        Serial.print("CO2: ");
        co2 = sensor.getCO2PPM();
        Serial.print(co2);
        Serial.print("ppm, TVOC: ");
        tvoc = sensor.getTVOCPPB();
        Serial.print(tvoc);
        Serial.println("ppb");
        
    } else {
        Serial.println("Data is not ready!");
    }
    /*!
     * @brief Set baseline
     * @param get from getBaseline.ino
     */
    sensor.writeBaseLine(0x2483); // use the baseline value here
    //delay cannot be less than measurement cycle
    delay(250);
}
void pressure()
{
   if (! baro.begin()) {
    Serial.println("Couldnt find sensor");
    return;
  }
  
  /*float*/ pascals = baro.getPressure();
  // Our weather page presents pressure in Inches (Hg)
  // Use http://www.onlineconversion.com/pressure.htm for other units
  inches = pascals/3377;
  Serial.print(inches); Serial.println(" Inches (Hg)");

  /*float*/ altm = baro.getAltitude();
  Serial.print(altm); Serial.println(" meters");

  /*float*/ tempC = baro.getTemperature();
  Serial.print(tempC); Serial.println("*C");

  delay(250);//250
}
void getWeather()
{
  // Measure Relative Humidity from the HTU21D or Si7021
  humidity = sensor1.getRH();

  // Measure Temperature from the HTU21D or Si7021
  tempc = sensor1.getTemp();
  // Temperature is measured every time RH is requested.
  // It is faster, therefore, to read it from previous RH
  // measurement with getTemp() instead with readTemp()
  
}

void printInfo()
{
//This function prints the weather data out to the default Serial Port

  Serial.print("Temp:");
  Serial.print(tempc);
  Serial.print("C, ");

  Serial.print("Humidity:");
  Serial.print(humidity);
  Serial.println("%");
  delay(250);
}
