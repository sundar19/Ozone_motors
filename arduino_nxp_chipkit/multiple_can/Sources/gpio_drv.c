/*
 *########################################################################
 *                (c) Copyright 2013 Freescale Semiconductor, Inc.
 *                         ALL RIGHTS RESERVED. 
 *########################################################################
 * 
 * Brief Description     : GPIO driver file
 *
 **************************************************************************
*/
/******************************************************************************
* Includes
******************************************************************************/
#include "gpio_drv.h"

/******************************************************************************
* Constants
******************************************************************************/

/******************************************************************************
* Macros 
******************************************************************************/

/******************************************************************************
* Types
******************************************************************************/

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

/******************************************************************************
*   Function: GPIO_GetState
*
*   Description: Get state for an GPIO pin
*
******************************************************************************/
uint8_t GPIO_GetState (uint16_t ch)
{
    uint8_t result;

    result = (uint8_t)SIU.GPDI[ch].B.PDI;

    return(result);
}

/******************************************************************************
*   Function: GPIO_SetState
*
*   Description: Set state for an GPIO pin
*
******************************************************************************/
void GPIO_SetState (uint16_t ch, uint8_t value)
{
    SIU.GPDO[ch].B.PDO = value;
}

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/