#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 7; //change 10 for arduino
int ledHIGH    = 1;
int ledLOW     = 0;

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

        Serial.println("-----------------------------");
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

    while (CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz))
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
}

unsigned char stmp[8] = {1,2,3,4,5,6,7,8};
unsigned char stmps[8] = {8,7,6,5,4,3,2,1};
    
void loop()
{   
  Serial.println("In loop");
  int state = Serial.parseInt();
  if(state == 1)
  {
  CAN.sendMsgBuf(0x01, 0, 8, stmp);
  Serial.println("led command sent...");
  state = 2;
  }
  if (state == 3)
  {
  CAN.sendMsgBuf(0x01, 0, 8, stmps);
  Serial.println("led command sent...");
  state = 2;
  }
  if (state == 2)
  {
    Serial.println("send command ...");
  }
  delay(1000);
  recv();
}
