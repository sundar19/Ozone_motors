/* 
 bpCanBlink.ino                                                                     4/24/20
 C:\Users\jhe\Documents\PlatformIO\mySTM32LIBS\eXoCAN\bpCanBlink.cpp

 This simple example requires two STM32f103 boards.  One of the boards is loaded
 with the 'frame' using txMsg = 0x069.  The second board gets loaded with the second
 frame where tsMsgID = 0x005 by uncommenting that section.

 On each board connect CAN default RX and TX pins(11,12) together.  Then connect
 the boards together: +5V, Gnd., and Can TX/RX.

 When a board receives a CAN message it toggles its LED.  One board sends a message
 every second and the other every five seconds.

  RAM:   904 bytes 
  Flash: 12988 bytes  

 working                                                                            4/25

*/
#include <arduino.h>
#include <eXoCAN.h>

//#define bluePillLED PC13

int txMsgID = 0x01;
uint8_t txData[8]{0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08};
uint8_t txDataLen = 8;
uint32_t txDly = 500; // mSec

//  ****** uncomment the following for the second stm32f103 board ******

// int txMsgID = 0x005;
// uint8_t txData[8]{{0x01, 0xfe, 0xdc, 0xba, 0x11, 0x12, 0x34, 0x56};
// uint_8 txDataLen = 8;
// uint32_t txDly = 1000;  // mSec

int id, fltIdx;
uint8_t rxbytes[8];
eXoCAN can;

void setup()
{
  Serial.begin(115200);
  can.begin(STD_ID_LEN, BR500K, PORTA_11_12_XCVR); // 11b IDs, 500k bit rate, no transceiver chip, portA external tx/rx pins 11,12
  can.filterMask16Init(0, 0, 0, 0, 0);                // filter bank 0, filter 0: don't pass any(0x7ff), flt 1: pass all msgs
  pinMode(PC13, OUTPUT);
  while (!Serial);
}

uint32_t last = 0;
void loop()
{
  
  //if (can.receive(id, fltIdx, rxbytes) > -1) // poll for rx
  if(can.receive(id, fltIdx, rxbytes)>-1)
  {
  Serial.println();
  Serial.print(rxbytes[0]);
  Serial.print("\t");
  Serial.print(rxbytes[1]);
  Serial.print("\t");
  Serial.print(rxbytes[2]);
  Serial.print("\t");
  Serial.print(rxbytes[3]);
  Serial.print("\t");
  Serial.print(rxbytes[4]);
  Serial.print("\t");
  Serial.print(rxbytes[5]);
  Serial.print("\t");
  Serial.print(rxbytes[6]);
  Serial.print("\t");
  Serial.print(rxbytes[7]);
  Serial.print("\t");
  if (rxbytes[0] == 1)
  {
    digitalWrite(PC13,!(digitalRead(PC13)));
  }
}
can.transmit(txMsgID, txData, txDataLen);
delay(1000);
    //digitalToggle(bluePillLED);
}
