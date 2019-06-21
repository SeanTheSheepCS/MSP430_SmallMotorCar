/**********************************************************************
* Header file for car control functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-12  File created

************************************************************************/

#ifndef __CAR_CONTROL_HEADER
#define __CAR_CONTROL_HEADER

#include "typedef_MSP430.h"

/******************************************************************************
Type Definitions
******************************************************************************/

typedef struct
{
  u16* u16pPortAddressNegInput;
  u8 u8PinIdentifierNegInput;
  u16* u16pPortAddressPosInput;
  u8 u8PinIdentifierPosInput;
}MotorInformation;

/****************************************************************************************
Constants
****************************************************************************************/

#define CAR_SPEED_MS_TO_TRAVEL_ONE_MILLIMETER (u16)8
#define CAR_TURN_RATE_MS_TO_TURN_ONE_DEGREE   (u16)5

/************************ Function Declarations ****************************/

void TurnLeftThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void TurnRightThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void GoForwardThisManyMillimetres(u8 u8MillimetresToGoForwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void GoBackwardThisManyMillimetres(u8 u8MillimetresToGoBackwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void MotorOn(MotorInformation motorToTurnOn);
void MotorOff(MotorInformation motorToTurnOff);
void MotorReverse(MotorInformation motorToReverse);

#endif /* __CAR_HEADER */