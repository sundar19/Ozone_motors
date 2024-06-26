/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : 4_can_port
 *
 * Project File           : 4_can_port.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.2.1.5
 *
 * file                   : stm_init.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5606B
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 04-May-2021 07:33:29
 *
 * Created on Date        : 04-May-2021 07:33:30
 *
 * Brief Description      : STM Initialization file
 *
 ******************************************************************************** 
 *
 * Detail Description     : File contains definition for System Timer Module
 *                         (STM) initialization function. The function
 *                         configures STM parameters such as STM module status,
 *                         Counter pre-scalar, Individual Channel status &
 *                         compare value.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "stm_init.h"




/********************* Initialization Function(s) *********************** */


void stm_init_fnc(void)
{

    STM.CR0.B.TEN = 0x0;    
        /* Disable System Timer Module for initialization          */

/* ----------------------------------------------------------- */
/*                     Configure Counter Prescaler                */
/* ----------------------------------------------------------- */

    STM.CR0.B.CPS = 0;    
        /* Counter Prescaler is 1        */

/* ----------------------------------------------------------- */
/*                     Configure System Timer Registers                */
/* ----------------------------------------------------------- */

    STM.CMP0.R =0x00000000;    
        /* System Timer Channel 0's Compare value is :0    */
    
    STM.CCR0.B.CEN =0x0;    
        /* System Timer Channel 0: Disabled    */
    
    STM.CMP1.R =0x00000000;    
        /* System Timer Channel 1's Compare value is :0    */
    
    STM.CCR1.B.CEN =0x0;    
        /* System Timer Channel 1: Disabled    */
    
    STM.CMP2.R =0x00000000;    
        /* System Timer Channel 2's Compare value is :0    */
    
    STM.CCR2.B.CEN =0x0;    
        /* System Timer Channel 2: Disabled    */
    
    STM.CMP3.R =0x00000000;    
        /* System Timer Channel 3's Compare value is :0    */
    
    STM.CCR3.B.CEN =0x0;    
        /* System Timer Channel 3: Disabled    */
    


    STM.CR0.B.TEN = 0;    
        /* System Timer Module is:  Disabled        */

}

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

