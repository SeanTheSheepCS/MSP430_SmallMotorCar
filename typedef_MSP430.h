/**********************************************************************
* Typedef file
*
* File name: typedef_MSP430.h
**********************************************************************/

/************************ Revision History ****************************

YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2009-10-01  First release.

************************************************************************/

#ifndef __TYPEDEF_HEADER
#define __TYPEDEF_HEADER

typedef unsigned char u8;
typedef char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef long s32;

typedef  void (*fnCode_type)(void);

typedef enum {FALSE = 0, TRUE = 1} bool;

#endif /* __TYPDEF_HEADER */
