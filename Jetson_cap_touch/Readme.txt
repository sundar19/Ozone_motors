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

To Check which pin is touched use
sudo i2cget 1 0x29 0x03

To reset all pin capacitive touch state 
sudo i2cset 1 0x29 0x00 0x00 

NOTE : In my Jetson TK1
If sudo apt-get install package_name doesnot work

Use:
sudo add-apt-repository universe
sudo apt update

If pip3 doesnot work 

Use: 
whereis pip3

Know where the pip3 is located , delete it and reinstall pip3 and place it in the same directory.


