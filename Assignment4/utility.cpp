/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: utility function implementation file 
 * ****************************************************************************/

#include "utility.hpp"

/*******************************************************************************
 * Function: displayFighter()
 * Description: print out which two creatures are fighting one another (their 
 * names, types and team number)
 * Parameter: Creature*, Creature*
 * Pre-condition: Creature exists
 * Post-condition: identity of creature is printed out
 * ****************************************************************************/
void displayFighter(Creature* c1, Creature* c2)
{
   std::cout << std::endl;
   std::cout << "Team " << c1->getTeamNum() << ": " << c1->getName() << " the "
             << c1->getType() << " vs Team " << c2->getTeamNum() << ": " 
             << c2->getName() << " the " << c2->getType() << std::endl;
}

/*******************************************************************************
 * Function: displayCombatWinner()
 * Description: display which creature won the combat
 * Parameter: Creature*
 * Pre-condition: Creature exists and Creature won the combat
 * Post-condition: winner is displayed
 * ****************************************************************************/
void displayCombatWinner(Creature* winner)
{
   std::cout << std::endl;
   std::cout << "**** " << winner->getName() << " the " << winner->getType() 
             << " from team " << winner->getTeamNum() << " won the combat! ****" 
             << std::endl;
}

/*******************************************************************************
 * Function: print123()
 * Description: display top three finishers of the tournament. If parameter passed
 * in is NULL, do not have a third place winner because they were only 1 fighter
 * from each team
 * Parameter: Creature*
 * Pre-condition: Creature exists 
 * Post-condition: first, second, third place winners are displayed
 * ****************************************************************************/
void print123(Creature* first, Creature* second, Creature* third)
{
   std::cout << std::endl;
   std::cout << "1st - " << first->getName() << " the " << first->getType()  
             << " from team " << first->getTeamNum() << std::endl;
   std::cout << "2nd - " << second->getName() << " the " << second->getType()  
             << " from team " << second->getTeamNum() << std::endl;
 
   //check if third is NULL, that is no third place finisher because only have
   //a total of two fighters, therefore do nothing
   //if third is not NULL, then print out details
   if (third != NULL)
   {
      std::cout << "3rd - " << third->getName() << " the " << third->getType()  
                << " from team " << third->getTeamNum() << std::endl;
   }
}
/*******************************************************************************
 * Function: displayLoser
 * Description: ask if user wants to display final order. If yes, display order
 * and free memory allocated for creature. If no, free memory allocated for creature
 * in loser stack
 * Parameter: Stack&
 * Pre-condition: Stack exists. Top three finishers have been determined
 * Post-condition: display final order and free memory
 * ****************************************************************************/
void displayLoser(Stack& loser)
{
   char option;
   int count = 4; //start from 4 because top three finishers have been determined
   Creature* temp=NULL;
   std::cout << std::endl;
 
   //prompt user if they want to display final order, validate user input.
   //if input not valid, ask user to re-enter choices
   do
   {   
      std::cout << "Do you wish to display a list of final order? " << std::endl;
      std::cout << "(Enter Y for Yes or N for No)" << std::endl;
      std::cin >> option; 
   } while (!yesNoValidate(option));

   //user wants to display final order
   if (option == 'y' || option == 'Y')
   {
      std::cout << std::endl;

      //iterate the loop again while there is still fighter in loser Stack
      while (!loser.isEmpty())
      {
         //remove the last loser and declare this loser as 4th place finisher
         temp = loser.remove();
         std::cout << count << "th - " << temp->getName() << " the " << temp->getType()
                   << " from team " << temp->getTeamNum() << std::endl;

         //increment count for next loser
         count++;

         //free memory allocated for this loser, before iterating through the loop again
         delete temp;
         temp = NULL;
      }
   }

   //user does not want to display final order
   else
   {
      //free all memory allocated for creatures in loser stack
      while (!loser.isEmpty())
         delete (loser.remove());
   }
}

/**************************************************************************
 * Function: creatureType()
 * Description: display list of creature types, validate user's choice 
 * and return user's choice 
 * Post-condition: return user's choice
 * ***********************************************************************/
int creatureType()
{
   int choice;
//   system("clear");
   do {
      //display menu options
      std::cout << "Select your creature:" << std::endl;
      std::cout << "1 - Medusa " << std::endl;
      std::cout << "2 - Barbarian" << std::endl;
      std::cout << "3 - Baba Yaga" << std::endl;
      std::cout << "4 - Blue Men" << std::endl;
      std::cout << "5 - Harry Potter " << std::endl;
      std::cin >> choice;
   } while (!typeVal(choice));

   std::cin.ignore();
   return choice;
}

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
      if (input <=0) 
      {
         system("clear");
         std::cout<< "Invalid input. Number must be greater than 0." << std::endl;
         valid = false;
      }
      else
         valid = true;
   }
   return valid;
}

/**************************************************************************
 * Function: typeVal()
 * Description: validate user's choice from user's start menu
 * Paramter: int
 * Pre-condition: user made a choice
 * Post-condition: return true if user's choice is valid, or false if user's
 * choice is not valid
 * ***********************************************************************/
bool typeVal(int input)
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
      if (input < 1 || input > 5)
      {
         system("clear");
         std::cout <<"Invalid choice. Enter 1, 2, 3, 4 or 5 only. " << std::endl;
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
