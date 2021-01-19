I2CTOOLS: https://ubuntu.pkgs.org/14.04/ubuntu-universe-armhf/i2c-tools_3.1.0-2_armhf.deb
LIBI2C-DEV: https://ubuntu.pkgs.org/14.04/ubuntu-universe-armhf/libi2c-dev_3.1.0-2_all.deb
After which use sudo dpkg -i package_name.deb to install the software

Website : https://ubuntu.pkgs.org/14.04/ubuntu-universe-armhf/i2c-tools_3.1.0-2_armhf.deb.html , https://ubuntu.pkgs.org/14.04/ubuntu-universe-armhf/libi2c-dev_3.1.0-2_all.deb.html

PIN outs :
http://developer.download.nvidia.com/embedded/jetson/TK1/docs/3_HWDesignDev/JTK1_DevKit_Specification.pdf
https://elinux.org/Jetson/I2C
https://elinux.org/Jetson/GPIO

CAP touch module: http://ww1.microchip.com/downloads/en/DeviceDoc/00001620C.pdf

Connections: from https://elinux.org/Jetson/GPIO
Use J3A1
Jetson <===> Module
15 <===>GND
16<===>VIN
18<===>SCK
20<===>SCL

Use 

sudo i2cdetect -y -r 1 

command to check if the module is connected!!
We are using port 1 i2c