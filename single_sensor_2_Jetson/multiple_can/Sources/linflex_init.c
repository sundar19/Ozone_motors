/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : Multiple_can
 *
 * Project File           : Multiple_can.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.2.1.5
 *
 * file                   : linflex_init.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5606B
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 04-Jan-2021 06:16:55
 *
 * Created on Date        : 04-Jan-2021 06:16:56
 *
 * Brief Description      : This file initializes LINFlex registers
 *
 ******************************************************************************** 
 *
 * Detail Description     : The LINFlex (Local Interconnect Network Flexible)
 *                         controller interfaces the LIN network and supports
 *                         the LIN protocol versions 1.3, 2.0 and 2.1 and J2602
 *                         in both Master and Slave modes. File contains Linflex
 *                         subparts general configuration, interrupt and identifier
 *                         timeout and UART configuration
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "linflex_init.h"






/**********************  Initialization Function(s) *************************/


void linflex_init_fnc (void) 
{
    linflex0_init_fnc();
    linflex1_init_fnc();
    linflex2_init_fnc();
    linflex3_init_fnc();
    linflex4_init_fnc();
    linflex5_init_fnc();
}

void linflex0_init_fnc (void) 
{

    LINFLEX_0.LINCR1.B.INIT = 1;
        /*Initialization Request: Set */

    LINFLEX_0.LINCR1.B.SLEEP = 0;
        /*Sleep Request: Clear */

    LINFLEX_0.UARTCR.B.UART= 1;
        /* UART Mode: Enabled */
/*----------------------------------------------------------- */
/*        LIN control register 2   (LINFLEX_0_LINCR2)        */
/*----------------------------------------------------------- */

    LINFLEX_0.LINCR2.R = 0x6000;
        /* Idle on Bit Error: Enabled*/
        /* Idle on Identifier Parity Error: Enabled*/


/*----------------------------------------------------------- */
/*        LIN integer baudrate register  (LINFLEX_0_LINIBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_0.LINIBRR.R = 0x0008;
        /* Baudrate : 115107.91 Symbols/sec */
        /* Integer Baud Rate Factor: 8*/

/*----------------------------------------------------------- */
/*        LIN fractional baudrate register (LINFLEX_0_LINFBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_0.LINFBRR.R = 0x000B;
        /* Fractional Baud Rate Factor: 11*/

/*----------------------------------------------------------- */
/*        Identifier filter mode register  (LINFLEX_0_IFMR)         */
/*----------------------------------------------------------- */

    LINFLEX_0.IFMR.R = 0x0000;
        /* Filters 0 & 1:identifier list mode    */
        /* Filters 2 & 3:identifier list mode    */
        /* Filters 4 & 5:identifier list mode    */
        /* Filters 6 & 7:identifier list mode    */
        /* Filters 8 & 9:identifier list mode    */
        /* Filters 10 & 11:identifier list mode    */
        /* Filters 12 & 13:identifier list mode    */
        /* Filters 14 & 15:identifier list mode    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR0)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[0].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR1)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[1].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR2)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[2].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR3)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[3].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR4)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[4].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR5)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[5].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR6)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[6].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR7)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[7].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR8)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[8].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR9)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[9].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR10)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[10].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR11)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[11].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR12)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[12].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR13)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[13].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR14)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[14].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*    Identifier filter control register  (LINFLEX_0_IFCR15)    */
/*----------------------------------------------------------- */
    LINFLEX_0.IFCR[15].R = 0x0000;
        /* Data Field Length (Bytes): 1    */
        /* Direction: Receive    */
        /* Checksum: Enhanced    */
        /* Identifier: 0    */

/*----------------------------------------------------------- */
/*        Identifier filter enable register  (LINFLEX_0_IFER)         */
/*----------------------------------------------------------- */

    LINFLEX_0.IFER.R = 0x0000;
        /* Activate Filter 0 & 1:Disabled    */
        /* Activate Filter 2 & 3:Disabled    */
        /* Activate Filter 4 & 5:Disabled    */
        /* Activate Filter 6 & 7:Disabled    */
        /* Activate Filter 8 & 9:Disabled    */
        /* Activate Filter 10 & 11:Disabled    */
        /* Activate Filter 12 & 13:Disabled    */
        /* Activate Filter 14 & 15:Disabled    */

/*----------------------------------------------------------- */
/*    DMA Tx enable register  (LINFLEX_0_DMATXE)              */
/*----------------------------------------------------------- */
    LINFLEX_0.DMATXE.R = 0x0000;
        /* DMA Transmitter Channel 0 : Disabled  */
        /* DMA Transmitter Channel 1 : Disabled  */
        /* DMA Transmitter Channel 2 : Disabled  */
        /* DMA Transmitter Channel 3 : Disabled  */
        /* DMA Transmitter Channel 4 : Disabled  */
        /* DMA Transmitter Channel 5 : Disabled  */
        /* DMA Transmitter Channel 6 : Disabled  */
        /* DMA Transmitter Channel 7 : Disabled  */
        /* DMA Transmitter Channel 8 : Disabled  */
        /* DMA Transmitter Channel 9 : Disabled  */
        /* DMA Transmitter Channel 10 : Disabled  */
        /* DMA Transmitter Channel 11 : Disabled  */
        /* DMA Transmitter Channel 12 : Disabled  */
        /* DMA Transmitter Channel 13 : Disabled  */
        /* DMA Transmitter Channel 14 : Disabled  */
        /* DMA Transmitter Channel 15 : Disabled  */

/*----------------------------------------------------------- */
/*    DMA Rx enable register  (LINFLEX_0_DMARXE)             */
/*----------------------------------------------------------- */
    LINFLEX_0.DMARXE.R = 0x0000;
        /* DMA Receiver Channel 0 : Disabled  */
        /* DMA Receiver Channel 1 : Disabled  */
        /* DMA Receiver Channel 2 : Disabled  */
        /* DMA Receiver Channel 3 : Disabled  */
        /* DMA Receiver Channel 4 : Disabled  */
        /* DMA Receiver Channel 5 : Disabled  */
        /* DMA Receiver Channel 6 : Disabled  */
        /* DMA Receiver Channel 7 : Disabled  */
        /* DMA Receiver Channel 8 : Disabled  */
        /* DMA Receiver Channel 9 : Disabled  */
        /* DMA Receiver Channel 10 : Disabled  */
        /* DMA Receiver Channel 11 : Disabled  */
        /* DMA Receiver Channel 12 : Disabled  */
        /* DMA Receiver Channel 13 : Disabled  */
        /* DMA Receiver Channel 14 : Disabled  */
        /* DMA Receiver Channel 15 : Disabled  */

/*----------------------------------------------------------- */
/*        UART mode control register  (LINFLEX_0_UARTCR)        */
/*----------------------------------------------------------- */
    LINFLEX_0.UARTCR.R = 0x0033;
        /* UART Mode: Enable*/
        /* Parity transmit/check: Disable*/
        /* Parity Control Option: Even Parity*/
        /* Word Length in UART mode: 8 bit data (9 bit if PCE is set)*/
        /* Tx FIFO/buffer mode: Disabled */
        /* Rx FIFO/buffer mode: Disabled */
        /* Transmitter data field length / Tx FIFO counter (Bytes):1*/
        /* Receiver Data Field Length /Rx FIFO counter  (Bytes): 1*/
        /* Transmitter : Enable*/
        /* Receiver : Enable*/


/*----------------------------------------------------------- */
/*        UART preset timeout register (LINFLEX_0_UARTPTO)        */
/*----------------------------------------------------------- */
    LINFLEX_0.UARTPTO.R = 0x0FFF;
        /* Preset Timeout counter : 4095*/


/*----------------------------------------------------------- */
/*        LIN timeout control status register  (LINFLEX_0_LINTCSR)        */
/*----------------------------------------------------------- */

    LINFLEX_0.LINTCSR.R = 0x0200;
        /* LIN timeout mode: Disabled*/
        /* Idle on Timeout: Enabled*/
        /* Timeout Counter: Disabled*/


/*----------------------------------------------------------- */
/*        LIN output compare register  (LINFLEX_0_LINOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_0.LINOCR.R = 0xFFFF;
        /* Output compare Value 1: 255*/
        /* Output compare Value 2: 255*/

/*----------------------------------------------------------- */
/*        LIN timeout control register  (LINFLEX_0_LINTOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_0.LINTOCR.R = 0x0E2C;
        /* Header Timeout (Bit Time): 44*/
        /* Response Timeout: 14*/

/*----------------------------------------------------------- */
/*        LIN interrupt enable register  (LINFLEX_0_LINIER)        */
/*----------------------------------------------------------- */

    LINFLEX_0.LINIER.R = 0x0000;

        /* Header Received Interrupt: Disabled    */
        /* Data Transmitted Interrupt: Disabled    */
        /* Data Reception Complete Interrupt: Disabled    */
        /* Data Buffer Empty Interrupt: Disabled    */
        /* Data Buffer Full Interrupt: Disabled    */
        /* Wakeup Interrupt: Disabled    */
        /* LIN State Interrupt: Disabled    */
        /* Buffer Overrun Error Interrupt: Disabled    */
        /* Frame Error Interrupt: Disabled    */
        /* Header Error Interrupt: Disabled    */
        /* Checksum Error Interrupt: Disabled    */
        /* Bit Error Interrupt: Disabled    */
        /* Output Compare Interrupt: Disabled    */
        /* Stuck at Zero Interrupt: Disabled    */

/*----------------------------------------------------------- */
/*        LIN control register 1   (LINFLEX_0_LINCR1)        */
/*----------------------------------------------------------- */

    LINFLEX_0.LINCR1.R = 0x0081;
        /* Initialization Request: Set */
        /* Master Mode Enable: Slave*/
        /* Receiver Buffer: Not Locked*/
        /* Loopback Mode: Disabled*/
        /* Self Test Mode: Disabled*/
        /* LIN Master Break Length: 10 bits*/
        /* Slave Mode Break Detection Threshold: 11 bits*/
        /* Bypass Filter: Enabled*/
        /* Automatic Wake-Up Mode: Disabled*/
        /* Checksum field: Enabled*/
        /* Checksum Calculation: Disabled*/
        /* LIN Slave Automatic Resynchronization: Disabled*/



    LINFLEX_0.LINCR1.B.INIT = 0;
        /*Initialization Request: Clear */

}

void linflex1_init_fnc (void) 
{

    LINFLEX_1.LINCR1.B.INIT = 1;
        /*Initialization Request: Set */

    LINFLEX_1.LINCR1.B.SLEEP = 0;
        /*Sleep Request: Clear */

    LINFLEX_1.UARTCR.B.UART= 0;
        /* UART Mode: Disabled */
/*----------------------------------------------------------- */
/*        LIN control register 2   (LINFLEX_1_LINCR2)        */
/*----------------------------------------------------------- */

    LINFLEX_1.LINCR2.R = 0x6000;
        /* Idle on Bit Error: Enabled*/
        /* Idle on Identifier Parity Error: Enabled*/


/*----------------------------------------------------------- */
/*        LIN integer baudrate register  (LINFLEX_1_LINIBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_1.LINIBRR.R = 0x0000;
        /* Baudrate : ? Symbols/sec */
        /* Integer Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        LIN fractional baudrate register (LINFLEX_1_LINFBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_1.LINFBRR.R = 0x0000;
        /* Fractional Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*    DMA Tx enable register  (LINFLEX_1_DMATXE)              */
/*----------------------------------------------------------- */
    LINFLEX_1.DMATXE.R = 0x0000;
        /* DMA Transmitter : Disabled  */

/*----------------------------------------------------------- */
/*    DMA Rx enable register  (LINFLEX_1_DMARXE)             */
/*----------------------------------------------------------- */
    LINFLEX_1.DMARXE.R = 0x0000;
        /* DMA Receiver Channel : Disabled  */

/*----------------------------------------------------------- */
/*        UART mode control register  (LINFLEX_1_UARTCR)        */
/*----------------------------------------------------------- */
    LINFLEX_1.UARTCR.R = 0x0000;
        /* UART Mode: Disable*/
        /* Parity transmit/check: Disable*/
        /* Parity Control Option: Even Parity*/
        /* Word Length in UART mode: 7 bit data + parity*/
        /* Tx FIFO/buffer mode: Disabled */
        /* Rx FIFO/buffer mode: Disabled */
        /* Transmitter data field length / Tx FIFO counter (Bytes):1*/
        /* Receiver Data Field Length /Rx FIFO counter  (Bytes): 1*/
        /* Transmitter : Disable*/
        /* Receiver : Disable*/


/*----------------------------------------------------------- */
/*        UART preset timeout register (LINFLEX_1_UARTPTO)        */
/*----------------------------------------------------------- */
    LINFLEX_1.UARTPTO.R = 0x0FFF;
        /* Preset Timeout counter : 4095*/


/*----------------------------------------------------------- */
/*        LIN timeout control status register  (LINFLEX_1_LINTCSR)        */
/*----------------------------------------------------------- */

    LINFLEX_1.LINTCSR.R = 0x0200;
        /* LIN timeout mode: Disabled*/
        /* Idle on Timeout: Enabled*/
        /* Timeout Counter: Disabled*/


/*----------------------------------------------------------- */
/*        LIN output compare register  (LINFLEX_1_LINOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_1.LINOCR.R = 0xFFFF;
        /* Output compare Value 1: 255*/
        /* Output compare Value 2: 255*/

/*----------------------------------------------------------- */
/*        LIN timeout control register  (LINFLEX_1_LINTOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_1.LINTOCR.R = 0x0E2C;
        /* Header Timeout (Bit Time): 44*/
        /* Response Timeout: 14*/

/*----------------------------------------------------------- */
/*        LIN interrupt enable register  (LINFLEX_1_LINIER)        */
/*----------------------------------------------------------- */

    LINFLEX_1.LINIER.R = 0x0000;

        /* Header Received Interrupt: Disabled    */
        /* Data Transmitted Interrupt: Disabled    */
        /* Data Reception Complete Interrupt: Disabled    */
        /* Data Buffer Empty Interrupt: Disabled    */
        /* Data Buffer Full Interrupt: Disabled    */
        /* Wakeup Interrupt: Disabled    */
        /* LIN State Interrupt: Disabled    */
        /* Buffer Overrun Error Interrupt: Disabled    */
        /* Frame Error Interrupt: Disabled    */
        /* Header Error Interrupt: Disabled    */
        /* Checksum Error Interrupt: Disabled    */
        /* Bit Error Interrupt: Disabled    */
        /* Output Compare Interrupt: Disabled    */
        /* Stuck at Zero Interrupt: Disabled    */

/*----------------------------------------------------------- */
/*        LIN control register 1   (LINFLEX_1_LINCR1)        */
/*----------------------------------------------------------- */

    LINFLEX_1.LINCR1.R = 0x0081;
        /* Initialization Request: Set */
        /* Master Mode Enable: Slave*/
        /* Receiver Buffer: Not Locked*/
        /* Loopback Mode: Disabled*/
        /* Self Test Mode: Disabled*/
        /* LIN Master Break Length: 10 bits*/
        /* Slave Mode Break Detection Threshold: 11 bits*/
        /* Bypass Filter: Enabled*/
        /* Automatic Wake-Up Mode: Disabled*/
        /* Checksum field: Enabled*/
        /* Checksum Calculation: Disabled*/
        /* LIN Slave Automatic Resynchronization: Disabled*/



    LINFLEX_1.LINCR1.B.INIT = 0;
        /*Initialization Request: Clear */

}

void linflex2_init_fnc (void) 
{

    LINFLEX_2.LINCR1.B.INIT = 1;
        /*Initialization Request: Set */

    LINFLEX_2.LINCR1.B.SLEEP = 0;
        /*Sleep Request: Clear */

    LINFLEX_2.UARTCR.B.UART= 0;
        /* UART Mode: Disabled */
/*----------------------------------------------------------- */
/*        LIN control register 2   (LINFLEX_2_LINCR2)        */
/*----------------------------------------------------------- */

    LINFLEX_2.LINCR2.R = 0x6000;
        /* Idle on Bit Error: Enabled*/
        /* Idle on Identifier Parity Error: Enabled*/


/*----------------------------------------------------------- */
/*        LIN integer baudrate register  (LINFLEX_2_LINIBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_2.LINIBRR.R = 0x0000;
        /* Baudrate : ? Symbols/sec */
        /* Integer Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        LIN fractional baudrate register (LINFLEX_2_LINFBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_2.LINFBRR.R = 0x0000;
        /* Fractional Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        UART mode control register  (LINFLEX_2_UARTCR)        */
/*----------------------------------------------------------- */
    LINFLEX_2.UARTCR.R = 0x0000;
        /* UART Mode: Disable*/
        /* Parity transmit/check: Disable*/
        /* Parity Control Option: Even Parity*/
        /* Word Length in UART mode: 7 bit data + parity*/
        /* Tx FIFO/buffer mode: Disabled */
        /* Rx FIFO/buffer mode: Disabled */
        /* Transmitter data field length / Tx FIFO counter (Bytes):1*/
        /* Receiver Data Field Length /Rx FIFO counter  (Bytes): 1*/
        /* Transmitter : Disable*/
        /* Receiver : Disable*/


/*----------------------------------------------------------- */
/*        UART preset timeout register (LINFLEX_2_UARTPTO)        */
/*----------------------------------------------------------- */
    LINFLEX_2.UARTPTO.R = 0x0FFF;
        /* Preset Timeout counter : 4095*/


/*----------------------------------------------------------- */
/*        LIN timeout control status register  (LINFLEX_2_LINTCSR)        */
/*----------------------------------------------------------- */

    LINFLEX_2.LINTCSR.R = 0x0200;
        /* LIN timeout mode: Disabled*/
        /* Idle on Timeout: Enabled*/
        /* Timeout Counter: Disabled*/


/*----------------------------------------------------------- */
/*        LIN output compare register  (LINFLEX_2_LINOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_2.LINOCR.R = 0xFFFF;
        /* Output compare Value 1: 255*/
        /* Output compare Value 2: 255*/

/*----------------------------------------------------------- */
/*        LIN timeout control register  (LINFLEX_2_LINTOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_2.LINTOCR.R = 0x0E2C;
        /* Header Timeout (Bit Time): 44*/
        /* Response Timeout: 14*/

/*----------------------------------------------------------- */
/*        LIN interrupt enable register  (LINFLEX_2_LINIER)        */
/*----------------------------------------------------------- */

    LINFLEX_2.LINIER.R = 0x0000;

        /* Header Received Interrupt: Disabled    */
        /* Data Transmitted Interrupt: Disabled    */
        /* Data Reception Complete Interrupt: Disabled    */
        /* Data Buffer Empty Interrupt: Disabled    */
        /* Data Buffer Full Interrupt: Disabled    */
        /* Wakeup Interrupt: Disabled    */
        /* LIN State Interrupt: Disabled    */
        /* Buffer Overrun Error Interrupt: Disabled    */
        /* Frame Error Interrupt: Disabled    */
        /* Header Error Interrupt: Disabled    */
        /* Checksum Error Interrupt: Disabled    */
        /* Bit Error Interrupt: Disabled    */
        /* Output Compare Interrupt: Disabled    */
        /* Stuck at Zero Interrupt: Disabled    */

/*----------------------------------------------------------- */
/*        LIN control register 1   (LINFLEX_2_LINCR1)        */
/*----------------------------------------------------------- */

    LINFLEX_2.LINCR1.R = 0x0081;
        /* Initialization Request: Set */
        /* Master Mode Enable: Slave*/
        /* Receiver Buffer: Not Locked*/
        /* Loopback Mode: Disabled*/
        /* Self Test Mode: Disabled*/
        /* LIN Master Break Length: 10 bits*/
        /* Slave Mode Break Detection Threshold: 11 bits*/
        /* Bypass Filter: Enabled*/
        /* Automatic Wake-Up Mode: Disabled*/
        /* Checksum field: Enabled*/
        /* Checksum Calculation: Disabled*/
        /* LIN Slave Automatic Resynchronization: Disabled*/



    LINFLEX_2.LINCR1.B.INIT = 0;
        /*Initialization Request: Clear */

}

void linflex3_init_fnc (void) 
{

    LINFLEX_3.LINCR1.B.INIT = 1;
        /*Initialization Request: Set */

    LINFLEX_3.LINCR1.B.SLEEP = 0;
        /*Sleep Request: Clear */

    LINFLEX_3.UARTCR.B.UART= 0;
        /* UART Mode: Disabled */
/*----------------------------------------------------------- */
/*        LIN control register 2   (LINFLEX_3_LINCR2)        */
/*----------------------------------------------------------- */

    LINFLEX_3.LINCR2.R = 0x6000;
        /* Idle on Bit Error: Enabled*/
        /* Idle on Identifier Parity Error: Enabled*/


/*----------------------------------------------------------- */
/*        LIN integer baudrate register  (LINFLEX_3_LINIBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_3.LINIBRR.R = 0x0000;
        /* Baudrate : ? Symbols/sec */
        /* Integer Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        LIN fractional baudrate register (LINFLEX_3_LINFBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_3.LINFBRR.R = 0x0000;
        /* Fractional Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        UART mode control register  (LINFLEX_3_UARTCR)        */
/*----------------------------------------------------------- */
    LINFLEX_3.UARTCR.R = 0x0000;
        /* UART Mode: Disable*/
        /* Parity transmit/check: Disable*/
        /* Parity Control Option: Even Parity*/
        /* Word Length in UART mode: 7 bit data + parity*/
        /* Tx FIFO/buffer mode: Disabled */
        /* Rx FIFO/buffer mode: Disabled */
        /* Transmitter data field length / Tx FIFO counter (Bytes):1*/
        /* Receiver Data Field Length /Rx FIFO counter  (Bytes): 1*/
        /* Transmitter : Disable*/
        /* Receiver : Disable*/


/*----------------------------------------------------------- */
/*        UART preset timeout register (LINFLEX_3_UARTPTO)        */
/*----------------------------------------------------------- */
    LINFLEX_3.UARTPTO.R = 0x0FFF;
        /* Preset Timeout counter : 4095*/


/*----------------------------------------------------------- */
/*        LIN timeout control status register  (LINFLEX_3_LINTCSR)        */
/*----------------------------------------------------------- */

    LINFLEX_3.LINTCSR.R = 0x0200;
        /* LIN timeout mode: Disabled*/
        /* Idle on Timeout: Enabled*/
        /* Timeout Counter: Disabled*/


/*----------------------------------------------------------- */
/*        LIN output compare register  (LINFLEX_3_LINOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_3.LINOCR.R = 0xFFFF;
        /* Output compare Value 1: 255*/
        /* Output compare Value 2: 255*/

/*----------------------------------------------------------- */
/*        LIN timeout control register  (LINFLEX_3_LINTOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_3.LINTOCR.R = 0x0E2C;
        /* Header Timeout (Bit Time): 44*/
        /* Response Timeout: 14*/

/*----------------------------------------------------------- */
/*        LIN interrupt enable register  (LINFLEX_3_LINIER)        */
/*----------------------------------------------------------- */

    LINFLEX_3.LINIER.R = 0x0000;

        /* Header Received Interrupt: Disabled    */
        /* Data Transmitted Interrupt: Disabled    */
        /* Data Reception Complete Interrupt: Disabled    */
        /* Data Buffer Empty Interrupt: Disabled    */
        /* Data Buffer Full Interrupt: Disabled    */
        /* Wakeup Interrupt: Disabled    */
        /* LIN State Interrupt: Disabled    */
        /* Buffer Overrun Error Interrupt: Disabled    */
        /* Frame Error Interrupt: Disabled    */
        /* Header Error Interrupt: Disabled    */
        /* Checksum Error Interrupt: Disabled    */
        /* Bit Error Interrupt: Disabled    */
        /* Output Compare Interrupt: Disabled    */
        /* Stuck at Zero Interrupt: Disabled    */

/*----------------------------------------------------------- */
/*        LIN control register 1   (LINFLEX_3_LINCR1)        */
/*----------------------------------------------------------- */

    LINFLEX_3.LINCR1.R = 0x0081;
        /* Initialization Request: Set */
        /* Master Mode Enable: Slave*/
        /* Receiver Buffer: Not Locked*/
        /* Loopback Mode: Disabled*/
        /* Self Test Mode: Disabled*/
        /* LIN Master Break Length: 10 bits*/
        /* Slave Mode Break Detection Threshold: 11 bits*/
        /* Bypass Filter: Enabled*/
        /* Automatic Wake-Up Mode: Disabled*/
        /* Checksum field: Enabled*/
        /* Checksum Calculation: Disabled*/
        /* LIN Slave Automatic Resynchronization: Disabled*/



    LINFLEX_3.LINCR1.B.INIT = 0;
        /*Initialization Request: Clear */

}

void linflex4_init_fnc (void) 
{

    LINFLEX_4.LINCR1.B.INIT = 1;
        /*Initialization Request: Set */

    LINFLEX_4.LINCR1.B.SLEEP = 0;
        /*Sleep Request: Clear */

    LINFLEX_4.UARTCR.B.UART= 0;
        /* UART Mode: Disabled */
/*----------------------------------------------------------- */
/*        LIN control register 2   (LINFLEX_4_LINCR2)        */
/*----------------------------------------------------------- */

    LINFLEX_4.LINCR2.R = 0x6000;
        /* Idle on Bit Error: Enabled*/
        /* Idle on Identifier Parity Error: Enabled*/


/*----------------------------------------------------------- */
/*        LIN integer baudrate register  (LINFLEX_4_LINIBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_4.LINIBRR.R = 0x0000;
        /* Baudrate : ? Symbols/sec */
        /* Integer Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        LIN fractional baudrate register (LINFLEX_4_LINFBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_4.LINFBRR.R = 0x0000;
        /* Fractional Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        UART mode control register  (LINFLEX_4_UARTCR)        */
/*----------------------------------------------------------- */
    LINFLEX_4.UARTCR.R = 0x0000;
        /* UART Mode: Disable*/
        /* Parity transmit/check: Disable*/
        /* Parity Control Option: Even Parity*/
        /* Word Length in UART mode: 7 bit data + parity*/
        /* Tx FIFO/buffer mode: Disabled */
        /* Rx FIFO/buffer mode: Disabled */
        /* Transmitter data field length / Tx FIFO counter (Bytes):1*/
        /* Receiver Data Field Length /Rx FIFO counter  (Bytes): 1*/
        /* Transmitter : Disable*/
        /* Receiver : Disable*/


/*----------------------------------------------------------- */
/*        UART preset timeout register (LINFLEX_4_UARTPTO)        */
/*----------------------------------------------------------- */
    LINFLEX_4.UARTPTO.R = 0x0FFF;
        /* Preset Timeout counter : 4095*/


/*----------------------------------------------------------- */
/*        LIN timeout control status register  (LINFLEX_4_LINTCSR)        */
/*----------------------------------------------------------- */

    LINFLEX_4.LINTCSR.R = 0x0200;
        /* LIN timeout mode: Disabled*/
        /* Idle on Timeout: Enabled*/
        /* Timeout Counter: Disabled*/


/*----------------------------------------------------------- */
/*        LIN output compare register  (LINFLEX_4_LINOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_4.LINOCR.R = 0xFFFF;
        /* Output compare Value 1: 255*/
        /* Output compare Value 2: 255*/

/*----------------------------------------------------------- */
/*        LIN timeout control register  (LINFLEX_4_LINTOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_4.LINTOCR.R = 0x0E2C;
        /* Header Timeout (Bit Time): 44*/
        /* Response Timeout: 14*/

/*----------------------------------------------------------- */
/*        LIN interrupt enable register  (LINFLEX_4_LINIER)        */
/*----------------------------------------------------------- */

    LINFLEX_4.LINIER.R = 0x0000;

        /* Header Received Interrupt: Disabled    */
        /* Data Transmitted Interrupt: Disabled    */
        /* Data Reception Complete Interrupt: Disabled    */
        /* Data Buffer Empty Interrupt: Disabled    */
        /* Data Buffer Full Interrupt: Disabled    */
        /* Wakeup Interrupt: Disabled    */
        /* LIN State Interrupt: Disabled    */
        /* Buffer Overrun Error Interrupt: Disabled    */
        /* Frame Error Interrupt: Disabled    */
        /* Header Error Interrupt: Disabled    */
        /* Checksum Error Interrupt: Disabled    */
        /* Bit Error Interrupt: Disabled    */
        /* Output Compare Interrupt: Disabled    */
        /* Stuck at Zero Interrupt: Disabled    */

/*----------------------------------------------------------- */
/*        LIN control register 1   (LINFLEX_4_LINCR1)        */
/*----------------------------------------------------------- */

    LINFLEX_4.LINCR1.R = 0x0081;
        /* Initialization Request: Set */
        /* Master Mode Enable: Slave*/
        /* Receiver Buffer: Not Locked*/
        /* Loopback Mode: Disabled*/
        /* Self Test Mode: Disabled*/
        /* LIN Master Break Length: 10 bits*/
        /* Slave Mode Break Detection Threshold: 11 bits*/
        /* Bypass Filter: Enabled*/
        /* Automatic Wake-Up Mode: Disabled*/
        /* Checksum field: Enabled*/
        /* Checksum Calculation: Disabled*/
        /* LIN Slave Automatic Resynchronization: Disabled*/



    LINFLEX_4.LINCR1.B.INIT = 0;
        /*Initialization Request: Clear */

}

void linflex5_init_fnc (void) 
{

    LINFLEX_5.LINCR1.B.INIT = 1;
        /*Initialization Request: Set */

    LINFLEX_5.LINCR1.B.SLEEP = 0;
        /*Sleep Request: Clear */

    LINFLEX_5.UARTCR.B.UART= 0;
        /* UART Mode: Disabled */
/*----------------------------------------------------------- */
/*        LIN control register 2   (LINFLEX_5_LINCR2)        */
/*----------------------------------------------------------- */

    LINFLEX_5.LINCR2.R = 0x6000;
        /* Idle on Bit Error: Enabled*/
        /* Idle on Identifier Parity Error: Enabled*/


/*----------------------------------------------------------- */
/*        LIN integer baudrate register  (LINFLEX_5_LINIBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_5.LINIBRR.R = 0x0000;
        /* Baudrate : ? Symbols/sec */
        /* Integer Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        LIN fractional baudrate register (LINFLEX_5_LINFBRR)        */
/*----------------------------------------------------------- */
    LINFLEX_5.LINFBRR.R = 0x0000;
        /* Fractional Baud Rate Factor: 0*/

/*----------------------------------------------------------- */
/*        UART mode control register  (LINFLEX_5_UARTCR)        */
/*----------------------------------------------------------- */
    LINFLEX_5.UARTCR.R = 0x0000;
        /* UART Mode: Disable*/
        /* Parity transmit/check: Disable*/
        /* Parity Control Option: Even Parity*/
        /* Word Length in UART mode: 7 bit data + parity*/
        /* Tx FIFO/buffer mode: Disabled */
        /* Rx FIFO/buffer mode: Disabled */
        /* Transmitter data field length / Tx FIFO counter (Bytes):1*/
        /* Receiver Data Field Length /Rx FIFO counter  (Bytes): 1*/
        /* Transmitter : Disable*/
        /* Receiver : Disable*/


/*----------------------------------------------------------- */
/*        UART preset timeout register (LINFLEX_5_UARTPTO)        */
/*----------------------------------------------------------- */
    LINFLEX_5.UARTPTO.R = 0x0FFF;
        /* Preset Timeout counter : 4095*/


/*----------------------------------------------------------- */
/*        LIN timeout control status register  (LINFLEX_5_LINTCSR)        */
/*----------------------------------------------------------- */

    LINFLEX_5.LINTCSR.R = 0x0200;
        /* LIN timeout mode: Disabled*/
        /* Idle on Timeout: Enabled*/
        /* Timeout Counter: Disabled*/


/*----------------------------------------------------------- */
/*        LIN output compare register  (LINFLEX_5_LINOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_5.LINOCR.R = 0xFFFF;
        /* Output compare Value 1: 255*/
        /* Output compare Value 2: 255*/

/*----------------------------------------------------------- */
/*        LIN timeout control register  (LINFLEX_5_LINTOCR)        */
/*----------------------------------------------------------- */

    LINFLEX_5.LINTOCR.R = 0x0E2C;
        /* Header Timeout (Bit Time): 44*/
        /* Response Timeout: 14*/

/*----------------------------------------------------------- */
/*        LIN interrupt enable register  (LINFLEX_5_LINIER)        */
/*----------------------------------------------------------- */

    LINFLEX_5.LINIER.R = 0x0000;

        /* Header Received Interrupt: Disabled    */
        /* Data Transmitted Interrupt: Disabled    */
        /* Data Reception Complete Interrupt: Disabled    */
        /* Data Buffer Empty Interrupt: Disabled    */
        /* Data Buffer Full Interrupt: Disabled    */
        /* Wakeup Interrupt: Disabled    */
        /* LIN State Interrupt: Disabled    */
        /* Buffer Overrun Error Interrupt: Disabled    */
        /* Frame Error Interrupt: Disabled    */
        /* Header Error Interrupt: Disabled    */
        /* Checksum Error Interrupt: Disabled    */
        /* Bit Error Interrupt: Disabled    */
        /* Output Compare Interrupt: Disabled    */
        /* Stuck at Zero Interrupt: Disabled    */

/*----------------------------------------------------------- */
/*        LIN control register 1   (LINFLEX_5_LINCR1)        */
/*----------------------------------------------------------- */

    LINFLEX_5.LINCR1.R = 0x0081;
        /* Initialization Request: Set */
        /* Master Mode Enable: Slave*/
        /* Receiver Buffer: Not Locked*/
        /* Loopback Mode: Disabled*/
        /* Self Test Mode: Disabled*/
        /* LIN Master Break Length: 10 bits*/
        /* Slave Mode Break Detection Threshold: 11 bits*/
        /* Bypass Filter: Enabled*/
        /* Automatic Wake-Up Mode: Disabled*/
        /* Checksum field: Enabled*/
        /* Checksum Calculation: Disabled*/
        /* LIN Slave Automatic Resynchronization: Disabled*/



    LINFLEX_5.LINCR1.B.INIT = 0;
        /*Initialization Request: Clear */

}


 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

