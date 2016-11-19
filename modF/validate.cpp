/**************************************************************************
 * Name: Chermaine Cheang
 * Date: May 20, 2016
 * Description: validate functions implementation file
 * ***********************************************************************/
#include "validate.hpp"

/**************************************************************************
 * Function: validate()
 * Description: validate user's input
 * Paramter: int
 * Pre-condition: user made a choice
 * Post-condition: return true if user's choice is valid, or false if user's
 * choice is not valid
 * ***********************************************************************/
bool validate(int input)
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
      if (input <= 0)
      {
         system("clear");
         std::cout <<"Invalid input. Input must be greater than 0 " << std::endl;
         valid = false;
      }
      else
         valid = true;
   }
   return valid;
}

