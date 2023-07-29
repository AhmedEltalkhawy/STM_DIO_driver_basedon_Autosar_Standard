/*

 Platform_Types.h

 Created on: Dec 28, 2021
 Author: EL-talkhawy

 AUTOSAR Version : 4.3.1
DOC Name : AUTOSAR_SWS_PlatformTypes.pdf
Target : STM32F401VE

 */


#ifndef COMMON_PLATFORM_TYPES_H_
#define COMMON_PLATFORM_TYPES_H_

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

#define CPU_TYPE_8 		8
#define CPU_TYPE_16 	16
#define CPU_TYPE_32 	32
#define CPU_TYPE_64 	64

#define CPU_TYPE			CPU_TYPE_32	        /*the register width of the CPU */

#define MSB_FIRST 		0                       /* In case of Big Endian bit ordering CPU_BIT_ORDER */
#define LSB_FIRST 		1                       /* In case of Little Endian bit ordering CPU_BIT_ORDER */

#define HIGH_BYTE_FIRST 0		                /* In case of Big Endian byte ordering CPU_BYTE_ORDER   */
#define LOW_BYTE_FIRST 	1                       /*In case of Little Endian byte ordering CPU_BYTE_ORDER */

#define CPU_BIT_ORDER		LSB_FIRST			/* bit order on register level */
#define CPU_BYTE_ORDER 		LOW_BYTE_FIRST

typedef void*               VoidPtr ;
typedef const void*         ConstVoidPtr ;

typedef unsigned char 		boolean;

typedef signed char 		sint8;
typedef unsigned char 		uint8;

typedef signed short 		sint16;
typedef unsigned short 		uint16;

typedef signed long 		sint32;
typedef unsigned long 		uint32;

typedef signed long long 	sint64;
typedef unsigned long long 	uint64;

typedef unsigned char 		uint8_least; /* e.g. maximum loop count = 124 ) use uint8_least */
typedef unsigned short 		uint16_least;
typedef unsigned long 		uint32_least;

typedef signed char 		sint8_least;
typedef signed short 		sint16_least;
typedef signed long 		sint32_least;

typedef float 				float32;
typedef double 				float64;


#endif /* COMMON_PLATFORM_TYPES_H_ */
