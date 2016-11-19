/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Final Project clien program
 * ****************************************************************************/

#include "utility.hpp"
#include "game.hpp"
#include "Object.hpp"
#include "Space.hpp"
#include "Character.hpp"
#include "Kitchen.hpp"
#include "Basement.hpp"
#include "Rooftop.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
   system("clear");
   int startTime, endTime;
   std::string name;
   Space* currentSpace = NULL;
   Space* previousSpace = NULL;

   unsigned seed = time(0);
   srand(seed);

   std::cout << "Welcome to Save Your Friends!" << std::endl;

   //prompt user if they want to start the game
   char choice = startOption();

   std::cin.ignore();
   //if user wants to start the game
   if (choice == 'Y' || choice == 'y')
   {
      std::cout << std::endl;
      //display the objective of the game
      displayObjective();

      //create the spaces needed for the game to start
      currentSpace = createSpace();

      //prompt user for their name
      name = playerName();
 
      //create Character object based on user's name and current location
      Character player(name, currentSpace);

      //prompt user if they want to know the solution
      solutionMenu(player);

      //iterate the loop if the number of person to be saved by player is
      //greater than 0
      while (player.getToBeSaved() > 0)
      {
         //record starting time of this cycle
         startTime = time(0);

         //save a copy of player's current location
         previousSpace = player.getCurrentLocation();

         //call functions to start interaction with current space, ie start
         //the game. When return, player's location will be updated to next 
         //space
         interactWithSpace(player);

         if (previousSpace != NULL)
         {
            //if previously, player is in the Kitchen and player has rescued
            //the person in the kitchen, call deleteKitchen to free all memory
            //allocated for this space
            if (previousSpace->getNameOfSpace()=="Kitchen" 
                && static_cast<Kitchen*>(previousSpace)->getRescued()==true)
            {
               deleteKitchen(previousSpace);
               previousSpace = NULL;
            }
            //if previously, player is in the Basement and player has rescued
            //the person in the Basement, call deleteBasement to free all memory
            //allocated for this space
            else if (previousSpace->getNameOfSpace() == "Basement" 
                     && static_cast<Basement*>(previousSpace)->getRescued()==true)
            {
               deleteBasement(previousSpace);
               previousSpace = NULL;
            }
            //if previosly, player is in the Rooftop and player has rescued 
            //ther person in the Rooftop, call deleteRooftop to free all memory
            //allocated for this space
            else if (previousSpace->getNameOfSpace() == "Rooftop"
                     &&static_cast<Rooftop*>(previousSpace)->getRescued()==true)
            {  
               deleteRooftop(previousSpace);
               previousSpace = NULL;
            }
            //for all other spaces, set previousSpace to NULL
            else
               previousSpace = NULL;
         }
         //get the time when player finished interacting with one space
         endTime = time(0);

         //if player spent more than 30s in one particular space, the message
         //below will be printed, to act as a time constraint
         if (endTime - startTime > 30)
            std::cout << "\n********** Time is running out! Hurry Up! **********" << std::endl;
      }

      //when player has saved all the people in the game, print out winning messages
      if (player.getToBeSaved() == 0)
         printWon(player);

      //free memory allocated for spaces connecting to currentSpace
      freeMemory(currentSpace);
   }

   //if currentSpace pointer is not pointing to null
   //delete objects in this space and free memory allocated for this space
   if (currentSpace != NULL)
   {
      deleteObject(currentSpace);
      std::cout << "Deleted " << currentSpace->getNameOfSpace() << std::endl;
      delete currentSpace;
      currentSpace = NULL;
   }

   return 0;
}






