/********************************************************
 * Name: Chermaine Cheang
 * Date: April 1, 2016
 * Description: Grid class function implementation file
 * *****************************************************/

#include "Grid.hpp"
#include <iostream>

//Grid class initialize(): to dynamically allocated memory for 2D array
char** Grid::initialize(int x, int y)
{
   char** temp;

   temp = new char*[y]; //creating first chunk of memory
   for (int i=0; i<y; i++)
   {
      temp[i] = new char[x]; //creating the rest of the array
   }
   return temp;
}

//Grid class updateLocation(): update location of ant with parameters passed in
void Grid::updateLocation(int x, int y)
{
   //array subscript starts from 0, so minus 1 from parameters passed in
   //assign '*' to cell 
   myGrid[y-1][x-1] = '*';
}

//Grid class updateColor(): update current cell color
void Grid::updateColor(char color, int x, int y)
{
   if (color == ' ')
   {
      myGrid[y-1][x-1] = '#';
   }
   else  
   {
      myGrid[y-1][x-1] = ' ';
   }
}

//Grid class oriColor(): get original cell's color before ant moves to this cell
char Grid::oriColor(int x, int y)
{
   return myGrid[y-1][x-1];
}

//Grid class fillGrid(): fill new grid created with spaces (white)
void Grid::fillGrid(int x, int y)
{
   for (int i=0; i < y ; i++)
   {
      for (int j=0; j< x; j++)
      {
         myGrid[i][j] = ' ';
      }
   }
}

//Grid class printGrid(): display grid
void Grid::printGrid(int x, int y)
{
   for (int i=0; i < y ; i++)
   {
      for (int j=0; j< x; j++) 
      {
         std::cout << myGrid[i][j] << " " ;
      }
      std:: cout << std::endl;
   }
}

//Grid class removeGrid(): to free dynamically allocated memory for 2D array
void Grid:: removeGrid()
{
   for (int i=0; i< sizeof myGrid/sizeof myGrid[0] ; i++)
   {
      delete(myGrid[i]);
   }
   delete(myGrid);
}

//Grid class constructor
Grid::Grid (int row, int col)
{
   myGrid = initialize(row, col);
   fillGrid(row, col);
   setHeight(row);
   setWidth(col);
}

//Grid class setHeight(): set number of rows inputted by user to height
void Grid::setHeight(int& row)
{
   height = row;
}

//Grid class getHeight(): return height, ie number of rows
int Grid::getHeight()
{
   return height;
}

//Grid class setWidth(): set number of columns inputted by user to width
void Grid::setWidth(int& col)
{
   width = col;
}
 
//Grid class getWidth(): return width, ie number of columns 
int Grid::getWidth()
{
   return width;
}
