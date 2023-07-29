/*
 *
Compiler.h

Created on: Dec 28, 2021
Author: EL-talkhawy

AUTOSAR Version : 4.3.1
DOC Name : AUTOSAR_SWS_CompilerAbstraction.pdf
Target : STM32F401VE

*/

#ifndef COMMON_COMPILER_H_
#define COMMON_COMPILER_H_

#include "../src/DIO/Compiler_Cfg.h"
#include "../src/communcation stack/CanTP/CompilerCfg.h"

#define AUTOMATIC        /* To be used for local non static variables */

#define TYPEDEF   /* This memory class shall be used within type definitions, where no memory qualifier can be
                     specified This can be necessary for defining pointer types, with e.g. P2VAR
                     the second one (memory allocation of the pointer itself) cannot be defined at this
                      time. Hence, memory class TYPEDEF shall be applied */

#define	NULL_PTR	    ((void*) 0x0)
#define	INLINE 		    inline
#define LOCAL_INLINE	static inline /*define for abstraction of the keyword inline in functions with “static” scope.*/
#define LOCAL           static

/* 8.2.2 function definition use it to define functions */

#define FUNC( rettype, memclass )   rettype 	/* for the declaration and definition of functions
                                                   memclass classification of the function itself*/

#define FUNC_P2CONST(rettype, ptrclass, memclass)	const rettype /* declaration and definition of functions returning a pointer to a constant */

#define FUNC_P2VAR(rettype, ptrclass, memclass)		rettype * /* for the declaration and definition of functions returning a pointer to a variable */


/* 8.2.3 Pointer definitions use it to define pointers */

#define P2VAR(ptrtype, memclass, ptrclass)	ptrtype * 		                /* for the declaration and definition of pointers in RAM, pointing to variables */

#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype*				    /* for the declaration and definition of pointers in RAM pointing to constants */

#define CONSTP2VAR(ptrtype, memclass, ptrclass) ptrtype * const 		    /* for the declaration and definition of constant pointers accessing variables */

#define CONSTP2CONST(ptrtype, memclass, ptrclass)	const ptrtype * const	/* for the declaration and definition of constant pointers accessing constants */

#define P2FUNC(rettype, ptrclass, fctname)	rettype (* fctname)			    /* for the type definition of pointers to functions */ /* fctname is pointer to function name*/

#define CONSTP2FUNC(rettype, ptrclass, fctname)	rettype (* const fctname)	/* the type definition of constant pointers to functions */ /* fctname is pointer to function name*/


/* 8.2.4 Constant definitions use it to define Constants */

#define CONST(type, memclass)	const type		/* for the declaration and definition of constants */


/* 8.2.4 Variable definitions use it to define Variables */

#define VAR( type, memclass )  type		/* for the declaration and definition of variables */



#endif /* COMMON_COMPILER_H_ */
