
Connect CAN_H and CAN_L of curtis to CAN_H and CAN_L of mcp2515 module connected with Arduino
Use the curtis_nmt.ino file in Arduino to set the NMT state of the curtis

0x01	Enter Operational
0x02	Enter Stop
0x80	Enter Pre-operational
0x81	Reset node
0x82	Reset communication

Ensure you are in operational mode before sending PDO messages.