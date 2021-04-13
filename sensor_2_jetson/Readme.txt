NOTE: First switch ON power supply for NXP and then connect the USB else it wont respond
This folder tells about initializing 2 CAN ports and sending data from arduino to chipkit via nxp (with transceivers) 
Changes made with 
main.c
CANapi.h
CANdrv.c

Follow the instructions in the document 
1. to initialize multiple CAN enable all 6 CAN in the enabling step (RAPPID GUI)(Now initialized only 2 CAN)
2. In  CANdrv.c create function definitions and in CANapi.h declare them as global functions and edit them in main.c

connections:
This is CAN_0 of MPC5606B (CAN_0 with Chipkit)
TJA1050(1) <===> MPC5606B
Vcc <===> 5V(REG_5V/USB_5V)
GND <===>GND 
TX<===>PB0
RX<===>PB1
CAN_H<===>CAN_H(CAN2 of chipkit)
CAN_L<===>CAN_L(CAN2 of chipkit)

This is CAN_1 of MPC5606B(CAN_1 with Arduino)
TJA1050<===>MPC5606B
Vcc <===> 5V(REG_5V/USB_5V)
GND <===>GND 
TX<===>PC10
RX<===>PC11
CAN_H<===>CAN_H (Arduino CAN controller)
CAN_L<===>CAN_L(Arduino CAN controller)

Sensor <===> Arduino
Vcc<===>3.3V
GND<===>GND
SDA<===>A4
SCL<===>A5

Connect ethernet cable b/w Jetson and chipkit

Run multiple_can project in nxp and can_imu_nxp in Arduino and sensor_can in chipkit and socket_client_listen.py in jetson
For using seeeduino_xiao instead of arduino , use xiao_can_imu_nxp from seeeduino xiao folder, use tockn library also.

Run mpu6050_thresh_can to send values from all 4 imus from xiao to Jetson (values are sent only if there is a change in acceleration)
