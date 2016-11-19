/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Space class specification file
 * ****************************************************************************/

#include "Space.hpp"
#include <iostream>

/*******************************************************************************
 * Function: setDoorToN()
 * Description: set pointer doorToN to room on the North of this space
 * Parameter: Space*
 * Pre-condition: both spaces exist
 * Pre-condition: doorToN is now pointing to the North room
 * ****************************************************************************/
void Space::setDoorToN(Space* door)
{
   this->doorToN = door;
}

/*******************************************************************************
 * Function: setDoorToS()
 * Description: set pointer doorToS to room on the Sorth of this space
 * Parameter: Space*
 * Pre-condition: both spaces exist
 * Pre-condition: doorToS is now pointing to the Sorth room
 * ****************************************************************************/
void Space::setDoorToS(Space* door)
{
   this->doorToS = door;
}

/*******************************************************************************
 * Function: setDoorToE()
 * Description: set pointer doorToE to room on the East of this space
 * Parameter: Space*
 * Pre-condition: both spaces exist
 * Pre-condition: doorToE is now pointing to the East room
 * ****************************************************************************/
void Space::setDoorToE(Space* door)
{
   this->doorToE = door;
}

/*******************************************************************************
 * Function: setDoorToW()
 * Description: set pointer doorToW to room on the West of this space
 * Parameter: Space*
 * Pre-condition: both spaces exist
 * Pre-condition: doorToW is now pointing to the West room
 * ****************************************************************************/
void Space::setDoorToW(Space* door)
{
   this->doorToW = door;
}

/*******************************************************************************
 * Function: getDoorToN()
 * Description: return pointer to the space that is currently North of this space
 * Pre-condition: both space exist
 * ****************************************************************************/
Space* Space::getDoorToN() const
{
   return this->doorToN; 
}

/*******************************************************************************
 * Function: getDoorToS()
 * Description: return pointer to the space that is currently Sorth of this space
 * Pre-condition: both space exist
 * ****************************************************************************/
Space* Space::getDoorToS() const
{
   return this->doorToS; 
}

/*******************************************************************************
 * Function: getDoorToE()
 * Description: return pointer to the space that is currently East of this space
 * Pre-condition: both space exist
 * ****************************************************************************/
Space* Space::getDoorToE() const
{
   return this->doorToE; 
}

/*******************************************************************************
 * Function: getDoorToW()
 * Description: return pointer to the space that is currently West of this space
 * Pre-condition: both space exist
 * ****************************************************************************/
Space* Space::getDoorToW() const
{
   return this->doorToW; 
}

/*******************************************************************************
 * Function: setNameOfSpace()
 * Description: set the name of current space
 * Parameter: std::string
 * Pre-condition: space exists
 * Post-condition: nameOfSpace is set
 * ****************************************************************************/
void Space::setNameOfSpace(std::string name)
{
   this->nameOfSpace = name;
}

/*******************************************************************************
 * Function: getNameOfSpace()
 * Description: get the name of current space
 * Pre-condition: space exist
 * ****************************************************************************/
std::string Space::getNameOfSpace() const
{
   return this->nameOfSpace;
}

/*******************************************************************************
 * Function: setObjectInSpace()
 * Description: add Object passed in to queue
 * Parameter: Object*
 * Pre-condition: space and object exist
 * Post-condition: object is added to queue
 * ****************************************************************************/
void Space::setObjectInSpace(Object* obj)
{
   objectInSpace.push(obj);
}

/*******************************************************************************
 * Function: getObjectInSpace()
 * Description: remove the first object added to queue and return the object
 * Pre-condition: space and object exist
 * Post-condition: object is removed from queue and returned
 * ****************************************************************************/
Object* Space::getObjectInSpace()
{
   Object* temp = objectInSpace.front();
   objectInSpace.pop();
   return temp;
}

/******************************************************************************
 * Function: checkObjectInSpace()
 * Description: check if container has elements in it before calling getObjectInSpace()
 * Pre-condition: Space exists
 * Post-condition: return true for queue is empty, false for not
 * ****************************************************************************/
bool Space:: checkObjectInSpace()
{
   if (!objectInSpace.empty())
      return false;
   else
      return true;
}
/*******************************************************************************
 * Function: Space()
 * Description: Default constructor for Space class
 * ****************************************************************************/
Space::Space()
{
   this->doorToN = NULL;
   this->doorToS = NULL;
   this->doorToE = NULL;
   this->doorToW = NULL;
   this->nameOfSpace = "";
}

/*******************************************************************************
 * Function: ~Space()
 * Description: default destructor
 * ****************************************************************************/
Space::~Space()
{
}





