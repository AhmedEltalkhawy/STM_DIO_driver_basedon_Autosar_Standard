/*
 Compiler_Cfg.h
 *
Created on: Dec 31, 2021
Author: EL-talkhawy

AUTOSAR Version : 4.3.1
DOC Name : AUTOSAR_SWS_CompilerAbstraction.pdf

*/

#ifndef DIO_COMPILER_CFG_H_
#define DIO_COMPILER_CFG_H_

/************* 7.1.2 *****************/

/* this is compiler keywords (not C keywords) must by used with function, variables and, pointers to work in prober way */
/* for ARM C (GCC, ADS) compilers no need for those*/

#define   DIO_CODE                /* used for ordinary code */
#define   DIO_CONST               /* To be used for global or static constants.*/
#define   DIO_CONFIG_DATA	      /* To be used for module configuration constants */
#define   DIO_APPL_DATA           /* pointer , To be used for references on application data
                                  (expected to be in RAM or ROM) passed via API */
#define   DIO_APPL_CONST          /*pointer , To be used for references on application constants
                                   ( in ROM, for instance pointer of Init-function) passed via API */
#define   REGSPACE               /*To be used for pointers to registers
                                  (e.g. static volatile CONSTP2VAR(uint16, PWM_CONST, REGSPACE)). */

/**************** To be used for all global or static variables *********************/

#define DIO_VAR_NO_INIT             /* Used for variables that are never cleared and never initialized*/
#define DIO_VAR_CLEARED             /*Used for variables that are cleared to zero after every reset*/
#define DIO_VAR_POWER_ON_CLEARED   /* Used for variables that are cleared to zero only after power on reset.*/
#define DIO_VAR_INIT                /*Used for variables that are initialized with values after every reset.*/
#define DIO_VAR_POWER_ON_INIT       /*Used for variables that are initialized with values only after power on reset.*/


#endif /* DIO_COMPILER_CFG_H_ */
