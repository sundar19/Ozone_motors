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
 * file                   : adc_trigger_init.h
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
 * Brief Description      : This File contains functions declaration of ADC Trigger code file
 *
 *
 *######################################################################
*/

#ifndef  _ADC_TRIGGER_INIT_H
#define  _ADC_TRIGGER_INIT_H
/********************  Dependent Include files here **********************/

#include "jdp.h"

/**********************  Function Prototype here *************************/

void adc_0_normal_start_fnc(void);
void adc_1_normal_start_fnc(void);
void adc_0_injected_start_fnc(void);
void adc_1_injected_start_fnc(void);
void adc_0_normal_stop_fnc(void);
void adc_1_normal_stop_fnc(void);
void adc_0_chain_stop_fnc(void);
void adc_1_chain_stop_fnc(void);
void adc_0_enter_powerdown_mode(void);
void adc_1_enter_powerdown_mode(void);
void adc_0_exit_powerdown_mode(void);
void adc_1_exit_powerdown_mode(void);


#endif  /*_ADC_TRIGGER_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

