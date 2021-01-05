
Connect CAN_H and CAN_L of curtis to CAN_H and CAN_L of mcp2515 module connected with Arduino
Use the curtis_nmt.ino file in Arduino to set the NMT state of the curtis

0x01	Enter Operational
0x02	Enter Stop
0x80	Enter Pre-operational
0x81	Reset node
0x82	Reset communication

Ensure you are in operational mode before sending SDO messages.

For sending Reciever SDO messages from Arduino use SDO_RX.ino code to recieve various object dictionary parameters from curtis.

Change the byte values according to the SDO_data.png

For example in the curtis manual: The key switch voltage object dictionary looks like this 

Keyswitch Voltage
Keyswitch_Voltage
0x324D 0x00

Thus in the program change 
  stmp[1]= 0x4D;
  stmp[2]= 0x32;

Do not change other values as they are fixed for reading OD using SDO messages in curtis.

For further info visit http://www.byteme.org.uk/canopenparent/canopen/sdo-service-data-objects-canopen/