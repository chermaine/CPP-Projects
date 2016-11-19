/****************************************************************
 * Name: Chermaine Cheang
 * Date: April 5, 2016
 * Description: validation functions implementation file
 * *************************************************************/
#include "validate.hpp"
#include <iostream>
#include <stdlib.h>

/**************************************************************************
 * Function: validate()
 * Description: validate all integer inputted by user. Input must be greater
 * than 0
 * Parameter: int
 * Pre-condition: user's entered an integer
 * Post-condition: user's input is validated
 * ***********************************************************************/
bool validate(int input)
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

/**************************************************************************
 * Function: startValPoint()
 * Description: validate user's choice from start menu
 * Paramter: int
 * Pre-condition: user made a choice
 * Post-condition: return true if user's choice is valid, or false if user's
 * choice is not valid
 * ***********************************************************************/
bool startVal(int input)
{
   bool valid;
   if (input < 1 || input > 4)
   {
     // system("clear");
      std::cout <<"Invalid choice. Enter 1, 2, 3 or 4 only. " << std::endl;
      valid = false;
      std::cin.ignore();
      std::cout <<"(Enter to continue)" << std::endl;
      std::cin.get();
   }
   else
      valid = true;
   return valid;
}

/**************************************************************************
 * Function: validate()
 * Description: validate all double inputted by user. Input must be greater
 * than 0
 * Parameter: double
 * Pre-condition: user's entered a double 
 * Post-condition: user's input is validated
 * ***********************************************************************/
bool validate(double input)
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
   if (input != 'Y' && input != 'N') 
   {
      system("clear");
      std::cout<< "Invalid input." << std::endl;
      valid = false;
   }
   else
      valid = true;

   return valid;
}
