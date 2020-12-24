To download mpide go to link http://www.chipkit.org/wiki/index.php?title=MPIDE and download 2014-08-21 - 0023 Note that other versions will not work


Note : The CDM v2.12.28 WHQL Certified file consists of driver files for Chipkit Max32 . 
Go to link https://www.ftdichip.com/Drivers/D2XX.htm to download the drivers (Windows Version 2.12.28) 
For driver installation procedures visit https://www.usb-drivers.org/ft232r-usb-uart-driver.html 


Assign the Linux computer (Jetson or laptop) as client and chipkit as server

Upload this code to chipkit and assign server position to it 

For PC/Jetson:(client)
1.sudo ip ad add 10.0.0.10/24 dev eno1/eth0
2.Now run python3 socket_client.py 

To assign static IP to Jetson ethernet 

In “/etc/network/” the naming of file “interfaces” would lead you to believe that it automatically works with files in “/etc/network/interfaces.d/”, but it doesn’t. So I manually told it to source the relevant file. Try manually editing “/etc/network/interfaces” to become this with one extra line:

# interfaces(5) file used by ifup(8) and ifdown(8)
# Include files from /etc/network/interfaces.d:
source-directory /etc/network/interfaces.d

# This line is a custom edit.
source interfaces.d/eth0
Then inside of “/etc/network/interfaces.d/” add file “eth0”. Content something like this (I’m assuming your router is the gateway and that the gateway has address “192.168.1.2”…note that the address you gave of “192.168.150” is missing a digit, I’m assuming it is “192.168.1.150”):

auto eth0
iface eth0 inet static
address 10.0.0.10

If that file is read the content says to automatically bring the interface up using static protocols, so it may be this is enough to stop DHCP (it depends on other software and there is a mix of NetworkManager and older style files that don’t always play together nicely).

For testing connection:
Run TCPEchoServer_editz.pde in chipkit & socket_client.py in Jetson

Serial monitor output:

TCPEchoServer 1.0
Digilent, Copyright 2011

Started Listening
Listening on port: 65432
Got 1 clients pending
Got a Connection
Got 14 bytes
Writing: 
Hello, Chipkit
Closing TcpClient

Listening on port: 65432

Terminal output:
Recieved b'*Hello Jetson*\n'

For On request and On call communication:
Run TCPEchoServer_oncall.pde & socket_client_orq.py 

Serial monitor output:
Got 1 bytes
Writing:
a
Got 1 bytes
Writing:
b

Terminal output:
Enter 'a' for CURTIS and 'b' for NXP
a
Recieving CURTIS data ...
b'CURTIS'
Enter 'a' for CURTIS and 'b' for NXP
b
Recieving NXP data...
b'NXP'


TCPEchoServer 1.0

0.  Select the hardware library that matches the network adaptor you are using. Make sure to look in the hardware library
    header file to see exactly how to configure your board; for example there may be some jumpers to set. If you have
    a network adaptor physically mounted on the chipKIT board, then comment out ALL hardware libraries as the correct software
    will be included with the MPIDE selection of the chipKIT board. For example, the MX7cK has an SMSC-8720 phy on the board
    and uses the MX7 internal network MAC, no hardware library is needed for the MX7cK.

        /************************************************************************/
        /*                                                                      */
        /*              Include ONLY 1 hardware library that matches            */
        /*              the network hardware you are using                      */
        /*                                                                      */
        /*              If your base chipKIT board has a network adaptor        */
        /*              manufactured on the board, such as the MX7cK,           */
        /*              then you do not need to specify any hardware library    */
        /*              for that network hardware on the board.                 */
        /*              However, if you are using alternate network hardware,   */
        /*              then you will need to specify the hardware library      */
        /*              for the hardware you are using.                         */
        /*                                                                      */
        /*              Refer to the hardware library header file               */
        /*              for supported boards and hardware configurations        */
        /*                                                                      */
        /************************************************************************/
        #include <NetworkShield.h>
        // #include <PmodNIC.h>
        // #include <PmodNIC100.h>

1.  Make sure that the TCPIP Server address of 192.168.1.190:44300 will work on your network.
    If not then modify the server address in the sketch to one that will.

            /************************************************************************/
            /*                                                                      */
            /*              SET THESE VALUES FOR YOUR NETWORK                       */
            /*                                                                      */
            /************************************************************************/

            IPv4 ipServer = {192,168,1,190};
            unsigned short portServer = 44300;    

2.  Compile and upload TCPEchoServer from MPIDE. Once TCPEchoServer is uploaded open the serial monitor at 9600 baud. 
    You should see something like:

            TCPEchoServer 1.0
            Digilent, Copyright 2011

            Started Listening
            Listening on port: 44300

3.  Under the ...\libraries\DNETcK\examples\TCPEchoServer\PCCode directory start TCPEchoClient.exe; this is a windows Forms application 
    so a window will automatically open.

4.  In TCPEchoClient it defaults to the same hostname IP and port as the sketch was originally coded to. However, if you 
    changed those values, change them in TCPEchoClient before proceeding.

5.  The default "Send Text" in TCPEchoClient is "Text to Echo", you may leave this as is, or change it. This documentation is 
    assuming you left it as is.

6.  The Log in TCPEchoClient should look something like:

            TCPEchoClient Version 1.0.4414.23621
            Digilent, Copyright 2011

7.  Click the Send button in TCPEchoClient and wait about 10 seconds. You should see in the serial monitor something like:

            TCPEchoServer 1.0
            Digilent, Copyright 2011

            Started Listening
            Listening on port: 44300
            Got 1 clients pending
            Got a Connection
            Got 12 bytes
            Writing: 
            Text to Echo
            Closing TcpClient

            Listening on port: 44300

8.  And in the TCPEchoClient you should see something like:

            TCPEchoClient Version 1.0.4414.23621
            Digilent, Copyright 2011
            Info: Please wait, attempting to connect to: 192.168.1.190:44300
            TX: Text to Echo
            Starting to listen
            RX: Text to Echo
            Ending listening

9.  If you hit the Send button repeatedly quickly (within a second or so; actually less than 5 seconds).  You will see a repetition 
    of the TX and RX without Start/End listening as the connection is not dropped between sends. Likewise in the serial monitor 
    you will not see the Listening on port: 44300 between the echoes as that connection is not dropped either. 

10. To close TCPEchoClient, hit the RED X.
