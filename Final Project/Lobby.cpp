/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Lobby class implementation file
 * ****************************************************************************/

#include "Lobby.hpp"

/*******************************************************************************
 * Function: setDoorToBasement()
 * Description: set pointer to basement
 * Parameter: Space*
 * Pre-condition: lobby exists
 * Post-condition: the pointer to basement is set
 * ****************************************************************************/
void Lobby::setDoorToBasement(Space* doorToBasement)
{
   this->doorToBasement = doorToBasement;
}

/*******************************************************************************
 * Function: getDoorToBasement()
 * Description: return pointer to basement
 * Pre-condition: lobby exists
 * ****************************************************************************/
Space* Lobby::getDoorToBasement() const
{
   return this->doorToBasement;
}

/*******************************************************************************
 * Function: setDoorToRooftop()
 * Description: set pointer to rooftop
 * Parameter: Space*
 * Pre-condition: lobby exists
 * Post-condition: the pointer to rooftop is set
 * ****************************************************************************/
void Lobby::setDoorToRooftop(Space* doorToRoof)
{
   this->doorToRooftop = doorToRoof;
}

/*******************************************************************************
 * Function: getDoorToRooftop()
 * Description: return pointer to rooftop
 * Pre-condition: lobby exists
 * ****************************************************************************/
Space* Lobby::getDoorToRooftop() const
{
   return this->doorToRooftop;
}

/*******************************************************************************
 * Function: Lobby()
 * Description: default constructor
 * ****************************************************************************/
Lobby::Lobby():Space()
{
   this->nameOfSpace = "Lobby";
   this->doorToBasement = NULL;
   this->doorToRooftop = NULL;
   this->builtBasement = false;
   this->builtRooftop = false;
   createObject();
}

/*******************************************************************************
 * Function: ~Lobby()
 * Description: default destructor
 * ****************************************************************************/
Lobby::~Lobby()
{
}

/*******************************************************************************
 * Function: createObject()
 * Description: create objects needed in Lobby and add to queue
 * Pre-condition: Lobby exists
 * Post-condition: objects are created and added to queue
 * ****************************************************************************/
void Lobby::createObject()
{
   Object* receptionistDesk = new Object("Receptionist Desk", 
   "There's a computer on the left, a phone right next to it,\ntwo drawers underneath and a log book for checking in visitors", false, "");
   Object* drawer1 = new Object("First Drawer", "There's a lot of stationary in the drawer.", 
                     false, "");
   Object* drawer2 = new Object("Second Drawer", "A pile of papers is in this drawer.", 
                     true, "It's a name tag!!!");

   setObjectInSpace(receptionistDesk);
   setObjectInSpace(drawer1);
   setObjectInSpace(drawer2);
}

/*******************************************************************************
 * Function: setBuiltBasement()
 * Description: set variable builtBasement
 * Parameter: bool
 * Pre-condition: Lobby exists
 * Post-condition: variable is set
 * ****************************************************************************/
void Lobby::setBuiltBasement(bool val)
{
   this->builtBasement = val;
}

/*******************************************************************************
 * Function: setBuiltRooftop()
 * Description: set variable builtRooftop
 * Parameter: bool
 * Pre-condition: Lobby exists
 * Post-condition: variable is set
 * ****************************************************************************/
void Lobby::setBuiltRooftop(bool val)
{
   this->builtRooftop = val;
}

/*******************************************************************************
 * Function: getBuiltBasement()
 * Description: return variable builtBasement
 * Pre-condition: Lobby exists
 * ****************************************************************************/
bool Lobby::getBuiltBasement() const
{  
   return this->builtBasement;
}

/*******************************************************************************
 * Function: getBuiltBasement()
 * Description: return variable builtBasement
 * Pre-condition: Lobby exists
 * ****************************************************************************/
bool Lobby::getBuiltRooftop() const
{
   return this->builtRooftop;
}
