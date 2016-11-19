/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Driver program for Creatures combat game
 * ****************************************************************************/

#include "Queue.hpp"
#include "Stack.hpp"
#include "utility.hpp"
#include "Creature.hpp"
#include "game.hpp"
#include <ctime>

int main()
{
   unsigned seed = time(0);
   srand(seed);

   int numFight;
   Queue team1;
   Queue team2;
   Stack loser;

   system("clear");
   //get number of fighters from user. Re-iterate if input is not valid
   do 
   {
      std::cout << "Enter number of fighters for each team" << std::endl;
      std::cin >> numFight;
   } while (!validate(numFight));

   std::cin.ignore(); 

   //form team's lineup  
   createTeam(team1, numFight, 1);
   createTeam(team2, numFight, 2);

   system("clear");
   //start tournament between two teams, and collect all losers to loser stack
   loser = startTournament(team1, team2);

   //pointer to hold top three finishers
   Creature* first;
   Creature* second;
   Creature* third;

   //determine which team won the tournament by checking if they still have fighters
   //team1 still has fighters left
   if (!team1.isEmpty())
   {
      //check if team1 has more than 1 fighters left
      //if yes, call sameTeamBattle until team1 only has 1 fighter left
      if (team1.getNumFighter() > 1)
      {
         std::cout << std::endl;
         std::cout << std::string(75, '*') << std::endl;
         std::cout << "Starting battle within fighters in team 1"
                   << " to determine top three finishers" << std::endl;
         while (team1.getNumFighter() > 1)
            sameTeamBattle(team1, loser);
      }

      system("clear");
      //print out team1 won the tournament
      std::cout << "********** Team 1 won the tournament!!! **********" << std::endl;

      //the remaining fighter in team1 is the champion
      first = team1.remove();
   }

   //team2 still has fighters left
   else
   {
      //check if team2 has more than 1 fighters left
      //if yes, call sameTeamBattle until team2 only has 1 fighter remaining
      if (team2.getNumFighter() > 1)
      {
         std::cout << std::endl;
         std::cout << std::string(75, '*') << std::endl;
         std::cout << "Starting battle within fighters in team 2"
                   << " to determine top three finishers" << std::endl;
         while (team2.getNumFighter() > 1)
            sameTeamBattle(team2, loser);
      }

      system("clear");
      //print out team2 won the tournament
      std::cout << "********** Team 2 won the tournament!!! **********" << std::endl;

      //the remaining fighter in team 2 is the champion
      first = team2.remove();
   }

   //second place is the last loser in loser stack
   second = loser.remove();

   //third place is the second last loser in loser stack
   third = loser.remove();

   //print out top three finishers
   print123(first, second, third);

   //if loser stack is not empty, call displayLoser to ask if user wants to display 
   //final order and free memory allocated for all creatures in the loser stack
   if (loser.getNumFighter()>0)
   { 
      displayLoser(loser);
   }

   //free allocated memory for the top three finishers
   delete first;
   delete second;
   delete third;
   first = NULL;
   second = NULL;
   third = NULL;

   return 0;

}
