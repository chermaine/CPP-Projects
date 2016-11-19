/**************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: validation functions implementation file
 * ***********************************************************************/
#include "validate.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>

/**************************************************************************
 * Function: startVal()
 * Description: validate user's choice from user's start menu
 * Paramter: int
 * Pre-condition: user made a choice
 * Post-condition: return true if user's choice is valid, or false if user's
 * choice is not valid
 * ***********************************************************************/
bool startVal(int input)
{
   bool valid;
   if (!std::cin.good())
   {
      system("clear");
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
      std::cout <<"Invalid input. Input must be NUMERIC" << std::endl;
      valid = false;
   }   
   else
   {
      if (input < 1 || input > 6)
      {
         system("clear");
         std::cout <<"Invalid choice. Enter 1, 2, 3, 4, 5 or 6 only. " << std::endl;
         valid = false;
      }
      else
         valid = true;
   }
   return valid;
}

/**************************************************************************
 * Function: yesNoValidate()
 * Description: validate user's yes or no choices. Input must be either Y or N
 * Parameter: char
 * Pre-condition: user's entered an char
 * Post-condition: user's input is validated
 * ***********************************************************************/
bool yesNoValidate(char input)
{
   bool valid; 
   if (input != 'Y' && input != 'y' && input != 'n' && input != 'N') 
   {
      system("clear");
      std::cout<< "Invalid input." << std::endl;
      valid = false;
   }
   else
      valid = true;

   return valid;
}
