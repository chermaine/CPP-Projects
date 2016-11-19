/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: Driver program for Creatures combat game
 * ****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "menu.hpp"
#include "Creature.hpp"
#include "game.hpp"

int main()
{
   unsigned seed = time(0);
   srand(seed);

   int userChoice, oppChoice;
   char ch;
   Creature* p1 = NULL; //player 1
   Creature* p2 = NULL; //player 2

   //loop through at least once, continue until user's want to quit
   do {
      userChoice = userStart(); //get user's choice
      
      if (userChoice != 6) //user does not want to quit
      {
         p1 = createCreature(userChoice); //create user's creature

         oppChoice = oppStart(); //get opponent's choice

         if (oppChoice != 6) //user does not want to quit
         {
            p2 = createCreature(oppChoice); //create oponent's creature
            ch = attackOption(); 
            system("clear");

            //user wants to attack first, call startGame passing in user then opponent
            if (ch == 'y' || ch == 'Y')
               startGame(p1, p2);
            //user wants to defend first, call startGame passing in opponent then user
            else
               startGame(p2, p1);

            //determine which creature is still alive, that creature is the winner
            if (p1->getAlive() == true)
            {
               std::cout << std::endl;
               std::cout << "************* "<<p1->getName() << " won the battle! *************\n" << std::endl;
               std::cout << "(Enter to continue)" << std::endl;
               std::cin.get();
            }
            else
            {
               std::cout << std::endl;
               std::cout << "************* "<<p2->getName() << " won the battle! *************\n" << std::endl;
               std::cout << "(Enter to continue)" << std::endl;
               std::cin.get();
            }

            //ask if user wants to start another game, if yes, delete current creatures to free memory
            ch = newGame();
            if (ch == 'y' || ch == 'Y')
            {
               delete p1;
               p1 = NULL;
               delete p2;
               p2 = NULL;
            }
         }
      }
   } while (userChoice!=6 && oppChoice !=6 && ch != 'n' && ch != 'N');
   
   //free allocated memory if pointer is not free yet
   if (p1 != NULL)
   {
       delete p1;
       p1 = NULL;
   }
   if (p2 !=NULL)
   {
      delete p2;
      p2 = NULL;
   }

   return 0;

}
