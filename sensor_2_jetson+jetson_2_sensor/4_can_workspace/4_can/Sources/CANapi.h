/*
 *######################################################################
 *                (c) Copyright 2011 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED. 
 *######################################################################
 *
 * Project Name           : N/A
 *
 * @Revision Number       : 1.0
 * 
 * @File Name             : CANapi.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : N/A
 *
 * Part Errata Fixes      : none
 *
 * Created By             : John H. Floros
 *
 * Created on Date        : 11-Jan-2011 14:57:10
 * 
 * @Brief Description     : Application Interface file for Flex CAN driver
 ***********************************************************************
 *
 *   Revision History
 *
 *   Date          Author           Description
 *   ----------    ------           ------------------------------------
 *   mm-dd-yyyy    X. Z.            File Created
 *
 *######################################################################
*/
/******************************************************************************
* Includes
******************************************************************************/

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/

/******************************************************************************
* Types
******************************************************************************/
typedef struct
{
    uint32_t        id;      /* CAN message ID */
    uint8_t         data[8]; /* CAN data byte */
    uint8_t         length;  /* bytes, length of data */
    uint8_t         code;    /* Message Code */
    uint8_t         ext;	 /* Extended id  1 = yes; 0 = no */
} can_msg_struct;

/******************************************************************************
* Local Functions
******************************************************************************/

/******************************************************************************
* Global variables
******************************************************************************/

/******************************************************************************
* Static variables
******************************************************************************/

/******************************************************************************
* Global functions
******************************************************************************/
void SetCanRxFilter(uint32_t, uint8_t, uint8_t);
void CanTxMsg (uint32_t, uint8_t, uint8_t, uint8_t[], uint8_t);
can_msg_struct CanRxMsg (uint8_t);
uint8_t CanRxMbFull (uint8_t);
uint8_t CanTxMbEmpty (uint8_t);

void SetCanRxFilter0(uint32_t, uint8_t, uint8_t);
void CanTxMsg0 (uint32_t, uint8_t, uint8_t, uint8_t[], uint8_t);
can_msg_struct CanRxMsg0 (uint8_t);
uint8_t CanRxMbFull0 (uint8_t);
uint8_t CanTxMbEmpty0 (uint8_t);

void SetCanRxFilter2(uint32_t, uint8_t, uint8_t);
void CanTxMsg2 (uint32_t, uint8_t, uint8_t, uint8_t[], uint8_t);
can_msg_struct CanRxMsg2 (uint8_t);
uint8_t CanRxMbFull2 (uint8_t);
uint8_t CanTxMbEmpty2 (uint8_t);

void SetCanRxFilter3(uint32_t, uint8_t, uint8_t);
void CanTxMsg3 (uint32_t, uint8_t, uint8_t, uint8_t[], uint8_t);
can_msg_struct CanRxMsg3 (uint8_t);
uint8_t CanRxMbFull3 (uint8_t);
uint8_t CanTxMbEmpty3 (uint8_t);

