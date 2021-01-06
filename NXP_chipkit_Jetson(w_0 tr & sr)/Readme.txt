 To check communication between NXP and chipkit
 1. Upload chipkitcan_nxp into chipkit and debug main.c into nxp
 
 To establish whole communication between chipkit , nxp and jetson
 follow these steps correctly in order to establish the communication
 1. Upload tcp_can_nxp into chipkit (or reset chipkit first if its already flashed)
 2. debug main.c into nxp 6_can (or reset nxp second if its already flashed)
 3. Then run socket_client_orq.py in Jetson (lastly) to view the values.
 
 To be resolved: (same as jetson-chipkit-curtis)
 1. Synchronization problems in ethernet and CAN
 2. dummy data appears in jetson.
