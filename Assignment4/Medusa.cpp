/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Medusa class specification file
 * ****************************************************************************/

#include "Medusa.hpp"

/*******************************************************************************
 * Function: Medusa()
 * Description: Medusa class constructor
 * Parameter: string, int
 * Post-condition: Medusa object is created with basic information
 * ****************************************************************************/
Medusa::Medusa(std::string name, int team):Creature(name, team)
{
   this->defPoint = 1;
   this->armor = 3;
   this->strength = 8;
   this->type = "Medusa";
   this->maxStrength = 8;
}

/*******************************************************************************
 * Function: attack()
 * Description: To attack, Medusa will throw the dice x number of times based
 * on her attPoint, result will be randomly generated
 * Pre-condition: Medusa exists
 * Post-condition: attack value is determined and returned
 * ****************************************************************************/
int Medusa::attack()
{
   int temp, total=0;

   //loop through at least once to get a randomly generated number between 
   //1 to 6 because Medusa attacking style is 2d6
   //add that number to total and decrement attPoint by 1
   //if attPoint is less or equal to 0, exit the loop
   //else repeat the loop
   do
   {
      temp = rand()%6 + 1;
      total += temp;
      attPoint--;
   } while (attPoint > 0);

   setAttPoint(2); //reset attPoint to 2 for next attack
   return total;
}

/*******************************************************************************
 * Function: defense()
 * Description: throw the number of dice x number of times based on Medusa 
 * defending style (1d6); calculate the damage receive by Medusa during this round
 * of combat
 * Parameter: int
 * Pre-condition: Medusa exists
 * Post-condition: defending value is determined and returned
 * ****************************************************************************/
int Medusa::defense(int att)
{
   int temp=0, total=0, damage=0;
   while (defPoint>0)
   {
   temp = rand()%6 + 1;
   total = temp + getArmor();
   defPoint--;
   }

   setDefPoint(1);

   if (total < att)
   {
      damage = att - total;
      if (this->strength-damage < 0)
         setStrength(0);
      else
         setStrength(this->strength - damage);
   }

   if (this->strength <=0)
      this->alive = false;

   return damage;
}
