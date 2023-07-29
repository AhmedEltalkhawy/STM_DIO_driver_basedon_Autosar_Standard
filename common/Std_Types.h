/*
 * Std_Types.h

 Created on: Dec 24, 2021
 Author: EL-talkhawy

AUTOSAR Version : 4.3.1
DOC Name : AUTOSAR_SWS_StandardTypes.pdf
Target : STM32F401VE
 */

#ifndef COMMON_STD_TYPES_H_
#define COMMON_STD_TYPES_H_

#include "Platform_Types.h"
#include "Compiler.h"

/*8.2 Symbol definitions*/

/* Because E_OK is already defined within OSEK, the symbol E_OK has to be shared.
To avoid name clashes and redefinition problems, */

#ifndef STATUSTYPEDEFINED
#define STATUSTYPEDEFINED
#define E_OK 0x00u
typedef unsigned char StatusType; /* OSEK compliance */
#endif
#define E_NOT_OK 0x01u

#define STD_ON     0x01u
#define STD_OFF    0x00u

#define STD_ACTIVE 0x01u    /* Logical state active */
#define STD_IDLE   0x00u    /* Logical state idle */

#define STD_HIGH   0x01u    /* Physical state 5V or 3.3V */
#define STD_LOW    0x00u    /* Physical state 0V */

/***********************************************************/
/* can be used as standard API return type which is shared between the RTE and the BSW modules. */
typedef uint8 Std_ReturnType ;

/*type  shall be an enumeration with the following elements where each element represents a transformer class:*/
typedef uint8 Std_TransformerClass ;

#define STD_TRANSFORMER_UNSPECIFIED 0x00 /*shall be used if no transformer error occured. */
#define STD_TRANSFORMER_SERIALIZER  0x01
#define STD_TRANSFORMER_SAFETY      0x02
#define STD_TRANSFORMER_SECURITY    0x03
#define STD_TRANSFORMER_CUSTOM      0xff /*Transformer of a custom class not standardized by AUTOSAR.*/



/* shall be used to request the version of a BSW module using the <Module name>_GetVersionInfo() */
typedef struct
{
	VAR( uint16, AUTOMATIC )    vendorID ;
	VAR( uint16, AUTOMATIC )    moduleID ;
	VAR( uint8, AUTOMATIC  )	sw_major_version ;
	VAR( uint8, AUTOMATIC  )	sw_minor_version ;
	VAR( uint8, AUTOMATIC  )	sw_patch_version ;

} Std_VersionInfoType ;

/*is a struct which contains the error code and the transformer class to which the error belongs */

typedef struct
{
	VAR( uint8, AUTOMATIC  )  errorCode ;
	Std_TransformerClass transformerClass ;

} Std_TransformerError;

/* contains the forwarded status and the transformer class to which the forwarded status applies */

typedef struct
{
	VAR( uint8, AUTOMATIC  )  errorCode ;
	Std_TransformerClass transformerClass ;

} Std_TransformerForward;





#endif /* COMMON_STD_TYPES_H_ */
