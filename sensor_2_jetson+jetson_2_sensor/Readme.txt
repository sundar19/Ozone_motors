For circuit refer connections folder


Run the following programs

xiao with mpu6050,piezo and CAN ==> mpu6050_thresh_can_piezo

nano with temp&humid,press,airq and CAN ==>AirQ_Press_T_H_can

bluepill with led ==> bluepill_recv_led

NXP ==> 4_can_workspace

ChipKit ==> sensor_can_tcp_bidir

(set static IP for Jetson)

[using GUI]

Jetson  ==> gui_data_send

[OR for touch sensor ] 

Jetson ==> socket_bidir_usrctrl.py

[touch sensor + heal]

Jetson ==> socket_bidir_usrctrl_heal.py