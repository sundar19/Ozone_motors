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
 * file                   : flexcan_init.h
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
 * Brief Description      : This File contains functions declaration of FlexCAN
 *                          code file
 *
 *
 *######################################################################
*/

#ifndef  _FLEXCAN_INIT_H
#define  _FLEXCAN_INIT_H
/********************  Dependent Include files here **********************/

#include "jdp.h"


/*********************  Receive FIFO Macro here ****************************/

/**********************  Function Prototype here *************************/

uint8_t flexcan_init_fnc(void);
uint8_t flexcan_0_init_fnc(void);
uint8_t flexcan_1_init_fnc(void);
uint8_t flexcan_2_init_fnc(void);
uint8_t flexcan_3_init_fnc(void);
uint8_t flexcan_4_init_fnc(void);
uint8_t flexcan_5_init_fnc(void);


#endif  /*_FLEXCAN_INIT_H*/

/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

