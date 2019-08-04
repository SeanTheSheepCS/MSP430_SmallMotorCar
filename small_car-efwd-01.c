/**********************************************************************
* Supporting functions for Small Motor Car
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2013-11-21  Port from ANT key fob.
2019-06-05  Binary counter scoreboard first attempt
2019-06-12  Small motor car first attempt
2019-06-24  Documentation done
************************************************************************/

#include "small_car-efwd-01.h"
#include "io430.h"
#include "typedef_MSP430.h"
#include "intrinsics.h"
#include "leds.h"
#include "car_control.h"
#include "recievers.h"
#include "emitters.h"
#include "utilities.h"

/******************** External Globals ************************/
/* Globally available variables from other files as indicated */


/******************** Program Globals ************************/
/* Global variable definitions intended for scope across multiple files */
fnCode_type CarStateMachine = CarSM_Initialize;   /* The application state machine */
fnCode_type G_fCurrentStateMachine = CarSM_Idle;

volatile u16 u16GlobalRuntimeFlags = 0;               /* Flag register for communicating various runtime events. */
volatile u16 u16GlobalErrorFlags = 0;                 /* Flag register for communicating errors. */

volatile u16 u16GlobalCurrentSleepInterval;           /* Duration that the device will sleep */

/******************** Local Globals ************************/
/* Global variable definitions intended only for the scope of this file */

LedInformation LG_aLedInfoLeds[NUMBER_OF_LEDS] = {{(u16*)0x0029, P2_2_CENTER_LED_RED_INPUT, LED_ACTIVE_TYPE_LOW},
                                                  {(u16*)0x0029, P2_5_TAILLIGHTS_LEDS, LED_ACTIVE_TYPE_HIGH},
                                                  {(u16*)0x0019, P3_0_CENTER_LED_GREEN_INPUT, LED_ACTIVE_TYPE_LOW},
                                                  {(u16*)0x0019, P3_1_CENTER_LED_BLUE_INPUT, LED_ACTIVE_TYPE_LOW},
                                                  {(u16*)0x0019, P3_2_HEADLIGHTS_LEDS, LED_ACTIVE_TYPE_HIGH}};
LedInformation* LG_pLedInfoCenterLedRed = &(LG_aLedInfoLeds[0]);
LedInformation* LG_pLedInfoTaillights = &(LG_aLedInfoLeds[1]);
LedInformation* LG_pLedInfoCenterLedGreen = &(LG_aLedInfoLeds[2]);
LedInformation* LG_pLedInfoCenterLedBlue = &(LG_aLedInfoLeds[3]);
LedInformation* LG_pLedInfoHeadlights = &(LG_aLedInfoLeds[4]);

MotorInformation LG_aMInfoMotors[NUMBER_OF_MOTORS] = {{(u16*)0x0021, P1_1_LEFT_MOTOR_NEG_INPUT, (u16*)0x0021, P1_2_LEFT_MOTOR_POS_INPUT},
                                                      {(u16*)0x0029, P2_4_RIGHT_MOTOR_NEG_INPUT, (u16*)0x0021, P1_0_RIGHT_MOTOR_POS_INPUT}};
MotorInformation* LG_pMInfoLeftMotor = &(LG_aMInfoMotors[0]);
MotorInformation* LG_pMInfoRightMotor = &(LG_aMInfoMotors[1]);

RecieverInformation LG_aRInfoRecievers[NUMBER_OF_RECIEVERS] = {{(u16*)0x0029, P2_3_LEFT_RECIEVER_SIGNAL, 0x0360},
                                                               {(u16*)0x0019, P3_6_RIGHT_RECIEVER_SIGNAL, 0x0330},
                                                               {(u16*)0x0019, P3_7_CENTER_RECIEVER_SIGNAL, 0x0360}};
RecieverInformation* LG_pRInfoLeftReciever = &(LG_aRInfoRecievers[0]);
RecieverInformation* LG_pRInfoRightReciever = &(LG_aRInfoRecievers[1]);
RecieverInformation* LG_pRInfoCenterReciever = &(LG_aRInfoRecievers[2]);

EmitterInformation LG_aEInfoEmitters[NUMBER_OF_EMITTERS] = {{(u16*)0x0029, P2_0_CENTER_EMITTER},
                                                            {(u16*)0x0029, P2_1_LEFT_EMITTER},
                                                            {(u16*)0x0019, P3_3_RIGHT_EMITTER}};
EmitterInformation* pLG_pEInfoCenterEmitter = &(LG_aEInfoEmitters[0]);
EmitterInformation* pLG_pEInfoLeftEmitter = &(LG_aEInfoEmitters[1]);
EmitterInformation* pLG_pEInfoRightEmitter = &(LG_aEInfoEmitters[2]);

/******************** Function Definitions ************************/

/*------------------------------------------------------------------------------
Function: SetTimer

Description:
Sets the TACCRO register, clears timer and clear the interrupt flag.

Requires:
  - usTaccr0_ is the value to which TACCRO will be set, where the time before interrupt in seconds
    is usTaccr0_ * (8/32768).  e.g. TACCRO = 12288 is a 3000ms delay.

Promises:
  - Timer is reset to 0
  - The timer interrupt flag is cleared
  - TACCRO is loaded with usTaccr0_
*/
void SetTimer(u16 usTaccr0_)
/* Sets the TACCRO register, clears timer and the interrupt flag */
{
  TAR = 0;
	TACCR0 = usTaccr0_;
	TACTL &= ~TAIFG;

} /* end SetTimer */

/****************************************************************************************
State Machine Functions
****************************************************************************************/

/*----------------------------------------------------------------------------------------------------------------------
Function: CarSM_Initialize()

Description: Sets the direction on all of the pins and selects them as I/O, turns all the LEDS off, and sets the car to an idle state

Requires:
  - N/A

Promises:
  - All directions on the pins are set
  - All LEDs are turned off
  - The car state machine is now in its idle state

*/
void CarSM_Initialize()
{
  /* Reset key variables */
  u16GlobalCurrentSleepInterval = TIME_MAX;

  P1DIR |= P1_0_RIGHT_MOTOR_POS_INPUT; //Sets the pin as an output
  P1SEL2 &= ~P1_0_RIGHT_MOTOR_POS_INPUT; //Selects the I/O function
  P1SEL &= ~P1_0_RIGHT_MOTOR_POS_INPUT; //Also needed to select the I/O function
  P1DIR |= P1_1_LEFT_MOTOR_NEG_INPUT;
  P1SEL2 &= ~P1_1_LEFT_MOTOR_NEG_INPUT;
  P1SEL &= ~P1_1_LEFT_MOTOR_NEG_INPUT;
  P1DIR |= P1_2_LEFT_MOTOR_POS_INPUT;
  P1SEL2 &= ~P1_2_LEFT_MOTOR_POS_INPUT;
  P1SEL &= ~P1_2_LEFT_MOTOR_POS_INPUT;
  P1DIR |= P1_3_BUZZER;
  P1SEL2 &= ~P1_3_BUZZER;
  P1SEL &= ~P1_3_BUZZER;

  P2DIR |= P2_0_CENTER_EMITTER;
  P2SEL2 &= ~P2_0_CENTER_EMITTER;
  P2SEL &= ~P2_0_CENTER_EMITTER;
  P2DIR |= P2_1_LEFT_EMITTER;
  P2SEL2 &= ~P2_1_LEFT_EMITTER;
  P2SEL &= ~P2_1_LEFT_EMITTER;
  P2DIR |= P2_2_CENTER_LED_RED_INPUT;
  P2SEL2 &= ~P2_2_CENTER_LED_RED_INPUT;
  P2SEL &= ~P2_2_CENTER_LED_RED_INPUT;
  P2DIR &= ~P2_3_LEFT_RECIEVER_SIGNAL; //Sets the pin as an input
  P2SEL2 &= ~P2_3_LEFT_RECIEVER_SIGNAL;
  P2SEL &= ~P2_3_LEFT_RECIEVER_SIGNAL;
  P2DIR |= P2_4_RIGHT_MOTOR_NEG_INPUT;
  P2SEL2 &= ~P2_4_RIGHT_MOTOR_NEG_INPUT;
  P2SEL &= ~P2_4_RIGHT_MOTOR_NEG_INPUT;
  P2DIR |= P2_5_TAILLIGHTS_LEDS;
  P2SEL2 &= ~P2_5_TAILLIGHTS_LEDS;
  P2SEL &= ~P2_5_TAILLIGHTS_LEDS;
  P2DIR |= P2_6_EXTRA_INPUT_ONE;
  P2SEL2 &= ~P2_6_EXTRA_INPUT_ONE;
  P2SEL &= ~P2_6_EXTRA_INPUT_ONE;
  P2DIR |= P2_7_EXTRA_INPUT_TWO;
  P2SEL2 &= ~P2_7_EXTRA_INPUT_TWO;
  P2SEL &= ~P2_7_EXTRA_INPUT_TWO;

  //P3SEL2 is not set here since port 3 only has one select register
  P3DIR |= P3_0_CENTER_LED_GREEN_INPUT;
  P3SEL &= ~P3_0_CENTER_LED_GREEN_INPUT;
  P3DIR |= P3_1_CENTER_LED_BLUE_INPUT;
  P3SEL &= ~P3_1_CENTER_LED_BLUE_INPUT;
  P3DIR |= P3_2_HEADLIGHTS_LEDS;
  P3SEL &= ~P3_2_HEADLIGHTS_LEDS;
  P3DIR |= P3_3_RIGHT_EMITTER;
  P3SEL &= ~P3_3_RIGHT_EMITTER;
  P3DIR &= ~P3_6_RIGHT_RECIEVER_SIGNAL;
  P3SEL &= ~P3_6_RIGHT_RECIEVER_SIGNAL;
  P3DIR &= ~P3_7_CENTER_RECIEVER_SIGNAL;
  P3SEL &= ~P3_7_CENTER_RECIEVER_SIGNAL;

  LedOff(*LG_pLedInfoCenterLedRed);
  LedOff(*LG_pLedInfoCenterLedGreen);
  LedOff(*LG_pLedInfoCenterLedBlue);
  LedOff(*LG_pLedInfoTaillights);
  LedOff(*LG_pLedInfoHeadlights);

  CarStateMachine = CarSM_Idle;

} /* end CarSM_Initialize */

/*----------------------------------------------------------------------------------------------------------------------
State: CarSM_Idle()

Description: The car should go forward until it detects something in its path, then turns around or backs up accordingly

Requires:
  - Car has been properly initialized

Promises:
  - Follows the behaviour outlined in the excel sheet found at:        extra_information/car_behaviour.xlsx (LAST UPDATED JUNE 28th 2019)

*/
void CarSM_Idle()
{
  bool boolObstaclePresentCenterSide = IsObstaclePresent(CENTER_SIDE);
  bool boolObstaclePresentRightSide = IsObstaclePresent(RIGHT_SIDE);
  bool boolObstaclePresentLeftSide = IsObstaclePresent(LEFT_SIDE);

  LedOn(*LG_pLedInfoHeadlights);
  MotorOn(*LG_pMInfoLeftMotor);
  MotorOn(*LG_pMInfoRightMotor);

  if(boolObstaclePresentCenterSide)
  {
    LedOn(*LG_pLedInfoCenterLedRed);
  }
  else
  {
    LedOff(*LG_pLedInfoCenterLedRed);
  }

  if(boolObstaclePresentRightSide)
  {
    LedOn(*LG_pLedInfoCenterLedBlue);
  }
  else
  {
    LedOff(*LG_pLedInfoCenterLedBlue);
  }

  if(boolObstaclePresentLeftSide)
  {
    LedOn(*LG_pLedInfoCenterLedGreen);
  }
  else
  {
    LedOff(*LG_pLedInfoCenterLedGreen);
  }

  if(!(boolObstaclePresentCenterSide) && !(boolObstaclePresentRightSide) && !(boolObstaclePresentLeftSide))
  {
    WaitThisManyMilliseconds(10);
  }
  else if(!(boolObstaclePresentCenterSide) && !(boolObstaclePresentRightSide) &&  (boolObstaclePresentLeftSide))
  {
    LedOff(*LG_pLedInfoHeadlights);
    TurnRightThisManyDegrees(45, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
  }
  else if(!(boolObstaclePresentCenterSide) &&  (boolObstaclePresentRightSide) && !(boolObstaclePresentLeftSide))
  {
    LedOff(*LG_pLedInfoHeadlights);
    TurnLeftThisManyDegrees(45, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
  }
  else if(!(boolObstaclePresentCenterSide) &&  (boolObstaclePresentRightSide) &&  (boolObstaclePresentLeftSide))
  {
    LedOff(*LG_pLedInfoHeadlights);
    LedOn(*LG_pLedInfoTaillights);
    GoBackwardThisManyMillimetres(50, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    LedOff(*LG_pLedInfoTaillights);
    if(GenerateRandomishNumberOneOrZero() == 1)
    {
      TurnLeftThisManyDegrees(45, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    }
    else
    {
      TurnRightThisManyDegrees(45, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    }
  }
  else if( (boolObstaclePresentCenterSide) && !(boolObstaclePresentRightSide) && !(boolObstaclePresentLeftSide))
  {
    LedOff(*LG_pLedInfoHeadlights);
    LedOn(*LG_pLedInfoTaillights);
    GoBackwardThisManyMillimetres(50, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    LedOff(*LG_pLedInfoTaillights);
    if(GenerateRandomishNumberOneOrZero() == 1)
    {
      TurnLeftThisManyDegrees(90, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    }
    else
    {
      TurnRightThisManyDegrees(90, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    }
  }
  else if( (boolObstaclePresentCenterSide) && !(boolObstaclePresentRightSide) &&  (boolObstaclePresentLeftSide))
  {
    LedOff(*LG_pLedInfoHeadlights);
    TurnRightThisManyDegrees(90, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
  }
  else if( (boolObstaclePresentCenterSide) &&  (boolObstaclePresentRightSide) && !(boolObstaclePresentLeftSide))
  {
    LedOff(*LG_pLedInfoHeadlights);
    TurnLeftThisManyDegrees(90, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
  }
  else if( (boolObstaclePresentCenterSide) &&  (boolObstaclePresentRightSide) &&  (boolObstaclePresentLeftSide))
  {
    LedOff(*LG_pLedInfoHeadlights);
    LedOn(*LG_pLedInfoTaillights);
    GoBackwardThisManyMillimetres(50, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    LedOff(*LG_pLedInfoTaillights);
    if(GenerateRandomishNumberOneOrZero() == 1)
    {
      TurnLeftThisManyDegrees(90, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    }
    else
    {
      TurnRightThisManyDegrees(90, *LG_pMInfoLeftMotor, *LG_pMInfoRightMotor);
    }
  }

} /* end CarSM_Idle() */

/*----------------------------------------------------------------------------------------------------------------------
Function: IsObstaclePresent

Description: Takes in an enum which denotes which side of the car to check and returns TRUE if the IR reciever senses an obstacle nearby

Requires:
  -sotctSideToCheckForObstacle is LEFT_SIDE, RIGHT_SIDE, or CENTER_SIDE.

Promises:
  -returns TRUE if the reciever detected an obstacle on that side and returns FALSE otherwise

*/
bool IsObstaclePresent(SidesOfTheCarType sotctSideToCheckForObstacle)
{
  if(sotctSideToCheckForObstacle == LEFT_SIDE)
  {
    TurnOnEmitter(*pLG_pEInfoLeftEmitter);
    if(hasRecieverDetectedAWall(*LG_pRInfoLeftReciever))
    {
      TurnOffEmitter(*pLG_pEInfoLeftEmitter);
      return TRUE;
    }
    else
    {
      TurnOffEmitter(*pLG_pEInfoLeftEmitter);
      return FALSE;
    }
  }
  else if(sotctSideToCheckForObstacle == RIGHT_SIDE)
  {
    TurnOnEmitter(*pLG_pEInfoRightEmitter);
    if(hasRecieverDetectedAWall(*LG_pRInfoRightReciever))
    {
      TurnOffEmitter(*pLG_pEInfoRightEmitter);
      return TRUE;
    }
    else
    {
      TurnOffEmitter(*pLG_pEInfoRightEmitter);
      return FALSE;
    }
  }
  else if(sotctSideToCheckForObstacle == CENTER_SIDE)
  {
    TurnOnEmitter(*pLG_pEInfoCenterEmitter);
    if(hasRecieverDetectedAWall(*LG_pRInfoCenterReciever))
    {
      TurnOffEmitter(*pLG_pEInfoCenterEmitter);
      return TRUE;
    }
    else
    {
      TurnOffEmitter(*pLG_pEInfoCenterEmitter);
      return FALSE;
    }
  }
  else
  {
    return FALSE;
  }
}
