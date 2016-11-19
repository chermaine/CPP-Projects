/****************************************************************
 * Name: Chermaine Cheang
 * Date: April 5, 2016
 * Description: validation functions implementation file
 * *************************************************************/
#include "validate.hpp"
#include <iostream>
#include <stdlib.h>
//validate all integer inputted by user
bool intValidate(int input)
{
   bool valid; 
   if (input <=0) 
   {
      system("clear");
      std::cout<< "Invalid input. Number must be greater than 0." << std::endl;
      valid = false;
   }
   else
      valid = true;

   return valid;
}

//validate user's choice for starting location
bool startValPoint(int input)
{
   bool valid;
   if (input < 1 || input > 2)
   {
      system("clear");
      std::cout <<"Invalid choice. Enter 1 or 2 only. " << std::endl;
      valid = false;
   }
   else
      valid = true;
   return valid;
}

//validate user's choice for starting direction
bool startValFace(int input)
{
   bool valid;
   if (input < 1 || input > 5)
   {
      system("clear");
      std::cout<<"Invalid choice. Enter 1, 2, 3, 4, or 5 only." << std::endl;
      valid = false;
   }
   else
      valid = true;
   return valid;
}

