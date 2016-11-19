/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Kitchen class implementation file
 * ****************************************************************************/

#include "Kitchen.hpp"

/*******************************************************************************
 * Function: Kitchen()
 * Description: default constructor
 * ****************************************************************************/
Kitchen::Kitchen():Space()
{
   this->nameOfSpace = "Kitchen";
   this->rescued = false;
   createObject();
}

/*******************************************************************************
 * Function: Kitchen()
 * Description: default destructor
 * ****************************************************************************/
Kitchen::~Kitchen()
{
}

/*******************************************************************************
 * Function: createObject()
 * Description: create objects needed in kitchen and add to queue
 * Pre-condition: kitchen exists
 * Post-condition: objects are created and added
 * ****************************************************************************/
void Kitchen::createObject()
{
   Object* body = new Object ("Body", "Someone is in there!!!", false, "");
   setObjectInSpace(body);
}

/*******************************************************************************
 * Function: setRescued()
 * Description: set rescued variable
 * Parameter: bool
 * Pre-condition: Kitchen exists
 * Post-condition: variale is set
 * ****************************************************************************/
void Kitchen::setRescued(bool val)
{
   this->rescued = val;
}

/*******************************************************************************
 * Function: getRescued()
 * Description: return rescued variable
 * Pre-condition: Kitchen exists
 * ****************************************************************************/
bool Kitchen::getRescued() const
{
   return this->rescued;
}
