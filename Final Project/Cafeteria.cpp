/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Cafeteria class implementation file
 * ****************************************************************************/

#include "Cafeteria.hpp"

/*******************************************************************************
 * Function: Cafeteria()
 * Description: default constructor
 * ****************************************************************************/
Cafeteria::Cafeteria():Space()
{
   this->nameOfSpace = "Cafeteria";
   this->newSpace = NULL;
   this->builtKitchen = false;
   createObject();
}

/*******************************************************************************
 * Function: ~Cafeteria()
 * Description: default destructor
 * Pre-condition: end of program
 * ****************************************************************************/
Cafeteria::~Cafeteria()
{
}

/*******************************************************************************
 * Function: createObject();
 * Description: create objects needed in cafeteria and add to queue
 * Pre-condition: cafeteria exists
 * Post-condition: objects are created and added
 * ****************************************************************************/
void Cafeteria::createObject()
{
   Object* diningTable = new Object("Dining Table", 
                         "Rows of table and benches.", true, 
                         "Found a name tag underneath one of the table!!!");
   Object* counter = new Object ("Food Counter", "There is where food is usually served.", false, "");
   setObjectInSpace(diningTable);
   setObjectInSpace(counter);
}

/*******************************************************************************
 * Function: setNewSpace()
 * Description: set pointer to the fifth space
 * Parameter: Space*
 * Pre-condition: Cafeteria exists
 * Post-condition: the fifth pointer for Cafeteria is set
 * ****************************************************************************/
void Cafeteria::setNewSpace(Space* newSpace)
{
   this->newSpace = newSpace;
}

/*******************************************************************************
 * Function: getNewSpace()
 * Description: return pointer of the fifth room
 * Pre-condition: Cafeteria exists
 * ****************************************************************************/
Space* Cafeteria::getNewSpace() const
{
   return this->newSpace;
}

/*******************************************************************************
 * Function: setBuiltKitchen()
 * Description: set builtKitchen to true if Kitchen space has been created, else
 * builtKitchen remain false
 * Parameter: bool
 * Pre-condition: Cafeteria exists
 * Post-condition: builtKitchen is updated
 * ****************************************************************************/
void Cafeteria::setBuiltKitchen(bool val)
{
   this->builtKitchen = val;
}
  
/*******************************************************************************
 * Function: getBuiltKitchen()
 * Description: return builtKitchen
 * Pre-condition: Cafeteria exists
 * ****************************************************************************/
bool Cafeteria::getBuiltKitchen() const
{
   return this->builtKitchen;
}
