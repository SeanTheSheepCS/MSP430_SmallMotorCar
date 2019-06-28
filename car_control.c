/**********************************************************************
* Definitions for car control functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-12  File created
2019-06-28  Documentation done
************************************************************************/

#include "car_control.h"
#include "io430.h"
#include "typedef_MSP430.h"
#include "utilities.h"

/******************** Local Globals ************************/
/* Global variable definitions intended only for the scope of this file */

/******************** Function Definitions ************************/

/*----------------------------------------------------------------------------------------------------------------------
Function: TurnLeftThisManyDegrees

Description: turns left a certain number of degrees

Requires:
  - motoInfoLeftMotor and motoInfoRightMotor are the motorInformation belonging to the left and right motors
  - CAR_TURN_RATE_MS_TO_TURN_ONE_DEGREE is accurate

Promises:
  - turns the car u8AngleToTurn degrees to the left

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
Function: TurnRightThisManyDegrees

Description: turns right a certain number of degrees

Requires:
  - motoInfoLeftMotor and motoInfoRightMotor are the motorInformation belonging to the left and right motors
  - CAR_TURN_RATE_MS_TO_TURN_ONE_DEGREE is accurate

Promises:
  - turns the car u8AngleToTurn degrees to the right

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
Function: GoForwardThisManyMillimetres

Description: Moves the car forward a certain number of millimetres

Requires:
  - motoInfoLeftMotor and motoInfoRightMotor are the motorInformation belonging to the left and right motors
  - CAR_SPEED_MS_TO_TRAVEL_ONE_MILLIMETER is accurate

Promises:
  - moves the car u8MillimetresToGoForwards millimetres forwards

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
Function: GoBackwardThisManyMillimetres

Description: Moves the car backward a certain number of millimetres

Requires:
  - motoInfoLeftMotor and motoInfoRightMotor are the motorInformation belonging to the left and right motors
  - CAR_SPEED_MS_TO_TRAVEL_ONE_MILLIMETER is accurate

Promises:
  - moves the car u8MillimetresToGoBackwards millimetres backwards

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
Function: MotorOn

Description: turns a motor in the mode where the wheel spins forwards

Requires:
  - motorToTurnOn is valid motorInformation

Promises:
  - turns motorToTurnOn in the mode where the wheel spins forwards

*/
void MotorOn(MotorInformation motorToTurnOn)
{
  *(motorToTurnOn.u16pPortAddressNegInput) &= ~motorToTurnOn.u8PinIdentifierNegInput;
  *(motorToTurnOn.u16pPortAddressPosInput) |= motorToTurnOn.u8PinIdentifierPosInput;
}

/*----------------------------------------------------------------------------------------------------------------------
Function: MotorOff

Description: turns a motor in the mode where the wheel does not spin

Requires:
  - motorToTurnOff is valid motorInformation

Promises:
  - turns motorToTurnOff in the mode where the wheel does not spin

*/
void MotorOff(MotorInformation motorToTurnOff)
{
  *(motorToTurnOff.u16pPortAddressNegInput) &= ~motorToTurnOff.u8PinIdentifierNegInput;
  *(motorToTurnOff.u16pPortAddressPosInput) &= ~motorToTurnOff.u8PinIdentifierPosInput;
}

/*----------------------------------------------------------------------------------------------------------------------
Function: MotorReverse

Description: turns a motor in the mode where the wheel spins backwards

Requires:
  - motorToReverse is valid motorInformation

Promises:
  - turns motorToReverse in the mode where the wheel spins backwards

*/
void MotorReverse(MotorInformation motorToReverse)
{
  *(motorToReverse.u16pPortAddressNegInput) |= motorToReverse.u8PinIdentifierNegInput;
  *(motorToReverse.u16pPortAddressPosInput) &= ~motorToReverse.u8PinIdentifierPosInput;
}
