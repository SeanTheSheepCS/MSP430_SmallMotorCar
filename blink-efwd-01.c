/**********************************************************************
* Supporting functions for LED Blinker
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2013-09-14  First release. 

************************************************************************/

#include "io430.h"
#include "typedef_MSP430.h"
#include "intrinsics.h"
#include "blink-efwd-01.h"
#include "main.h"

/******************** External Globals ************************/
/* Globally available variables from other files as indicated */


/******************** Program Globals ************************/
/* Global variable definitions intended for scope across multiple files */
fnCode_type BlinkStateMachine = BlinkSM_Initialize;   /* The application state machine */
fnCode_type G_fCurrentStateMachine = BlinkSM_Off;  
fnCode_type G_pfPatterns[] = {BlinkSM_Off, ClockwiseSetup, BlinkSM_Pulse, BlinkSM_On};
volatile u8 G_u8ActivePattern = 0;                    /* Active LED pattern */
 

volatile u16 u16GlobalRuntimeFlags = 0;               /* Flag register for communicating various runtime events. */
volatile u16 u16GlobalErrorFlags = 0;                 /* Flag register for communicating errors. */

volatile u16 u16GlobalCurrentSleepInterval;           /* Duration that the device will sleep */
//volatile u16 u16GlobalSleepCounter;                   /* Active sleep cycle counter */



/******************** Local Globals ************************/
/* Global variable definitions intended only for the scope of this file */
u8 LG_u8Leds[]                    = {P1_2_LED1,    P1_1_LED5,    P3_6_LED2,    P3_2_LED6,    P3_1_LED3,    P3_0_LED7,    P2_2_LED4,    P1_3_LED8};
u16*  LG_pu16LedPorts[TOTAL_LEDS] = {(u16*)0x0021, (u16*)0x0021, (u16*)0x0019, (u16*)0x0019, (u16*)0x0019, (u16*)0x0019, (u16*)0x0029, (u16*)0x0021};

//u8 LG_u8Leds[]                    = {P1_2_LED1,    P3_6_LED2,    P3_1_LED3,    P2_2_LED4,    P1_1_LED5,    P3_2_LED6,    P3_0_LED7,    P1_3_LED8};
//u16*  LG_pu16LedPorts[TOTAL_LEDS] = {(u16*)0x0021, (u16*)0x0019, (u16*)0x0019, (u16*)0x0029, (u16*)0x0021, (u16*)0x0019, (u16*)0x0019, (u16*)0x0021};
u8  LG_u8ActiveIndex  = 0;


/******************** Function Definitions ************************/
/*------------------------------------------------------------------------------
Function: TestBlink

Description:
Non-returning brute force function to blink LED
Speed depends on clock and delay cycles in the loop.
 
Requires:
  - Active-high LED on Port 1 with the label defined as LED1 

Promises:
  - Port 1 LED pin toggled at x Hz, thus an LED will blink at x/2 Hz.
*/
void TestBlink()
{
/* A quick test function to blink the LEDs with brute force at x Hz */
	while(1)
  {
	  for(u16 i = 5000; i != 0; i--); 	/* 6 cycle loop */
    P2OUT ^= P2_2_LED4; 	/* Takes 5 instruction cycles */	
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
  

/****************************************************************************************
State Machine Functions
****************************************************************************************/
void BlinkSM_Initialize()
{
  /* Reset key variables */
  u16GlobalCurrentSleepInterval = TIME_MAX;
    
  /* Allow a button interrupt and timer to wake up sleep */
  P1IFG &= ~P1_0_BUTTON;
  P1IE |= P1_0_BUTTON;				
  TACTL = TIMERA_INT_ENABLE;
       
  BlinkStateMachine = BlinkSM_Sleep;
  
} /* end BlinkSM_Initialize */


/*----------------------------------------------------------------------------*/
void ClockwiseSetup()
{
  P1OUT &= ~(P1_2_LED1 | P1_1_LED5 | P1_3_LED8);
  P2OUT &= ~(P2_2_LED4);
  P3OUT &= ~(P3_0_LED7 | P3_1_LED3 | P3_2_LED6 | P3_6_LED2);
  
  LG_u8ActiveIndex = 0;
  u16GlobalCurrentSleepInterval = TIME_125MS;
  G_fCurrentStateMachine = BlinkSM_Clockwise;
  BlinkStateMachine = BlinkSM_Clockwise; 

} /* end ClockwiseSetup() */

  
/*----------------------------------------------------------------------------*/
void BlinkSM_Clockwise()
{
  for(u8 i = 0; i < TOTAL_LEDS; i++)
  {
    /* Turn the current active light on */
    if(i == LG_u8ActiveIndex)
    {
      *LG_pu16LedPorts[i] |= LG_u8Leds[i];
    }
    /* Otherwise turn the LED off */
    else
    {
      *LG_pu16LedPorts[i] &= ~LG_u8Leds[i];
    }
  }
  
  /* Increment and wrap the index pointer */
  LG_u8ActiveIndex++;
  if(LG_u8ActiveIndex == TOTAL_LEDS)
  {
    LG_u8ActiveIndex = 0;
  }
  
  BlinkStateMachine = BlinkSM_Sleep;

    
} /* end BlinkSM_Clockwise() */


/*----------------------------------------------------------------------------*/
void BlinkSM_On()
{
  for(u8 i = 0; i < TOTAL_LEDS; i++)
  {
    *LG_pu16LedPorts[i] |= LG_u8Leds[i];
  }
  
  /* Sleep for max time (or could disable sleep timer interrupt */
  u16GlobalCurrentSleepInterval = TIME_MAX;
  BlinkStateMachine = BlinkSM_Sleep;

    
} /* end BlinkSM_On() */


/*----------------------------------------------------------------------------*/
void BlinkSM_Off()
{
  for(u8 i = 0; i < TOTAL_LEDS; i++)
  {
    *LG_pu16LedPorts[i] &= ~LG_u8Leds[i];
  }
  
  /* Sleep for max time (or could disable sleep timer interrupt */
  u16GlobalCurrentSleepInterval = TIME_MAX;
  BlinkStateMachine = BlinkSM_Sleep;

    
} /* end BlinkSM_Off() */

 
/*----------------------------------------------------------------------------*/
void BlinkSM_Pulse()
{
  static bool bCurrentlyOn = FALSE;
  
  /* LEDs are on, so turn them off and sleep long */
  if(bCurrentlyOn)
  {
    for(u8 i = 0; i < TOTAL_LEDS; i++)
    {
      *LG_pu16LedPorts[i] &= ~LG_u8Leds[i];
    }
    bCurrentlyOn = FALSE;
    u16GlobalCurrentSleepInterval = TIME_3S;
  }
  /* LEDS are off, so turn them on and sleep short */
  else
  {
    for(u8 i = 0; i < TOTAL_LEDS; i++)
    {
      *LG_pu16LedPorts[i] |= LG_u8Leds[i];
    }
    bCurrentlyOn = TRUE;
    u16GlobalCurrentSleepInterval = TIME_125MS;
  }

  BlinkStateMachine = BlinkSM_Sleep;
  
} /* end BlinkSM_Pulse() */


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
void BlinkSM_Sleep()
{
  /* Update to the current sleep interval and re-enable the timer interrupt */
  SetTimer(u16GlobalCurrentSleepInterval);
  TACTL = TIMERA_INT_ENABLE;
    
  /* Enter low power mode */
  __bis_SR_register(CPUOFF);
     
  /* Wake up (timer interrupt is off now from ISR) and go to next state */
  BlinkStateMachine = G_fCurrentStateMachine;

} /* end BlinkSM_Sleep */

      