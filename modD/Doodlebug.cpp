/**********************************************************************************
 * Name: Chermaine Cheang
 * Date: April 28, 2016
 * Description: Doodlebug class implementation file
 * *****************************************************************************/

#include "Doodlebug.hpp"

//Doodlebug class default constructor, which also calls Critter class default constructor
Doodlebug::Doodlebug():Critter()
{
   count = 0;
   setStarve(true);
   starveCount =0;
}

/***************************************************************************
 * Function: setCount()
 * Description: set count to value passed in
 * Parameter: an integer 
 * Pre-condition: Doodlebug exists
 * Post-condition: count is set
 * ***********************************************************************/
void Doodlebug::setCount(int& value)
{
   count = value;
}

/***************************************************************************
 * Function: getCount()
 * Description: return count
 * Pre-condition: Doodlebug exists
 * ***********************************************************************/
int Doodlebug::getCount()
{
   return count;
}

/***************************************************************************
 * Function: Breed()
 * Description: create a new Doodlebug object if count is 8 and return the pointer
 * of the new Doodlebug, and set new Doodlebug x and y coordinates according
 * to parameter passed in, and set marker to moved to prevent new Doodlebug from 
 * moving this roun
 * Parameter: int, int
 * Pre-condition: count = 8
 * Post-condition: a new Doodlebug is created
 * ***********************************************************************/
Doodlebug* Doodlebug::Breed(int x, int y)
{
   Doodlebug* pDoo;
   pDoo = new Doodlebug();
   pDoo->setMarker(true);
   pDoo->setXCoor(x);
   pDoo->setYCoor(y);
   return pDoo;
}

/***************************************************************************
 * Function: getID()
 * Description: return 'D' for Doodlebug 
 * Pre-condition: Doodlebug exists
 * ***********************************************************************/
char Doodlebug::getID()
{
   return 'D';
}

/***************************************************************************
 * Function: setStarve()
 * Description: set starve to value passed in; true = Doodlebug is starving
 * false = Doodlebug is not starving
 * Parameter: bool 
 * Pre-condition: Doodlebug exists
 * Post-condition: starve is set
 * ***********************************************************************/
void Doodlebug::setStarve(bool cond)
{
   starve = cond;
}

/***************************************************************************
 * Function: getStarve()
 * Description: return Doodlebug's current starving condition
 * Pre-condition: Doodlebug exists
 * ***********************************************************************/
bool Doodlebug::getStarve()
{
   return starve;
}

/***************************************************************************
 * Function: Eat()
 * Description: called when Doodlebug is moving into a cell that contains
 * an Ant; Eat the Ant by freeing memory allocated for the Ant
 * Parameter: Critter*
 * Pre-condition: Doodlebug exists
 * Post-condition: memory is freed
 * ***********************************************************************/
void Doodlebug::Eat(Critter* c)
{
   delete c;  //free memory allocated for Ant
   setStarve(false); //set starve to false to indicate that Doodlebug has eaten
   setStarveCount(0);//reset starveCount to 0
}

/***************************************************************************
 * Function: Starve()
 * Description: called when Doodlebug did not eat; count the number of 
 * steps taken by that Doodlebug and if count == 3 and starve is true, 
 * kill Doodlebug by freeing the memory allocated for it
 * Parameter: Critter*
 * Pre-condition: Doodlebug exists
 * Post-condition: increment starveCount; Doodlebug is killed if starveCount 
 * is 3 and starve is true
 * ***********************************************************************/
bool Doodlebug::Starve(Critter* c)
{
   starveCount+=1;
   if (starveCount == 3 && starve == true)
   { 
      delete c;
      return true;   
   }
   else
      return false;
}

/***************************************************************************
 * Function: setStarveCount()
 * Description: set starveCount to value passed in (primarily for resetting
 * starveCount once Doodlebug ate)
 * Parameter: an integer 
 * Pre-condition: Doodlebug exists
 * Post-condition: starveCount is set
 * ***********************************************************************/
void Doodlebug::setStarveCount(int num)
{
   starveCount = num;
}

