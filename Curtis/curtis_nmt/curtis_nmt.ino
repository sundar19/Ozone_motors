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

unsigned char stmp[2] = {0,0};
    
void loop()
{   
  stmp[0]=0x01;//Operational state 
  stmp[1]=0x00;//target node ==> set 0x00 for all nodes
  Serial.println("In loop");
  CAN.sendMsgBuf(0x00, 0, 2, stmp);// COB-ID, 0 for standard ID and 1 for extended ID, 2 is the data length , stmp is the data
  delay(120);//heartbeat message rate
}
