/**********************************************************************
* Definitions for reciever functions
**********************************************************************/

/************************ Revision History ****************************
YYYY-MM-DD  Comments
-------------------------------------------------------------------------------------------
2019-06-04  File created

************************************************************************/

#include "recievers.h"
#include "io430f2112.h"
#include "utilities.h"

bool hasRecieverDetectedAWall(RecieverInformation rInfoReciever)
{
  if(rInfoReciever.u16pPortAddress == (u16*)0x0021)  /* If the reciever belongs to port one... */
  {
    if(!(P1IN & rInfoReciever.u8PinIdentifier))
    {
      //WaitThisManyMilliseconds(DEBOUNCE_TIME_MS);
      //if(!(P1IN & rInfoReciever.u8PinIdentifier))
      //{
        return TRUE;
      //}
    }
  }
  else if(rInfoReciever.u16pPortAddress == (u16*)0x0029)  /* If the reciever belongs to port two... */
  {
    if(!(P2IN & rInfoReciever.u8PinIdentifier))
    {
      //WaitThisManyMilliseconds(DEBOUNCE_TIME_MS);
      //if(!(P2IN & rInfoReciever.u8PinIdentifier))
      //{
        return TRUE;
      //}
    }
  }
  else if(rInfoReciever.u16pPortAddress == (u16*)0x0019)  /* If the reciever belongs to port three... */
  {
    if(!(P3IN & rInfoReciever.u8PinIdentifier))
    {
      //WaitThisManyMilliseconds(DEBOUNCE_TIME_MS);
      //if(!(P3IN & rInfoReciever.u8PinIdentifier))
      //{
        return TRUE;
      //}
    }
  }
  return FALSE;
}
