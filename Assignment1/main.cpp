/***********************************************************
 * Name: Chermaine Cheang
 * Date: April 5, 2016
 * Description: Ant class and grid class client program
 * ********************************************************/

#include "Grid.hpp"
#include "Ant.hpp"
#include "validate.hpp"
#include "menu.hpp"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
   int row, col, startP, step, startF;
   bool validRow, validCol, validStep, validStartP, validStartF;

   //prompt user for number of rows and columns and
   //validate user inputs
   //if input is not valid, prompt user to enter number of rows and columns again
   do {
      cout << "Enter number of rows and columns" << endl;
      cin >> row >> col;

      validRow = intValidate(row);
      validCol = intValidate(col);
   }while (!validRow || !validCol);

   system("clear"); //clear screen

   //create a grid object with user's entered row and column
   Grid grid1(row, col);

   //create an Ant object
   Ant ant1(&grid1);

   //display menu options for ant's starting location
   //validate user's choice
   //if not valid, ask user to choose again
   do {
      startP = startMenu();
      validStartP = startValPoint(startP);
   } while (!validStartP);
   
   system("clear");
   //variables to hold user inputed x and y coordinates
   int xCoor, yCoor;
   bool valid;

   //if user wants to speficy starting location
   if (startP == 1)
   {
      //prompt user to enter x-coordinate
      //validate user's input by checking if it is a valid integer and
      //input must be smaller than or equal to number of rows specified
      //repeat until a valid x-coordinate is entered
      do {
         cout<<"Enter starting x-coordinate." << endl;
         cin >> xCoor;
         valid = intValidate(xCoor);
         if (xCoor > col)
         {
            valid = false;
            cout<<"X-coordinate is out of bound. Enter a value smaller than ";
            cout<<col << "." <<endl;
         }
      }while(!valid);

      system("clear");

      //prompt user to enter y-coordinate
      //validate user's input by checking if it is a valid integer and
      //input must be smaller than or equal to number of rows specified
      //repeat until a valid y-coordinate is entered
      do {
         cout << "Enter starting y-coordinate." << endl;
         cin >> yCoor;
         valid = intValidate(yCoor);
         if (yCoor > row) 
         {
            valid = false;
            cout <<"Y-coordinate is out of bound. Enter a value smaller than ";
            cout << row << "." << endl;
         }
      } while (!valid);

      ant1.userStart(xCoor, yCoor);//set ant's x and y coordinates
   }

   //if user wants to randomly generate a starting location
   //call ant class randStart() function
   else
   {
      ant1.randStart();
   }
   
   system("clear");

   //display menu options for starting direction
   //validate user's choice
   //if not valid, ask user to choose again
   do {
      startF = dirMenu();
      validStartF = startValFace(startF);
   } while (!validStartF);
   system("clear"); 
   //if user wants to randomly generated a starting direction
   //call ant class randFace() function
   if (startF == 5)
      ant1.randFace();
   
   //else set ant's direction to user's choice
   else
      ant1.setFace(startF);
   
   //prompt user to enter number of steps the ant should take
   //validate user's input
   //if not valid, prompt user to re-enter steps
   do{
      cout << "Enter number of steps the ant should take (several hundred to 10 000)." << endl;
      cin >> step;
      validStep = intValidate(step);
   } while (!validStep);

   system("clear");
   //display ant's starting location
   cout << "Ant's starting location " << endl;
   grid1.printGrid(row, col);
   usleep(500000); //delay screen for 0.5s

   bool movement = true;

   //loop to control number of steps the ant should take
   for (int i = 0; i<step; i++)
   {
      system("clear"); //clear screen 
      cout << "Step " << i+1 << endl;
      movement = ant1.moveAnt();
      grid1.printGrid(row, col); //display ant's location after each step
      usleep(500000); //hold screen for 0.5s
      if (movement == false)
      //ant moved out of grid boundaries, exit for loop
      {
          cout << "Ant moved out of bound. Program terminates now. " << endl;
          break;
      }
   }

   grid1.removeGrid();
   return 0;
}
