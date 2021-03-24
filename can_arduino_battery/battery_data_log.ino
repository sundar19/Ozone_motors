#include <SPI.h>
#include <mcp_can.h>

const int spiCSPin = 9;

MCP_CAN CAN(spiCSPin);



void recv()
{
  unsigned char len = 0;
  unsigned char buf[8];
  unsigned char a,b,c,d,e,f,g,h;
  int a1,b1,c1,d1,e1,f1,g1,h1;
  int volt,curr,ofcell_cnt,obcell_cnt,temp_sens1,temp_sens2,temp_sens3,temp_sens4;


  //Serial.println("No message!");
  if(CAN_MSGAVAIL == CAN.checkReceive())
    {
        CAN.readMsgBuf(&len, buf);

        unsigned long canId = CAN.getCanId();

        //Serial.println("-----------------------------");
        //Serial.print("Data from ID: 0x");
        //Serial.println(canId, HEX);
if (canId == 25956084)
{
        for(int i = 0; i<len; i++)
        {
            //Serial.print(buf[i]);
            //Serial.print("\t");
            a = buf[0]; //MSB V
            b = buf[1];// LSB V
            c = buf[2];// MSB I
            d = buf[3];// LSB I
            e = buf[4];//SOC
            f = buf[5];//SOH
            g = buf[6];//Status 
            h = buf[7];//reserved
         }
        a1 = (int)a;
        b1 = (int)b;
        c1 = (int)c;
        d1 = (int)d;
      volt = a1 << 8 | b1;
      curr = c1 << 8 | d1;
      Serial.println();
      Serial.print(volt);Serial.print(",");Serial.print(curr);
      Serial.print(",");Serial.print(e);Serial.print(",");Serial.print(f);  
      Serial.print(",");Serial.print(g,BIN);
    }

 else if (canId == 25956085)

 {
     for(int i = 0; i<len; i++)
        {
            //Serial.print(buf[i]);
            //Serial.print("\t");
            a = buf[0]; //MSB official cell count
            b = buf[1];// LSB official cell count 
            c = buf[2];// MSB observed cell count
            d = buf[3];// LSB observed cell count
            e = buf[4];//official cascaded LTC
            f = buf[5];//observed cascaded LTC
            g = buf[6];//Number of temp sensors
            h = buf[7];//communication interface
         }
        a1 = (int)a;
        b1 = (int)b;
        c1 = (int)c;
        d1 = (int)d;
      ofcell_cnt = a1 << 8 | b1;
      ofcell_cnt = c1 << 8 | d1;
      //Serial.println();
      Serial.print(",");Serial.print(ofcell_cnt);Serial.print(",");Serial.print(ofcell_cnt);
      Serial.print(",");Serial.print(e);Serial.print(",");Serial.print(f);  
      Serial.print(",");Serial.print(g);Serial.print(","),Serial.print(h,BIN);
 }
   else if (canId == 25956090)
   {
    for(int i = 0; i<len; i++)
        {
            //Serial.print(buf[i]);
            //Serial.print("\t");
            a = buf[0];//temperature sensors
            b = buf[1];// reserved 
            c = buf[2];// reserved
            d = buf[3];// reserved
            e = buf[4];// MSB temp sensor 1
            f = buf[5];//LSB temp sensor 1
            g = buf[6];//MSB temp sensor 2 
            h = buf[7];//LSB temp sensor 2
         }
        e1 = (int)e;
        f1 = (int)f;
        g1 = (int)g;
        h1 = (int)h;
      temp_sens1 = e1 << 8 | f1;
      temp_sens2 = g1 << 8 | h1;
      //Serial.println();
      Serial.print(",");Serial.print(a,BIN);Serial.print(",");Serial.print(temp_sens1);
      Serial.print(",");Serial.print(temp_sens2);  
  }
 else if (canId == 25956091)
  {
    for(int i = 0; i<len; i++)
        {
            //Serial.print(buf[i]);
            //Serial.print("\t");
            a = buf[0];//MSB temp sensor 3
            b = buf[1];//LSB temp sensor 3
            c = buf[2];//MSB temp sensor 4
            d = buf[3];//LSB temp sensor 4
            e = buf[4];// reserved
            f = buf[5];// reserved 
            g = buf[6];// reserved 
            h = buf[7];// reserved
         }
        a1 = (int)a;
        b1 = (int)b;
        c1 = (int)c;
        d1 = (int)d;
      temp_sens1 = a1 << 8 | b1;
      temp_sens2 = c1 << 8 | d1;
      //Serial.println();
      Serial.print(",");Serial.print(temp_sens3);Serial.print(",");Serial.print(temp_sens4);   
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
   // Serial.println("CAN BUS Shield Init OK!");
Serial.println("Voltage,Current,SOC%,SOH%,SOC_SOH_STATUS,official_cell_cnt,observed_cell_cnt,official_LTC,observed_LTC,temp_sens_cnt,comm_interf,sensor_status,temp_sens1,temp_sens2,temp_sens3,temp_sens4");

}


unsigned char stmp[0] = {};   
void loop()
{   

  
  CAN.sendMsgBuf(0x018C0EF4, 1, 0, stmp);//give the address here... , 0 for standard ID and 1 for extended ID, ... , stmp is the data
  //Serial.println("sent message");
  //delay(100);// timeout
  recv();
  CAN.sendMsgBuf(0x018C0EF5, 1, 0, stmp);//give the address here... , 0 for standard ID and 1 for extended ID, ... , stmp is the data
  //Serial.println("sent message");
  //delay(100);// timeout
  recv();
  CAN.sendMsgBuf(0x018C0EFA, 1, 0, stmp);//give the address here... , 0 for standard ID and 1 for extended ID, ... , stmp is the data
  //Serial.println("sent message");
  //delay(100);// timeout
  recv();
  CAN.sendMsgBuf(0x018C0EFB, 1, 0, stmp);//give the address here... , 0 for standard ID and 1 for extended ID, ... , stmp is the data
  //Serial.println("sent message");
  //delay(100);// timeout
  recv();
}
