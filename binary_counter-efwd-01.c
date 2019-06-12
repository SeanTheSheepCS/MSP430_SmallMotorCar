/**********************************************************************
* Supporting functions for LED Binary Counter
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2013-09-14  First release.
2019-06-05  Binary counter scoreboard first attempt

************************************************************************/

#include "io430.h"
#include "typedef_MSP430.h"
#include "intrinsics.h"
#include "binary_counter-efwd-01.h"
#include "main.h"
#include "leds.h"

/******************** External Globals ************************/
/* Globally available variables from other files as indicated */


/******************** Program Globals ************************/
/* Global variable definitions intended for scope across multiple files */
fnCode_type CounterStateMachine = CounterSM_Initialize;   /* The application state machine */
fnCode_type G_fCurrentStateMachine = CounterSM_Idle;  

volatile u16 u16GlobalRuntimeFlags = 0;               /* Flag register for communicating various runtime events. */
volatile u16 u16GlobalErrorFlags = 0;                 /* Flag register for communicating errors. */

volatile u16 u16GlobalCurrentSleepInterval;           /* Duration that the device will sleep */

/******************** Local Globals ************************/
/* Global variable definitions intended only for the scope of this file */

u8 LG_u8ScoreLedIdentifiers[LEDS_FOR_SCORE]   = {P2_4_LED1,    P1_0_LED2,    P1_1_LED3,    P1_2_LED4,    P1_3_LED5,    P3_2_LED6};
u16*  LG_pu16ScoreLedPorts[LEDS_FOR_SCORE]    = {(u16*)0x0029, (u16*)0x0021, (u16*)0x0021, (u16*)0x0021, (u16*)0x0021, (u16*)0x0019};
LedInformation LG_aLedInfoScoreLeds[LEDS_FOR_SCORE] = {{(u16*)0x0029, P2_4_LED1},
                                                       {(u16*)0x0021, P1_0_LED2},
                                                       {(u16*)0x0021, P1_1_LED3},
                                                       {(u16*)0x0021, P1_2_LED4},
                                                       {(u16*)0x0021, P1_3_LED5},
                                                       {(u16*)0x0019, P3_2_LED6}};
//This is so that the campers will have a simpler name to use
#define scoreLeds LG_aLedInfoScoreLeds

u8 LG_u8LifeLedIdentifiers[LEDS_FOR_LIVES]   = {P3_1_LED7,    P3_0_LED8,    P2_2_LED9};
u16*  LG_pu16LifeLedPorts[LEDS_FOR_LIVES]    = {(u16*)0x0019, (u16*)0x0019, (u16*)0x0029};
LedInformation LG_aLedInfoLifeLeds[LEDS_FOR_LIVES] = {{(u16*)0x0019, P3_1_LED7},
                                                      {(u16*)0x0019, P3_0_LED8},
                                                      {(u16*)0x0029, P2_2_LED9}};
//This is so that the campers will have a simpler name to use
#define lifeLeds LG_aLedInfoLifeLeds

u8  LG_u8ActiveIndex  = 0;


/******************** Function Definitions ************************/
/*------------------------------------------------------------------------------
Function: TestBlink

Description:
Non-returning brute force function to blink LED
Speed depends on clock and delay cycles in the loop.
 
Requires:
  - Active-high LED on Port 1 with the label defined as LED2 

Promises:
  - Port 1 LED pin toggled at x Hz, thus an LED will blink at x/2 Hz.
*/
void TestBlink()
{
/* A quick test function to blink the LEDs with brute force at x Hz */
	while(1)
  {
	  for(u16 i = 5000; i != 0; i--); 	/* 6 cycle loop */
    P1OUT ^= P1_0_LED2; 	/* Takes 5 instruction cycles */	
	} 
} /* end TestBlink */


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

void gameOver()
{
  CounterStateMachine = CounterSM_GameOver;
}
  

/****************************************************************************************
State Machine Functions
****************************************************************************************/
void CounterSM_Initialize()
{
  /* Reset key variables */
  u16GlobalCurrentSleepInterval = TIME_MAX;
    
  /* Allow a button interrupt and timer to wake up sleep */
  P2IFG &= ~P2_0_LOSELIFE;
  P2IE |= P2_0_LOSELIFE;	
  P2IFG &= ~P2_1_SCORE;
  P2IE |= P2_1_SCORE;	
  P2IFG &= ~P2_6_BUTTON_1;
  P2IE |= P2_6_BUTTON_1;	
  P2IFG &= ~P2_7_BUTTON_0;
  P2IE |= P2_7_BUTTON_0;	
  TACTL = TIMERA_INT_ENABLE;
  
  P1DIR |= P1_0_LED2;
  P1DIR |= P1_1_LED3;
  P1DIR |= P1_2_LED4;
  P1DIR |= P1_3_LED5;
  
  P2DIR &= ~P2_0_LOSELIFE;
  P2DIR &= ~P2_1_SCORE;
  P2DIR |= P2_2_LED9;
  P2DIR |= P2_3_RGB_RED;
  P2DIR |= P2_4_LED1;
  P2DIR &= ~P2_5_SPARE;
  P2DIR &= ~P2_6_BUTTON_1;
  P2DIR &= ~P2_7_BUTTON_0;
  
  P3DIR |= P3_0_LED8;
  P3DIR |= P3_1_LED7;
  P3DIR |= P3_2_LED6;
  P3DIR |= P3_3_BUZZER_1;
  P3DIR |= P3_6_RGB_BLU;
  P3DIR |= P3_7_RGB_BLU;
       
  CounterStateMachine = CounterSM_TestState;
  
} /* end CounterSM_Initialize */

/*----------------------------------------------------------------------------*/
void CounterSM_GameOver()
{
  turnAllScoreLedsOff();
  /* Sleep for max time (or could disable sleep timer interrupt */
  u16GlobalCurrentSleepInterval = TIME_MAX;
  CounterStateMachine = CounterSM_Sleep;
    
} /* end CounterSM_GameOver() */


/*----------------------------------------------------------------------------*/
void CounterSM_ScorePostTouched()
{
  incrementScoreByOne();
  /* Sleep for max time (or could disable sleep timer interrupt */
  u16GlobalCurrentSleepInterval = TIME_MAX;
  CounterStateMachine = CounterSM_Sleep;

    
} /* end CounterSM_ScorePostTouched() */

/*----------------------------------------------------------------------------*/
void CounterSM_LoseLifePostTouched()
{
  
}
 
/*----------------------------------------------------------------------------*/
void CounterSM_Idle()
{
  
  
  

  CounterStateMachine = CounterSM_Sleep;
  
} /* end CounterSM_Idle() */


#if 0
/*----------------------------------------------------------------------------*/
void BlinkSM_ButtonCheck()
{
#if 0
  /* Check for button press / hold */
  SetTimer(TIME_3S);
  while( !(P1IN & P1_0_BUTTON) && !(TACTL & TAIFG) )
  {
    P2OUT |= P2_2_LED4;
  } 

  if( !(P1IN & P1_0_BUTTON) && (TACTL & TAIFG) )
  {
    BlinkStateMachine = BlinkSM_Clockwise;
  } 
  else
  {
    P2OUT &= ~P2_2_LED4;
    BlinkStateMachine = BlinkSM_Sleep;
  }
#endif
  
} /* end BlinkSM_ButtonCheck */
#endif

/*----------------------------------------------------------------------------*/
void CounterSM_Sleep()
{
  /* Update to the current sleep interval and re-enable the timer interrupt */
  SetTimer(u16GlobalCurrentSleepInterval);
  TACTL = TIMERA_INT_ENABLE;
    
  /* Enter low power mode */
  __bis_SR_register(CPUOFF);
     
  /* Wake up (timer interrupt is off now from ISR) and go to next state */
  CounterStateMachine = G_fCurrentStateMachine;

} /* end CounterSM_Sleep */

void CounterSM_ResetButtonPressed()
{
  turnAllScoreLedsOff();
  turnAllLifeLedsOn();
  CounterStateMachine = CounterSM_Sleep;
}

void CounterSM_TestState()
{
  while(1)
  {
    LedOn(LG_aLedInfoLifeLeds[2]);
    if(isLedOn(LG_aLedInfoScoreLeds[0]))
    {
      LedOn(LG_aLedInfoScoreLeds[2]);
      LedOff(LG_aLedInfoScoreLeds[3]);
    }
    else
    {
      LedOff(LG_aLedInfoScoreLeds[2]);
      LedOn(LG_aLedInfoScoreLeds[3]);
    }
  }
}

void CounterSM_SpareButtonPressed()
{
  manageSpareButtonPress();
  CounterStateMachine = CounterSM_Sleep;
}














/*-----------------------------------------------------------------------------

HERE BEGINS THE CODE THAT THE CAMPERS WILL WRITE.
The campers will implement each of these functions and then bring it to the leader to be inspected and run on the board.
Solutions are provided here. The functions they will need to know about are as follows:

-void LedOff(LedInformation LedInfo)                     This function turns off the LED you pass in as an argument
-void LedOn(LedInformation LedInfo)                      This function turns on the LED you pass in as an argument
-bool isLedOff(LedInformation LedInfo)                   This function returns true (1) if the LED you pass in as an argument is off
-bool isLedOn(LedInformation LedInfo)                    This function returns false (0) if the LED you pass in as an argument is on
-void gameOver()                                         This function should be called if the game has ended

They will also need to know about these two arrays:

-LedInformation LG_u8ScoreLeds[LEDS_FOR_SCORE]           This array contains the six LEDS used to keep track of score. The LED at index zero is the rightmost, the LED at index five is the leftmost.
-LedInformation LG_u8LifeLeds[LEDS_FOR_LIVES]             This array contains the three LEDS used to keep track of lives. The LED at index zero is the leftmost, the LED at index two is the rightmost.

-----------------------------------------------------------------------------*/




void turnAllScoreLedsOff()
{
  for(int i = 0; i < LEDS_FOR_SCORE; i++)
  {
    LedOff(LG_aLedInfoScoreLeds[i]);
  }
}

void turnAllLifeLedsOn()
{
  for(int i = 0; i < LEDS_FOR_LIVES; i++)
  {
    LedOn(LG_aLedInfoLifeLeds[i]);
  }
}

void decrementLivesByOne()
{
  for(int i = 0; i < LEDS_FOR_LIVES; i++)
  {
    if(isLedOn(LG_aLedInfoLifeLeds[i]))
    {
      LedOff(LG_aLedInfoLifeLeds[i]);
      return;
    }
  }
  gameOver();
}

void incrementScoreByOne()
{
  for(int i = 0; i < LEDS_FOR_SCORE; i++)
  {
    if(isLedOff(LG_aLedInfoScoreLeds[i]))
    {
      LedOn(LG_aLedInfoScoreLeds[i]);
      return;
    }
    else
    {
      LedOff(LG_aLedInfoScoreLeds[i]);
    }
  }
}

void manageSpareButtonPress()
{
  //The campers can put anything they want here!
}