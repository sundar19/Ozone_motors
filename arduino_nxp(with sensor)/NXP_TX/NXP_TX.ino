#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 10;
int ledHIGH    = 1;
int ledLOW     = 0;

MCP_CAN CAN(spiCSPin);

void setup()
{
    Serial.begin(115200);

    while (CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
}

unsigned char stmp[1] = {1};
unsigned char stmps[1] = {0};
    
void loop()
{   
  Serial.println("In loop");
  int state = Serial.parseInt();
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
  }
  delay(1000);
}
