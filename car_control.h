/**********************************************************************
* Header file for car control functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-12  File created

************************************************************************/

#ifndef __CAR_HEADER
#define __CAR_HEADER

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

#define SPEED_OF_THE_CAR_METRES_PER_SECOND (u8)5

/************************ Function Declarations ****************************/

void turnLeftThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void turnRightThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void goForwardThisManyMetres(u8 u8MetresToGoForwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void goBackwardThisManyMetres(u8 u8MetresToGoBackwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor);
void motorOn(MotorInformation motorToTurnOn);
void motorOff(MotorInformation motorToTurnOff);

#endif /* __CAR_HEADER */