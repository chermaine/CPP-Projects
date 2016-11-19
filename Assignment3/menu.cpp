/**************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: start menu implementation file
 * ***********************************************************************/

#include "menu.hpp"
#include "validate.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

/**************************************************************************
 * Function: userStart()
 * Description: display menu options, validate user's choice and return 
 * user's choice 
 * Post-condition: return user's choice
 * ***********************************************************************/
int userStart()
{
   int choice;
   system("clear");
   do {
      //display menu options
      std::cout << "Select your creature:" << std::endl;
      std::cout << "1 - Medusa " << std::endl;
      std::cout << "2 - Barbarian" << std::endl;
      std::cout << "3 - Baba Yaga" << std::endl;
      std::cout << "4 - Blue Men" << std::endl;
      std::cout << "5 - Harry Potter " << std::endl;
      std::cout << "6 - Quit " << std::endl;
      std::cin >> choice;
   } while (!startVal(choice));

   std::cin.ignore();
   return choice;
}

/**************************************************************************
 * Function: oppStart()
 * Description: display menu options for opponent choice, 
 * validate user's choice and return user's choice 
 * Post-condition: return user's choice
 * ***********************************************************************/
int oppStart()
{
   int choice;
   system("clear");
   do {
      //display menu options
      std::cout << "Select your opponent:" << std::endl;
      std::cout << "1 - Medusa " << std::endl;
      std::cout << "2 - Barbarian" << std::endl;
      std::cout << "3 - Baba Yaga" << std::endl;
      std::cout << "4 - Blue Men" << std::endl;
      std::cout << "5 - Harry Potter " << std::endl;
      std::cout << "6 - Quit " << std::endl;
      std::cin >> choice;
   } while (!startVal(choice));

   std::cin.ignore();
   return choice;
}

/**************************************************************************
 * Function: attackOption()
 * Description: display menu options for whether user wants to attack first 
 * or defend first, validate user's choice and return user's choice
 * Post-condition: return user's choice
 * ***********************************************************************/
char attackOption()
{
   char choice;
   system("clear");
   do {
      std::cout << "Do you wish to attack first?" << std::endl;
      std::cout << "Y - Yes " << std::endl;
      std::cout << "N - No" << std::endl;
      std::cin >> choice;
   } while (!yesNoValidate(choice));

   std::cin.ignore();
   return choice;
}

/**************************************************************************
 * Function: newGame()
 * Description: display menu options for whether user wants to start a new
 * game
 * Post-condition: return user's choice
 * ***********************************************************************/
char newGame()
{
   char choice;
   system("clear");
   do {
      std::cout << "Start a new battle? " << std::endl;
      std::cout << "Y - Yes " << std::endl;
      std::cout << "N - No" << std::endl;
      std::cin >> choice;
   } while (!yesNoValidate(choice));

   std::cin.ignore();
   return choice;
}
