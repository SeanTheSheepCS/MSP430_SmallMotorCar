/**********************************************************************
* Definitions for car control functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-12  File created

************************************************************************/

#include "car_control.h"
#include "io430.h"
#include "typedef_MSP430.h"
#include "utilities.h"

/******************** Local Globals ************************/
/* Global variable definitions intended only for the scope of this file */

/******************** Function Definitions ************************/

/*----------------------------------------------------------------------------------------------------------------------
Function: 

Description: 

Requires:
  -

Promises:
  -

*/
void TurnLeftThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToTurnFor = CAR_TURN_RATE_MS_TO_TURN_ONE_DEGREE * u8AngleToTurn;
  MotorOn(motoInfoRightMotor);
  MotorReverse(motoInfoLeftMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToTurnFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

/*----------------------------------------------------------------------------------------------------------------------
Function: 

Description: 

Requires:
  -

Promises:
  -

*/
void TurnRightThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToTurnFor = CAR_TURN_RATE_MS_TO_TURN_ONE_DEGREE * u8AngleToTurn;
  MotorOn(motoInfoLeftMotor);
  MotorReverse(motoInfoRightMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToTurnFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

/*----------------------------------------------------------------------------------------------------------------------
Function: 

Description: 

Requires:
  -

Promises:
  -

*/
void GoForwardThisManyMillimetres(u8 u8MillimetresToGoForwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToMoveForwardsFor = CAR_SPEED_MS_TO_TRAVEL_ONE_MILLIMETER * u8MillimetresToGoForwards;
  MotorOn(motoInfoLeftMotor);
  MotorOn(motoInfoRightMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToMoveForwardsFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

/*----------------------------------------------------------------------------------------------------------------------
Function: 

Description: 

Requires:
  -

Promises:
  -

*/
void GoBackwardThisManyMillimetres(u8 u8MillimetresToGoBackwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToMoveBackwardsFor = CAR_SPEED_MS_TO_TRAVEL_ONE_MILLIMETER * u8MillimetresToGoBackwards;
  MotorReverse(motoInfoLeftMotor);
  MotorReverse(motoInfoRightMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToMoveBackwardsFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

/*----------------------------------------------------------------------------------------------------------------------
Function: 

Description: 

Requires:
  -

Promises:
  -

*/
void MotorOn(MotorInformation motorToTurnOn)
{
  *(motorToTurnOn.u16pPortAddressNegInput) &= ~motorToTurnOn.u8PinIdentifierNegInput;
  *(motorToTurnOn.u16pPortAddressPosInput) |= motorToTurnOn.u8PinIdentifierPosInput;
}

/*----------------------------------------------------------------------------------------------------------------------
Function: 

Description: 

Requires:
  -

Promises:
  -

*/
void MotorOff(MotorInformation motorToTurnOff)
{
  *(motorToTurnOff.u16pPortAddressNegInput) &= ~motorToTurnOff.u8PinIdentifierNegInput;
  *(motorToTurnOff.u16pPortAddressPosInput) &= ~motorToTurnOff.u8PinIdentifierPosInput;
}

/*----------------------------------------------------------------------------------------------------------------------
Function: 

Description: 

Requires:
  -

Promises:
  -

*/
void MotorReverse(MotorInformation motorToReverse)
{
  *(motorToReverse.u16pPortAddressNegInput) |= motorToReverse.u8PinIdentifierNegInput;
  *(motorToReverse.u16pPortAddressPosInput) &= ~motorToReverse.u8PinIdentifierPosInput;
}
