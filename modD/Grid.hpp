/*********************************************************
 * Name: Chermaine Cheang
 * Date: April 6, 2016
 * Description: Grid class specification file
 * *******************************************************/

#ifndef GRID_HPP
#define GRID_HPP

#include "Critter.hpp"
#include "Ant.hpp"
#include "Doodlebug.hpp"

class Grid
{
   private:
      Critter*** myGrid;  //2D array
      int height;     //variable to hold number of rows of grid
      int width;      //variable to hold number of columns of grid
      Critter *pCrit;//pointer variable to Critter object

   public:
      Grid(); //default constructor
      Grid(int x, int y, int aNum, int dNum);//constructor
      Critter*** initialize(int x, int y); //dynamically allocated 2D array with parameters given
      void updateLocation(Critter*, int, int);  //update location of critter
      void printGrid(int, int);        //print out current grid's content
      void fillGrid(int, int);         //set cell to NULL pointer  when a grid is created
      void setHeight(int&);            
      int getHeight();
      void setWidth(int&);
      int getWidth();
      void checkMove();     //check if critter movement is valid
      void randStart(Critter*); //generate a random starting position for ant
      void createAnt(int); //generate x number of ants according to user's input
      void createDoo(int); //generate x number of doodlebug according to user's input
      void resetMarker();   //reset critter's marker 
      void moveCrit(int, int, int, int);//move critter if movement is valid
      bool checkGrid();     //check if grid is full
      ~Grid();
};

#endif
