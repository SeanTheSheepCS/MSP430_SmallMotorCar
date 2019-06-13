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

#define CAR_SPEED_SECONDS_TO_TRAVEL_ONE_MM       (u16)5
#define CAR_TURN_RATE_SECONDS_TO_TURN_ONE_DEGREE (u16)

/************************ Function Declarations ****************************/

void turnLeftThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void turnRightThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void goForwardThisManyMillimetres(u8 u8MetresToGoForwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void goBackwardThisManyMillimetres(u8 u8MetresToGoBackwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void motorOn(MotorInformation motorToTurnOn);
void motorOff(MotorInformation motorToTurnOff);

#endif /* __CAR_HEADER */