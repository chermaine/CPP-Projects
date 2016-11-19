/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Basement class implementation file
 * ****************************************************************************/

#include "Basement.hpp"

/*******************************************************************************
 * Function: Basement()
 * Description: default constructor
 * ****************************************************************************/
Basement::Basement():Space()
{
   this->nameOfSpace = "Basement";
   this->rescued = false;
   createObject();
}

/*******************************************************************************
 * Function: ~Basement()
 * Description: class destructor
 * Pre-condition: end of program
 * ****************************************************************************/
Basement::~Basement()
{
}

/*******************************************************************************
 * Function: createObject()
 * Description: create objects needed in basement and add to its queue container
 * Pre-condition: basement exists
 * Post-condition: objects are created and add to queue
 * ****************************************************************************/
void Basement::createObject()
{
   Object* body = new Object("Body", "", false, "");
   setObjectInSpace(body);
}

/*******************************************************************************
 * Function: setRescued()
 * Description: when player successfully rescued the person in this space, this
 * will set the rescued variable to true, so this room can be deleted once the
 * player left this room
 * Parameter: bool
 * Pre-condition: player rescued the person in this room
 * Post-condition: this space will soon be deleted
 * ****************************************************************************/
void Basement::setRescued(bool val)
{
   this->rescued = val;
}

/*******************************************************************************
 * Function: getRescued()
 * Description: accessor function for rescued variable
 * Pre-condition: Basement exists
 * Post-condition: rescued value is returned
 * ****************************************************************************/
bool Basement::getRescued() const
{
   return this->rescued;
}
