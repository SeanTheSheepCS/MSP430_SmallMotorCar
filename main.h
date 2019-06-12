/**********************************************************************
* Header file for ANT Library
* Author:	   Jason Long
**********************************************************************/


/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2010-01-08  Add new defines for FCC_TX and RX Test
2009-11-11  File created for GEN II Key Fob

************************************************************************/

#ifndef __MAIN
#define __MAIN

/* Test modes available (intended to use only one at a time).  Released code should have all of these commented out */
//#define	LED_TEST		          1   /* Simple LED blink test */
//#define	CW_TEST			          1   /* CW mode with frequency scroll through low, mid, high channels on button press */
//#define STARTUP_TEST          1   /* Intended with battery disconnect board to repeatedly run start ups and count ANT comm failures */
//#define ANT_COMMS_TEST        1   /* Repeated test of ANT communications */
//#define BAT_LIFE_TEST         1   /* Checks battery every cycle */
//#define PLAIN_TEXT_MESSAGES   1   /* Takes off encryption of messages */
//#define FCC_TX_TEST           1   /* FCC test mode with constant messages at about 1ms; 1Hz blink */
//#define FCC_RX_TEST           1   /* FCC test mode with receive channel open forever.  4Hz blink.  Builds with 1 warning for unreachable statement */


/************************ Function Declarations ****************************/
#pragma vector = PORT1_VECTOR
__interrupt void Port1ISR(void);
/*
Handles waking up from low power mode via a button press.
This triggers a reset of the sleep interval to SHORT_SLEEP_TIME and sets the sleep
counter to ensure the current sleep loop is exitted on return.
Returns with the processor awake.
*/


#pragma vector = PORT2_VECTOR
__interrupt void Port2ISR(void);
/*
Handles waking up from low power mode via motion.
This triggers a reset of the sleep interval to SHORT_SLEEP_TIME and sets the sleep
counter to ensure the current sleep loop is exitted on return.
Returns with the processor awake.
*/


#pragma vector = TIMER0_A1_VECTOR
__interrupt void TimerAISR(void);
/*
Handles waking up from low power mode via TimerA.
The timer interrupt is disabled.
Returns with the processor awake.
*/


#if 0
#pragma vector = USCIAB0RX_VECTOR
__interrupt void SPIRxISR(void);
/*
Handles waking up from a received byte on the SPI module.
The byte is copied to ucGlobalSPIRxByte which clears the interrupt flag.
Returns with the processor awake.
*/


#pragma vector = USCIAB0TX_VECTOR
__interrupt void SPITxISR(void);
/*
Handles waking up from a received byte on the SPI module.
Clears UCA0TXIFG.
Returns with the processor awake.
*/
#endif /* SPI interrupts */

#endif /* __MAIN */
