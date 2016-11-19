/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: utility function for assignment 4
 * ****************************************************************************/

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Creature.hpp"
#include "Stack.hpp"
#include <limits>

   //menu
   int creatureType();

   //print out functions 
   void displayFighter(Creature*, Creature*);
   void displayCombatWinner(Creature*);
   void print123(Creature*, Creature*, Creature*);
   void displayLoser(Stack&);

   //validate functions
   bool validate(int); //validate integers inputted 
   bool typeVal(int);//validate user's type of creature choice
   bool yesNoValidate(char); //validate yes or no option inputted 


#endif
