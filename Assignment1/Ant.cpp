/**********************************************************
 * Name: Chermaine Cheang
 * Date: April 5, 2016
 * Description: Ant class implementation file
 * *********************************************************/

#include "Ant.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

//Ant class default constructor
Ant::Ant()
{
   pGrid = NULL; //set pointer variable pGrid to NULL
}

//Ant class constructor
Ant::Ant(Grid* g)
{
   pGrid = g;   //set pointer variable pGrid to parameter passed in
   color = ' '; //set cell's color to white
}

//Ant class setXCoor():set x-coordinate
void Ant::setXCoor(int& x)
{
   xCoor = x;
}

//Ant class setYCoor(): set y-coordinate
void Ant::setYCoor(int& y)
{
   yCoor = y;
}

//Ant class getXCoor(): return x-coordinate
int Ant::getXCoor()
{
   return xCoor;
}

//Ant class getYCoor(): return y-coordinate
int Ant::getYCoor()
{
   return yCoor;
}

//Ant class setColor(): set cell's color
void Ant::setColor(char& col)
{
   color = col;
}

//Ant class getColor(): return cell's color
char Ant::getColor()
{
   return color;
}

//Ant class setFace(): set current ant's direction
void Ant::setFace(int& dir)
{
   face = dir;
}

//Ant class getFace(): return ant's direction
int Ant::getFace()
{
   return face;
}

//Ant class randFace(): randomly generate the starting direction the ant will face
void Ant::randFace()
{
   unsigned seed; //random generator seed
   seed = time(0);//use time function to get a "seed" value for srand
   srand(seed);

   int num = rand()%4 + 1; //generate a random number between 1 and 4 with each 
                           //number represents a direction
                           //1 = UP
                           //2 = DOWN
                           //3 = Left
                           //4 = Right
   setFace(num); //use the number generated to set direction ant facing 
}

//Ant class userFace(): set direction ant is facing to user's input
void Ant::userFace(int dir)
{
   setFace(dir);
}

//Ant class randStart(): randomly generate a starting location for ant
void Ant::randStart()
{
   unsigned seed;
   seed = time(0);
   srand(seed);

   int gHeight, gWidth;
   gHeight = pGrid->getHeight(); //get grid's number of rows
   gWidth = pGrid->getWidth();   //get grid's number of columns

   int randX, randY;
   randX = rand()%10 + 1; //randomly generate a value for x-coordinate, limiting 
                          //value between 1 and 10 to reduce time required

   randY = rand()%10 + 1; //randomly generate a value for y-coordinate, limiting
                          //value between 1 and 10 to reduce time required

   while (randX > gWidth) //check if randX is greater than grid's number or rows
      randX = rand();     //to avoid a starting x-coordinate that is out of bound
   
   while (randY > gHeight)//check if randY is greater than grid's number of columns
      randY = rand();     //to prevent a starting y-coordinate that is out bound

   setXCoor(randX);
   setYCoor(randY);
   pGrid->updateLocation(randX, randY); //update current ant's location with random
                                        //coordinates generated
}

//Ant class userStart(): set x and y coordinates according to user's input and
//update ant's location
void Ant::userStart(int x, int y)
{
   setXCoor(x);
   setYCoor(y);
   pGrid->updateLocation(x, y);
}
   
//Ant class whiteMove(): move ant according to the rules for a white space
//turn ant 90 degree to the right and change the color of the cell the
//ant was standing on before movement to black
bool Ant::whiteMove(int dir, int x, int y)
{
   bool valid;
   if (dir == 1) //if ant is current facing up(1), turn ant to the right
   {             //and move one to the right columns by incrementing x-coor 
      x += 1;
      face = 4;  //ant will now be facing right(4)
   }

   else if (dir == 2)//if ant is facing down(2), turn ant to the right
   {                 //move one to the left column by decrementing x-coor
      x -= 1;
      face = 3;      //ant will now be facing left(3)
   }

   else if (dir == 3)//if ant is facing left(3), turn ant to the right,
   {                 //move one to the upper row by decrementing y-coor
      y -= 1;
      face = 1;      //ant will now be facing up(1)
   }

   else        //if ant is facing right(4), turn ant to the right,
   {           //move one to the lower row by incrementing y-coor
      y += 1;
      face = 2;//ant will now be facing down(2)
   }
  
   char oriColor; 
   if (x <= pGrid->getWidth() && y <= pGrid->getHeight() && x>0 && y>0)
   {
      setXCoor(x);
      setYCoor(y);
      //variable to hold the color of the cell the ant will be moving to
      //before moving the ant
      oriColor = pGrid -> oriColor(x,y);
      setColor(oriColor);
      pGrid -> updateLocation(x, y);//move the ant to according to the updated coors
      valid = true;
   }
   else
      valid = false;

   return valid;
}

//Ant class blackMove(): move the ant according to the rules for black space
//turn the ant 90 degree to the left
//change cell's color to white
bool Ant::blackMove(int dir, int x, int y)
{
   if (dir == 1) //if ant is facing up(1), move ant to the left column
   {
      x -= 1;
      face = 3; //ant will now be facing left(3)
   }

   else if (dir == 2)//if ant is facing down(2), move ant to the right column
   {
      x += 1;
      face = 4; //ant will now be facing right(4)
   }

   else if (dir == 3) //if ant is facing left(3), move ant to the lower row
   {
      y += 1;
      face = 2; //ant will now be facing down(2)
   }

   else  //if ant is facing right(4) move ant to the upper row
   {
      y -= 1;
      face = 1;//ant will now be facing up(1)
   }
   bool valid;
   char oriColor;

   //check if updated x and y are valid
   if (x <= pGrid->getWidth() && y <= pGrid->getHeight() && x>0 && y>0)
   {
      setXCoor(x);
      setYCoor(y);
   
      //variable to store color of cell the ant will be moving to before actual movement
      //set color to value store
      oriColor = pGrid->oriColor(x,y);
      setColor(oriColor);
      
      pGrid -> updateLocation(x, y);//move ant according to updated coors
      valid = true;   
   }
   else
      valid = false;

   return valid;
}


//Ant class moveAnt(): facilitate ant movement by calling appropriate function
bool Ant::moveAnt()
{
   //get current xCoor, yCoor, direction ant is facing and cell's color
   char curColor;
   int curX, curY, curFace;
   curX = getXCoor();
   curY = getYCoor();
   curFace = getFace();
   curColor = getColor();
   
   bool validMove;

   if (curColor == ' ')//if cell is white
   {
      validMove =  whiteMove(curFace, curX, curY);//call whiteMove to move ant
      if (validMove) 
         pGrid->updateColor(curColor, curX, curY); //update cell's color to black
   }


   else if (curColor == '#')//if cell is black
   {
      validMove = blackMove(curFace, curX, curY);//call blackMove() to move ant 
      if(validMove)
         pGrid->updateColor(curColor, curX, curY);//update cell's color to white
   }
   return validMove;
}

