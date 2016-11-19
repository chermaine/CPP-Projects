/**********************************************************
 * Name: Chermaine Cheang
 * Date: April 6, 2016
 * Description: Critter class and grid class client program
 * ********************************************************/

#include "Grid.hpp"
#include <iostream>
#include <cstdlib>
#include <unistd.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
   int row, col, antCount, bugCount, steps;

   unsigned seed = time(NULL);
   srand(seed);

   system("clear");

   //prompt user to enter number of rows and columns for grid size
   cout << "Enter number of rows and columns" << endl;
   cin >> row >> col;
   //validate user inputs, inputs must be greater than 0
   while (row<=0 || col<=0)
   {
      cout<<"Invalid input. Inputs must be greater than 0." <<endl;
      cout <<"Enter number of rows and columns" << endl;
      cin >> row >> col;
   }

   system("clear");
   //prompt user to enter number of critters and validate input
   cout << "Enter number of Ants. " << endl;
   cin >> antCount;
   while (antCount < 1 || antCount>row*col)
   {
      cout <<"Invalid input. Input must be greater than 0 and smaller than ";
      cout << row*col << endl;
      cout <<"Enter number of Ants. " << endl;
      cin >> antCount;
   }

   //prompt user to enter number of critters and validate input
   cout << "Enter number of Doodlebug. " << endl;
   cin >> bugCount;
   while (bugCount < 1 || bugCount>row*col)
   {
      cout <<"Invalid input. Input must be greater than 0 and smaller than ";
      cout << row*col << endl;
      cout <<"Enter number of Doodlebug. " << endl;
      cin >> bugCount;
   }

   system("clear");
   Grid grid1(row, col, antCount, bugCount); //create Grid object with user's inputs  
  
   cout<<"Ants' and Doodlebugs' starting position: " << endl;
   grid1.printGrid(row,col); //display critter starting position
   usleep(1000000);

   //check if grid is packed with critter. If not, then prompt user for
   //number of steps and validating input
   //if grid is packed, no critters can move, therefore, program terminates 
   int count = antCount + bugCount;
   if (count != row*col)
   {
      do {
         cout <<"Enter number of steps critters should take. " << endl;
         cin >> steps;
         if (steps < 1)
            cout <<"Invalid input. Number must be greater than 1." << endl;
      } while (steps<1);
   }
   else
   {
      cout <<"The grid is packed with Critters." <<endl;
      cout <<"No critter can move. Program terminates now. " <<endl;
      steps =0;
   }

   bool valid = grid1.checkGrid(); //check if grid is full
   int k=0;
   //loop to keep moving critter randomly x number of times while grid is not full
   while (k<steps && valid == false)
   {
      system("clear");
      grid1.checkMove();
      cout << "Critters location after " << k+1 << " move(s). " << endl;
      grid1.printGrid(row,col);
      usleep(1500000);
      k++;
      grid1.resetMarker();
      valid = grid1.checkGrid();
   }

   if (valid == true)
   {
      cout<<"Grid is full. Program terminates now. " <<endl;
   }

   return 0;
}
