/*****************************************************************
 * Name: Chermaine Cheang
 * Date: April 6, 2016
 * Description: Critter class function implementation file
 * **************************************************************/

#include "Critter.hpp"
#include <cstdlib>

/***************************************************************************
 * Function: setXCoor()
 * Description: set xCoor to parameter passed in
 * Parameter: int 
 * Pre-condition: Critter exists
 * Post-condition: xCoor is set
 * ***********************************************************************/
void Critter::setXCoor(int& x)
{
   xCoor = x;
}
 
/***************************************************************************
 * Function: setYCoor()
 * Description: set yCoor to parameter passed in
 * Parameter: int
 * Pre-condition: critter exists
 * Post-condition: yCoor is set
 * ***********************************************************************/
void Critter::setYCoor(int& y)
{
   yCoor = y;
}

/***************************************************************************
 * Function: getNumMoves()
 * Description: return numMoves
 * Pre-condition: critter exists
 * ***********************************************************************/
int Critter::getNumMoves()
{
   return numMoves;
}
  
/***************************************************************************
 * Function: getXCoor()
 * Description: return x coordinate
 * Pre-condition: critter exists
 * ***********************************************************************/
int Critter::getXCoor()
{
   return xCoor;
}

/***************************************************************************
 * Function: getYCoor()
 * Description: return y coordinates
 * Pre-condition: critter exists
 * ***********************************************************************/
int Critter::getYCoor()
{
   return yCoor;
}

/***************************************************************************
 * Function: setMarker()
 * Description: set marker to parameter passed in; true = moved; false=not moved
 * Parameter: bool true or false
 * Pre-condition: Critter exists
 * Post-condition: marker is set
 * ***********************************************************************/
void Critter::setMarker(bool move)
{ 
   marker = move;
}

/***************************************************************************
 * Function: getMarker()
 * Description: return current critter's mark 
 * Pre-condition: Critter exists
 * ***********************************************************************/
bool Critter::getMarker()
{
   return marker;
}

/***************************************************************************
 * Function: randMove()
 * Description: generate a move of critter by random and validate if movement
 * is valid, that is if movement will cause critter to move out of grid's boundaries
 * and return that result
 * Parameter: number of rows and columns
 * Pre-condition: critter exists
 * Post-condition: return true if move is valid, return false if move is not valid
 * ***********************************************************************/
bool Critter::randMove(int row, int col)
{
   bool cond; //act as a flag 
   int move, xTemp, yTemp;

   move =1 + rand()%4; //generate a random number between 1 and 4 with each number represents
                        //one of the four directions of movement
                        //1 = move up
                        //2 = move down
                        //3 = move to the right
                        //4 = move to the left
 
   xTemp = xCoor;  //hold current critter's x-coordinate (row)
   yTemp = yCoor;  //hold current critter's y-coordinate (column)
   switch (move)
   {
      case 1: //move up one row, minus 1 from yTemp
         yTemp -= 1;
         break;

      case 2: //move down one row, plus 1 to yTemp
         yTemp += 1;
         break;

      case 3: //move to the next column (move to the right), plus 1 to xTemp
         xTemp += 1;
         break;
      case 4: //move to the previous column (move to the left), minus 1 from xTemp
         xTemp -= 1;
         break;
   }

   //check if movement caused critter to move out of grid's borders
   if (xTemp < 1 || xTemp > col || yTemp < 1 || yTemp > row)
   {
      numMoves++; //increment numMoves
      cond = false; //set flag to false so program will terminate
   }

   //if movement is valid
   else {
      setXCoor(xTemp); //update current xCoor to xTemp(new x-coor after movement) 
      setYCoor(yTemp); //update current yCoor to yTemp(new y-coor after movement)
      numMoves++; //increment numMoves
      cond = true; //set flag to true so program will continue until critter moves out of bound
   }
   return cond;
}


/***************************************************************************
 * Function: Critter()
 * Description: critter class default constructor 
 * Post-condition: new Critter is created 
 * ***********************************************************************/
Critter::Critter()
{
   numMoves = 0;
   setMarker(false);
}  

/***************************************************************************
 * Function: getID()
 * Description: return 'C' for critter 
 * Pre-condition: Critter exists
 * ***********************************************************************/
char Critter::getID()
{
   return 'C';
}

