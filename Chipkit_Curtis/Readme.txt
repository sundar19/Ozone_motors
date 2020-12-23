This directory contains instructions about communication between Chipkit CAN to curtis

Connect the chipkit CAN1 CAN_H to CAN_H of the curtis & chipkit CAN1 CAN_L to CAN_L of curtis

1. ChipkitCAN_nmt.pde consists of sending a NMT message to put the curtis to operational state.
2. ChipkitCAN_SDO.pde consists of sending a expedited SDO message to retrieve key switch voltage OD entry from curtis

IMPORTANT PARTS of the program to be edited

#define	node1can1	0x00L //Mention the CAN ID of curtis here to recieve data (for CAN 1)
#define node2can1	0x00L
#define node1can2	0x00L //Mention the CAN ID of chipkit here to transmit data (for CAN 1)
#define node2can2	0x00L


CAN TRANSMIT DATA
    message->msgSID.SID   = rxnode;	// chipkit CAN ID which is already set
    message->msgEID.IDE   = 0;			
    message->msgEID.DLC   = 8/2;	//Enter the correct data length here , varies for nmt-2 and sdo-8	
    message->data[0]        = 0x40; // enter the correct data ==> command for sdo or mode for nmt 
    message->data[1]        = 0x4D; // enter the correct data ==> index value for sdo or target node for nmt 
    message->data[2]        = 0x32; // enter the correct data ==> subindex value for sdo , not applicable for nmt
    message->data[3]        = 0x00;
    message->data[4]        = 0x00;
    message->data[5]        = 0x00;
    message->data[6]        = 0x00;
    message->data[7]        = 0x00;
 
 CAN RECIEVE DATA
    
   a = int(message->data[4]); // data byte 4 consists of the LSBs of the data 
   b = int(message->data[5]); // data byte 5 consists of the MSBs of the data 
   c = b << 8 | a ; // MSB << 8 (left shift by 8 places) | (and concatenate  with) LSB
   Serial.print("\nKey_switch_voltage:");
   Serial.println(c);