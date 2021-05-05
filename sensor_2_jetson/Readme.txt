for circuit refer connections

UPDATE:
For multiple 3 CAN ports,
use 3_can_workspace for NXP , sensor_can for chipkit , AirQ_Press_T_H_can for arduino nano , mpu6050_thresh_can_piezo for xiao (values are sent only if there is a change in acceleration/impact on piezo sensor) , socket_client_listen.py for Jetson

UPDATE:
For multiple 4 CAN ports,
use 4_can_workspace for NXP , sensor_can for chipkit , AirQ_Press_T_H_can for arduino nano , mpu6050_thresh_can_piezo for xiao (values are sent only if there is a change in acceleration/impact on piezo sensor) , bluepill_can_led for blue pill,socket_client_listen.py for Jetson
refer Ozone_Alice_accel , ozone_alice_sensors, ozone_alice_relay for circuit