/**********************************************************************
* Header file for reciever functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-12  File created
2019-06-28  Documentation done
************************************************************************/

#ifndef __RECIEVER_HEADER
#define __RECIEVER_HEADER

#include "typedef_MSP430.h"

/******************************************************************************
Type Definitions
******************************************************************************/

typedef struct
{
  u16* u16pPortAddress;
  u8 u8PinIdentifier;
}RecieverInformation; //The information needed to turn a reciever on and off

/****************************************************************************************
Constants
****************************************************************************************/

#define RECIEVER_SENSITIVITY_MAX_VOLTAGE_TO_NOT_TURN (u16) 0x0360 //I RECOMMEND 360. 365 is the absolute maximum sensitivity

/************************ Function Declarations ****************************/

bool hasRecieverDetectedAWall(RecieverInformation rInfoReciever);

#endif /* __RECIEVER_HEADER */