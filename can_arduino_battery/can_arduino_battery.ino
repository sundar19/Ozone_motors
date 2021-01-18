#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 9;

MCP_CAN CAN(spiCSPin);



void recv()
{
  unsigned char len = 0;
  unsigned char buf[8];

  Serial.println("No message!");
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
    

    while (CAN_OK != CAN.begin(CAN_500KBPS,MCP_8MHz))//,MCP_8MHz
    {
        Serial.println("CAN BUS init Failed");
        delay(100);
    }
    Serial.println("CAN BUS Shield Init OK!");
delay(1000);// timeout
}


unsigned char stmp[0] = {};   
void loop()
{   

  
  CAN.sendMsgBuf(0x018C0EF4, 1, 0, stmp);//give the address here... , 0 for standard ID and 1 for extended ID, ... , stmp is the data
  Serial.println("sent message");
  delay(100);// timeout
  recv();
}
