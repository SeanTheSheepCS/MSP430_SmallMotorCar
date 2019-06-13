/**********************************************************************
* Definitions for emitter functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-13  File created

************************************************************************/

#include "emitters.h"

void TurnOnEmitter(EmitterInformation eInfoEmitter)
{
  *(eInfoEmitter.u16pPortAddress) |= eInfoEmitter.u8EmitterIdentifier;
}

void TurnOffEmitter(EmitterInformation eInfoEmitter)
{
  *(eInfoEmitter.u16pPortAddress) |= eInfoEmitter.u8EmitterIdentifier;
}