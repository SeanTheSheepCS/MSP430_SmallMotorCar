/**********************************************************************
* Definitions for utility functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-13  File created

************************************************************************/

#include "utilities.h"

void WaitThisManyMilliseconds(u32 u32NumberOfMillisecondsToWait)
{
  for(u32 i = 0; i < (u32NumberOfMillisecondsToWait*12); i++);
}