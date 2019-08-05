/**********************************************************************
* Definitions for reciever functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-04  File created
2019-07-14  Documentation done
************************************************************************/

#include "recievers.h"
#include "io430f2112.h"
#include "utilities.h"

/*------------------------------------------------------------------------------
Function: hasRecieverDetectedAWall

Description:
Returns true if this reciever has decided that there is something in front of it

Requires:
  - rInfoReciever has all fields properly initialized and belongs to port one, two, or three.
  - The pin being used has analog input enabled.

Promises:
  - returns true if this reciever has decided that there is something in front of it.
*/
bool hasRecieverDetectedAWall(RecieverInformation rInfoReciever)
{
  if(rInfoReciever.u16pPortAddress == (u16*)0x0021)  /* If the reciever belongs to port one... */
  {
    P1SEL |= rInfoReciever.u8PinIdentifier;
    ADC10CTL1 = INCH_3 + ADC10DIV_3;
    ADC10CTL0 = ADC10ON + ADC10IE + SREF_0 + ADC10SHT_3;  // Turns the control on, enables interrupts
    ADC10AE0 |= rInfoReciever.u8PinIdentifier;
    ADC10CTL0 |= ENC + ADC10SC;
    if(ADC10MEM < rInfoReciever.u16TurnVoltageThreshold)
    {
      return TRUE;
    }
  }
  else if(rInfoReciever.u16pPortAddress == (u16*)0x0029)  /* If the reciever belongs to port two... */
  {
    P2SEL |= rInfoReciever.u8PinIdentifier;
    ADC10CTL1 = INCH_3 + ADC10DIV_3;
    ADC10CTL0 = ADC10ON + ADC10IE + SREF_0 + ADC10SHT_3;  // Turns the control on, enables interrupts
    ADC10AE0 |= rInfoReciever.u8PinIdentifier;
    ADC10CTL0 |= ENC + ADC10SC;
    if(ADC10MEM < rInfoReciever.u16TurnVoltageThreshold)
    {
      return TRUE;
    }
  }
  else if(rInfoReciever.u16pPortAddress == (u16*)0x0019)  /* If the reciever belongs to port three... */
  {
    P3SEL |= rInfoReciever.u8PinIdentifier;
    ADC10CTL1 = INCH_7 + ADC10DIV_3;
    ADC10CTL0 = ADC10ON + ADC10IE + SREF_0 + ADC10SHT_3;  // Turns the control on, enables interrupts
    ADC10AE0 |= rInfoReciever.u8PinIdentifier;
    ADC10CTL0 |= ENC + ADC10SC;
    if(ADC10MEM < rInfoReciever.u16TurnVoltageThreshold)
    {
      return TRUE;
    }
  }
  return FALSE;
}
