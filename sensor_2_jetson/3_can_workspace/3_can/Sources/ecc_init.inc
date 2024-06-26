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
 * file                   : ecc_init.inc
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
 * Brief Description      : This File contain SRAM initialization and Configuration for ECC
 *
 ******************************************************************************** 
 *
 * Detail Description     : This File contains the code for SRAM initialization
 *                         based on GPR/user defined values.It configures ECC
 *                         Configuration Register which is a control register
 *                         for specifying which types of memory errors are reported
 *
 ******************************************************************************** 
 *
 *######################################################################
*/

 
 


#  ----------------------------------------------------------- 
#  ECSM_ECR Register (Set to value 00000000)                  
#----------------------------------------------------------- 
    e_lis   r11, 0x4000
    e_or2i  r11, 0
#              base address of the L2SRAM, 64-bit word aligned
    e_li    r12, 640
    mtctr r12
#              loop counter to get all of L2SRAM;
loop:
    e_stmw  r0, 0(r11)
    e_addi  r11, r11, 128
#             Write all 32 GPRs to L2SRAM; 32 GPRs * 4 bytes = 128
    e_bdnz  loop
#             Loop for 80k of L2SRAM

    e_lis   r11, 0xFFF4
    e_or2i  r11, 0x0043
#             Load ECSM Configuration Reg address
    e_lis   r12, 0x0000
    e_or2i   r12, 0x0000
    e_stb   r12, 0 (r11)
#             ECC RAM non-correction error report disabled
#             ECC FLASH non-correction error report disabled
#             Reporting of single-bit RAM corrections disabled
#             Reporting of single-bit flash corrections disabled

 
/*
 *######################################################################
 *                           End of File
 *######################################################################
*/

