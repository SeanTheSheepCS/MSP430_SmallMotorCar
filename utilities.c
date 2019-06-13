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
  
u8 GenerateRandomishNumberOneOrZero()
{
  static u8 au8RandomNumberSequence[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1};
  static u8 u8LengthOfRandomNumberSequence = 20;
  static u8 u8CurrentIndexInList = 0;
  //Picks numbers from a sequence that was pregenerated using a random number generator
  //NOTE: this function is not truly random.
  while(u8CurrentIndexInList >= u8LengthOfRandomNumberSequence)
  {
    u8CurrentIndexInList -= u8LengthOfRandomNumberSequence;
  }
  return au8RandomNumberSequence[u8LengthOfRandomNumberSequence];
}