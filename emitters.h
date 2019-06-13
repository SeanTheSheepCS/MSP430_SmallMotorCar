/**********************************************************************
* Header file for emitter functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-13  File created

************************************************************************/

#ifndef __EMITTER_HEADER
#define __EMITTER_HEADER

#include "typedef_MSP430.h"

/******************************************************************************
Type Definitions
******************************************************************************/

typedef struct
{
  u16* u16pPortAddress;
  u8 u8EmitterIdentifier;  
}EmitterInformation;

/****************************************************************************************
Constants
****************************************************************************************/

/************************ Function Declarations ****************************/

void TurnOnEmitter(EmitterInformation eInfoEmitter);
void TurnOffEmitter(EmitterInformation eInfoEmitter);

#endif /* __RECIEVER_HEADER */