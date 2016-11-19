/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: BabaYaga class specification file
 * ****************************************************************************/

#include "BabaYaga.hpp"

/*******************************************************************************
 * Function: BabaYaga()
 * Description: BabaYaga class default constructor
 * Post-condition: BabaYaga object is created with basic information
 * ****************************************************************************/
BabaYaga::BabaYaga():Medusa()
{
   this->strength = 12;
   this->name = "Baba Yaga";
}

/*******************************************************************************
 * Function: attack()
 * Description: To attack, BabaYaga will throw the dice x number of times based
 * on her attPoint, result will be randomly generated
 * Pre-condition: BabaYaga exists
 * Post-condition: attack value is determined and returned
 * ****************************************************************************/
int BabaYaga::attack()
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
   std::cout << getName() << " attacks for " << total << std::endl;

   int soul = total/3;
   setStrength(this->strength + soul);
   std::cout << "****** Baba Yaga's strength increases by " << soul << " ******"
             << std::endl;
   std::cout << "****** Baba Yaga's new strength points: " << this->strength << " ******"
             << std::endl;
   return total;
}
/*******************************************************************************
 * Function: defense()
 * Description: throw the number of dice x number of times based on BabaYaga 
 * defending style (1d10); calculate damage receive for this round of combat
 * update strength accordingly
 * Parameter: int
 * Pre-condition: BabaYaga exists
 * Post-condition: defending value is determined and returned
 * ****************************************************************************/
int BabaYaga::defense(int att)
{
   int temp=0, total=0, damage=0;
   while (defPoint>0)
   {
      temp = rand()%10 + 1;
      total = temp + getArmor();
      defPoint--;
   }
   setDefPoint(1);

   std::cout << getName() << " defends for " << temp << " + " << getArmor() <<
		" points armor" << std::endl;
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

   std::cout << getName() << " receives " << damage << " points of damage." << std::endl;
   std::cout << getName() << " current strength points: " << getStrength() << std::endl;
   return damage;
}
