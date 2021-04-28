/*
 *######################################################################
 *                                RAppIDJDP
 *           Rapid Application Initialization and Documentation Tool
 *                         Freescale Semiconductor Inc.
 *
 *######################################################################
 *
 * Project Name           : 3_can
 *
 * Project File           : 3_can.rsp
 *
 * Revision Number        : 1.0
 *
 * Tool Version           : 1.2.1.5
 *
 * file                   : rtc_init.c
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5606B
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 13-Apr-2021 09:00:26
 *
 * Created on Date        : 13-Apr-2021 09:00:27
 *
 * Brief Description      : RTC/API Initialization file
 *
 ******************************************************************************** 
 *
 * Detail Description     : File contains Real Time Clock (RTC) & Automatic
 *                         Periodic Interrupt (API ) initialization function.
 *                         The function configures parameters such RTC/API
 *                         Module status, RTC/API Interrupt status, RTC/API
 *                         compare values and RTC Clock source.
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 
/********************  Dependent Include files here **********************/

#include "rtc_init.h"




/********************* Initialization Function(s) *********************** */


void rtc_init_fnc(void)
{
    RTC.RTCC.B.CNTEN = 0;    
        /* Disable Real Timer Counter Module for initialization        */

    RTC.RTCC.R = 0x00000000;    
        /* RTC Interrupt: Disabled        */
        /* Counter Rollover Interrupt : Disabled        */
        /* RTC Compare Value is 0        */
        /* Autonomous Periodic Interrupt: Disabled        */
        /* API Interrupt Request to the System : Disabled        */
        /* RTC's Clock is selected to 32 KHz OSC Divided        */
        /* RTC's Clock divide by 512: Disabled        */
        /* RTC's Clock divide by 32: Disabled        */
        /* API Compare Value is 0        */

    RTC.RTCC.B.CNTEN = 0;    
        /* Real Timer Counter Module : Disabled        */

}

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

