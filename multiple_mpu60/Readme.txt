mpu6050_check_plot is used for obtaining graph along Z axis and xiao_imu is generally used to read sensor values.
mpu6050_xiao_thresh_set has a threshold value set above noise level. Any movement results in pushing the sensor values to display.

For getting a graph do the following,
1. run the mpu6050_check_plot.ino files to record the values in the serial monitor.
2.copy those values to a csv file and plot it using line graph , this is helpful for obtaining bumps.


Thresholds are set using min and max values in csv files.
