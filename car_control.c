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

/******************** Local Globals ************************/
/* Global variable definitions intended only for the scope of this file */

/******************** Function Definitions ************************/

void TurnLeftThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToTurnFor = CAR_TURN_RATE_MS_TO_TURN_ONE_DEGREE * u8AngleToTurn;
  MotorOn(motoInfoRightMotor);
  MotorReverse(motoInfoLeftMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToTurnFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

void TurnRightThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToTurnFor = CAR_TURN_RATE_MS_TO_TURN_ONE_DEGREE * u8AngleToTurn;
  MotorOn(motoInfoLeftMotor);
  MotorReverse(motoInfoRightMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToTurnFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

void GoForwardThisManyMillimetres(u8 u8MillimetresToGoForwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToMoveForwardsFor = CAR_SPEED_MS_TO_TRAVEL_ONE_MM * u8MetresToGoForwards;
  MotorOn(motoInfoLeftMotor);
  MotorOn(motoInfoRightMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToMoveForwardsFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

void GoBackwardThisManyMillimetres(u8 u8MillimetresToGoBackwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  u32 u32NumberOfMillisecondsToMoveBackwardsFor = CAR_SPEED_MS_TO_TRAVEL_ONE_MM * u8MetresToGoBackwards;
  MotorReverse(motoInfoLeftMotor);
  MotorReverse(motoInfoRightMotor);
  WaitThisManyMilliseconds(u32NumberOfMillisecondsToMoveBackwardsFor);
  MotorOff(motoInfoRightMotor);
  MotorOff(motoInfoLeftMotor);
}

void MotorOn(MotorInformation motorToTurnOn)
{
  
}

void MotorOff(MotorInformation motorToTurnOff)
{
  
}

void MotorReverse(MotorInformation motorToReverse)
{
  
}
