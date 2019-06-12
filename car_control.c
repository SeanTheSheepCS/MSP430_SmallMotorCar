/**********************************************************************
* Definitions for car control functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-12  File created

************************************************************************/

#include "io430f2122.h"
#include "typedef_MSP430.h"
#include "car_control.h"

/******************** Local Globals ************************/
/* Global variable definitions intended only for the scope of this file */

MotorPinInformation LG_aMPinInfoScoreLeds[NUMBER_OF_MPINS] = {{(u16*)0x0029, P2_4_LEFT_MOTOR_NEG_INPUT, (u16*)0x0021, P1_0_LEFT_MOTOR_POS_INPUT},
                                                              {(u16*)0x0021, P1_1_RIGHT_MOTOR_NEG_INPUT, (u16*)0x0021, P1_2_RIGHT_MOTOR_POS_INPUT}};
                                                             

/******************** Function Definitions ************************/

void turnLeftThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  
}

void turnRightThisManyDegrees(u8 u8AngleToTurn, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  
}

void goForwardThisManyMetres(u8 u8MetresToGoForwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  
}

void goBackwardThisManyMetres(u8 u8MetresToGoBackwards, MotorInformation motoInfoLeftMotor, MotorInformation motoInfoRightMotor)
{
  
}

void motorOn(MotorInformation motorToTurnOn)
{
  
}

void motorOff(MotorInformation motorToTurnOff)
{
  
}
