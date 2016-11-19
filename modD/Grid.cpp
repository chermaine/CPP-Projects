/**************************************************************************
 * Name: Chermaine Cheang
 * Date: April 12, 2016
 * Description: Grid class function implementation file
 * ***********************************************************************/

#include "Grid.hpp"
#include <iostream>
#include <cstdlib>

/***************************************************************************
 * Function: Grid()
 * Description: default constructor
 * Post-condition: Grid is created
 * ***********************************************************************/
Grid::Grid()
{
   pCrit = NULL;
}

/***************************************************************************
 * Function: Grid()
 * Description: constructor
 * Parameter: int number of row, column, number of ant, and number of Doodlebug 
 * Pre-condition: inputs are valid
 * Post-condition: Grid is created with number of critters specified
 * ***********************************************************************/
Grid::Grid(int row, int col, int aNum, int dNum)
{
   myGrid = initialize(row, col);
   fillGrid(row, col);
   setHeight(row);
   setWidth(col);
   createAnt(aNum);
   createDoo(dNum);
}

/***************************************************************************
 * Function: createAnt()
 * Description: create x number of ants according to user's input
 * Parameter: int number of ants inputted by user
 * Pre-condition: grid exists
 * Post-condition: x number of ants are created
 * ***********************************************************************/
void Grid::createAnt(int num)
{
   for (int i=0;i<num; i++) //create the number of ants according to user's input
   {
      pCrit = new Ant();
      randStart(pCrit); //randomly generate a start location for each ant
   }
}

/***************************************************************************
 * Function: createDoo()
 * Description: create x number of doodlebugs according to user's input
 * Parameter: number of doodlebugs inputted by user
 * Pre-condition: grid exists
 * Post-condition: x number of doodlebugs are created
 * ***********************************************************************/
void Grid::createDoo(int num)
{
   for (int i=0;i<num; i++) //create the number of doodlebugs according to user's input
   {
      pCrit = new Doodlebug();
      randStart(pCrit);
   }
}
   
/***************************************************************************
 * Function: initialize()
 * Description: to dynamically allocate memory for 2D array of Critter pointers
 * Parameter: number of rows and columns
 * Pre-condition: number of rows and columns are valid
 * Post-condition: 2D array of pointers is created
 * ***********************************************************************/
Critter*** Grid::initialize(int row, int col)
{
   Critter*** temp;

   temp = new Critter**[row]; //creating first chunk of memory
   for (int i=0; i<row; i++)
   {
      temp[i] = new Critter*[col]; //creating the rest of the array
   }
   return temp;
}

/***************************************************************************
 * Function: updateLocation()
 * Description: update location of critter with parameters passed in
 * Parameter: pointer to Critter, x-coordinate and y-coordinate
 * Pre-condition: Both grid and critter exists 
 * Post-condition: cell now point to this critter
 * ***********************************************************************/
void Grid::updateLocation(Critter* c, int x, int y)
{
   //array subscript starts from 0, so minus 1 from parameters passed in
   //if this cell is pointing to NULL, assign it to critter's address passed in
   //if this cell is pointing to a critter, assign it to NULL
   Critter* temp = c;
   if (myGrid[y-1][x-1]==NULL)
      myGrid[y-1][x-1]=c;
   else 
      myGrid[y-1][x-1]=NULL;
}

/***************************************************************************
 * Function: fillGrid()
 * Description: fill grid with NULL pointers
 * Parameter: number of rows and columns
 * Pre-condition: grid exists
 * Post-condition: all cell in grid is a NULL pointer
 * ***********************************************************************/
void Grid::fillGrid(int row, int col)
{
   for (int i=0; i < row ; i++)
   {
      for (int j=0; j< col; j++)
      {
         myGrid[i][j] = NULL;
      }
   }
}

/***************************************************************************
 * Function: printGrid()
 * Description: display content of grid
 * Parameter: number of rows and number of columns of grid
 * Pre-condition: grid exists
 * Post-condition: screen display current grid's content
 * ***********************************************************************/
void Grid::printGrid(int row, int col)
{
   for (int i=0; i < row ; i++)
   {
      for (int j=0; j< col; j++) 
      {
         if (myGrid[i][j] == NULL) //if pointer is not holding any address of Critter
         {                         //cout ' '
            std::cout << '.' ;
         }
         else                      //if pointer is currently holding an address of Critter
         {                         //cout Critter's ID/Ant's ID/ Doodlebug's ID
            std::cout << myGrid[i][j]->getID();
         }
      }
      std:: cout << std::endl;
   }
}

/***************************************************************************
 * Function: setHeight()
 * Description: set number of rows inputted by user to width
 * Parameter: number of rows inputted by user
 * Pre-condition: grid exists
 * Post-condition: height is set
 * ***********************************************************************/
void Grid::setHeight(int& row)
{
   height = row;
}


/*******************************************************************************
 * Function: getHeight()
 * Description: return height, ie number of rows
 * Pre-condition: grid exists
 * **************************************************************************/
int Grid::getHeight()
{
   return height;
}

/***************************************************************************
 * Function: setWidth()
 * Description: set number of columns inputted by user to width
 * Parameter: number of columns inputted by user
 * Pre-condition: grid exists
 * Post-condition: width is set
 * ************************************************************************/
void Grid::setWidth(int& col)
{
   width = col;
}

/*******************************************************************************
 * Function: getWidth()
 * Description: return width, ie number of columns 
 * Pre-condition: grid exists
 * **************************************************************************/
int Grid::getWidth()
{
   return width;
}
/********************************************************************************
 * Function: checkMove
 * Description: check if movement of critter is valid, if valid call moveCrit()
 * Pre-condition: if grid is not full
 * Post-condition: critter is moved
 * ******************************************************************************/
void Grid::checkMove()
{
   bool move, mark;
   int cpyX, cpyY, newX, newY, dir, breedCount, starveCount;

   //loop through entire array and check if current cell is holding any Critter's address
   for (int i=0; i<height; i++)
   {
      for (int j=0; j<width; j++)
      {
         if (myGrid[i][j] != NULL)
         {
            mark = myGrid[i][j]->getMarker();
            cpyX = myGrid[i][j]->getXCoor();
            cpyY = myGrid[i][j]->getYCoor();
            if (mark == false) //check if current critter has been moved, if critter has
            {                  //not moved, call randMove()
               move = myGrid[i][j]->randMove(width,height);

               //get current Critter's move count, increment count, and set Critter's count
               breedCount = myGrid[i][j]->getCount();
               breedCount += 1;
               myGrid[i][j]->setCount(breedCount);

               if (move == true) //if randMove() return true, that is critter is not moving
               {                 //out of boundaries, call moveCrit()
                  newX = myGrid[i][j]->getXCoor();
                  newY = myGrid[i][j]->getYCoor();
                  moveCrit(cpyX,cpyY,newX,newY);
               }

               else //if randMove() return false, that is critter is moving out of boundaries
               {  
                  //if current Critter is an Ant and breedCount is 3
                  //reset breedCount to 0 because Ant cannot move this round, hence cannot breed 
                  if (myGrid[i][j]->getID()=='A'&& breedCount == 3)
                  {
                     breedCount = 0;
                     myGrid[i][j]->setCount(breedCount);
                  }

                  //if current critter is a Doodlebug 
                  if (myGrid[i][j]->getID()=='D')
                  {
                     //check if this Doodlebug is starving (has not eaten in 3 consecutive steps)
                     //if true, Doodlebug has died from starvation, assign pointer to NULL
                     if (static_cast<Doodlebug*>(myGrid[i][j])->Starve(myGrid[i][j]))
                        myGrid[i][j]=NULL;
                     
                     //if Doodlebug is not starving and breedCount is 8
                     //reset breedCount to 0 because Doodlebug cannot move this round, hence
                     //cannot breed
                     else if (breedCount == 8)
                     {
                        breedCount = 0;
                        myGrid[i][j]->setCount(breedCount);
                     }
                  }
                   
               }   
            }
         }
      }
   }
}

/*********************************************************************************
 * Function: moveCrit()
 * Description: move critter after checking if randMove() is valid. If the cell 
 * the critter wants to move to is free, move the critter to that cell.
 * If the cell is not free, reset critter x and y coordinates to coordinates
 * before calling randMove(). If ant's count is 3, call Breed() and set parent's 
 * coordinates before moving to this new Ant's coordinate. If doodlebug's wants to 
 * move to a cell that contains Ant, doodlebug will eat that Ant, and take over that
 * cell. 
 * Pre-condition: randMove() returned true
 * Post-condition: move critter and breed a new ant if count is 3 and move is valid;
 * move critter and eat the ant if move is valid
 * *********************************************************************************/
void Grid::moveCrit(int oldX, int oldY, int newX, int newY)
{
   Critter* temp = NULL;
   int count =0;
   count = myGrid[oldY-1][oldX-1]->getCount();
   //check if the cell the critter wants to move to is free
   //if the cell is free, then move critter to that cell and set marker to moved
   if (myGrid[newY-1][newX-1]==NULL)
   {
      temp = myGrid[oldY-1][oldX-1];
      myGrid[oldY-1][oldX-1]=NULL;
      myGrid[newY-1][newX-1] = temp;
      myGrid[newY-1][newX-1]->setMarker(true);

      //if current critter is an Ant
      if (myGrid[newY-1][newX-1]->getID() == 'A')
      { 
         if (count == 3) //if current Ant's count is 3, call Ant's Breed(), and assign 
         {               //previous cell coordinates to new Ant
            temp = myGrid[newY-1][newX-1]->Breed(oldX,oldY);
            myGrid[oldY-1][oldX-1] = temp;
            //reset parent Ant's count to 0
            count = 0;
            myGrid[newY-1][newX-1]->setCount(count);
         }
      }

      //if current critter is a Doodlebug
      else if (myGrid[newY-1][newX-1]->getID() == 'D')
      {
         //since Doodlebug is moving to an empty cell, it will not eat for this round,
         //setStarve to true
         static_cast<Doodlebug*>(myGrid[newY-1][newX-1])->setStarve(true);

         //if Doodlebug has been starving for three consecutive steps, the Doodlebug will die
         //assign cell that is holding this Doodlebug to NULL after calling Starve()
         if (static_cast<Doodlebug*>(myGrid[newY-1][newX-1])->Starve(myGrid[newY-1][newX-1]))
            myGrid[newY-1][newX-1]=NULL;

         //if Doodlebug's current count is 8, call Breed() and assign parent's coordinate to
         //child Doodlebug 
         else if (count == 8)
         {
            temp = myGrid[newY-1][newX-1]->Breed(oldX, oldY);
            myGrid[oldY-1][oldX-1] = temp;
            //reset parent count to 0
            count = 0;
            myGrid[newY-1][newX-1]->setCount(count);
         }
      }
   }

   //cell is not free
   //if the critter that wants to move is a Doodlebug and if the cell that this critter
   //wants to move to has an Ant, call Doodlebug's Eat() and move Doodlebug to the Ant's cell 
   else if (myGrid[newY-1][newX-1]->getID()=='A' && myGrid[oldY-1][oldX-1]->getID()=='D')
   {
      myGrid[oldY-1][oldX-1]->Eat(myGrid[newY-1][newX-1]);
      temp = myGrid[oldY-1][oldX-1];
      myGrid[newY-1][newX-1] = temp;
      myGrid[oldY-1][oldX-1] = NULL;
      myGrid[newY-1][newX-1]->setMarker(true);

      //if Doodlebug's current breedCount is 8, call Doodlebug's Breed() and assign parent's 
      //Doodlebug coordinates to child coordinates
      if (myGrid[newY-1][newX-1]->getID()=='D' && count == 8)
      {
         temp = myGrid[newY-1][newX-1]->Breed(oldX, oldY);
         myGrid[oldY-1][oldX-1] = temp;
         //reset parent's count to 0
         count = 0;
         myGrid[newY-1][newX-1]->setCount(count);
      }
   }
   //if the cell is not free, reset critter's x and y coordinates to original
   //coordinates before calling randMove() and mark critter as moved for this round
   //reset Ant's count to 0 if current Ant's count is 3
   //reset Doodlebug's count to 0 if current Doodlebug's count is 8
   else
   {
      myGrid[oldY-1][oldX-1]->setXCoor(oldX);
      myGrid[oldY-1][oldX-1]->setYCoor(oldY);
      myGrid[oldY-1][oldX-1]->setMarker(true);

      //current critter is an Ant
      if (myGrid[oldY-1][oldX-1]->getID()=='A')
      {
         if (count == 3)
         {
            count = 0;
            myGrid[oldY-1][oldX-1]->setCount(count);
         }
      }

      //current critter is a Doodlebug
      else if (myGrid[oldY-1][oldX-1]->getID()=='D')
      {
         //Doodlebug is not eating this round, set starve to true
         static_cast<Doodlebug*>(myGrid[oldY-1][oldX-1])->setStarve(true);   

         //if Doodlebug has been starving for 3 rounds, assign current cell to NULL   
         if (static_cast<Doodlebug*>(myGrid[oldY-1][oldX-1])->Starve(myGrid[oldY-1][oldX-1]))
            myGrid[oldY-1][oldX-1]=NULL;

         else if (count == 8)
         {
            count = 0;
            myGrid[oldY-1][oldX-1]->setCount(count);
         }
      }
   }
}

/*******************************************************************************
 * Function: updateMarker()
 * Description: update Critter's marker to not moved after every step
 * Pre-condition: All critter in grid must be step through before calling this function
 * Post-condition: All critter in grid are now mark as not moved
 * *****************************************************************************/ 
void Grid::resetMarker()
{
   for (int i=0; i<height; i++)
   {
      for (int j=0; j<width; j++)
      {
         if (myGrid[i][j] != NULL)
            myGrid[i][j]->setMarker(false);
      }
   }
}

/**********************************************************************************
 * Function: randStart()
 * Description: randomly generate a starting position for Critter object, set Critter's
 * x and y coordinates and update Critter's location
 * Parameters: pointer to Critter object
 * Pre-condition: Critter object must already been created before calling this function
 * Post-condition: Critter's x and y coordinates are set, and Critter starting location
 * is updated on Grid.
 * ********************************************************************************/
void Grid::randStart(Critter* c)
{
   int randX, randY;
   //randomly generate a x and y coordinates, if either coordinates is greater than
   //grid's boundaries and if the cell is already occupied, 
   //regenerate coordinates
   do 
   { 
      randX = rand()%10 + 1;
      randY = rand()%10 + 1;
   } while (randX>width || randY>height || myGrid[randY-1][randX-1]!=NULL);

   if (myGrid[randY-1][randX-1]==NULL)
   {
      updateLocation(c, randX,randY);
      c->setXCoor(randX);
      c->setYCoor(randY);
   }
}
/****************************************************************************
 * Function: checkGrid()
 * Description: check to see if current Grid is full
 * Post-condition: return true is grid is full and false if grid is not full
 * **************************************************************************/
bool Grid::checkGrid()
{
   bool full = true;
   for (int i=0; i<height; i++)
   {
      for (int j=0; j<width; j++)
      {
         if (myGrid[i][j]==NULL) //if current cell is not pointing to anything
            full = false;        //this mean that the grid is not full yet
                                 //hence, set condition to false
      }
   }
   return full;
}

/***************************************************************************
 * Function: ~Grid()
 * Description: to free dynamically allocated memory for this program
 * Pre-condition: program terminating
 * Post-condition: memory is free
 * ***********************************************************************/
Grid::~Grid()
{
   for (int i=0; i<height; i++)
   {
      for (int j=0; j<width; j++)
      {
         if (myGrid[i][j]!=NULL)
            delete myGrid[i][j];
      }
      delete [] myGrid[i];
   }
   delete [] myGrid;
}
