/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: BlueMen class specification file (inherit Creature)
 * ****************************************************************************/

#include "BlueMen.hpp"
#include <cstdlib>

/*******************************************************************************
 * Function: BlueMen()
 * Description: BlueMen class constructor
 * Parameter: string, int
 * Post-condition: BlueMen object is created with basic information
 * ****************************************************************************/
BlueMen::BlueMen(std::string name, int team):Creature(name, team)
{
   this->defPoint = 3;
   this->armor = 3;
   this->strength = 12;
   this->type = "Blue Men";
}

/*******************************************************************************
 * Function: attack()
 * Description: To attack, BlueMen will throw the dice x number of times based
 * on his attPoint, result will be randomly generated
 * Pre-condition: BlueMen exists
 * Post-condition: attack value is determined and returned
 * ****************************************************************************/
int BlueMen::attack()
{
   int temp, total=0;

   //loop through at least once to get a randomly generated number between 
   //1 to 6 because BlueMen attacking style is 2d6
   //add that number to total and decrement attPoint by 1
   //if attPoint is less or equal to 0, exit the loop
   //else repeat the loop
   do
   {
      temp = rand()%10 + 1;
      total += temp;
      attPoint--;
   } while (attPoint > 0);
   setAttPoint(2); //reset attPoint to 2 for next attack
   return total;
}

/*******************************************************************************
 * Function: defense()
 * Description: throw the number of dice x number of times based on BlueMen 
 * defending style (2d6); calculate damage receives for this round of combat;
 * update strength accordingly; update defPoint according to Mob's ability
 * Parameter: int
 * Pre-condition: BlueMen exists
 * Post-condition: defending value is determined and returned
 * ****************************************************************************/
int BlueMen::defense(int att)
{
   int temp=0, total=0, damage=0;
   int initial = getDefPoint();

   while (defPoint >0)
   {
      temp = rand()%6 + 1;
      total += temp;
      defPoint--;
   }

   setDefPoint(initial);

   total += getArmor();

   //if BlueMen will survive this round of combat
   if (total < att)
   {
      //calculate damege
      damage = att - total;
      
      //if damage is greater than strength, set strength to 0, set alive to false
      if (this->strength-damage <= 0)
      {
         setStrength(0);
         setAlive(false);
      }
      //else, update strength accordingly
      else
         setStrength(this->strength - damage);

      //check if BlueMen receives 4 points of damage, to take Mob's ability into
      //account
      if (getStrength() <=8)
      {
         if (getDefPoint() == 3)
            setDefPoint(this->defPoint - 1);
      }   
      if (getStrength() <=4)
      {
         if (getDefPoint() == 2)
            setDefPoint(this->defPoint - 1);
      }
   }
   else
      damage = 0;

   return damage; 
}

