/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Barbarian class specification file
 * ****************************************************************************/

#include "Barbarian.hpp"

/*******************************************************************************
 * Function: Barbarian()
 * Description: Barbarian class constructor
 * Parameter: string, int
 * Post-condition: Barbarian object is created with basic information
 * ****************************************************************************/
Barbarian::Barbarian(std::string name, int team):Creature(name, team)
{
   this->type = "Barbarian";
}

/*******************************************************************************
 * Function: attack()
 * Description: To attack, Barbarian will throw the dice x number of times based
 * on his attPoint, result will be randomly generated
 * Pre-condition: Barbarian exists
 * Post-condition: attack value is determined and returned
 * ****************************************************************************/
int Barbarian::attack()
{
   int temp, total=0;

   //loop through at least once to get a randomly generated number between 
   //1 to 6 because Barbarian attacking style is 2d6
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
 * Description: throw the number of dice x number of times based on Barbarian 
 * defending style (2d6); calculate damage received during this attack; update 
 * strength accordingly; if Barbarian does not survive the attack, set alive to false
 * Paramter: int
 * Pre-condition: Barbarian exists
 * Post-condition: defending value is determined and returned
 * ****************************************************************************/
int Barbarian::defense(int att)
{
   int temp=0, total=0, damage=0;
   
   //roll number of dice based on defPoint
   while (defPoint >0)
   {
      temp = rand()%6 + 1;
      total += temp;
      defPoint--;
   }
   //reset defPoint to starting value for next battle
   setDefPoint(2);

   //if d is smaller than a, then calculate damage inflicted and update strength
   //else damage = 0
   if (total < att)
   {
      damage = att - total;
      if (this->strength-damage < 0)
         setStrength(0);
      else
         setStrength(this->strength - damage);
   }
   else
      damage = 0;

   //check to see if Barbarian is still alive, if strength is less than 0, Barbarian
   //is not alive
   if (this->strength <=0)
      this->alive = false;

   return damage;
}

