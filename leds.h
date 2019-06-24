/**********************************************************************
* Header file for LED functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-04  File created
2019-06-24  File documented and finalized for camp

************************************************************************/

#ifndef __LED_HEADER
#define __LED_HEADER

#include "typedef_MSP430.h"

/******************************************************************************
Type Definitions
******************************************************************************/

typedef enum {LED_ACTIVE_TYPE_HIGH = 0, LED_ACTIVE_TYPE_LOW = 1} LedActiveType; //LED_ACTIVE_TYPE_HIGH means when a voltage is provided, the LED turns on. LED_ACTIVE_TYPE_LOW means when no voltage is provided, the LED turns on

typedef struct
{
  u16* u16pPortAddress;
  u8 u8LedIdentifier;
  LedActiveType ledactActiveType;
}LedInformation; //This struct contains all the information needed to turn on and off an LED

/****************************************************************************************
Constants
****************************************************************************************/

/************************ Function Declarations ****************************/

void LedOn(LedInformation LedInfo);
void LedOff(LedInformation LedInfo);
bool isLedOn(LedInformation LedInfo);
bool isLedOff(LedInformation LedInfo);

#endif /* __LED_HEADER */