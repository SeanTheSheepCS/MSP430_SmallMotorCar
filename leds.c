/**********************************************************************
* Definitions for LED functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-04  File created
2019-06-24  Documentation done
************************************************************************/

#include "leds.h"
#include "io430f2122.h"
#include "typedef_MSP430.h"

/*----------------------------------------------------------------------------------------------------------------------
Function: LedOn(LedInformation LedInfo)

Description: Turns the LED with the specified information on

Requires:
  - LedInfo has a valid portAddress and LedIndentifier

Promises:
  - Turns the LED with the specified LedInformation on

*/
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
} /* end LedOn */

/*----------------------------------------------------------------------------------------------------------------------
Function: LedOff(LedInformation LedInfo)

Description: Turns the LED with the specified information off

Requires:
  - LedInfo has a valid portAddress and LedIndentifier

Promises:
  - Turns the LED with the specified LedInformation off

*/
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
} /* end LedOff */

/*----------------------------------------------------------------------------------------------------------------------
Function: IsLedOn(LedInformation LedInfo)

Description: returns TRUE if the LED with the specified information is currently on, otherwise returns FALSE. THIS FUNCTION DOES NOT CURRENTLY TAKE INTO ACCOUNT IF THE LED IS ACTIVE HIGH OR ACTIVE LOW

Requires:
  -LedInfo has a valid portAddress and ledIdentifier

Promises:
  -returns TRUE if the LED with the specified information is currently on, otherwise returns FALSE

*/
bool isLedOn(LedInformation LedInfo)
{
  return (((*(LedInfo.u16pPortAddress)) & LedInfo.u8LedIdentifier) == LedInfo.u8LedIdentifier);
} /* end isLedOn */

/*----------------------------------------------------------------------------------------------------------------------
Function: IsLedOn(LedInformation LedInfo)

Description: returns TRUE if the LED with the specified information is currently off, otherwise returns FALSE. THIS FUNCTION DOES NOT CURRENTLY TAKE INTO ACCOUNT IF THE LED IS ACTIVE HIGH OR ACTIVE LOW

Requires:
  -LedInfo has a valid portAddress and ledIdentifier

Promises:
  -returns TRUE if the LED with the specified information is currently off, otherwise returns FALSE

*/
bool isLedOff(LedInformation LedInfo)
{
  return !isLedOn(LedInfo);
} /* end isLedOff */
