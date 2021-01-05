This folder consists of connecting arduino to mpc5606b via a tja1050 transceiver and checking values.
NOTE: Remove jumpers from CAN_TXD (J6_A) and CAN_RXD(J6_B)
Connections:

CAN module (Arduino) <===> TJA1050 transceiver
CAN_H <===>CAN_H
CAN_L<===>CAN_L
   
MPC5606B <=====> TJA1050 Transceiver
PC10 <===> TX
PC11 <==>RX
5V (REG_5V / USB_5V) <===> Vcc
GND <===>GND

Upload  nxp_text.ino in Arduino and debug main.c in MPC5606B  
check arduino serial monitor for numbers
