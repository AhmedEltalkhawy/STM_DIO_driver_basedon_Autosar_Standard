/*
 * Dio.c
 *
 *  Created on: Feb 1, 2022
 *      Author: EL-talkhawy
 */
#include "../src/common/Utils.h"
#include "Dio.h"
#include "Dio_MemMap.h"


/*Synchronous ,Reentrant Service ID 0x00*
If development error detection is enabled, the services Dio_ReadChannel, Dio_WriteChannel
and Dio_FlipChannel shall check the “ChannelId” parameter to be valid within the current configuration
If the “ChannelId” parameter is invalid,  * the functions shall report the error code
DIO_E_PARAM_INVALID_CHANNEL_ID to the DET */

FUNC( Dio_LevelType, DIO_CODE) Dio_ReadChannel ( Dio_ChannelType ChannelId )
{

	VAR(Dio_ChannelType , AUTOMATIC)  pnum = ChannelId % 16 ;
	VAR(Dio_PortType , AUTOMATIC)     port = ChannelId / 16 ;
    VAR(Dio_LevelType ,AUTOMATIC)     volt = STD_LOW ;
	switch(port)
	{
	 case PORT_A :
	   volt = READ_BIT(GPIOA_IDR , pnum) ;
	   break ;
	 case PORT_B :
	   volt = READ_BIT(GPIOB_IDR , pnum) ;
	   break ;
	 case PORT_C :
	   volt = READ_BIT(GPIOC_IDR , pnum) ;
	   break ;
	 case PORT_D :
	   volt = READ_BIT(GPIOD_IDR , pnum) ;
	   break ;
	 case PORT_E :
	   volt = READ_BIT(GPIOE_IDR , pnum) ;
	   break ;
	 case PORT_H :
	   volt = READ_BIT(GPIOH_IDR , pnum) ;
	   break ;
	}

	return volt ;
}

/*Synchronous ,Reentrant Service ID 0x01
.f the specified channel is configured as an input channel,function shall have no influence on the physical output*/

FUNC( void, DIO_CODE) Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )
{

	VAR(Dio_ChannelType , AUTOMATIC) pnum  = ChannelId % 16 ;
	VAR(Dio_PortType , AUTOMATIC)    port  = ChannelId %16 ;
	if((Level = STD_HIGH))
	{
		switch (port)
		{
		 case PORT_A :
		   SET_BIT(GPIOA_ODR ,pnum) ;
		   break ;
		 case PORT_B :
		   SET_BIT(GPIOB_ODR ,pnum) ;
		   break ;
		 case PORT_C :
		   SET_BIT(GPIOC_ODR ,pnum) ;
		   break ;
		 case PORT_D :
		   SET_BIT(GPIOD_ODR ,pnum)  ;
		   break ;
		 case PORT_E :
		   SET_BIT(GPIOE_ODR ,pnum) ;
		   break ;
		 case PORT_H :
		   SET_BIT(GPIOH_ODR ,pnum) ;
		   break ;
		}


		}
	else if((Level = STD_LOW))
	{

		switch (port)
		{
		case PORT_A :
		  CLEAR_BIT(GPIOA_ODR ,pnum) ;
		  break ;
		case PORT_B :
		  CLEAR_BIT(GPIOB_ODR ,pnum) ;
		  break ;
	    case PORT_C :
		  CLEAR_BIT(GPIOC_ODR ,pnum) ;
		  break ;
		case PORT_D :
		  CLEAR_BIT(GPIOD_ODR ,pnum)  ;
		  break ;
		case PORT_E :
		  CLEAR_BIT(GPIOE_ODR ,pnum) ;
		  break ;
	    case PORT_H :
		  CLEAR_BIT(GPIOH_ODR ,pnum) ;
		  break ;
		}


	}

}


/*Synchronous ,Reentrant Service ID 0x02
.When reading a port which is smaller than the Dio_PortLevelType
the function shall set the bits corresponding to undefined port pins to 0
If development error detection is enabled, the functions Dio_ReadPort, Dio_WritePort and Dio_MaskedWritePort
 shall check the “PortId” parameter to be valid within the current configuration.
 If the “PortId” parameter is invalid, the functions shall report the error code DIO_E_PARAM_INVALID_PORT_ID
 to the DET..*/

FUNC( Dio_PortLevelType, DIO_CODE) Dio_ReadPort ( Dio_PortType PortId )
{
	VAR(Dio_PortLevelType , AUTOMATIC ) portlevel = 0 ;
	switch(PortId)
	{
	case PORT_A :
		portlevel = GPIOA_IDR  ;
		break ;
	case PORT_B :
	    portlevel = GPIOB_IDR  ;
		break ;
	case PORT_C :
	    portlevel = GPIOC_IDR  ;
		break ;
	case PORT_D :
		portlevel = GPIOD_IDR  ;
		break ;
	case PORT_E :
		portlevel = GPIOE_IDR  ;
		break ;
	case PORT_H :
	    portlevel = GPIOH_IDR  ;
		break ;

	}

	return portlevel ;

}

/*Synchronous ,Reentrant Service ID 0x03
 DIO Channels that are configured as input shall remain unchanged.
 .When writing a port which is smaller than the Dio_PortLevelType the function shall ignore the MSB. */

FUNC( void, DIO_CODE) Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level )
{
	switch(PortId)
    {
	case PORT_A :
	  GPIOA_ODR= Level ;
	  break ;
    case PORT_B :
	  GPIOB_ODR= Level  ;
	  break ;
	case PORT_C :
	  GPIOC_ODR = Level  ;
	  break ;
    case PORT_D :
	  GPIOD_ODR = Level  ;
	  break ;
	case PORT_E :
	  GPIOE_ODR = Level  ;
	  break ;
	case PORT_H :
	  GPIOH_ODR = Level  ;
	  break ;
	}
}


/*Synchronous ,Reentrant Service ID 0x04
 * shall do the masking of the channel group , shall do the shifting so that the values read by the function
 * are aligned to the LSB. If development error detection is enabled, shall check the“ChannelGroupIdPtr”
 * parameter to be valid within the current configuration.
 * the functions shall report the error code DIO_E_PARAM_INVALID_GROUP to the DET*/

FUNC( Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{


}

/* Synchronous , Reentrant Service ID 0x05
 * shall not change the remaining channels of the port and channels which are configured as input
 * function shall do the masking of the channel group.shall do the shifting so that the values written by the function
 *  are aligned to the LSB.  */
FUNC( void, DIO_CODE) Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{

}

/* Synchronous , Reentrant Service ID 0x12
 VersionInfo Pointer to where to store the version information of this module.
 Service to get the version information of this module.
 If DET is enabled for the DIO Driver module, the function Dio_GetVersionInfo shall raise DIO_E_PARAM_POINTER,
 if the argument is NULL pointer and return without any action  */

/*FUNC( void, DIO_CODE) Dio_GetVersionInfo ( Std_VersionInfoType* VersionInfo )
{
	VersionInfo->moduleID         = DIO_MODULE_ID ;
	VersionInfo->sw_major_version = DIO_SW_MAJOR_VERSION ;
	VersionInfo->sw_minor_version = DIO_SW_MINOR_VERSION ;
    VersionInfo->sw_patch_version = DIO_SW_PATCH_VERSION ;
}*/

/*Synchronous , Reentrant Service ID 0x11 , Return value STD_HIGH , STD_LOW , Service to flip
(change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
If the specified channel is configured as an input channel , have no influence */

FUNC( Dio_LevelType, DIO_CODE) Dio_FlipChannel ( Dio_ChannelType ChannelId )
{
	VAR(Dio_ChannelType , AUTOMATIC) pnum = ChannelId % 16 ;
	VAR(Dio_PortType , AUTOMATIC)    port = ChannelId / 16 ;
	VAR(Dio_LevelType , AUTOMATIC)   volt = STD_LOW ;
	switch(port)
	{
	case PORT_A :
	  TOGGLE_BIT(GPIOA_ODR , pnum) ;
	  volt = READ_BIT(GPIOA_IDR , pnum) ;
	  break ;
	case PORT_B :
	  TOGGLE_BIT(GPIOB_ODR  , pnum) ;
	  volt = READ_BIT(GPIOB_IDR , pnum) ;
	  break ;
	case PORT_C :
	  TOGGLE_BIT(GPIOC_ODR  , pnum) ;
	  volt = READ_BIT(GPIOC_IDR , pnum) ;
	  break ;
	case PORT_D :
	  TOGGLE_BIT(GPIOD_ODR  , pnum) ;
	  volt = READ_BIT(GPIOD_IDR , pnum) ;
	  break ;
	case PORT_E :
	  TOGGLE_BIT(GPIOE_ODR , pnum) ;
	  volt = READ_BIT(GPIOE_IDR , pnum) ;
	  break  ;
	case PORT_H :
	  TOGGLE_BIT(GPIOH_ODR  , pnum) ;
	  volt = READ_BIT(GPIOH_IDR , pnum) ;
	  break  ;
	}

	return volt ;

}


/*Synchronous , Reentrant Service ID 0x13  , Level Value to be written , Mask Channels  masked in the port
 shall set the specified value for the channels in the specified port if the corresponding bit in Mask is '1'.
 DIO Channels that are configured as input shall remain unchanged.
 When writing a port which is smaller than the Dio_PortLevelType using the Dio_MaskedWritePort function
 the function shall ignore the MSB.*/

FUNC(void, DIO_CODE) Dio_MaskedWritePort (Dio_PortType PortId,Dio_PortLevelType Level,Dio_PortLevelType Mask )
{
	;
}
