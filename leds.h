/**********************************************************************
* Header file for LED functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-04  File created

************************************************************************/

#ifndef __LED_HEADER
#define __LED_HEADER

#include "typedef_MSP430.h"

/******************************************************************************
Type Definitions
******************************************************************************/

typedef enum {LED_ACTIVE_TYPE_HIGH = 0, LED_ACTIVE_TYPE_LOW = 1} LedActiveType;

typedef struct
{
  u16* u16pPortAddress;
  u8 u8LedIdentifier;
  LedActiveType ledactActiveType;
}LedInformation;

/****************************************************************************************
Constants
****************************************************************************************/

/************************ Function Declarations ****************************/

void LedOn(LedInformation LedInfo);
void LedOff(LedInformation LedInfo);
bool isLedOn(LedInformation LedInfo);
bool isLedOff(LedInformation LedInfo);

#endif /* __LED_HEADER */