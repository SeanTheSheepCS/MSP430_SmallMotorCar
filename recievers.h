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
  u16 u16TurnVoltageThreshold; /* If the analog voltage read and put into ADC10MEM is above whatever number is here, the car will decide there is no obstacle in the way.
                                * If the analog voltage read and put into ADC10MEM is under whatever number is here, the car will decide there is an obstacle in the way.
                                * Reasonable values to test are anywhere from 0x0350 to 0x03B0. 0x0350 is not very sensitive, 0x03B0 should be very sensitive.
                                */
}RecieverInformation; //The information needed to turn a reciever on and off

/****************************************************************************************
Constants
****************************************************************************************/

/************************ Function Declarations ****************************/

bool hasRecieverDetectedAWall(RecieverInformation rInfoReciever);

#endif /* __RECIEVER_HEADER */