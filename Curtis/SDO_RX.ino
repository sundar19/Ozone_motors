#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 10;

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
            a = buf[4];
            b = buf[5];
            

         }
        a1 = (int)a;
        b1 = (int)b;
        c1 = b1 << 8 | a1 ;
        Serial.print("\nKey_switch_voltage:");
        Serial.println(c1);
        Serial.println();
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

unsigned char stmp[8] = {0,0,0,0,0,0,0,0};
    
void loop()
{   
  stmp[0]= 0x40; //fixed do not change
  stmp[1]= 0x4D;
  stmp[2]= 0x32;
  stmp[3]= 0x00;
  stmp[4]= 0x00;
  stmp[5]= 0x00;
  stmp[6]= 0x00;
  stmp[7]= 0x00;
  Serial.println("In loop");
  CAN.sendMsgBuf(0x626, 0, 8, stmp);//... , 0 for standard ID and 1 for extended ID, ... , stmp is the data
  delay(100);// timeout
  recv();
}
