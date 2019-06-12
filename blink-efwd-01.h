/**********************************************************************
* Header file for LED Blinker
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2013-11-21  Port from ANT key fob.

************************************************************************/

#ifndef __BLINK_HEADER
#define __BLINK_HEADER

/****************************************************************************************
Constants
****************************************************************************************/
/* Timing constants */
#define TIME_1MS            (u16)3     /* Taccro used to kill roughly 1ms */
#define TIME_10MS           (u16)30    /* Taccro used to kill roughly 10ms */
#define TIME_62MS           (u16)186   /* Taccro for 62.5ms period */
#define TIME_125MS          (u16)372   /* Taccro for 125ms period */
#define TIME_250MS          (u16)744   /* Taccro for 250ms period */
#define TIME_500MS          (u16)1488  /* Taccro for 500ms period */
#define TIME_1S             (u16)2976  /* Taccro for 1 second period */
#define TIME_3S             (u16)8928  /* Taccro for 3 second period */
#define TIME_7S             (u16)20832 /* Taccro for 7 second period */
#define TIME_MAX            (u16)65535 /* Taccro for max second period */

#define TOTAL_LEDS          (u8)8
#define TOTAL_PATTERNS      (u8)4


/****************************************************************************************
Hardware Definitions
****************************************************************************************/
/* Port 1 pins */
#define P1_0_BUTTON              0x01
#define P1_1_LED5                0x02
#define P1_2_LED1                0x04
#define P1_3_LED8                0x08
#define P1_4_                    0x10
#define P1_5_                    0x20
#define P1_6_                    0x40
#define P1_7_                    0x80

/* Port 2 pins */
#define P2_0_ACLK                0x01
#define P2_1_SMCLK               0x02
#define P2_2_LED4                0x04
#define P2_3_TP7                 0x08
#define P2_4_TP8                 0x10
#define P2_5_TICK                0x20
#define P2_6_TP4                 0x40
#define P2_7_TP3                 0x80


/* Port 3 pins */
#define P3_0_LED7                0x01
#define P3_1_LED3                0x02
#define P3_2_LED6                0x04
#define P3_3_TP5                 0x08
#define P3_4_                    0x10
#define P3_5_                    0x20
#define P3_6_LED2                0x40
#define P3_7_TP6                 0x80

/* Setup constants */
#define TIMERA_INT_ENABLE  0x0196
/* Value for TACTL to set up Timer A to be running with the interrupt enabled:
    <15-10> [000000] not used
    <9-8> [01] ACLK Timer A clock source
    <7-6> [10] Input divider /8
    <5-4> [01] Up mode
    <3> [0] not used
    <2> [1] Reset the timer module
    <1> [1] Enable the timer interrupt
    <0> [0] Clear the interrupt flag
*/

#define TIMERA_INT_DISABLE  0x0194	
/* Value for TACTL to set up Timer A to be running with the interrupt disabled:
    <15-10> [000000] not used
    <9-8> [01] ACLK Timer A clock source
    <7-6> [10] Input divider /4
    <5-4> [01] Up mode
    <3> [0] not used
    <2> [1] Reset the timer module
    <1> [0] Disable the timer interrupt
    <0> [0] Clear the interrupt flag
*/


/************************ Function Declarations ****************************/
void BlinkSM_Initialize();

void TestBlink();
void SetTimer(u16 u16Taccr0_);
void ClockwiseSetup();


/****************************************************************************************
State Machine Functions
****************************************************************************************/
void BlinkSM_Clockwise();                /* Clockwise sequential blinking of LEDs (100ms each), 3 second pause */
void BlinkSM_Pulse();                    /* All leds blink 100ms every 5 seconds */
void BlinkSM_On();                       /* All leds on */
void BlinkSM_Off();                      /* All leds blink 100ms every 5 seconds */

//void BlinkSM_ButtonCheck();              /* Check if button is pressed and held to trigger mode change */
void BlinkSM_Sleep();                    /* Determines which mode of sleep to enter and sleep */

#endif /* __BLINK_HEADER */
