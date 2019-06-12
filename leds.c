/**********************************************************************
* Definitions for LED functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-04  File created

************************************************************************/

#include "leds.h"
#include "io430f2122.h"
#include "typedef_MSP430.h"

void LedOn(LedInformation LEDInfo)
{
  *(LEDInfo.u16pPortAddress) |= LEDInfo.u8LEDIdentifier;
}

void LedOff(LedInformation LEDInfo)
{
  *(LEDInfo.u16pPortAddress) &= ~LEDInfo.u8LEDIdentifier;
}

bool isLedOn(LedInformation LEDInfo)
{
  return (((*(LEDInfo.u16pPortAddress)) & LEDInfo.u8LEDIdentifier) == LEDInfo.u8LEDIdentifier);
}
bool isLedOff(LedInformation LEDInfo)
{
  return !isLedOn(LEDInfo);
}
