/*********************************************************
 * Name: Chermaine Cheang
 * Date: April1, 2016
 * Description: Grid class specification file
 * *******************************************************/

#ifndef GRID_HPP
#define GRID_HPP

class Grid
{
   private:
      char** myGrid;  //2D array
      int height;     //variable to hold number of rows of grid
      int width;      //variable to hold number of columns of grid
   public:
      char** initialize(int x, int y); //dynamically allocated 2D array with parameters given
      void updateLocation(int , int);  //update location of critter
      void printGrid(int, int);        //print out current grid
      void fillGrid(int, int);         //fill grid with spaces when a grid is created
      void removeGrid();               //free memory allocated for 2D array
      Grid(int x, int y);              //constructor
      void setHeight(int&);            
      int getHeight();
      void setWidth(int&);
      int getWidth();
      void updateColor(char, int, int);//update cell's color
      char oriColor(int, int);//return original cell's color before movement
};

#endif
