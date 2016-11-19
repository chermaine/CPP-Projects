/************************************************************
 * Name:Chermaine Cheang
 * Date: April 5, 2016
 * Description: Menu function
 * **********************************************************/

#include <iostream>

//menu options for ant's starting location
int startMenu()
{
   int choice;
   std::cout<<"Do you wish to specify the Ant's starting location " << std::endl;
   std::cout<<"or you wish for the system to randomnly generate a " << std::endl;
   std::cout<<"starting point? " << std::endl;
   std::cout<<"1 - Specify my own location " << std::endl;
   std::cout<<"2 - Randomly generate" << std::endl;
   std::cout<<"Enter 1 or 2 as your choice." << std::endl;
   std::cin>>choice;
   return choice;
}

//menu options for ant's starting direction
int dirMenu()
{
   int choice;
   std::cout<<"Which direction the Ant is facing?" << std::endl;
   std::cout<<"1 - UP (NORTH)" << std::endl;
   std::cout<<"2 - DOWN (SOUTH)" << std::endl;
   std::cout<<"3 - LEFT (WEST)" << std::endl;
   std::cout<<"4 - RIGHT (EAST)" << std::endl;
   std::cout<<"5 - RANDOM" << std::endl;
   std::cin >>choice;
   return choice;
}
