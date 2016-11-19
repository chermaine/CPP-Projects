/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: Creature's game facilitating functions
 * ****************************************************************************/

#include <iostream>
#include <unistd.h>
#include "game.hpp"
#include "Creature.hpp"
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
Creature* createCreature(int choice)
{
   Creature* temp;
   
   switch (choice)
   {
      case 1: //create Medusa
             temp = new Medusa();
             break;

      case 2: //create Barbarian
             temp = new Barbarian();
             break;

      case 3: //create Baba Yaga
             temp = new BabaYaga();
             break;

      case 4: //create Blue Men
             temp = new BlueMen();
             break;

      case 5: //create Harry Potter
             temp = new HarryPotter();
             break;

      case 6: //quit
             break;
   }

   return temp;

}

/*******************************************************************************
 * Function: startGame()
 * Description: function to facilitate the combat between two creatures by calling
 * their attack, defense, and damage function
 * Parameter: pointer to Creature
 * Pre-condition: Both creature exists
 * Post-condition: result of each fight is displayed, winnner is determined
 * ****************************************************************************/
void startGame(Creature* p1, Creature* p2)
{
   int attack, damage;
   
   attack = p1->attack();
   if (attack == 12 && p1->getName() == "Medusa")
   {
      std::cout << "****** Medusa's Glare super power is activated! ******" << std::endl;
      std::cout << std::endl;
      attack = p2->getStrength();

      if (p2->getName() == "Harry Potter" && static_cast<HarryPotter*>(p2)->getDeath()==0)
      {
         p2->setDefPoint(0);
         damage = p2->defense(attack);
         usleep(1500000);   
         std::cout  << std::endl;
         //call startGame recurvively with Harry now being the attacker and Medusa the defender
         startGame(p2,p1);
      }
      else 
      {   
         p2->setDefPoint(0);
         damage = p2->defense(attack);
      }
   }
   else
   {
      damage = p2->defense(attack);
      if (p2->getStrength()>0)
      {
         usleep(1500000);   
         std::cout  << std::endl;
         startGame(p2, p1);
      }
   }
}
