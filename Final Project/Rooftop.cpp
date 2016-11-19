/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Rooftop class implementation file
 * ****************************************************************************/

#include "Rooftop.hpp"

/*******************************************************************************
 * Function: Rooftop()
 * Description: default constructor
 * ****************************************************************************/
Rooftop::Rooftop():Space()
{
   this->nameOfSpace = "Rooftop";
   this->rescued = false;
   createObject();
}

/*******************************************************************************
 * Function: Rooftop()
 * Description: default destructor
 * ****************************************************************************/
Rooftop::~Rooftop()
{
}

/*******************************************************************************
 * Function: createObject()
 * Description: create objects in rooftop
 * Pre-condition: rooftop exists
 * Post-condition: objects in rooftop are created and added to queue container
 * ****************************************************************************/
void Rooftop::createObject()
{
   Object* body = new Object("Body", "", false, "");
   setObjectInSpace(body);
}
  
/*******************************************************************************
 * Function: setRescued
 * Description: set variable rescued
 * Parameter: bool
 * Pre-condition: rooftop exists
 * Post-condition: variable is set
 * ****************************************************************************/
void Rooftop::setRescued(bool val)
{
   this->rescued = val;
}

/*******************************************************************************
 * Function: getRescued()
 * Description: return variable rescued
 * Pre-condition: rooftop exists
 * ****************************************************************************/
bool Rooftop::getRescued() const
{
   return this->rescued;
}
