/**********************************************************************
* Definitions for emitter functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-13  File created
2019-06-28  Documentation done
************************************************************************/

#include "emitters.h"

/*----------------------------------------------------------------------------------------------------------------------
Function: TurnOnEmitter

Description: turns on the emitter with the given EmitterInformation

Requires:
  - N/A

Promises:
  - turns on the emitter

*/
void TurnOnEmitter(EmitterInformation eInfoEmitter)
{
  *(eInfoEmitter.u16pPortAddress) |= eInfoEmitter.u8EmitterIdentifier;
}

/*----------------------------------------------------------------------------------------------------------------------
Function: TurnOffEmitter

Description: turns off the emitter with the given EmitterInformation

Requires:
  - N/A

Promises:
  - turns off the emitter

*/
void TurnOffEmitter(EmitterInformation eInfoEmitter)
{
  *(eInfoEmitter.u16pPortAddress) &= ~eInfoEmitter.u8EmitterIdentifier;
}