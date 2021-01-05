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
 * file                   : adc_init.h
 *
 * Target Compiler        : Codewarrior
 *
 * Target Part            : MPC5606B
 *
 * Part Errata Fixes      : none
 *
 * Project Last Save Date : 04-Jan-2021 06:16:55
 *
 * Created on Date        : 04-Jan-2021 06:16:55
 *
 * Brief Description      : This file contains function declaration for ADC code File.
 *
 *
 *######################################################################
*/

#ifndef  _ADC_INIT_H
#define  _ADC_INIT_H
/********************  Dependent Include files here **********************/

#include "jdp.h"

/**********************  Function Prototype here *************************/

void adc_init_fnc(void);
void adc_0_init_fnc(void);
void adc_1_init_fnc(void);
void adc_0_channel_setup_fnc(void);
void adc_1_channel_setup_fnc(void);
void adc_ctuevent_init_fnc(void);
void adc_0_trigger_setup_fnc(void);
void adc_1_trigger_setup_fnc(void);


#endif  /*_ADC_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

