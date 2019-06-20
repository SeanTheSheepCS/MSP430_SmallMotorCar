/**********************************************************************
* Header file for Small Motor Car
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2013-11-21  Port from ANT key fob.
2019-06-05  Binary counter scoreboard first attempt
2019-06-12  Small motor car first attempt

************************************************************************/

#ifndef __SMALL_CAR_HEADER
#define __SMALL_CAR_HEADER

#include "typedef_MSP430.h"

/****************************************************************************************
Constants
****************************************************************************************/

#define NUMBER_OF_LEDS      (u8)5
#define NUMBER_OF_MOTORS    (u8)2
#define NUMBER_OF_RECIEVERS (u8)3
#define NUMBER_OF_EMITTERS  (u8)3

#define HOW_LONG_TO_WAIT_BETWEEN_TRANSMIT_AND_RECIEVE_MS (u32)100

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

/****************************************************************************************
Constants
****************************************************************************************/

typedef enum {LEFT_SIDE = 0, RIGHT_SIDE = 1, CENTER_SIDE = 2} SidesOfTheCarType;

/****************************************************************************************
Hardware Definitions
****************************************************************************************/
/* Port 1 pins */
#define P1_0_LEFT_MOTOR_POS_INPUT   0x01
#define P1_1_RIGHT_MOTOR_NEG_INPUT  0x02
#define P1_2_RIGHT_MOTOR_POS_INPUT  0x04
#define P1_3_BUZZER                 0x08
#define P1_4_                       0x10
#define P1_5_                       0x20
#define P1_6_                       0x40
#define P1_7_                       0x80

/* Port 2 pins */
#define P2_0_CENTER_EMITTER         0x01
#define P2_1_LEFT_EMITTER           0x02
#define P2_2_CENTER_LED_RED_INPUT   0x04
#define P2_3_LEFT_RECIEVER_SIGNAL   0x08
#define P2_4_LEFT_MOTOR_NEG_INPUT   0x10
#define P2_5_TAILLIGHTS_LEDS        0x20
#define P2_6_EXTRA_INPUT_ONE        0x40
#define P2_7_EXTRA_INPUT_TWO        0x80


/* Port 3 pins */
#define P3_0_CENTER_LED_GREEN_INPUT 0x01
#define P3_1_CENTER_LED_BLUE_INPUT  0x02
#define P3_2_HEADLIGHTS_LEDS        0x04
#define P3_3_RIGHT_EMITTER          0x08
#define P3_4_                       0x10
#define P3_5_                       0x20
#define P3_6_RIGHT_RECIEVER_SIGNAL  0x40
#define P3_7_CENTER_RECIEVER_SIGNAL 0x80

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

bool IsObstaclePresent(SidesOfTheCarType sotctSideToCheckForObstacle);
/****************************************************************************************
State Machine Functions
****************************************************************************************/
void CarSM_Idle(void);                     /* The state the counter enters if nothing of note has recently happened */
void CarSM_Initialize(void);
void CarSM_Sleep(void);                    /* Determines which mode of sleep to enter and sleep */

#endif /* __CAR_HEADER */
