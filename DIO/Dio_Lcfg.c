/*
 * Dio_Lcfg.c
 *
 *  Created on: Feb 1, 2022
 *      Author: EL-talkhawy
 */

#include "Dio_Lcfg.h"

/* those array is used to link time configuration of channel groups created by user using configuration tool */

CONST(Dio_ChannelGroupType, DIO_CONFIG_DATA )  Dio_ChannelGroupArray  [DIO_CHANNELlGROUP_NUMBERES]  =
{
 {
  .port = PORT_A
  ,
  .mask = 0x0F
  ,
  .offset = 0
 }
 ,
 {
  .port = PORT_B
  ,
  .mask = 0x1E
  ,
  .offset = 1
 }
 ,
 {
  .port = PORT_C
  ,
  .mask = 0x3C
  ,
  .offset = 2
 }
 ,
 {
  .port = PORT_D
  ,
  .mask = 0x78
  ,
  .offset = 3
 }
 ,
 {
  .port = PORT_E
  ,
  .mask = 0x30
  ,
  .offset = 4
 }
 ,
 {
  .port = PORT_H
  ,
  .mask = 0x1F
  ,
  .offset = 0
 }
};



