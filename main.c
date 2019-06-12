/**********************************************************************
File name:	main.c

Main program file for Blinker 
A simple program to sequentially blink an array of 8 LEDs, where 
blinking pattern is selectable by button press.

When complete, the following modes will be available:
1. Off
2. All LEDs on (this will stress the battery!)
3. Random blinking
4. Cyclical blink

**********************************************************************/




/************************ Revision History ****************************
YYYY-MM-DD  Checksum  Comments
-------------------------------------------------------------------------------------------
2009-04-08            First release. 

************************************************************************/

#include "io430.h"
#include "typedef_MSP430.h"
#include "intrinsics.h"
#include "main.h"
#include "small_car-efwd-01.h"


/************************ External Program Globals ****************************/
/* Globally available variables from other files as indicated */
extern fnCode_type CounterStateMachine;                 /* From blink-efwd-01.c */
extern fnCode_type G_fCurrentStateMachine;            /* From blink-efwd-01.c */
extern fnCode_type G_pfPatterns[];                    /* From blink-efwd-01.c */
 

extern volatile u16 u16GlobalRuntimeFlags;            /* From blink-efwd-01.c */
extern volatile u16 u16GlobalErrorFlags;              /* From blink-efwd-01.c */

extern volatile u8 u8GlobalCurrentSleepInterval;      /* From blink-efwd-01.c */
extern volatile u8 G_u8ActivePattern;                 /* From blink-efwd-01.c */
extern fnCode_type LG_fPatterns[];                    /* From blink-efwd-01.c */


/************************ Program Globals ****************************/
/* Global variable definitions intended for scope of multiple files */


/************************ Main Program ****************************/
/* From cstartup.s43, the processor is running from the ACLK, TimerA is running, and I/O lines have been configured. */

int main(void)
{

  /* Enter the state machine where the program will remain unless power cycled */
  __bis_SR_register(GIE);

  while(1)
  {
	  CounterStateMachine();
  } 
  
} /* end main */


/************************ Interrupt Service Routines ****************************/
#pragma vector = PORT2_VECTOR
__interrupt void Port2ISR(void)
/* Handles waking up from low power mode via a button press and returns with processor awake */
{
  /* Debounce the button press for 10 ms -- not a great idea in an ISR but ok for a hack */
  /* 120 / 12,000 = 10 ms */
  for(u16 i = 0; i < 120; i++);
  
  /* If button is still down, consider it a valid press */
  if( !(P2IN & P2_0_LOSELIFE) )
  {
    G_fCurrentStateMachine = CounterSM_LoseLifePostTouched;
  }
  else if( !(P2IN & P2_1_SCORE) )
  {
    G_fCurrentStateMachine = CounterSM_ScorePostTouched;
  }
  else if( !(P2IN & P2_6_BUTTON_1) )
  {
    G_fCurrentStateMachine = CounterSM_ResetButtonPressed;
  }
  else if( !(P2IN & P2_7_BUTTON_0) )
  {
    G_fCurrentStateMachine = CounterSM_SpareButtonPressed;
  }
 
  /* Clear the flag, but keep the interrupt active */
  P2IFG &= ~P2_0_LOSELIFE;
  P2IFG &= ~P2_1_SCORE;
  P2IFG &= ~P2_6_BUTTON_1;
  P2IFG &= ~P2_7_BUTTON_0;
  
  //u8GlobalCurrentSleepInterval = SLEEP_TIME;
  //u8GlobalSleepCounter = 1;
  //TACTL = TIMERA_INT_DISABLE;
  asm("BIC #0x0010,4(SP)"); 
} /* end Port1ISR */


/*----------------------------------------------------------------------------*/
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TimerAISR(void)
{
/* Handles waking up from low power mode via TimerA expiration and returns with processor awake */
  
  //u8GlobalCurrentSleepInterval = SLEEP_TIME;
  TACTL = TIMERA_INT_DISABLE;
  asm("BIC #0x0010,0(SP)");
} // end timer_wakeup_isr

