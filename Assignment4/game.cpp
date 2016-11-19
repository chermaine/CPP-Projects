/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: Creature's game facilitating functions
 * ****************************************************************************/

#include "game.hpp"
#include "Barbarian.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "BabaYaga.hpp"
#include "BlueMen.hpp"

/*******************************************************************************
 * Function: createCreature()
 * Description: create type of creature according to user's choice
 * Parameter: int
 * Pre-condition: user's input is valid
 * Post-condition: user's specified creature is created
 * ****************************************************************************/
Creature* createCreature(int choice, int team, std::string name)
{
   switch (choice)
   {
      case 1: //create Medusa
             return (new Medusa(name, team));
             break;

      case 2: //create Barbarian
             return (new Barbarian(name, team));
             break;

      case 3: //create Baba Yaga
             return (new BabaYaga(name, team));
             break;

      case 4: //create Blue Men
             return (new BlueMen(name, team));
             break;

      case 5: //create Harry Potter
             return (new HarryPotter(name, team));
             break;

      case 6: //quit
             break;
   }
}

/*******************************************************************************
 * Function: createTeam()
 * Description: create a team lineup according to user's entered number of fighters
 * and user choices of creature. 
 * Parameter: Queue, int
 * Pre-condition: Queue exists, user specified number of fighters for each team
 * Post-condition: x number of creatures are created and added to team lineup
 * ****************************************************************************/
void createTeam(Queue& team, int number, int teamNum)
{
   int choice;
   std::string name;

   system("clear");

   //ask user to pick x number of fighters
   std::cout << "Select " << number << " fighters for team " << teamNum << std::endl;

   //iterate through the loop x number of times according to user's enter number of fighter
   for (int i=0; i < number; i++)
   {
      std::cout << std::endl;
      std::cout << "Fighter #" << i+1 << ": \n" << std::endl;
      //display types of Creature
      choice = creatureType();

      //iterate through the loop again if user entered a space or new line character
      //as name for selected creature
      do 
      {
         std::cout << "\nEnter a name for Fighter #" << i+1 << ": " << std::endl;
         std::getline(std::cin, name);
         if (name == "" || name == " ")
         {
            std::cout << "\nInvalid input. Input must be a combination of CHARACTERS!" 
                      << std::endl;
         }
      } while (name == "" || name == " ");

      //call createCreature to create the selected creature and add this creature to
      //team lineup
      team.add(createCreature(choice, teamNum, name));
   }
}

/*******************************************************************************
 * Function: combatBetwFighters()
 * Description: function to facilitate the combat between two creatures by calling
 * their attack, defense, and damage function
 * Parameter: pointer to Creature
 * Pre-condition: Both creature exists
 * Post-condition: result of each fight is displayed, winnner is determined
 * ****************************************************************************/
void combatBetwFighters(Creature* p1, Creature* p2)
{
   int attack, damage;

   //get fighter1 attacking points
   attack = p1->attack();

   //if attacking for 12 points, check if fighter1 is Medusa
   //if fighter is Medusa, activate Medusa's glare power
   if (attack == 12 && p1->getType() == "Medusa")
   {
      usleep(3000000);
      std::cout << p1->getName() << "'s super power (Glare) is activated!" << std::endl;
      std::cout << std::endl;

      //set attack to fighter2 current strength
      attack = p2->getStrength();

      //check if fighter2 is Harry Potter and if Harry's has used up his hogwarts power
      //if fighter2 is Harry Potter and he hasn't use his power, then he will survive 
      //Medusa's glare attack
      if (p2->getType() == "Harry Potter" && static_cast<HarryPotter*>(p2)->getDeath()==0)
      {
         //set defPoint to 0, so no defending dice will be rolled, and call Harry's defense 
         p2->setDefPoint(0);
         damage = p2->defense(attack);

         //call startGame recurvively with Harry now being the attacker and Medusa the defender
         combatBetwFighters(p2,p1);
      }

      //all other creatures will not survive Medusa's glare attack
      else 
      {   
         p2->setDefPoint(0);
         damage = p2->defense(attack);
      }
   }

   //for all other attacker, check if defender survives this round of attack
   //if survives, recursively call combatBetwFighters for next round of attack
   else
   {
      damage = p2->defense(attack);
      if (p2->getStrength()>0)
      {
         combatBetwFighters(p2, p1);
      }
   }
}

/*******************************************************************************
 * Function: startTournament()
 * Description: facilitate the entire tournament. Call combatBetwFighters by 
 * determining who is fighter from each team. Facilitate combats until one
 * team has no fighters left. Determine and display winner after each round of 
 * combats. Call recover() and resetAbility() before adding winner back to their
 * team lineup. Add defeated fighter to loser stack
 * Parameter: Queue
 * Pre-condition: Queue exists with at least one fighter
 * Post-condition: Winner for each round of combat is determined, recovered and
 * added back to lineup, loser is added to the loser stack, and at the end of the
 * tournament, this loser stack is returned to main
 * ****************************************************************************/
Stack startTournament(Queue& team1, Queue& team2)
{
   Creature* fighter1;
   Creature* fighter2;
   Stack loser;

   //run the tournament while none of the team is empty
   while (!team1.isEmpty() && !team2.isEmpty())
   {
      //get first fighters from both team
      fighter1 = team1.remove();
      fighter2 = team2.remove();

      //print out who is fighting who and start the combat
      displayFighter(fighter1, fighter2);
      combatBetwFighters(fighter1, fighter2);

      //hold screen for 3s
      usleep(3000000);

      //determine who won the combat by checking who is still alive
      //fighter1 is still alive
      if (fighter1->getAlive())
      {
         //print out the winner for this combat
         displayCombatWinner(fighter1);
         usleep(3000000);
         //reset special abilities of fighter1 and add fighter1 back to team lineup
         resetAbility(fighter1);
         team1.add(fighter1);

         //add fighter2 to loser's stack
         loser.add(fighter2);
      }
      //if fighter2 is still alive
      else
      {
         //print out the winner of this combat
         displayCombatWinner(fighter2);
         usleep(3000000);
       
         //reset special abilities of fighter2 and add back to team lineup
         resetAbility(fighter2);
         team2.add(fighter2);

         //add fighter1 (loser) to loser's stack
         loser.add(fighter1);
      }
      usleep(3000000);
   }
   return loser;
}

/*******************************************************************************
 * Function: recover()
 * Description: facilitate the recover process of the winning fighter from a 
 * combat. Call randRecover() to get recover points if an only if current strength
 * is less than max strength, then add those points to fighter strength accordingly.
 * Parameter: Creature*
 * Pre-condition: Creature exists and Creature won the battle
 * Post-condition: creature recovered some strength points
 * ****************************************************************************/
void recover(Creature* c1)
{
   int recoverPoint;

   //if creature is Medusa, check if current strength is less than max
   //if yes, call randRecover() and check if recoverPoint + current strength 
   //will be greater than max strength (8)
   //if greater than 8, set strength to max (which is 8)
   //if not greater than 8, set strength to current strength + recoverPoint
   if (c1->getType() == "Medusa" && c1->getStrength() < 8)
   {
      recoverPoint = c1->randRecover();
      std::cout << c1->getName() << "'s strength before recovery: " << c1->getStrength() << std::endl;
      if ((recoverPoint + c1->getStrength()) >= 8)
         c1->setStrength(8);
      else
         c1->setStrength(recoverPoint + c1->getStrength());
      std::cout << c1->getName() << " will recover a total of " << recoverPoint << " points" 
                << std::endl;
      std::cout << c1->getName() << "'s strength after recovery: " << c1->getStrength() << std::endl;
   }

   //if creature is Barbarian, Baba Yaga, or Blue Men, check if current strength  is less than max
   //if yes, call randRecover() and check if recoverPoint + current Strength 
   //will be greater than max strength (12)
   //if greater than 12, set strength to max (12)
   //if not greater than 12, set strength to current strength + recoverPoint
   if (c1->getType() == "Barbarian" || c1->getType() == "Baba Yaga" || c1->getType() == "Blue Men")
   {
      if (c1->getStrength() < 12)
      {
         recoverPoint = c1->randRecover();
         std::cout << c1->getName() << "'s strength before recovery: " << c1->getStrength() << std::endl;

         if ((recoverPoint + c1->getStrength()) >= 12)
            c1->setStrength(12);
         else 
            c1->setStrength(recoverPoint + c1->getStrength());
         std::cout << c1->getName() << " will recover a total of " << recoverPoint << " points" 
                   << std::endl;
         std::cout << c1->getName() << "'s strength after recovery: " << c1->getStrength() << std::endl;
      }
   }
   
   //if Creature is Harry Potter, check if current strength is less than max
   //if yes, call randRecover() and check if recoverPoint + current strength will be greater
   //than max strength (10)
   //if greater than 10, set strength to 10
   //if not, set strength to current strength + recoverPoint
   if (c1->getType() == "Harry Potter" && c1->getStrength() < 10)
   {
      recoverPoint = c1->randRecover();
      std::cout << c1->getName() << "'s strength before recovery: " << c1->getStrength() << std::endl;
      if ((recoverPoint + c1->getStrength()) >= 10)
         c1->setStrength(10);
      else
         c1->setStrength(recoverPoint + c1->getStrength());
      std::cout << c1->getName() << " will recover a total of " << recoverPoint << " points" 
                << std::endl;
      std::cout << c1->getName() << "'s strength after recovery: " << c1->getStrength() << std::endl;
   } 
}

/*******************************************************************************
 * Function: resetAbility()
 * Description: function to reset creature's special ability for next combat &
 * call recover() after resetting abilities
 * Reset Harry Potter's death count to 0, and strength to 10 if more than 10
 * Reset Baba Yaga's strength to 12 if its more than 12
 * Reset Baba Yaga's soulCounter to 20 if its less than 20
 * Reset Blue Men's defPoint to 3 if its less than 3
 * Parameter: Creature*
 * Pre-condition: Creature exists and won the combat
 * Post-condition: Creature's special ability is reset 
 * ****************************************************************************/
void resetAbility(Creature* c1)
{
   std::cout << std::endl;

   //reset Baba Yaga's soul ability
   if (c1->getType() == "Baba Yaga")
   {
      //reset Baba Yaga's strength to 12 if it is currently more than 12 due to Soul
      if (c1->getStrength() > 12)
      {
         std::cout << c1->getName() << " the Baba Yaga current strength: " 
                   << c1->getStrength() << std::endl;
         c1->setStrength(12);
         std::cout << "Reset " << c1->getName() << "'s strength to " 
                   << c1->getStrength() << std::endl;
      }
      //call recover() if strength is less than 12
      else
         recover(c1);

      //reset Baba Yaga's soul counter to 20 if it is currently less than 20
      if (static_cast<BabaYaga*>(c1)->getSoulCounter() < 20)
         static_cast<BabaYaga*>(c1)->setSoulCounter(20);
   }

   //reset Blue Men's mob ability
   else if (c1->getType() == "Blue Men")
   {
      //reset Blue Men's defPoint to 3 if it is currently less than 3 due to Mob
      if (c1->getDefPoint() < 3)
      {
         std::cout << c1->getName() << " the Blue Men current defense point: " 
                   << c1->getDefPoint() << std::endl;
         c1->setDefPoint(3);
         std::cout << "Reset " << c1->getName() << "'s defense point to " 
                   << c1->getDefPoint() << std::endl;
      }

      //call recover() if strength is less than 12
      if (c1->getStrength() < 12)
         recover(c1);
   }

   //reset Harry Potter's hogwarts ability
   else if (c1->getType() == "Harry Potter")
   {
      //reset Harry Potter's death count to 0 if it is currently more than 0
      if (static_cast<HarryPotter*>(c1)->getDeath() > 0)
      {
         std::cout << c1->getName() << " the Harry Potter current death count: " 
                   << static_cast<HarryPotter*>(c1)->getDeath() << std::endl;
         static_cast<HarryPotter*>(c1)->setDeath(0);
         std::cout << "Reset " << c1->getName() << "'s death count to " 
                   << static_cast<HarryPotter*>(c1)->getDeath() << std::endl;
      }

      //reset Harry Potter's strength to 10 if it is currently more than 10
      //due to Hogwarts
      if (c1->getStrength() >= 10)
      {
         std::cout << c1->getName() << " current strength: " << c1->getStrength() << std::endl;
         c1->setStrength(10);
         std::cout << "Reset "<< c1->getName() << "'s strength to " << c1->getStrength() << std::endl;
      }
      //if strength is less than 10, call recover()
      else
         recover(c1);
   }

   //call recover() for other creatures
   else 
      recover(c1);

}

/*******************************************************************************
 * Function: sameTeamBattle()
 * Description: facilitate combats between fighters from the same team. This function
 * will only be called at the end of the tournament to help determine the top
 * three finishers
 * Parameter: Queue&, Stack&
 * Pre-condition: tournament ended, and the team has more than one fighter left
 * Post-condition: only one fighter left in team, top three finishers can be determined
 * ****************************************************************************/
void sameTeamBattle(Queue& team, Stack& loser)
{
   Creature* fighter1;
   Creature* fighter2;

   //get first two fighters ready for combat
   fighter1 = team.remove();
   fighter2 = team.remove();

   displayFighter(fighter1, fighter2);
   combatBetwFighters(fighter1, fighter2);

   //hold screen for 3s
   usleep(3000000);

   //determine who won the battle, call resetAbility for that fighter and add
   //the fighter back to its team lineup, while add the losing fighter to the 
   //loser stack
   if (fighter1->getAlive())
   {
      displayCombatWinner(fighter1);
      usleep(3000000);
      resetAbility(fighter1);
      team.add(fighter1);
      loser.add(fighter2);
   }
   else
   {
      displayCombatWinner(fighter2);
      usleep(3000000);
      resetAbility(fighter2);
      team.add(fighter2);
      loser.add(fighter1);
   }
}
