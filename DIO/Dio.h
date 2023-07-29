/*
 * Dio.h

 Created on: Dec 15, 2021
  Author: EL-talkhawy

AUTOSAR Version : 4.3.1Dio_ChannelType
DOC Name : AUTOSAR_SRS_DIODriver.pdf
*/

#ifndef DIO_DIO_H_
#define DIO_DIO_H_

#include "../src/common/Std_Types.h"
#include  "Dio_Cfg.h"




/******************* Type definitions ***********************/

typedef VAR( uint16, TYPEDEF ) Dio_ChannelType  ;    /* contain the numeric ID of a DIO channel.
                                                 .The mapping of the ID is implementation not configurable. */

typedef VAR( uint8, TYPEDEF )  Dio_PortType ;     /* Numeric ID of a DIO port.*/

typedef struct
{

    VAR( uint8, TYPEDEF ) mask ;                  /*defines the positions of the channel group.
                                                  put pins that you need to select it with 1 others with 0*/

    VAR( uint8_least, TYPEDEF ) offset ;        /*the position of the Channel Group on the port,from the LSB.
                                                 used to shift the mask to start from speciified pin */
    Dio_PortType port ;

}Dio_ChannelGroupType ;


typedef VAR( boolean, TYPEDEF ) Dio_LevelType ;  /*STD_LOW 0x00,  STD_HIGH 0x01 */

typedef VAR( uint16, TYPEDEF ) Dio_PortLevelType ;  /* inherits the size of the largest port.
                                                      has a status of pin of specific port */


/******************* Function definitions ************************/

/*Synchronous ,Reentrant Service ID 0x00*
If development error detection is enabled, the services Dio_ReadChannel, Dio_WriteChannel
and Dio_FlipChannel shall check the “ChannelId” parameter to be valid within the current configuration
If the “ChannelId” parameter is invalid,  * the functions shall report the error code
DIO_E_PARAM_INVALID_CHANNEL_ID to the DET */

FUNC( Dio_LevelType, DIO_CODE) Dio_ReadChannel ( Dio_ChannelType ChannelId ) ;

/*Synchronous ,Reentrant Service ID 0x01
.f the specified channel is configured as an input channel,function shall have no influence on the physical output*/

FUNC( void, DIO_CODE) Dio_WriteChannel ( Dio_ChannelType ChannelId, Dio_LevelType Level )  ;

/*Synchronous ,Reentrant Service ID 0x02
.When reading a port which is smaller than the Dio_PortLevelType
the function shall set the bits corresponding to undefined port pins to 0
If development error detection is enabled, the functions Dio_ReadPort, Dio_WritePort and Dio_MaskedWritePort
 shall check the “PortId” parameter to be valid within the current configuration.
 If the “PortId” parameter is invalid, the functions shall report the error code DIO_E_PARAM_INVALID_PORT_ID
 to the DET..*/

FUNC( Dio_PortLevelType, DIO_CODE) Dio_ReadPort ( Dio_PortType PortId ) ;

/*Synchronous ,Reentrant Service ID 0x03
 DIO Channels that are configured as input shall remain unchanged.
 .When writing a port which is smaller than the Dio_PortLevelType the function shall ignore the MSB. */

FUNC( void, DIO_CODE) Dio_WritePort ( Dio_PortType PortId, Dio_PortLevelType Level ) ;

/*Synchronous ,Reentrant Service ID 0x04
 * shall do the masking of the channel group , shall do the shifting so that the values read by the function
 * are aligned to the LSB. If development error detection is enabled, shall check the“ChannelGroupIdPtr”
 * parameter to be valid within the current configuration.
 * the functions shall report the error code DIO_E_PARAM_INVALID_GROUP to the DET*/

FUNC( Dio_PortLevelType, DIO_CODE) Dio_ReadChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr ) ;

/* Synchronous , Reentrant Service ID 0x05
 * shall not change the remaining channels of the port and channels which are configured as input
 * function shall do the masking of the channel group.shall do the shifting so that the values written by the function
 *  are aligned to the LSB.  */
FUNC( void, DIO_CODE) Dio_WriteChannelGroup ( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level ) ;

/* Synchronous , Reentrant Service ID 0x12
 VersionInfo Pointer to where to store the version information of this module.
 Service to get the version information of this module.
 If DET is enabled for the DIO Driver module, the function Dio_GetVersionInfo shall raise DIO_E_PARAM_POINTER,
 if the argument is NULL pointer and return without any action  */

FUNC( void, DIO_CODE) Dio_GetVersionInfo ( Std_VersionInfoType* VersionInfo ) ;

/*Synchronous , Reentrant Service ID 0x11 , Return value STD_HIGH , STD_LOW , Service to flip
(change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
If the specified channel is configured as an input channel , have no influence */

FUNC( Dio_LevelType, DIO_CODE) Dio_FlipChannel ( Dio_ChannelType ChannelId ) ;

/*Synchronous , Reentrant Service ID 0x13  , Level Value to be written , Mask Channels  masked in the port
 shall set the specified value for the channels in the specified port if the corresponding bit in Mask is '1'.
 DIO Channels that are configured as input shall remain unchanged.
 When writing a port which is smaller than the Dio_PortLevelType using the Dio_MaskedWritePort function
 the function shall ignore the MSB.*/

FUNC( void, DIO_CODE) Dio_MaskedWritePort ( Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask ) ;


#endif /* DIO_DIO_H_ */
