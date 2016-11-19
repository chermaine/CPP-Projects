/**********************************************************************************
 * Name: Chermaine Cheang
 * Date: April 12, 2016
 * Description: Ant class implementation file
 * *****************************************************************************/

#include "Ant.hpp"

//Ant class default constructor, which also calls Critter class default constructor
Ant::Ant():Critter()
{
   count = 0;
}

/***************************************************************************
 * Function: setCount()
 * Description: set count to value passed in
 * Parameter: an integer 
 * Pre-condition: Ant exists
 * Post-condition: count is set
 * ***********************************************************************/
void Ant::setCount(int& value)
{
   count = value;
}

/***************************************************************************
 * Function: getCount()
 * Description: return count
 * Pre-condition: Ant exists
 * ***********************************************************************/
int Ant::getCount()
{
   return count;
}

/***************************************************************************
 * Function: Breed()
 * Description: create a new Ant object if count is 3 and return the pointer
 * to the new Ant, and set new Ant x and y coordinates according
 * to parameter passed in, and set marker to moved to prevent new Ant from 
 * moving this roun
 * Parameter: int, int
 * Pre-condition: count = 3
 * Post-condition: a new Ant is created
 * ***********************************************************************/
Ant* Ant::Breed(int x, int y)
{
   Ant* pAnt;
   pAnt = new Ant();
   pAnt->setXCoor(x);
   pAnt->setYCoor(y);
   pAnt->setMarker(true);
   return pAnt;
}

/***************************************************************************
 * Function: getID()
 * Description: return 'A' for Ant 
 * Pre-condition: Ant exists
 * ***********************************************************************/
char Ant::getID()
{
   return 'A';
}

/***************************************************************************
 * Function: Eat()
 * Description: a pure virtual function inherited from Critter; its an empty
 * function to prevent Ant class from being abstract class
 * Parameter: Critter*
 * Pre-condition: Ant exists
 * Post-condition: Ant class is not abstract
 * ***********************************************************************/
void Ant::Eat(Critter* c)
{
}
