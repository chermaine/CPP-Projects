/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Break room implementation file
 * ****************************************************************************/

#include "BreakRoom.hpp"

/*******************************************************************************
 * Function: BreakRoom()
 * Description: default constructor
 * ****************************************************************************/
BreakRoom::BreakRoom():Space()
{
   this->nameOfSpace = "Break Room";
   createObject();
}
  
/*******************************************************************************
 * Function: ~BreakRoom()
 * Description: class destructor
 * Pre-condition: end of program
 * ****************************************************************************/
BreakRoom::~BreakRoom()
{
}

/*******************************************************************************
 * Function: createObject()
 * Description: create objects needed for break room and add to queue
 * Pre-condition: break room exist
 * Post-condition: objects are created and added
 * ****************************************************************************/
void BreakRoom::createObject()
{
   Object* pool = new Object("Pool Table", 
                  "Some of the ball are on the table. \nLook's like someone was playing a game here.",
                   false, "");
   Object* couches = new Object("Couches", "Black leather couches are against the wall.", false, "");
   Object* tv = new Object("TV", "32 inch LCD TV is hanging on the wall.", false, "");

   setObjectInSpace(pool);
   setObjectInSpace(couches);
   setObjectInSpace(tv);
}
