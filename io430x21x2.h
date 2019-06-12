
/********************************************************************
 *
 * Standard register and bit definitions for the Texas Instruments
 * MSP430 microcontroller.
 *
 * This file supports assembler and C/EC++ development for
 * MSP430x21x2 devices.
 *
 * Copyright 1996-2008 IAR Systems. All rights reserved.
 *
 * $Revision: 4349 $
 *
 ********************************************************************/

#ifndef __IO430X21X2
#define __IO430X21X2

#ifdef  __IAR_SYSTEMS_ICC__
#ifndef _SYSTEM_BUILD
#pragma system_include
#endif
#endif

#if (((__TID__ >> 8) & 0x7F) != 0x2b)     /* 0x2b = 43 dec */
#error io430x21x2.h file for use with ICC430/A430 only
#endif

 
#ifdef __IAR_SYSTEMS_ICC__
#pragma language=extended
#pragma system_include

#ifdef __cplusplus
#define __READ    /* not supported */
#else
#define __READ    const
#endif


/*-------------------------------------------------------------------------
 *   Standard Bits
 *-------------------------------------------------------------------------*/

#define BIT0                (0x0001)
#define BIT1                (0x0002)
#define BIT2                (0x0004)
#define BIT3                (0x0008)
#define BIT4                (0x0010)
#define BIT5                (0x0020)
#define BIT6                (0x0040)
#define BIT7                (0x0080)
#define BIT8                (0x0100)
#define BIT9                (0x0200)
#define BITA                (0x0400)
#define BITB                (0x0800)
#define BITC                (0x1000)
#define BITD                (0x2000)
#define BITE                (0x4000)
#define BITF                (0x8000)

/*-------------------------------------------------------------------------
 *   Status register bits
 *-------------------------------------------------------------------------*/

#define C                   (0x0001)
#define Z                   (0x0002)
#define N                   (0x0004)
#define V                   (0x0100)
#define GIE                 (0x0008)
#define CPUOFF              (0x0010)
#define OSCOFF              (0x0020)
#define SCG0                (0x0040)
#define SCG1                (0x0080)

/* Low Power Modes coded with Bits 4-7 in SR */

#define LPM0_bits           (CPUOFF)
#define LPM1_bits           (SCG0+CPUOFF)
#define LPM2_bits           (SCG1+CPUOFF)
#define LPM3_bits           (SCG1+SCG0+CPUOFF)
#define LPM4_bits           (SCG1+SCG0+OSCOFF+CPUOFF)


#define LPM0      _BIS_SR(LPM0_bits)     /* Enter Low Power Mode 0 */
#define LPM0_EXIT _BIC_SR_IRQ(LPM0_bits) /* Exit Low Power Mode 0 */
#define LPM1      _BIS_SR(LPM1_bits)     /* Enter Low Power Mode 1 */
#define LPM1_EXIT _BIC_SR_IRQ(LPM1_bits) /* Exit Low Power Mode 1 */
#define LPM2      _BIS_SR(LPM2_bits)     /* Enter Low Power Mode 2 */
#define LPM2_EXIT _BIC_SR_IRQ(LPM2_bits) /* Exit Low Power Mode 2 */
#define LPM3      _BIS_SR(LPM3_bits)     /* Enter Low Power Mode 3 */
#define LPM3_EXIT _BIC_SR_IRQ(LPM3_bits) /* Exit Low Power Mode 3 */
#define LPM4      _BIS_SR(LPM4_bits)     /* Enter Low Power Mode 4 */
#define LPM4_EXIT _BIC_SR_IRQ(LPM4_bits) /* Exit Low Power Mode 4 */



/*-------------------------------------------------------------------------
 *   Special Function
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char IE1;  /* Interrupt Enable 1 */ 
  
  struct
  {
    unsigned char WDTIE          : 1;  /* Watchdog Interrupt Enable */ 
    unsigned char OFIE           : 1;  /* Osc. Fault  Interrupt Ena */ 
    unsigned char                : 2; 
    unsigned char NMIIE          : 1;  /* NMI Interrupt Enable */ 
    unsigned char ACCVIE         : 1;  /* Flash Access Violation Interrupt Enable */ 
  } IE1_bit;  
} @ 0x0000;


enum {
  WDTIE               = 0x0001,
  OFIE                = 0x0002,
  NMIIE               = 0x0010,
  ACCVIE              = 0x0020,
};


__no_init volatile union
{
  unsigned char IFG1;  /* Interrupt Flag 1 */ 
  
  struct
  {
    unsigned char WDTIFG         : 1;  /* Watchdog Interrupt Flag */ 
    unsigned char OFIFG          : 1;  /* Osc. Fault Interrupt Flag */ 
    unsigned char PORIFG         : 1;  /* Power On Interrupt Flag */ 
    unsigned char RSTIFG         : 1;  /* Reset Interrupt Flag */ 
    unsigned char NMIIFG         : 1;  /* Watchdog Interrupt Enable */ 
  } IFG1_bit;  
} @ 0x0002;


enum {
  WDTIFG              = 0x0001,
  OFIFG               = 0x0002,
  PORIFG              = 0x0004,
  RSTIFG              = 0x0008,
  NMIIFG              = 0x0010,
};


__no_init volatile union
{
  unsigned char IE2;  /* Interrupt Enable 2 */ 
  
  struct
  {
    unsigned char UCA0RXIE       : 1; 
    unsigned char UCA0TXIE       : 1; 
    unsigned char UCB0RXIE       : 1; 
    unsigned char UCB0TXIE       : 1; 
  } IE2_bit;  
} @ 0x0001;


enum {
  UCA0RXIE            = 0x0001,
  UCA0TXIE            = 0x0002,
  UCB0RXIE            = 0x0004,
  UCB0TXIE            = 0x0008,
};


__no_init volatile union
{
  unsigned char IFG2;  /* Interrupt Flag 2 */ 
  
  struct
  {
    unsigned char UCA0RXIFG      : 1; 
    unsigned char UCA0TXIFG      : 1; 
    unsigned char UCB0RXIFG      : 1; 
    unsigned char UCB0TXIFG      : 1; 
  } IFG2_bit;  
} @ 0x0003;


enum {
  UCA0RXIFG           = 0x0001,
  UCA0TXIFG           = 0x0002,
  UCB0RXIFG           = 0x0004,
  UCB0TXIFG           = 0x0008,
};



/*-------------------------------------------------------------------------
 *   ADC10
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char ADC10DTC0;  /* ADC10 Data Transfer Control 0 */ 
  
  struct
  {
    unsigned char ADC10FETCH     : 1; 
    unsigned char ADC10B1        : 1; 
    unsigned char ADC10CT        : 1; 
    unsigned char ADC10TB        : 1; 
  } ADC10DTC0_bit;  
} @ 0x0048;


enum {
  ADC10FETCH          = 0x0001,
  ADC10B1             = 0x0002,
  ADC10CT             = 0x0004,
  ADC10TB             = 0x0008,
};


 /* ADC10 Data Transfer Control 1 */ 
__no_init volatile unsigned char ADC10DTC1 @ 0x0049;  
 

 /* ADC10 Analog Enable 0 */ 
__no_init volatile unsigned char ADC10AE0 @ 0x004A;  
 

 /* ADC10 Analog Enable 1 */ 
__no_init volatile unsigned char ADC10AE1 @ 0x004B;  
 

__no_init volatile union
{
  unsigned short ADC10CTL0;  /* ADC10 Control 0 */ 
  
  struct
  {
    unsigned short ADC10SC       : 1;  /* ADC10 Start Conversion */ 
    unsigned short ENC           : 1;  /* ADC10 Enable Conversion */ 
    unsigned short ADC10IFG      : 1;  /* ADC10 Interrupt Flag */ 
    unsigned short ADC10IE       : 1;  /* ADC10 Interrupt Enalbe */ 
    unsigned short ADC10ON       : 1;  /* ADC10 On/Enable */ 
    unsigned short REFON         : 1;  /* ADC10 Reference on */ 
    unsigned short REF2_5V       : 1;  /* ADC10 Ref 0:1.5V / 1:2.5V */ 
    unsigned short MSC           : 1;  /* ADC10 Multiple SampleConversion */ 
    unsigned short REFBURST      : 1;  /* ADC10 Reference Burst Mode */ 
    unsigned short REFOUT        : 1;  /* ADC10 Enalbe output of Ref. */ 
    unsigned short ADC10SR       : 1;  /* ADC10 Sampling Rate 0:200ksps / 1:50ksps */ 
    unsigned short ADC10SHT      : 2;  /* ADC10 Sample Hold Select */ 
    unsigned short ADC10SREF     : 3;  /* ADC10 Reference Select */ 
  } ADC10CTL0_bit;  
} @ 0x01B0;


enum {
  ADC10SC             = 0x0001,
  ENC                 = 0x0002,
  ADC10IFG            = 0x0004,
  ADC10IE             = 0x0008,
  ADC10ON             = 0x0010,
  REFON               = 0x0020,
  REF2_5V             = 0x0040,
  MSC                 = 0x0080,
  REFBURST            = 0x0100,
  REFOUT              = 0x0200,
  ADC10SR             = 0x0400,
  ADC10SHT            = 0x1000,
  ADC10SREF           = 0x8000,
};


__no_init volatile union
{
  unsigned short ADC10CTL1;  /* ADC10 Control 1 */ 
  
  struct
  {
    unsigned short ADC10BUSY     : 1;  /*  */ 
    unsigned short ADC10CONSEQ   : 2;  /* ADC10 Conversion Sequence Select */ 
    unsigned short ADC10SSEL     : 2;  /* ADC10 Clock Source Select */ 
    unsigned short ADC10DIV      : 3;  /* ADC10 Clock Divider Select */ 
    unsigned short ISSH          : 1;  /* ADC10 Invert Sample Hold Signal */ 
    unsigned short ADC10DF       : 1;  /* ADC10 Data Format 0:binary 1:2's complement */ 
    unsigned short SHS           : 2;  /* ADC10 Sample/Hold Source */ 
    unsigned short INCH          : 4;  /* ADC10 Input Channel Select */ 
  } ADC10CTL1_bit;  
} @ 0x01B2;


enum {
  ADC10BUSY           = 0x0001,
  ADC10CONSEQ         = 0x0004,
  ADC10SSEL           = 0x0010,
  ADC10DIV            = 0x0080,
  ISSH                = 0x0100,
  ADC10DF             = 0x0200,
  SHS                 = 0x0800,
  INCH                = 0x8000,
};


 /* DC10 Memory */ 
__no_init volatile unsigned short ADC10MEM @ 0x01B4;  
 

 /* ADC10 Data Transfer Start Address */ 
__no_init volatile unsigned short ADC10SA @ 0x01BC;  
 
 
#define __MSP430_HAS_ADC10__         /* Definition to show that Module is available */
#define ADC10DISABLE    (0x000)      /* ADC10DTC1 */
#define ADC10SHT_0      (0*0x800u)   /* 4 x ADC10CLKs */
#define ADC10SHT_1      (1*0x800u)   /* 8 x ADC10CLKs */
#define ADC10SHT_2      (2*0x800u)   /* 16 x ADC10CLKs */
#define ADC10SHT_3      (3*0x800u)   /* 64 x ADC10CLKs */

#define SREF_0          (0*0x2000u)  /* VR+ = AVCC and VR- = AVSS */
#define SREF_1          (1*0x2000u)  /* VR+ = VREF+ and VR- = AVSS */
#define SREF_2          (2*0x2000u)  /* VR+ = VEREF+ and VR- = AVSS */
#define SREF_3          (3*0x2000u)  /* VR+ = VEREF+ and VR- = AVSS */
#define SREF_4          (4*0x2000u)  /* VR+ = AVCC and VR- = VREF-/VEREF- */
#define SREF_5          (5*0x2000u)  /* VR+ = VREF+ and VR- = VREF-/VEREF- */
#define SREF_6          (6*0x2000u)  /* VR+ = VEREF+ and VR- = VREF-/VEREF- */
#define SREF_7          (7*0x2000u)  /* VR+ = VEREF+ and VR- = VREF-/VEREF- */

#define CONSEQ_0        (0*2u)       /* Single channel single conversion */
#define CONSEQ_1        (1*2u)       /* Sequence of channels */
#define CONSEQ_2        (2*2u)       /* Repeat single channel */
#define CONSEQ_3        (3*2u)       /* Repeat sequence of channels */

#define ADC10SSEL_0     (0*8u)       /* ADC10OSC */
#define ADC10SSEL_1     (1*8u)       /* ACLK */
#define ADC10SSEL_2     (2*8u)       /* MCLK */
#define ADC10SSEL_3     (3*8u)       /* SMCLK */

#define ADC10DIV_0      (0*0x20u)
#define ADC10DIV_1      (1*0x20u)
#define ADC10DIV_2      (2*0x20u)
#define ADC10DIV_3      (3*0x20u)
#define ADC10DIV_4      (4*0x20u)
#define ADC10DIV_5      (5*0x20u)
#define ADC10DIV_6      (6*0x20u)
#define ADC10DIV_7      (7*0x20u)

#define SHS_0           (0*0x400u)   /* ADC10SC */
#define SHS_1           (1*0x400u)   /* TA3 OUT1 */
#define SHS_2           (2*0x400u)   /* TA3 OUT0 */
#define SHS_3           (3*0x400u)   /* TA3 OUT2 */

#define INCH_0          (0*0x1000u)
#define INCH_1          (1*0x1000u)
#define INCH_2          (2*0x1000u)
#define INCH_3          (3*0x1000u)
#define INCH_4          (4*0x1000u)
#define INCH_5          (5*0x1000u)
#define INCH_6          (6*0x1000u)
#define INCH_7          (7*0x1000u)
#define INCH_8          (8*0x1000u)
#define INCH_9          (9*0x1000u)
#define INCH_10         (10*0x1000u)
#define INCH_11         (11*0x1000u)
#define INCH_12         (12*0x1000u) /* Selects Channel 11 */
#define INCH_13         (13*0x1000u) /* Selects Channel 11 */
#define INCH_14         (14*0x1000u) /* Selects Channel 11 */
#define INCH_15         (15*0x1000u) /* Selects Channel 11 */

#define ADC10AE         ADC10AE0    /* ADC10 Analog Enable */


 

/*-------------------------------------------------------------------------
 *   Basic Clock Module
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char DCOCTL;  /* DCO Clock Frequency Control */ 
  
  struct
  {
    unsigned char MOD0           : 1;  /* Modulation Bit 0 */ 
    unsigned char MOD1           : 1;  /* Modulation Bit 1 */ 
    unsigned char MOD2           : 1;  /* Modulation Bit 2 */ 
    unsigned char MOD3           : 1;  /* Modulation Bit 3 */ 
    unsigned char MOD4           : 1;  /* Modulation Bit 4 */ 
    unsigned char DCO0           : 1;  /* DCO Select Bit 0 */ 
    unsigned char DCO1           : 1;  /* DCO Select Bit 1 */ 
    unsigned char DCO2           : 1;  /* DCO Select Bit 2 */ 
  } DCOCTL_bit;  
} @ 0x0056;


enum {
  MOD0                = 0x0001,
  MOD1                = 0x0002,
  MOD2                = 0x0004,
  MOD3                = 0x0008,
  MOD4                = 0x0010,
  DCO0                = 0x0020,
  DCO1                = 0x0040,
  DCO2                = 0x0080,
};


__no_init volatile union
{
  unsigned char BCSCTL1;  /* Basic Clock System Control 1 */ 
  
  struct
  {
    unsigned char RSEL0          : 1;  /* Range Select Bit 0 */ 
    unsigned char RSEL1          : 1;  /* Range Select Bit 1 */ 
    unsigned char RSEL2          : 1;  /* Range Select Bit 2 */ 
    unsigned char RSEL3          : 1;  /* Range Select Bit 3 */ 
    unsigned char DIVA0          : 1;  /* ACLK Divider 0 */ 
    unsigned char DIVA1          : 1;  /* ACLK Divider 1 */ 
    unsigned char XTS            : 1;  /* LFXTCLK 0:Low Freq. / 1: High Freq. */ 
    unsigned char XT2OFF         : 1;  /* Enable XT2CLK */ 
  } BCSCTL1_bit;  
} @ 0x0057;


enum {
  RSEL0               = 0x0001,
  RSEL1               = 0x0002,
  RSEL2               = 0x0004,
  RSEL3               = 0x0008,
  DIVA0               = 0x0010,
  DIVA1               = 0x0020,
  XTS                 = 0x0040,
  XT2OFF              = 0x0080,
};


__no_init volatile union
{
  unsigned char BCSCTL2;  /* Basic Clock System Control 2 */ 
  
  struct
  {
    unsigned char DCOR           : 1;  /* Enable External Resistor : 1 */ 
    unsigned char DIVS0          : 1;  /* SMCLK Divider 0 */ 
    unsigned char DIVS1          : 1;  /* SMCLK Divider 1 */ 
    unsigned char SELS           : 1;  /* SMCLK Source Select 0:DCOCLK / 1:XT2CLK/LFXTCLK */ 
    unsigned char DIVM0          : 1;  /* CLK Divider 0 */ 
    unsigned char DIVM1          : 1;  /* CLK Divider 1 */ 
    unsigned char SELM0          : 1;  /* MCLK Source Select 0 */ 
    unsigned char SELM1          : 1;  /* MCLK Source Select 1 */ 
  } BCSCTL2_bit;  
} @ 0x0058;


enum {
  DCOR                = 0x0001,
  DIVS0               = 0x0002,
  DIVS1               = 0x0004,
  SELS                = 0x0008,
  DIVM0               = 0x0010,
  DIVM1               = 0x0020,
  SELM0               = 0x0040,
  SELM1               = 0x0080,
};


__no_init volatile union
{
  unsigned char BCSCTL3;  /* Basic Clock System Control 3 */ 
  
  struct
  {
    unsigned char LFXT1OF        : 1;  /* Low/high Frequency Oscillator Fault Flag */ 
    unsigned char XT2OF          : 1;  /* High frequency oscillator 2 fault flag */ 
    unsigned char XCAP0          : 1;  /* XIN/XOUT Cap 0 */ 
    unsigned char XCAP1          : 1;  /* XIN/XOUT Cap 1 */ 
    unsigned char LFXT1S0        : 1;  /* Mode 0 for LFXT1 (XTS = 0) */ 
    unsigned char LFXT1S1        : 1;  /* Mode 1 for LFXT1 (XTS = 0) */ 
    unsigned char XT2S0          : 1;  /* Mode 0 for XT2 */ 
    unsigned char XT2S1          : 1;  /* Mode 1 for XT2 */ 
  } BCSCTL3_bit;  
} @ 0x0053;


enum {
  LFXT1OF             = 0x0001,
  XT2OF               = 0x0002,
  XCAP0               = 0x0004,
  XCAP1               = 0x0008,
  LFXT1S0             = 0x0010,
  LFXT1S1             = 0x0020,
  XT2S0               = 0x0040,
  XT2S1               = 0x0080,
};

 
#define __MSP430_HAS_BC2__           /* Definition to show that Module is available */

#define DIVA_0              (0x00)   /* ACLK Divider 0: /1 */
#define DIVA_1              (0x10)   /* ACLK Divider 1: /2 */
#define DIVA_2              (0x20)   /* ACLK Divider 2: /4 */
#define DIVA_3              (0x30)   /* ACLK Divider 3: /8 */

#define DIVS_0              (0x00)   /* SMCLK Divider 0: /1 */
#define DIVS_1              (0x02)   /* SMCLK Divider 1: /2 */
#define DIVS_2              (0x04)   /* SMCLK Divider 2: /4 */
#define DIVS_3              (0x06)   /* SMCLK Divider 3: /8 */

#define DIVM_0              (0x00)   /* MCLK Divider 0: /1 */
#define DIVM_1              (0x10)   /* MCLK Divider 1: /2 */
#define DIVM_2              (0x20)   /* MCLK Divider 2: /4 */
#define DIVM_3              (0x30)   /* MCLK Divider 3: /8 */

#define SELM_0              (0x00)   /* MCLK Source Select 0: DCOCLK */
#define SELM_1              (0x40)   /* MCLK Source Select 1: DCOCLK */
#define SELM_2              (0x80)   /* MCLK Source Select 2: XT2CLK/LFXTCLK */
#define SELM_3              (0xC0)   /* MCLK Source Select 3: LFXTCLK */

#define XCAP_0              (0x00)   /* XIN/XOUT Cap : 0 pF */
#define XCAP_1              (0x04)   /* XIN/XOUT Cap : 6 pF */
#define XCAP_2              (0x08)   /* XIN/XOUT Cap : 10 pF */
#define XCAP_3              (0x0C)   /* XIN/XOUT Cap : 12.5 pF */

#define LFXT1S_0            (0x00)   /* Mode 0 for LFXT1 : Normal operation */
#define LFXT1S_1            (0x10)   /* Mode 1 for LFXT1 : Reserved */
#define LFXT1S_2            (0x20)   /* Mode 2 for LFXT1 : VLO */
#define LFXT1S_3            (0x30)   /* Mode 3 for LFXT1 : Digital input signal */

#define XT2S_0              (0x00)   /* Mode 0 for XT2 : 0.4 - 1 MHz */
#define XT2S_1              (0x40)   /* Mode 1 for XT2 : 1 - 4 MHz */
#define XT2S_2              (0x80)   /* Mode 2 for XT2 : 2 - 16 MHz */
#define XT2S_3              (0xC0)   /* Mode 3 for XT2 : Digital input signal */
 

/*-------------------------------------------------------------------------
 *   Comparator A
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned char CACTL1;  /* Comparator A Control 1 */ 
  
  struct
  {
    unsigned char CAIFG          : 1;  /* Comp. A Interrupt Flag */ 
    unsigned char CAIE           : 1;  /* Comp. A Interrupt Enable */ 
    unsigned char CAIES          : 1;  /* Comp. A Int. Edge Select: 0:rising / 1:falling */ 
    unsigned char CAON           : 1;  /* Comp. A enable */ 
    unsigned char CAREF0         : 1;  /* Comp. A Internal Reference Select 0 */ 
    unsigned char CAREF1         : 1;  /* Comp. A Internal Reference Select 1 */ 
    unsigned char CARSEL         : 1;  /* Comp. A Internal Reference Enable */ 
    unsigned char CAEX           : 1;  /* Comp. A Exchange Inputs */ 
  } CACTL1_bit;  
} @ 0x0059;


enum {
  CAIFG               = 0x0001,
  CAIE                = 0x0002,
  CAIES               = 0x0004,
  CAON                = 0x0008,
  CAREF0              = 0x0010,
  CAREF1              = 0x0020,
  CARSEL              = 0x0040,
  CAEX                = 0x0080,
};


__no_init volatile union
{
  unsigned char CACTL2;  /* Comparator A Control 2 */ 
  
  struct
  {
    unsigned char CAOUT          : 1;  /* Comp. A Output */ 
    unsigned char CAF            : 1;  /* Comp. A Enable Output Filter */ 
    unsigned char P2CA0          : 1;  /* Comp. A +Terminal Multiplexer */ 
    unsigned char P2CA1          : 1;  /* Comp. A -Terminal Multiplexer */ 
    unsigned char P2CA2          : 1;  /* Comp. A -Terminal Multiplexer */ 
    unsigned char P2CA3          : 1;  /* Comp. A -Terminal Multiplexer */ 
    unsigned char P2CA4          : 1;  /* Comp. A +Terminal Multiplexer */ 
    unsigned char CASHORT        : 1;  /* Comp. A Short + and - Terminals */ 
  } CACTL2_bit;  
} @ 0x005A;


enum {
  CAOUT               = 0x0001,
  CAF                 = 0x0002,
  P2CA0               = 0x0004,
  P2CA1               = 0x0008,
  P2CA2               = 0x0010,
  P2CA3               = 0x0020,
  P2CA4               = 0x0040,
  CASHORT             = 0x0080,
};


__no_init volatile union
{
  unsigned char CAPD;  /* Comparator A Port Disable */ 
  
  struct
  {
    unsigned char CAPD0          : 1;  /* Comp. A Disable Input Buffer of Port Register .0 */ 
    unsigned char CAPD1          : 1;  /* Comp. A Disable Input Buffer of Port Register .1 */ 
    unsigned char CAPD2          : 1;  /* Comp. A Disable Input Buffer of Port Register .2 */ 
    unsigned char CAPD3          : 1;  /* Comp. A Disable Input Buffer of Port Register .3 */ 
    unsigned char CAPD4          : 1;  /* Comp. A Disable Input Buffer of Port Register .4 */ 
    unsigned char CAPD5          : 1;  /* Comp. A Disable Input Buffer of Port Register .5 */ 
    unsigned char CAPD6          : 1;  /* Comp. A Disable Input Buffer of Port Register .6 */ 
    unsigned char CAPD7          : 1;  /* Comp. A Disable Input Buffer of Port Register .7 */ 
  } CAPD_bit;  
} @ 0x005B;


enum {
  CAPD0               = 0x0001,
  CAPD1               = 0x0002,
  CAPD2               = 0x0004,
  CAPD3               = 0x0008,
  CAPD4               = 0x0010,
  CAPD5               = 0x0020,
  CAPD6               = 0x0040,
  CAPD7               = 0x0080,
};

 
#define __MSP430_HAS_CAPLUS__      /* Definition to show that Module is available */

#define CAREF_0          (0x00)    /* Comp. A Int. Ref. Select 0 : Off */
#define CAREF_1          (0x10)    /* Comp. A Int. Ref. Select 1 : 0.25*Vcc */
#define CAREF_2          (0x20)    /* Comp. A Int. Ref. Select 2 : 0.5*Vcc */
#define CAREF_3          (0x30)    /* Comp. A Int. Ref. Select 3 : Vt*/
 

/*-------------------------------------------------------------------------
 *   Flash Memory
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned short FCTL1;  /* FLASH Control 1 */ 
  
  struct
  {
    unsigned short               : 1; 
    unsigned short ERASE         : 1;  /* Enable bit for Flash segment erase */ 
    unsigned short MERAS         : 1;  /* Enable bit for Flash mass erase */ 
    unsigned short EEI           : 1; 
    unsigned short EEIEX         : 1; 
    unsigned short               : 1; 
    unsigned short WRT           : 1;  /* Enable bit for Flash write */ 
    unsigned short BLKWRT        : 1;  /* Enable bit for Flash segment write */ 
    unsigned short               : 8;  /* old definition */ /* Enable bit for Flash segment write */ 
  } FCTL1_bit;  
} @ 0x0128;


enum {
  ERASE               = 0x0002,
  MERAS               = 0x0004,
  EEI                 = 0x0008,
  EEIEX               = 0x0010,
  WRT                 = 0x0040,
  BLKWRT              = 0x0080,
};


__no_init volatile union
{
  unsigned short FCTL2;  /* FLASH Control 2 */ 
  
  struct
  {
    unsigned short FN0           : 1;  /* Divide Flash clock by 1 to 64 using FN0 to FN5 according to: */ 
    unsigned short FN1           : 1;  /* 32*FN5 + 16*FN4 + 8*FN3 + 4*FN2 + 2*FN1 + FN0 + 1 */ 
    unsigned short FN2           : 1; 
    unsigned short FN3           : 1; 
    unsigned short FN4           : 1; 
    unsigned short FN5           : 1; 
    unsigned short FSSEL0        : 1;  /* Flash clock select 0 */ 
    unsigned short FSSEL1        : 1;  /* Flash clock select 1 */ 
    unsigned short KEY           : 8; 
  } FCTL2_bit;  
} @ 0x012A;


enum {
  FN0                 = 0x0001,
  FN1                 = 0x0002,
  FN2                 = 0x0004,
  FN3                 = 0x0008,
  FN4                 = 0x0010,
  FN5                 = 0x0020,
};


__no_init volatile union
{
  unsigned short FCTL3;  /* FLASH Control 3 */ 
  
  struct
  {
    unsigned short BUSY          : 1;  /* Flash busy: 1 */ 
    unsigned short KEYV          : 1;  /* Flash Key violation flag */ 
    unsigned short ACCVIFG       : 1;  /* Flash Access violation flag */ 
    unsigned short WAIT          : 1;  /* Wait flag for segment write */ 
    unsigned short LOCK          : 1;  /* Lock bit: 1 - Flash is locked (read only) */ 
    unsigned short EMEX          : 1;  /* Flash Emergency Exit */ 
    unsigned short LOCKA         : 1;  /* Segment A Lock bit: read = 1 - Segment is locked (read only) */ 
    unsigned short FAIL          : 1;  /* Last Program or Erase failed */ 
    unsigned short               : 8; 
  } FCTL3_bit;  
} @ 0x012C;


enum {
  BUSY                = 0x0001,
  KEYV                = 0x0002,
  ACCVIFG             = 0x0004,
  WAIT                = 0x0008,
  LOCK                = 0x0010,
  EMEX                = 0x0020,
  LOCKA               = 0x0040,
  FAIL                = 0x0080,
};


__no_init volatile union
{
  unsigned short FCTL4;  /* FLASH Control 4 */ 
  
  struct
  {
    unsigned short               : 4; 
    unsigned short MGR0          : 1; 
    unsigned short MGR1          : 1; 
  } FCTL4_bit;  
} @ 0x01BE;


enum {
  MGR0                = 0x0010,
  MGR1                = 0x0020,
};

 
#define __MSP430_HAS_FLASH2__         /* Definition to show that Module is available */

#define FRKEY            (0x9600)    /* Flash key returned by read */
#define FWKEY            (0xA500)    /* Flash key for write */
#define FXKEY            (0x3300)    /* for use with XOR instruction */

#define FSSEL_0          (0x0000)    /* Flash clock select: 0 - ACLK */
#define FSSEL_1          (0x0040)    /* Flash clock select: 1 - MCLK */
#define FSSEL_2          (0x0080)    /* Flash clock select: 2 - SMCLK */
#define FSSEL_3          (0x00C0)    /* Flash clock select: 3 - SMCLK */
 

/*-------------------------------------------------------------------------
 *   DIGITAL I/O Port1/2 Pull up / Pull down Resistors
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned __READ char P1IN;  /* Port 1 Input */ 
  
  struct
  {
    unsigned __READ char P1IN_0  : 1; 
    unsigned __READ char P1IN_1  : 1; 
    unsigned __READ char P1IN_2  : 1; 
    unsigned __READ char P1IN_3  : 1; 
    unsigned __READ char P1IN_4  : 1; 
    unsigned __READ char P1IN_5  : 1; 
    unsigned __READ char P1IN_6  : 1; 
    unsigned __READ char P1IN_7  : 1; 
  } P1IN_bit;  
} @ 0x0020;




__no_init volatile union
{
  unsigned char P1OUT;  /* Port 1 Output */ 
  
  struct
  {
    unsigned char P1OUT_0        : 1; 
    unsigned char P1OUT_1        : 1; 
    unsigned char P1OUT_2        : 1; 
    unsigned char P1OUT_3        : 1; 
    unsigned char P1OUT_4        : 1; 
    unsigned char P1OUT_5        : 1; 
    unsigned char P1OUT_6        : 1; 
    unsigned char P1OUT_7        : 1; 
  } P1OUT_bit;  
} @ 0x0021;


enum {
  P1OUT_0             = 0x0001,
  P1OUT_1             = 0x0002,
  P1OUT_2             = 0x0004,
  P1OUT_3             = 0x0008,
  P1OUT_4             = 0x0010,
  P1OUT_5             = 0x0020,
  P1OUT_6             = 0x0040,
  P1OUT_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P1DIR;  /* Port 1 Direction */ 
  
  struct
  {
    unsigned char P1DIR_0        : 1; 
    unsigned char P1DIR_1        : 1; 
    unsigned char P1DIR_2        : 1; 
    unsigned char P1DIR_3        : 1; 
    unsigned char P1DIR_4        : 1; 
    unsigned char P1DIR_5        : 1; 
    unsigned char P1DIR_6        : 1; 
    unsigned char P1DIR_7        : 1; 
  } P1DIR_bit;  
} @ 0x0022;


enum {
  P1DIR_0             = 0x0001,
  P1DIR_1             = 0x0002,
  P1DIR_2             = 0x0004,
  P1DIR_3             = 0x0008,
  P1DIR_4             = 0x0010,
  P1DIR_5             = 0x0020,
  P1DIR_6             = 0x0040,
  P1DIR_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P1IFG;  /* Port 1 Interrupt Flag */ 
  
  struct
  {
    unsigned char P1IFG_0        : 1; 
    unsigned char P1IFG_1        : 1; 
    unsigned char P1IFG_2        : 1; 
    unsigned char P1IFG_3        : 1; 
    unsigned char P1IFG_4        : 1; 
    unsigned char P1IFG_5        : 1; 
    unsigned char P1IFG_6        : 1; 
    unsigned char P1IFG_7        : 1; 
  } P1IFG_bit;  
} @ 0x0023;


enum {
  P1IFG_0             = 0x0001,
  P1IFG_1             = 0x0002,
  P1IFG_2             = 0x0004,
  P1IFG_3             = 0x0008,
  P1IFG_4             = 0x0010,
  P1IFG_5             = 0x0020,
  P1IFG_6             = 0x0040,
  P1IFG_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P1IES;  /* Port 1 Interrupt Edge Select */ 
  
  struct
  {
    unsigned char P1IES_0        : 1; 
    unsigned char P1IES_1        : 1; 
    unsigned char P1IES_2        : 1; 
    unsigned char P1IES_3        : 1; 
    unsigned char P1IES_4        : 1; 
    unsigned char P1IES_5        : 1; 
    unsigned char P1IES_6        : 1; 
    unsigned char P1IES_7        : 1; 
  } P1IES_bit;  
} @ 0x0024;


enum {
  P1IES_0             = 0x0001,
  P1IES_1             = 0x0002,
  P1IES_2             = 0x0004,
  P1IES_3             = 0x0008,
  P1IES_4             = 0x0010,
  P1IES_5             = 0x0020,
  P1IES_6             = 0x0040,
  P1IES_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P1IE;  /* Port 1 Interrupt Enable */ 
  
  struct
  {
    unsigned char P1IE_0         : 1; 
    unsigned char P1IE_1         : 1; 
    unsigned char P1IE_2         : 1; 
    unsigned char P1IE_3         : 1; 
    unsigned char P1IE_4         : 1; 
    unsigned char P1IE_5         : 1; 
    unsigned char P1IE_6         : 1; 
    unsigned char P1IE_7         : 1; 
  } P1IE_bit;  
} @ 0x0025;


enum {
  P1IE_0              = 0x0001,
  P1IE_1              = 0x0002,
  P1IE_2              = 0x0004,
  P1IE_3              = 0x0008,
  P1IE_4              = 0x0010,
  P1IE_5              = 0x0020,
  P1IE_6              = 0x0040,
  P1IE_7              = 0x0080,
};


__no_init volatile union
{
  unsigned char P1SEL;  /* Port 1 Selection */ 
  
  struct
  {
    unsigned char P1SEL_0        : 1; 
    unsigned char P1SEL_1        : 1; 
    unsigned char P1SEL_2        : 1; 
    unsigned char P1SEL_3        : 1; 
    unsigned char P1SEL_4        : 1; 
    unsigned char P1SEL_5        : 1; 
    unsigned char P1SEL_6        : 1; 
    unsigned char P1SEL_7        : 1; 
  } P1SEL_bit;  
} @ 0x0026;


enum {
  P1SEL_0             = 0x0001,
  P1SEL_1             = 0x0002,
  P1SEL_2             = 0x0004,
  P1SEL_3             = 0x0008,
  P1SEL_4             = 0x0010,
  P1SEL_5             = 0x0020,
  P1SEL_6             = 0x0040,
  P1SEL_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P1REN;  /* Port 1 Resistor Enable */ 
  
  struct
  {
    unsigned char P1REN_0        : 1; 
    unsigned char P1REN_1        : 1; 
    unsigned char P1REN_2        : 1; 
    unsigned char P1REN_3        : 1; 
    unsigned char P1REN_4        : 1; 
    unsigned char P1REN_5        : 1; 
    unsigned char P1REN_6        : 1; 
    unsigned char P1REN_7        : 1; 
  } P1REN_bit;  
} @ 0x0027;


enum {
  P1REN_0             = 0x0001,
  P1REN_1             = 0x0002,
  P1REN_2             = 0x0004,
  P1REN_3             = 0x0008,
  P1REN_4             = 0x0010,
  P1REN_5             = 0x0020,
  P1REN_6             = 0x0040,
  P1REN_7             = 0x0080,
};


__no_init volatile union
{
  unsigned __READ char P2IN;  /* Port 2 Input */ 
  
  struct
  {
    unsigned __READ char P2IN_0  : 1; 
    unsigned __READ char P2IN_1  : 1; 
    unsigned __READ char P2IN_2  : 1; 
    unsigned __READ char P2IN_3  : 1; 
    unsigned __READ char P2IN_4  : 1; 
    unsigned __READ char P2IN_5  : 1; 
    unsigned __READ char P2IN_6  : 1; 
    unsigned __READ char P2IN_7  : 1; 
  } P2IN_bit;  
} @ 0x0028;


enum {
  P2IN_0              = 0x0001,
  P2IN_1              = 0x0002,
  P2IN_2              = 0x0004,
  P2IN_3              = 0x0008,
  P2IN_4              = 0x0010,
  P2IN_5              = 0x0020,
  P2IN_6              = 0x0040,
  P2IN_7              = 0x0080,
};


__no_init volatile union
{
  unsigned char P2OUT;  /* Port 2 Output */ 
  
  struct
  {
    unsigned char P2OUT_0        : 1; 
    unsigned char P2OUT_1        : 1; 
    unsigned char P2OUT_2        : 1; 
    unsigned char P2OUT_3        : 1; 
    unsigned char P2OUT_4        : 1; 
    unsigned char P2OUT_5        : 1; 
    unsigned char P2OUT_6        : 1; 
    unsigned char P2OUT_7        : 1; 
  } P2OUT_bit;  
} @ 0x0029;


enum {
  P2OUT_0             = 0x0001,
  P2OUT_1             = 0x0002,
  P2OUT_2             = 0x0004,
  P2OUT_3             = 0x0008,
  P2OUT_4             = 0x0010,
  P2OUT_5             = 0x0020,
  P2OUT_6             = 0x0040,
  P2OUT_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P2DIR;  /* Port 2 Direction */ 
  
  struct
  {
    unsigned char P2DIR_0        : 1; 
    unsigned char P2DIR_1        : 1; 
    unsigned char P2DIR_2        : 1; 
    unsigned char P2DIR_3        : 1; 
    unsigned char P2DIR_4        : 1; 
    unsigned char P2DIR_5        : 1; 
    unsigned char P2DIR_6        : 1; 
    unsigned char P2DIR_7        : 1; 
  } P2DIR_bit;  
} @ 0x002A;


enum {
  P2DIR_0             = 0x0001,
  P2DIR_1             = 0x0002,
  P2DIR_2             = 0x0004,
  P2DIR_3             = 0x0008,
  P2DIR_4             = 0x0010,
  P2DIR_5             = 0x0020,
  P2DIR_6             = 0x0040,
  P2DIR_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P2IFG;  /* Port 2 Interrupt Flag */ 
  
  struct
  {
    unsigned char P2IFG_0        : 1; 
    unsigned char P2IFG_1        : 1; 
    unsigned char P2IFG_2        : 1; 
    unsigned char P2IFG_3        : 1; 
    unsigned char P2IFG_4        : 1; 
    unsigned char P2IFG_5        : 1; 
    unsigned char P2IFG_6        : 1; 
    unsigned char P2IFG_7        : 1; 
  } P2IFG_bit;  
} @ 0x002B;


enum {
  P2IFG_0             = 0x0001,
  P2IFG_1             = 0x0002,
  P2IFG_2             = 0x0004,
  P2IFG_3             = 0x0008,
  P2IFG_4             = 0x0010,
  P2IFG_5             = 0x0020,
  P2IFG_6             = 0x0040,
  P2IFG_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P2IES;  /* Port 2 Interrupt Edge Select */ 
  
  struct
  {
    unsigned char P2IES_0        : 1; 
    unsigned char P2IES_1        : 1; 
    unsigned char P2IES_2        : 1; 
    unsigned char P2IES_3        : 1; 
    unsigned char P2IES_4        : 1; 
    unsigned char P2IES_5        : 1; 
    unsigned char P2IES_6        : 1; 
    unsigned char P2IES_7        : 1; 
  } P2IES_bit;  
} @ 0x002C;


enum {
  P2IES_0             = 0x0001,
  P2IES_1             = 0x0002,
  P2IES_2             = 0x0004,
  P2IES_3             = 0x0008,
  P2IES_4             = 0x0010,
  P2IES_5             = 0x0020,
  P2IES_6             = 0x0040,
  P2IES_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P2IE;  /* Port 2 Interrupt Enable  */ 
  
  struct
  {
    unsigned char P2IE_0         : 1; 
    unsigned char P2IE_1         : 1; 
    unsigned char P2IE_2         : 1; 
    unsigned char P2IE_3         : 1; 
    unsigned char P2IE_4         : 1; 
    unsigned char P2IE_5         : 1; 
    unsigned char P2IE_6         : 1; 
    unsigned char P2IE_7         : 1; 
  } P2IE_bit;  
} @ 0x002D;


enum {
  P2IE_0              = 0x0001,
  P2IE_1              = 0x0002,
  P2IE_2              = 0x0004,
  P2IE_3              = 0x0008,
  P2IE_4              = 0x0010,
  P2IE_5              = 0x0020,
  P2IE_6              = 0x0040,
  P2IE_7              = 0x0080,
};


__no_init volatile union
{
  unsigned char P2SEL;  /* Port 2 Selection */ 
  
  struct
  {
    unsigned char P2SEL_0        : 1; 
    unsigned char P2SEL_1        : 1; 
    unsigned char P2SEL_2        : 1; 
    unsigned char P2SEL_3        : 1; 
    unsigned char P2SEL_4        : 1; 
    unsigned char P2SEL_5        : 1; 
    unsigned char P2SEL_6        : 1; 
    unsigned char P2SEL_7        : 1; 
  } P2SEL_bit;  
} @ 0x002E;


enum {
  P2SEL_0             = 0x0001,
  P2SEL_1             = 0x0002,
  P2SEL_2             = 0x0004,
  P2SEL_3             = 0x0008,
  P2SEL_4             = 0x0010,
  P2SEL_5             = 0x0020,
  P2SEL_6             = 0x0040,
  P2SEL_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P2REN;  /* Port 2 Resistor Enable */ 
  
  struct
  {
    unsigned char P2REN_0        : 1; 
    unsigned char P2REN_1        : 1; 
    unsigned char P2REN_2        : 1; 
    unsigned char P2REN_3        : 1; 
    unsigned char P2REN_4        : 1; 
    unsigned char P2REN_5        : 1; 
    unsigned char P2REN_6        : 1; 
    unsigned char P2REN_7        : 1; 
  } P2REN_bit;  
} @ 0x002F;


enum {
  P2REN_0             = 0x0001,
  P2REN_1             = 0x0002,
  P2REN_2             = 0x0004,
  P2REN_3             = 0x0008,
  P2REN_4             = 0x0010,
  P2REN_5             = 0x0020,
  P2REN_6             = 0x0040,
  P2REN_7             = 0x0080,
};

 
#define __MSP430_HAS_PORT1_R__        /* Definition to show that Module is available */
#define __MSP430_HAS_PORT2_R__        /* Definition to show that Module is available */
 

/*-------------------------------------------------------------------------
 *   Digital I/O Port3
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned __READ char P3IN;  /* Port 3 Input */ 
  
  struct
  {
    unsigned __READ char P3IN_0  : 1; 
    unsigned __READ char P3IN_1  : 1; 
    unsigned __READ char P3IN_2  : 1; 
    unsigned __READ char P3IN_3  : 1; 
    unsigned __READ char P3IN_4  : 1; 
    unsigned __READ char P3IN_5  : 1; 
    unsigned __READ char P3IN_6  : 1; 
    unsigned __READ char P3IN_7  : 1; 
  } P3IN_bit;  
} @ 0x0018;


enum {
  P3IN_0              = 0x0001,
  P3IN_1              = 0x0002,
  P3IN_2              = 0x0004,
  P3IN_3              = 0x0008,
  P3IN_4              = 0x0010,
  P3IN_5              = 0x0020,
  P3IN_6              = 0x0040,
  P3IN_7              = 0x0080,
};


__no_init volatile union
{
  unsigned char P3OUT;  /* Port 3 Output */ 
  
  struct
  {
    unsigned char P3OUT_0        : 1; 
    unsigned char P3OUT_1        : 1; 
    unsigned char P3OUT_2        : 1; 
    unsigned char P3OUT_3        : 1; 
    unsigned char P3OUT_4        : 1; 
    unsigned char P3OUT_5        : 1; 
    unsigned char P3OUT_6        : 1; 
    unsigned char P3OUT_7        : 1; 
  } P3OUT_bit;  
} @ 0x0019;


enum {
  P3OUT_0             = 0x0001,
  P3OUT_1             = 0x0002,
  P3OUT_2             = 0x0004,
  P3OUT_3             = 0x0008,
  P3OUT_4             = 0x0010,
  P3OUT_5             = 0x0020,
  P3OUT_6             = 0x0040,
  P3OUT_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P3DIR;  /* Port 3 Direction */ 
  
  struct
  {
    unsigned char P3DIR_0        : 1; 
    unsigned char P3DIR_1        : 1; 
    unsigned char P3DIR_2        : 1; 
    unsigned char P3DIR_3        : 1; 
    unsigned char P3DIR_4        : 1; 
    unsigned char P3DIR_5        : 1; 
    unsigned char P3DIR_6        : 1; 
    unsigned char P3DIR_7        : 1; 
  } P3DIR_bit;  
} @ 0x001A;


enum {
  P3DIR_0             = 0x0001,
  P3DIR_1             = 0x0002,
  P3DIR_2             = 0x0004,
  P3DIR_3             = 0x0008,
  P3DIR_4             = 0x0010,
  P3DIR_5             = 0x0020,
  P3DIR_6             = 0x0040,
  P3DIR_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P3SEL;  /* Port 3 Selection */ 
  
  struct
  {
    unsigned char P3SEL_0        : 1; 
    unsigned char P3SEL_1        : 1; 
    unsigned char P3SEL_2        : 1; 
    unsigned char P3SEL_3        : 1; 
    unsigned char P3SEL_4        : 1; 
    unsigned char P3SEL_5        : 1; 
    unsigned char P3SEL_6        : 1; 
    unsigned char P3SEL_7        : 1; 
  } P3SEL_bit;  
} @ 0x001B;


enum {
  P3SEL_0             = 0x0001,
  P3SEL_1             = 0x0002,
  P3SEL_2             = 0x0004,
  P3SEL_3             = 0x0008,
  P3SEL_4             = 0x0010,
  P3SEL_5             = 0x0020,
  P3SEL_6             = 0x0040,
  P3SEL_7             = 0x0080,
};


__no_init volatile union
{
  unsigned char P3REN;  /* Port 3 Resistor Enable */ 
  
  struct
  {
    unsigned char P3REN_0        : 1; 
    unsigned char P3REN_1        : 1; 
    unsigned char P3REN_2        : 1; 
    unsigned char P3REN_3        : 1; 
    unsigned char P3REN_4        : 1; 
    unsigned char P3REN_5        : 1; 
    unsigned char P3REN_6        : 1; 
    unsigned char P3REN_7        : 1; 
  } P3REN_bit;  
} @ 0x0010;


enum {
  P3REN_0             = 0x0001,
  P3REN_1             = 0x0002,
  P3REN_2             = 0x0004,
  P3REN_3             = 0x0008,
  P3REN_4             = 0x0010,
  P3REN_5             = 0x0020,
  P3REN_6             = 0x0040,
  P3REN_7             = 0x0080,
};

 
#define __MSP430_HAS_PORT3_R__        /* Definition to show that Module is available */
 

/*-------------------------------------------------------------------------
 *   Timer A3
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned __READ short TAIV;  /* Timer A Interrupt Vector Word */ 
  
  struct
  {
    unsigned __READ short        : 1; 
    unsigned __READ short IRQVEC : 3; 
    unsigned __READ short        : 12; 
  } TAIV_bit;  
} @ 0x012E;


enum {
  IRQVEC              = 0x0008,
};


__no_init volatile union
{
  unsigned short TACTL;  /* Timer A Control */ 
  
  struct
  {
    unsigned short TAIFG         : 1;  /* Timer A counter interrupt flag */ 
    unsigned short TAIE          : 1;  /* Timer A counter interrupt enable */ 
    unsigned short TACLR         : 1;  /* Timer A counter clear */ 
    unsigned short               : 1; 
    unsigned short TAMC          : 2;  /* Timer A mode control 0 */ 
    unsigned short TAID          : 2;  /* Timer A clock input divider */ 
    unsigned short TASSEL        : 2;  /* Timer A clock source select */ 
    unsigned short               : 6; 
  } TACTL_bit;  
} @ 0x0160;


enum {
  TAIFG               = 0x0001,
  TAIE                = 0x0002,
  TACLR               = 0x0004,
  TAMC                = 0x0020,
  TAID                = 0x0080,
  TASSEL              = 0x0200,
};


__no_init volatile union
{
  unsigned short TACCTL0;  /* Timer A Capture/Compare Control 0 */ 
  
  struct
  {
    unsigned short CCIFG         : 1;  /* Capture/compare interrupt flag */ 
    unsigned short COV           : 1;  /* Capture/compare overflow flag */ 
    unsigned short OUT           : 1;  /* PWM Output signal if output mode 0 */ 
    unsigned short CCI           : 1;  /* Capture input signal (read) */ 
    unsigned short CCIE          : 1;  /* Capture/compare interrupt enable */ 
    unsigned short OUTMOD        : 3;  /* Output mode */ 
    unsigned short CAP           : 1;  /* Capture mode: 1 /Compare mode : 0 */ 
    unsigned short               : 1; 
    unsigned short SCCI          : 1;  /* Latched capture signal (read) */ 
    unsigned short SCS           : 1;  /* Capture sychronize */ 
    unsigned short CCIS          : 2;  /* Capture input select */ 
    unsigned short CM            : 2;  /* Capture mode */ 
  } TACCTL0_bit;  
} @ 0x0162;


enum {
  CCIFG               = 0x0001,
  COV                 = 0x0002,
  OUT                 = 0x0004,
  CCI                 = 0x0008,
  CCIE                = 0x0010,
  OUTMOD              = 0x0080,
  CAP                 = 0x0100,
  SCCI                = 0x0400,
  SCS                 = 0x0800,
  CCIS                = 0x2000,
  CM                  = 0x8000,
};


__no_init volatile union
{
  unsigned short TACCTL1;  /* Timer A Capture/Compare Control 1 */ 
  
  struct
  {
    unsigned short CCIFG         : 1;  /* Capture/compare interrupt flag */ 
    unsigned short COV           : 1;  /* Capture/compare overflow flag */ 
    unsigned short OUT           : 1;  /* PWM Output signal if output mode 0 */ 
    unsigned short CCI           : 1;  /* Capture input signal (read) */ 
    unsigned short CCIE          : 1;  /* Capture/compare interrupt enable */ 
    unsigned short OUTMOD        : 3;  /* Output mode */ 
    unsigned short CAP           : 1;  /* Capture mode: 1 /Compare mode : 0 */ 
    unsigned short               : 1; 
    unsigned short SCCI          : 1;  /* Latched capture signal (read) */ 
    unsigned short SCS           : 1;  /* Capture sychronize */ 
    unsigned short CCIS          : 2;  /* Capture input select */ 
    unsigned short CM            : 2;  /* Capture mode */ 
  } TACCTL1_bit;  
} @ 0x0164;




__no_init volatile union
{
  unsigned short TACCTL2;  /* Timer A Capture/Compare Control 2 */ 
  
  struct
  {
    unsigned short CCIFG         : 1;  /* Capture/compare interrupt flag */ 
    unsigned short COV           : 1;  /* Capture/compare overflow flag */ 
    unsigned short OUT           : 1;  /* PWM Output signal if output mode 0 */ 
    unsigned short CCI           : 1;  /* Capture input signal (read) */ 
    unsigned short CCIE          : 1;  /* Capture/compare interrupt enable */ 
    unsigned short OUTMOD        : 3;  /* Output mode */ 
    unsigned short CAP           : 1;  /* Capture mode: 1 /Compare mode : 0 */ 
    unsigned short               : 1; 
    unsigned short SCCI          : 1;  /* Latched capture signal (read) */ 
    unsigned short SCS           : 1;  /* Capture sychronize */ 
    unsigned short CCIS          : 2;  /* Capture input select */ 
    unsigned short CM            : 2;  /* Capture mode */ 
  } TACCTL2_bit;  
} @ 0x0166;




 /* Timer A */ 
__no_init volatile unsigned short TAR @ 0x0170;  
 

 /* Timer A Capture/Compare 0 */ 
__no_init volatile unsigned short TACCR0 @ 0x0172;  
 

 /* Timer A Capture/Compare 1 */ 
__no_init volatile unsigned short TACCR1 @ 0x0174;  
 

 /* Timer A Capture/Compare 2 */ 
__no_init volatile unsigned short TACCR2 @ 0x0176;  
 
 
#define __MSP430_HAS_TA3__         /* Definition to show that Module is available */

#define MC_0            (0*0x10u)  /* Timer A mode control: 0 - Stop */
#define MC_1            (1*0x10u)  /* Timer A mode control: 1 - Up to CCR0 */
#define MC_2            (2*0x10u)  /* Timer A mode control: 2 - Continous up */
#define MC_3            (3*0x10u)  /* Timer A mode control: 3 - Up/Down */
#define ID_0            (0*0x40u)  /* Timer A input divider: 0 - /1 */
#define ID_1            (1*0x40u)  /* Timer A input divider: 1 - /2 */
#define ID_2            (2*0x40u)  /* Timer A input divider: 2 - /4 */
#define ID_3            (3*0x40u)  /* Timer A input divider: 3 - /8 */
#define TASSEL_0        (0*0x100u) /* Timer A clock source select: 0 - TACLK */
#define TASSEL_1        (1*0x100u) /* Timer A clock source select: 1 - ACLK  */
#define TASSEL_2        (2*0x100u) /* Timer A clock source select: 2 - SMCLK */
#define TASSEL_3        (3*0x100u) /* Timer A clock source select: 3 - INCLK */

#define OUTMOD_0        (0*0x20u)  /* PWM output mode: 0 - output only */
#define OUTMOD_1        (1*0x20u)  /* PWM output mode: 1 - set */
#define OUTMOD_2        (2*0x20u)  /* PWM output mode: 2 - PWM toggle/reset */
#define OUTMOD_3        (3*0x20u)  /* PWM output mode: 3 - PWM set/reset */
#define OUTMOD_4        (4*0x20u)  /* PWM output mode: 4 - toggle */
#define OUTMOD_5        (5*0x20u)  /* PWM output mode: 5 - Reset */
#define OUTMOD_6        (6*0x20u)  /* PWM output mode: 6 - PWM toggle/set */
#define OUTMOD_7        (7*0x20u)  /* PWM output mode: 7 - PWM reset/set */
#define CCIS_0          (0*0x1000u) /* Capture input select: 0 - CCIxA */
#define CCIS_1          (1*0x1000u) /* Capture input select: 1 - CCIxB */
#define CCIS_2          (2*0x1000u) /* Capture input select: 2 - GND */
#define CCIS_3          (3*0x1000u) /* Capture input select: 3 - Vcc */
#define CM_0            (0*0x4000u) /* Capture mode: 0 - disabled */
#define CM_1            (1*0x4000u) /* Capture mode: 1 - pos. edge */
#define CM_2            (2*0x4000u) /* Capture mode: 1 - neg. edge */
#define CM_3            (3*0x4000u) /* Capture mode: 1 - both edges */

/* Alternate register names */
#define CCTL0           TACCTL0   /* Timer A Capture/Compare Control 0 */
#define CCTL1           TACCTL1   /* Timer A Capture/Compare Control 1 */
#define CCTL2           TACCTL2   /* Timer A Capture/Compare Control 2 */
#define CCR0            TACCR0    /* Timer A Capture/Compare 0 */
#define CCR1            TACCR1    /* Timer A Capture/Compare 1 */
#define CCR2            TACCR2    /* Timer A Capture/Compare 2 */
#define CCTL0_          TACCTL0   /* Timer A Capture/Compare Control 0 */
#define CCTL1_          TACCTL1   /* Timer A Capture/Compare Control 1 */
#define CCTL2_          TACCTL2   /* Timer A Capture/Compare Control 2 */
#define CCR0_           TACCR0    /* Timer A Capture/Compare 0 */
#define CCR1_           TACCR1    /* Timer A Capture/Compare 1 */
#define CCR2_           TACCR2    /* Timer A Capture/Compare 2 */

/* TA3IV Definitions */
#define TAIV_NONE           (0x0000)    /* No Interrupt pending */
#define TAIV_TACCR1         (0x0002)    /* TACCR1_CCIFG */
#define TAIV_TACCR2         (0x0004)    /* TACCR2_CCIFG */
#define TAIV_6              (0x0006)    /* Reserved */
#define TAIV_8              (0x0008)    /* Reserved */
#define TAIV_TAIFG          (0x000A)    /* TAIFG */

 

/*-------------------------------------------------------------------------
 *   Timer1 A2
 *-------------------------------------------------------------------------*/


 /* Timer1_A5 Interrupt Vector Word */ 
__no_init volatile unsigned __READ short TA1IV @ 0x011E;  
 

__no_init volatile union
{
  unsigned short TA1CTL;  /* Timer1_A5 Control */ 
  
  struct
  {
    unsigned short IFG           : 1; 
    unsigned short IE            : 1; 
    unsigned short CLR           : 1; 
    unsigned short MC0           : 1; 
    unsigned short MC1           : 1; 
    unsigned short ID0           : 1; 
    unsigned short ID1           : 1; 
    unsigned short SSEL0         : 1; 
    unsigned short SSEL1         : 1; 
  } TA1CTL_bit;  
} @ 0x0180;


enum {
  IFG                 = 0x0001,
  IE                  = 0x0002,
  CLR                 = 0x0004,
  MC0                 = 0x0008,
  MC1                 = 0x0010,
  ID0                 = 0x0020,
  ID1                 = 0x0040,
  SSEL0               = 0x0080,
  SSEL1               = 0x0100,
};


__no_init volatile union
{
  unsigned short TA1CCTL0;  /* Timer1_A5 Capture/Compare Control 0 */ 
  
  struct
  {
    unsigned short TA2_CCIFG     : 1; 
    unsigned short TA2_COV       : 1; 
    unsigned short TA2_OUT       : 1; 
    unsigned short TA2_CCI       : 1; 
    unsigned short TA2_CCIE      : 1; 
    unsigned short TA2_OUTMOD0   : 1; 
    unsigned short TA2_OUTMOD1   : 1; 
    unsigned short TA2_OUTMOD2   : 1; 
    unsigned short TA2_CAP       : 1; 
    unsigned short TA2_SCCI      : 1; 
    unsigned short TA2_SCS       : 1; 
    unsigned short TA2_CCIS0     : 1; 
    unsigned short TA2_CCIS1     : 1; 
    unsigned short TA2_CM0       : 1; 
    unsigned short TA2_CM1       : 1; 
  } TA1CCTL0_bit;  
} @ 0x0182;


enum {
  TA2_CCIFG           = 0x0001,
  TA2_COV             = 0x0002,
  TA2_OUT             = 0x0004,
  TA2_CCI             = 0x0008,
  TA2_CCIE            = 0x0010,
  TA2_OUTMOD0         = 0x0020,
  TA2_OUTMOD1         = 0x0040,
  TA2_OUTMOD2         = 0x0080,
  TA2_CAP             = 0x0100,
  TA2_SCCI            = 0x0200,
  TA2_SCS             = 0x0400,
  TA2_CCIS0           = 0x0800,
  TA2_CCIS1           = 0x1000,
  TA2_CM0             = 0x2000,
  TA2_CM1             = 0x4000,
};


__no_init volatile union
{
  unsigned short TA1CCTL1;  /* Timer1_A5 Capture/Compare Control 1 */ 
  
  struct
  {
    unsigned short TA2_CCIFG     : 1; 
    unsigned short TA2_COV       : 1; 
    unsigned short TA2_OUT       : 1; 
    unsigned short TA2_CCI       : 1; 
    unsigned short TA2_CCIE      : 1; 
    unsigned short TA2_OUTMOD0   : 1; 
    unsigned short TA2_OUTMOD1   : 1; 
    unsigned short TA2_OUTMOD2   : 1; 
    unsigned short TA2_CAP       : 1; 
    unsigned short TA2_SCCI      : 1; 
    unsigned short TA2_SCS       : 1; 
    unsigned short TA2_CCIS0     : 1; 
    unsigned short TA2_CCIS1     : 1; 
    unsigned short TA2_CM0       : 1; 
    unsigned short TA2_CM1       : 1; 
  } TA1CCTL1_bit;  
} @ 0x0184;




 /* Timer1_A5 */ 
__no_init volatile unsigned short TA1R @ 0x0190;  
 

 /* Timer1_A5 Capture/Compare 0 */ 
__no_init volatile unsigned short TA1CCR0 @ 0x0192;  
 

 /* Timer1_A5 Capture/Compare 1 */ 
__no_init volatile unsigned short TA1CCR1 @ 0x0194;  
 
 
#define __MSP430_HAS_T1A2__        /* Definition to show that Module is available */

 

/*-------------------------------------------------------------------------
 *   USCI
 *-------------------------------------------------------------------------*/


 /* USCI A0 Control Register 0 */ 
__no_init volatile unsigned char UCA0CTL0 @ 0x0060;  
 

 /* USCI A0 Control Register 1 */ 
__no_init volatile unsigned char UCA0CTL1 @ 0x0061;  
 

 /* USCI A0 Baud Rate 0 */ 
__no_init volatile unsigned char UCA0BR0 @ 0x0062;  
 

 /* USCI A0 Baud Rate 1 */ 
__no_init volatile unsigned char UCA0BR1 @ 0x0063;  
 

 /* USCI A0 Modulation Control */ 
__no_init volatile unsigned char UCA0MCTL @ 0x0064;  
 

 /* USCI A0 Status Register */ 
__no_init volatile unsigned char UCA0STAT @ 0x0065;  
 

 /* USCI A0 Receive Buffer */ 
__no_init volatile unsigned __READ char UCA0RXBUF @ 0x0066;  
 

 /* USCI A0 Transmit Buffer */ 
__no_init volatile unsigned char UCA0TXBUF @ 0x0067;  
 

 /* USCI A0 LIN Control */ 
__no_init volatile unsigned char UCA0ABCTL @ 0x005D;  
 

 /* USCI A0 IrDA Transmit Control */ 
__no_init volatile unsigned char UCA0IRTCTL @ 0x005E;  
 

 /* USCI A0 IrDA Receive Control */ 
__no_init volatile unsigned char UCA0IRRCTL @ 0x005F;  
 

 /* USCI B0 Control Register 0 */ 
__no_init volatile unsigned char UCB0CTL0 @ 0x0068;  
 

 /* USCI B0 Control Register 1 */ 
__no_init volatile unsigned char UCB0CTL1 @ 0x0069;  
 

 /* USCI B0 Baud Rate 0 */ 
__no_init volatile unsigned char UCB0BR0 @ 0x006A;  
 

 /* USCI B0 Baud Rate 1 */ 
__no_init volatile unsigned char UCB0BR1 @ 0x006B;  
 

 /* USCI B0 I2C Interrupt Enable Register */ 
__no_init volatile unsigned char UCB0I2CIE @ 0x006C;  
 

 /* USCI B0 Status Register */ 
__no_init volatile unsigned char UCB0STAT @ 0x006D;  
 

 /* USCI B0 Receive Buffer */ 
__no_init volatile unsigned __READ char UCB0RXBUF @ 0x006E;  
 

 /* USCI B0 Transmit Buffer */ 
__no_init volatile unsigned char UCB0TXBUF @ 0x006F;  
 

 /* USCI B0 I2C Own Address */ 
__no_init volatile unsigned char UCB0I2COA @ 0x0118;  
 

 /* USCI B0 I2C Slave Address */ 
__no_init volatile unsigned char UCB0I2CSA @ 0x011A;  
 
 
#define __MSP430_HAS_USCI__           /* Definition to show that Module is available */


// UART-Mode Bits
#define UCPEN               (0x80)    /* Async. Mode: Parity enable */
#define UCPAR               (0x40)    /* Async. Mode: Parity     0:odd / 1:even */
#define UCMSB               (0x20)    /* Async. Mode: MSB first  0:LSB / 1:MSB */
#define UC7BIT              (0x10)    /* Async. Mode: Data Bits  0:8-bits / 1:7-bits */
#define UCSPB               (0x08)    /* Async. Mode: Stop Bits  0:one / 1: two */
#define UCMODE1             (0x04)    /* Async. Mode: USCI Mode 1 */
#define UCMODE0             (0x02)    /* Async. Mode: USCI Mode 0 */
#define UCSYNC              (0x01)    /* Sync-Mode  0:UART-Mode / 1:SPI-Mode */

// SPI-Mode Bits
#define UCCKPH              (0x80)    /* Sync. Mode: Clock Phase */
#define UCCKPL              (0x40)    /* Sync. Mode: Clock Polarity */ 
#define UCMST               (0x08)    /* Sync. Mode: Master Select */

// I2C-Mode Bits
#define UCA10               (0x80)    /* 10-bit Address Mode */
#define UCSLA10             (0x40)    /* 10-bit Slave Address Mode */ 
#define UCMM                (0x20)    /* Multi-Master Environment */
//#define res               (0x10)    /* reserved */
#define UCMODE_0            (0x00)    /* Sync. Mode: USCI Mode: 0 */
#define UCMODE_1            (0x02)    /* Sync. Mode: USCI Mode: 1 */
#define UCMODE_2            (0x04)    /* Sync. Mode: USCI Mode: 2 */
#define UCMODE_3            (0x06)    /* Sync. Mode: USCI Mode: 3 */

// UART-Mode Bits
#define UCSSEL1             (0x80)    /* USCI 0 Clock Source Select 1 */
#define UCSSEL0             (0x40)    /* USCI 0 Clock Source Select 0 */
#define UCRXEIE             (0x20)    /* RX Error interrupt enable */
#define UCBRKIE             (0x10)    /* Break interrupt enable */                     
#define UCDORM              (0x08)    /* Dormant (Sleep) Mode */
#define UCTXADDR            (0x04)    /* Send next Data as Address */
#define UCTXBRK             (0x02)    /* Send next Data as Break */
#define UCSWRST             (0x01)    /* USCI Software Reset */

// SPI-Mode Bits
//#define res               (0x20)    /* reserved */
//#define res               (0x10)    /* reserved */
//#define res               (0x08)    /* reserved */
//#define res               (0x04)    /* reserved */
//#define res               (0x02)    /* reserved */

// I2C-Mode Bits
//#define res               (0x20)    /* reserved */
#define UCTR                (0x10)    /* Transmit/Receive Select/Flag */
#define UCTXNACK            (0x08)    /* Transmit NACK */
#define UCTXSTP             (0x04)    /* Transmit STOP */
#define UCTXSTT             (0x02)    /* Transmit START */
#define UCSSEL_0            (0x00)    /* USCI 0 Clock Source: 0 */
#define UCSSEL_1            (0x40)    /* USCI 0 Clock Source: 1 */
#define UCSSEL_2            (0x80)    /* USCI 0 Clock Source: 2 */
#define UCSSEL_3            (0xC0)    /* USCI 0 Clock Source: 3 */

#define UCBRF3              (0x80)    /* USCI First Stage Modulation Select 3 */
#define UCBRF2              (0x40)    /* USCI First Stage Modulation Select 2 */
#define UCBRF1              (0x20)    /* USCI First Stage Modulation Select 1 */
#define UCBRF0              (0x10)    /* USCI First Stage Modulation Select 0 */
#define UCBRS2              (0x08)    /* USCI Second Stage Modulation Select 2 */
#define UCBRS1              (0x04)    /* USCI Second Stage Modulation Select 1 */
#define UCBRS0              (0x02)    /* USCI Second Stage Modulation Select 0 */
#define UCOS16              (0x01)    /* USCI 16-times Oversampling enable */

#define UCBRF_0             (0x00)    /* USCI First Stage Modulation: 0 */
#define UCBRF_1             (0x10)    /* USCI First Stage Modulation: 1 */
#define UCBRF_2             (0x20)    /* USCI First Stage Modulation: 2 */
#define UCBRF_3             (0x30)    /* USCI First Stage Modulation: 3 */
#define UCBRF_4             (0x40)    /* USCI First Stage Modulation: 4 */
#define UCBRF_5             (0x50)    /* USCI First Stage Modulation: 5 */
#define UCBRF_6             (0x60)    /* USCI First Stage Modulation: 6 */
#define UCBRF_7             (0x70)    /* USCI First Stage Modulation: 7 */
#define UCBRF_8             (0x80)    /* USCI First Stage Modulation: 8 */
#define UCBRF_9             (0x90)    /* USCI First Stage Modulation: 9 */
#define UCBRF_10            (0xA0)    /* USCI First Stage Modulation: A */
#define UCBRF_11            (0xB0)    /* USCI First Stage Modulation: B */
#define UCBRF_12            (0xC0)    /* USCI First Stage Modulation: C */
#define UCBRF_13            (0xD0)    /* USCI First Stage Modulation: D */
#define UCBRF_14            (0xE0)    /* USCI First Stage Modulation: E */
#define UCBRF_15            (0xF0)    /* USCI First Stage Modulation: F */

#define UCBRS_0             (0x00)    /* USCI Second Stage Modulation: 0 */
#define UCBRS_1             (0x02)    /* USCI Second Stage Modulation: 1 */
#define UCBRS_2             (0x04)    /* USCI Second Stage Modulation: 2 */
#define UCBRS_3             (0x06)    /* USCI Second Stage Modulation: 3 */
#define UCBRS_4             (0x08)    /* USCI Second Stage Modulation: 4 */
#define UCBRS_5             (0x0A)    /* USCI Second Stage Modulation: 5 */
#define UCBRS_6             (0x0C)    /* USCI Second Stage Modulation: 6 */
#define UCBRS_7             (0x0E)    /* USCI Second Stage Modulation: 7 */

#define UCLISTEN            (0x80)    /* USCI Listen mode */
#define UCFE                (0x40)    /* USCI Frame Error Flag */
#define UCOE                (0x20)    /* USCI Overrun Error Flag */
#define UCPE                (0x10)    /* USCI Parity Error Flag */
#define UCBRK               (0x08)    /* USCI Break received */
#define UCRXERR             (0x04)    /* USCI RX Error Flag */
#define UCADDR              (0x02)    /* USCI Address received Flag */
#define UCBUSY              (0x01)    /* USCI Busy Flag */
#define UCIDLE              (0x02)    /* USCI Idle line detected Flag */

//#define res               (0x80)    /* reserved */
//#define res               (0x40)    /* reserved */
//#define res               (0x20)    /* reserved */
//#define res               (0x10)    /* reserved */
#define UCNACKIE            (0x08)    /* NACK Condition interrupt enable */
#define UCSTPIE             (0x04)    /* STOP Condition interrupt enable */
#define UCSTTIE             (0x02)    /* START Condition interrupt enable */
#define UCALIE              (0x01)    /* Arbitration Lost interrupt enable */

#define UCSCLLOW            (0x40)    /* SCL low */
#define UCGC                (0x20)    /* General Call address received Flag */
#define UCBBUSY             (0x10)    /* Bus Busy Flag */
#define UCNACKIFG           (0x08)    /* NAK Condition interrupt Flag */
#define UCSTPIFG            (0x04)    /* STOP Condition interrupt Flag */
#define UCSTTIFG            (0x02)    /* START Condition interrupt Flag */
#define UCALIFG             (0x01)    /* Arbitration Lost interrupt Flag */

#define UCIRTXPL5           (0x80)    /* IRDA Transmit Pulse Length 5 */
#define UCIRTXPL4           (0x40)    /* IRDA Transmit Pulse Length 4 */
#define UCIRTXPL3           (0x20)    /* IRDA Transmit Pulse Length 3 */
#define UCIRTXPL2           (0x10)    /* IRDA Transmit Pulse Length 2 */
#define UCIRTXPL1           (0x08)    /* IRDA Transmit Pulse Length 1 */
#define UCIRTXPL0           (0x04)    /* IRDA Transmit Pulse Length 0 */
#define UCIRTXCLK           (0x02)    /* IRDA Transmit Pulse Clock Select */
#define UCIREN              (0x01)    /* IRDA Encoder/Decoder enable */

#define UCIRRXFL5           (0x80)    /* IRDA Receive Filter Length 5 */
#define UCIRRXFL4           (0x40)    /* IRDA Receive Filter Length 4 */
#define UCIRRXFL3           (0x20)    /* IRDA Receive Filter Length 3 */
#define UCIRRXFL2           (0x10)    /* IRDA Receive Filter Length 2 */
#define UCIRRXFL1           (0x08)    /* IRDA Receive Filter Length 1 */
#define UCIRRXFL0           (0x04)    /* IRDA Receive Filter Length 0 */
#define UCIRRXPL            (0x02)    /* IRDA Receive Input Polarity */
#define UCIRRXFE            (0x01)    /* IRDA Receive Filter enable */

//#define res               (0x80)    /* reserved */
//#define res               (0x40)    /* reserved */
#define UCDELIM1            (0x20)    /* Break Sync Delimiter 1 */
#define UCDELIM0            (0x10)    /* Break Sync Delimiter 0 */
#define UCSTOE              (0x08)    /* Sync-Field Timeout error */
#define UCBTOE              (0x04)    /* Break Timeout error */
//#define res               (0x02)    /* reserved */
#define UCABDEN             (0x01)    /* Auto Baud Rate detect enable */

#define UCGCEN              (0x8000)  /* I2C General Call enable */
#define UCOA9               (0x0200)  /* I2C Own Address 9 */
#define UCOA8               (0x0100)  /* I2C Own Address 8 */
#define UCOA7               (0x0080)  /* I2C Own Address 7 */
#define UCOA6               (0x0040)  /* I2C Own Address 6 */
#define UCOA5               (0x0020)  /* I2C Own Address 5 */
#define UCOA4               (0x0010)  /* I2C Own Address 4 */
#define UCOA3               (0x0008)  /* I2C Own Address 3 */
#define UCOA2               (0x0004)  /* I2C Own Address 2 */
#define UCOA1               (0x0002)  /* I2C Own Address 1 */
#define UCOA0               (0x0001)  /* I2C Own Address 0 */

#define UCSA9               (0x0200)  /* I2C Slave Address 9 */
#define UCSA8               (0x0100)  /* I2C Slave Address 8 */
#define UCSA7               (0x0080)  /* I2C Slave Address 7 */
#define UCSA6               (0x0040)  /* I2C Slave Address 6 */
#define UCSA5               (0x0020)  /* I2C Slave Address 5 */
#define UCSA4               (0x0010)  /* I2C Slave Address 4 */
#define UCSA3               (0x0008)  /* I2C Slave Address 3 */
#define UCSA2               (0x0004)  /* I2C Slave Address 2 */
#define UCSA1               (0x0002)  /* I2C Slave Address 1 */
#define UCSA0               (0x0001)  /* I2C Slave Address 0 */
 

/*-------------------------------------------------------------------------
 *   Watchdog Timer
 *-------------------------------------------------------------------------*/


__no_init volatile union
{
  unsigned short WDTCTL;  /* Watchdog Timer Control */ 
  
  struct
  {
    unsigned short WDTIS0        : 1; 
    unsigned short WDTIS1        : 1; 
    unsigned short WDTSSEL       : 1; 
    unsigned short WDTCNTCL      : 1; 
    unsigned short WDTTMSEL      : 1; 
    unsigned short WDTNMI        : 1; 
    unsigned short WDTNMIES      : 1; 
    unsigned short WDTHOLD       : 1; 
    unsigned short               : 8; 
  } WDTCTL_bit;  
} @ 0x0120;


enum {
  WDTIS0              = 0x0001,
  WDTIS1              = 0x0002,
  WDTSSEL             = 0x0004,
  WDTCNTCL            = 0x0008,
  WDTTMSEL            = 0x0010,
  WDTNMI              = 0x0020,
  WDTNMIES            = 0x0040,
  WDTHOLD             = 0x0080,
};

 
#define __MSP430_HAS_WDT__            /* Definition to show that Module is available */
    
#define WDTPW               (0x5A00)
  
/* WDT-interval times [1ms] coded with Bits 0-2 */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MDLY_32         (WDTPW+WDTTMSEL+WDTCNTCL)                         /* 32ms interval (default) */
#define WDT_MDLY_8          (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS0)                  /* 8ms      */
#define WDT_MDLY_0_5        (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1)                  /* 0.5ms    */
#define WDT_MDLY_0_064      (WDTPW+WDTTMSEL+WDTCNTCL+WDTIS1+WDTIS0)           /* 0.064ms  */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ADLY_1000       (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL)                 /* 1000ms   */
#define WDT_ADLY_250        (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS0)          /* 250ms    */
#define WDT_ADLY_16         (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1)          /* 16ms     */
#define WDT_ADLY_1_9        (WDTPW+WDTTMSEL+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0)   /* 1.9ms    */
/* Watchdog mode -> reset after expired time */
/* WDT is clocked by fSMCLK (assumed 1MHz) */
#define WDT_MRST_32         (WDTPW+WDTCNTCL)                                  /* 32ms interval (default) */
#define WDT_MRST_8          (WDTPW+WDTCNTCL+WDTIS0)                           /* 8ms      */
#define WDT_MRST_0_5        (WDTPW+WDTCNTCL+WDTIS1)                           /* 0.5ms    */
#define WDT_MRST_0_064      (WDTPW+WDTCNTCL+WDTIS1+WDTIS0)                    /* 0.064ms  */
/* WDT is clocked by fACLK (assumed 32KHz) */
#define WDT_ARST_1000       (WDTPW+WDTCNTCL+WDTSSEL)                          /* 1000ms   */
#define WDT_ARST_250        (WDTPW+WDTCNTCL+WDTSSEL+WDTIS0)                   /* 250ms    */
#define WDT_ARST_16         (WDTPW+WDTCNTCL+WDTSSEL+WDTIS1)                   /* 16ms     */
#define WDT_ARST_1_9        (WDTPW+WDTCNTCL+WDTSSEL+WDTIS1+WDTIS0)            /* 1.9ms    */
  
/* INTERRUPT CONTROL */
/* These two bits are defined in the Special Function Registers */
/* #define WDTIE               0x01 */
/* #define WDTIFG              0x01 */
 

/*-------------------------------------------------------------------------
 *   TLV Calibration Data
 *-------------------------------------------------------------------------*/


 /* TLV CHECK SUM */ 
__no_init volatile unsigned __READ short TLV_CHECKSUM @ 0x10C0;  
 

 /* TLV TAG_DCO30 TAG */ 
__no_init volatile unsigned __READ char TLV_DCO_30_TAG @ 0x10F6;  
 

 /* TLV TAG_DCO30 LEN */ 
__no_init volatile unsigned __READ char TLV_DCO_30_LEN @ 0x10F7;  
 

 /* TLV ADC12_1 TAG */ 
__no_init volatile unsigned __READ char TLV_ADC12_1_TAG @ 0x10DA;  
 

 /* TLV ADC12_1 LEN */ 
__no_init volatile unsigned __READ char TLV_ADC12_1_LEN @ 0x10DB;  
 
 
/* TLV Calibration Data Structure */
#define TAG_DCO_30             (0x01)    /* Tag for DCO30  Calibration Data */
#define TAG_ADC12_1            (0x10)    /* Tag for ADC12_1 Calibration Data */
#define TAG_EMPTY              (0xFE)    /* Tag for Empty Data Field in Calibration Data */

#define CAL_ADC_25T85          (0x0007)  /* Index for 2.5V/85Deg Cal. Value */
#define CAL_ADC_25T30          (0x0006)  /* Index for 2.5V/30Deg Cal. Value */
#define CAL_ADC_25VREF_FACTOR  (0x0005)  /* Index for 2.5V Ref. Factor */
#define CAL_ADC_15T85          (0x0004)  /* Index for 1.5V/85Deg Cal. Value */
#define CAL_ADC_15T30          (0x0003)  /* Index for 1.5V/30Deg Cal. Value */
#define CAL_ADC_15VREF_FACTOR  (0x0002)  /* Index for ADC 1.5V Ref. Factor */
#define CAL_ADC_OFFSET         (0x0001)  /* Index for ADC Offset */
#define CAL_ADC_GAIN_FACTOR    (0x0000)  /* Index for ADC Gain Factor */

#define CAL_DCO_16MHZ          (0x0000)  /* Index for DCOCTL  Calibration Data for 16MHz */
#define CAL_BC1_16MHZ          (0x0001)  /* Index for BCSCTL1 Calibration Data for 16MHz */
#define CAL_DCO_12MHZ          (0x0002)  /* Index for DCOCTL  Calibration Data for 12MHz */
#define CAL_BC1_12MHZ          (0x0003)  /* Index for BCSCTL1 Calibration Data for 12MHz */
#define CAL_DCO_8MHZ           (0x0004)  /* Index for DCOCTL  Calibration Data for 8MHz */
#define CAL_BC1_8MHZ           (0x0005)  /* Index for BCSCTL1 Calibration Data for 8MHz */
#define CAL_DCO_1MHZ           (0x0006)  /* Index for DCOCTL  Calibration Data for 1MHz */
#define CAL_BC1_1MHZ           (0x0007)  /* Index for BCSCTL1 Calibration Data for 1MHz */

 

/*-------------------------------------------------------------------------
 *   Calibration Data in Info Mem
 *-------------------------------------------------------------------------*/


 /* DCOCTL  Calibration Data for 16MHz */ 
__no_init volatile unsigned __READ char CALDCO_16MHZ @ 0x10F8;  
 

 /* BCSCTL1 Calibration Data for 16MHz */ 
__no_init volatile unsigned __READ char CALBC1_16MHZ @ 0x10F9;  
 

 /* DCOCTL  Calibration Data for 12MHz */ 
__no_init volatile unsigned __READ char CALDCO_12MHZ @ 0x10FA;  
 

 /* BCSCTL1 Calibration Data for 12MHz */ 
__no_init volatile unsigned __READ char CALBC1_12MHZ @ 0x10FB;  
 

 /* DCOCTL  Calibration Data for 8MHz */ 
__no_init volatile unsigned __READ char CALDCO_8MHZ @ 0x10FC;  
 

 /* BCSCTL1 Calibration Data for 8MHz */ 
__no_init volatile unsigned __READ char CALBC1_8MHZ @ 0x10FD;  
 

 /* DCOCTL  Calibration Data for 1MHz */ 
__no_init volatile unsigned __READ char CALDCO_1MHZ @ 0x10FE;  
 

 /* BCSCTL1 Calibration Data for 1MHz */ 
__no_init volatile unsigned __READ char CALBC1_1MHZ @ 0x10FF;  
 



#pragma language=default
#endif  /* __IAR_SYSTEMS_ICC__  */


/************************************************************
* Timer A interrupt vector value
************************************************************/

#define TAIV_CCIFG1         (2)       /* Capture/compare 1 */
#define TAIV_CCIFG2         (4)       /* Capture/compare 2 */
#define TAIV_TAIFG          (10)      /* Timer overflow */

/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/

#define PORT1_VECTOR        (2 * 2u)  /* 0xFFE4 Port 1 */
#define PORT2_VECTOR        (3 * 2u)  /* 0xFFE6 Port 2 */
#define ADC10_VECTOR        (5 * 2u)  /* 0xFFEA ADC10 */
#define USCIAB0TX_VECTOR    (6 * 2u)  /* 0xFFEC USCI A0/B0 Transmit */
#define USCIAB0RX_VECTOR    (7 * 2u)  /* 0xFFEE USCI A0/B0 Receive */
#define TIMER0_A1_VECTOR    (8 * 2u)  /* 0xFFF0 Timer0 A CC1-2, TA */
#define TIMER0_A0_VECTOR    (9 * 2u)  /* 0xFFF2 Timer0 A CC0 */
#define WDT_VECTOR          (10 * 2u) /* 0xFFF4 Watchdog Timer */
#define COMPARATORA_VECTOR  (11 * 2u) /* 0xFFF6 Comparator A */
#define TIMER1_A1_VECTOR    (12 * 2u) /* 0xFFF8 Timer1 A CC1-2, TA */
#define TIMER1_A0_VECTOR    (13 * 2u) /* 0xFFFA Timer1 A CC0 */
#define NMI_VECTOR          (14 * 2u) /* 0xFFFC Non-maskable */
#define RESET_VECTOR        (15 * 2u) /* 0xFFFE Reset [Highest Priority] */



#endif /* __IO430xxxx */


