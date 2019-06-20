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

void LedOn(LedInformation LedInfo)
{
  if(LedInfo.ledactActiveType == LED_ACTIVE_TYPE_HIGH)
  {
    *(LedInfo.u16pPortAddress) |= LedInfo.u8LedIdentifier;
  }
  else if(LedInfo.ledactActiveType == LED_ACTIVE_TYPE_LOW)
  {
    *(LedInfo.u16pPortAddress) &= ~LedInfo.u8LedIdentifier;
  }
}

void LedOff(LedInformation LedInfo)
{
  if(LedInfo.ledactActiveType == LED_ACTIVE_TYPE_LOW)
  {
    *(LedInfo.u16pPortAddress) |= LedInfo.u8LedIdentifier;
  }
  else if(LedInfo.ledactActiveType == LED_ACTIVE_TYPE_HIGH)
  {
    *(LedInfo.u16pPortAddress) &= ~LedInfo.u8LedIdentifier;
  }
}

bool isLedOn(LedInformation LedInfo)
{
  return (((*(LedInfo.u16pPortAddress)) & LedInfo.u8LedIdentifier) == LedInfo.u8LedIdentifier);
}
bool isLedOff(LedInformation LedInfo)
{
  return !isLedOn(LedInfo);
}
