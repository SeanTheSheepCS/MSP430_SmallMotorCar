/**********************************************************************
File name:	main.c

Main program file for the car 

**********************************************************************/




/************************ Revision History ****************************
YYYY-MM-DD  Checksum  Comments
-------------------------------------------------------------------------------------------
2009-04-08            First release. 
2019-06-28            Documentation updated
************************************************************************/

#include "small_car-efwd-01.h"
#include "io430.h"
#include "typedef_MSP430.h"
#include "intrinsics.h"
#include "main.h"



/************************ External Program Globals ****************************/
/* Globally available variables from other files as indicated */
extern fnCode_type CarStateMachine;                 /* From blink-efwd-01.c */
extern fnCode_type G_fCurrentStateMachine;            /* From blink-efwd-01.c */
extern fnCode_type G_pfPatterns[];                    /* From blink-efwd-01.c */
 

extern volatile u16 u16GlobalRuntimeFlags;            /* From blink-efwd-01.c */
extern volatile u16 u16GlobalErrorFlags;              /* From blink-efwd-01.c */

extern volatile u8 u8GlobalCurrentSleepInterval;      /* From blink-efwd-01.c */


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
	  CarStateMachine();
  } 
  
} /* end main */


/************************ Interrupt Service Routines ****************************/




/*----------------------------------------------------------------------------*/
#pragma vector = TIMER0_A1_VECTOR
__interrupt void TimerAISR(void)
{
/* Handles waking up from low power mode via TimerA expiration and returns with processor awake */
  
  //u8GlobalCurrentSleepInterval = SLEEP_TIME;
  TACTL = TIMERA_INT_DISABLE;
  asm("BIC #0x0010,0(SP)");
} // end timer_wakeup_isr


#pragma vector = ADC10_VECTOR
__interrupt void adc10_interrupt(void)
{
    
}