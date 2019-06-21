/**********************************************************************
* Header file for reciever functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-12  File created

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
}RecieverInformation;

/****************************************************************************************
Constants
****************************************************************************************/

#define DEBOUNCE_TIME_MS (u8)20
#define RECIEVER_SENSITIVITY_MAX_VOLTAGE_TO_NOT_TURN (u16) 0x0365

/************************ Function Declarations ****************************/

bool hasRecieverDetectedAWall(RecieverInformation rInfoReciever);

#endif /* __RECIEVER_HEADER */