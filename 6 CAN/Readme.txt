See the training PDF file in the documents folder. All the softwares can be downloaded from https://www.nxp.com/design/development-boards/automotive-development-platforms/startertrak-platforms/mpc5606b-startertrak-development-kit:TRK-MPC5606B
Use codewarrior for coding and debugging as well

Troubleshoot in example program:
1. Change RAM to FLASH
2. Ensure you add all the driver files (check the sources folder and compare them with existing example project), .lnf file , .rsp file in the sources folder

This file send CAN commands from Arduino to MPC5606B 

Connections:
Arduino CAN MCP <==> MPC5606B
CAN_H<==>7th Pin of DB9 connector
CAN_L<==>2nd Pin of DB9 connector 

In Arduino serial port enter "1" to switch ON LED 3 in starterTRAK dev board
In Arduino serial port enter "0" to switch OFF LED 3 in starterTRAK dev board