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

typedef struct
{
  u16* u16pPortAddress;
  u8 u8LEDIdentifier;
}LedInformation;

/****************************************************************************************
Constants
****************************************************************************************/

/************************ Function Declarations ****************************/

void LedOn(LedInformation LEDInfo);
void LedOff(LedInformation LEDInfo);
bool isLedOn(LedInformation LEDInfo);
bool isLedOff(LedInformation LEDInfo);

#endif /* __LED_HEADER */