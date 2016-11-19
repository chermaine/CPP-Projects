/*********************************************************************
 * Name: Chermaine Cheang
 * Date: April 5, 2016
 * Description: Ant class specification file
 * ******************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Grid.hpp"

class Ant 
{
   private:
      int face;    //variable to hold current direction ant is facing
      int xCoor;   //variabel to hold current x-coordinate
      int yCoor;   //variable to hold current y-coordinate
      char color;  //variable to hold origanal cell's color
      Grid* pGrid; //pointer variable to a Grid object

   public:
      Ant(); //default constructor
      Ant(Grid*); //constructor for when user doesn't not specified starting 
                  //location or direction
      void setXCoor(int&);//set xCoor with parameter passed in
      void setYCoor(int&);//set yCoor with parameter passed in
      int getXCoor();     //return xCoor
      int getYCoor();     //return yCoor
      void setColor(char&);//set cell's color
      char getColor();    //return current cell's color
      void setFace(int&); //set direction ant is facing
      int getFace();      //return direction ant is facing
      void randFace();    //random generate a direction the ant will face
      void userFace(int); //set face to user specified direction
      void randStart();   //random generate a starting point for ant
      void userStart(int, int);//set x and y coordinates according to user's input
      bool moveAnt();     //function to move ant accordingly. 
                          //call whiteMove() and blackMove() according to color 
      bool whiteMove(int, int, int);//move ant by turning 90 degree to the right and update ant's location
      bool blackMove(int, int, int);//move ant by turning 90 degree to the left and update ant's location
};
#endif
