/**********************************************************************
* Definitions for utility functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-13  File created

************************************************************************/

#include "utilities.h"
#include "small_car-efwd-01.h"

void WaitThisManyMilliseconds(u32 u32NumberOfMillisecondsToWait)
{
  /* Since TIME_1MS = 3, multiplying the time we need by 3 gives an okay estimate of how many cycles to wait. */
  u32 u32numberOfCyclesToWait = (u32NumberOfMillisecondsToWait*TIME_1MS);
  /* Since two instructions need to be executed every iteration of the loop, i is incremented by 2 each time. */
  for(u32 i = 0; i < u32numberOfCyclesToWait; i+=2);
}
  
u8 GenerateRandomishNumberOneOrZero()
{
  static u8 au8RandomNumberSequence[] = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1};
  static u8 u8LengthOfRandomNumberSequence = 20;
  static u8 u8CurrentIndexInList = 0;
  //Picks numbers from a sequence that was pregenerated using a random number generator
  //This function is not really random at all
  while(u8CurrentIndexInList >= u8LengthOfRandomNumberSequence)
  {
    u8CurrentIndexInList -= u8LengthOfRandomNumberSequence;
  }
  return au8RandomNumberSequence[u8LengthOfRandomNumberSequence];
}