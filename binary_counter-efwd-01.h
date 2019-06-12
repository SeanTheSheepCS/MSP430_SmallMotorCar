/**********************************************************************
* Header file for LED Binary Counter
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2013-11-21  Port from ANT key fob.
2019-06-05  Binary counter scoreboard first attempt

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

#define LEDS_FOR_SCORE      (u8)6
#define LEDS_FOR_LIVES      (u8)3

#define SCORE_LED1                (u8)0
#define SCORE_LED2                (u8)1
#define SCORE_LED3                (u8)2
#define SCORE_LED4                (u8)3
#define SCORE_LED5                (u8)4
#define SCORE_LED6                (u8)5
#define LIFE_LED1                 (u8)6
#define LIFE_LED2                 (u8)7
#define LIFE_LED3                 (u8)8

/****************************************************************************************
Hardware Definitions
****************************************************************************************/
/* Port 1 pins */
#define P1_0_LED2                0x01
#define P1_1_LED3                0x02
#define P1_2_LED4                0x04
#define P1_3_LED5                0x08
#define P1_4_                    0x10
#define P1_5_                    0x20
#define P1_6_                    0x40
#define P1_7_                    0x80

/* Port 2 pins */
#define P2_0_LOSELIFE            0x01
#define P2_1_SCORE               0x02
#define P2_2_LED9                0x04
#define P2_3_RGB_RED             0x08
#define P2_4_LED1                0x10
#define P2_5_SPARE               0x20
#define P2_6_BUTTON_1            0x40
#define P2_7_BUTTON_0            0x80


/* Port 3 pins */
#define P3_0_LED8                0x01
#define P3_1_LED7                0x02
#define P3_2_LED6                0x04
#define P3_3_BUZZER_1            0x08
#define P3_4_                    0x10
#define P3_5_                    0x20
#define P3_6_RGB_BLU             0x40
#define P3_7_RGB_BLU             0x80

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
void CounterSM_Initialize();
void SetTimer(u16 u16Taccr0_);
void gameOver();

/****************** Functions For The Campers To Fill **********************/
void turnAllScoreLedsOff();
void turnAllLifeLedsOn();
void decrementLivesByOne();
void incrementScoreByOne();
void manageSpareButtonPress();

/****************************************************************************************
State Machine Functions
****************************************************************************************/
void CounterSM_GameOver();                 /* The state the counter enters if the gameover signal is a one */
void CounterSM_Score();                    /* The state the counter enters if the score signal is a one */
void CounterSM_Idle();                     /* The state the counter enters if nothing of note has recently happened */
void CounterSM_ResetButtonPressed();       /* The state the counter enters if the reset button is pressed */
void CounterSM_TestState();                /* Used for testing */
void CounterSM_SpareButtonPressed();       /* The state the counter enters if the spare button was pressed */

void CounterSM_Sleep();                    /* Determines which mode of sleep to enter and sleep */

#endif /* __BLINK_HEADER */
