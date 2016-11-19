/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: BabaYaga class specification file
 * ****************************************************************************/

#include "BabaYaga.hpp"

/*******************************************************************************
 * Function: BabaYaga()
 * Description: BabaYaga class constructor
 * Parameter: string, int
 * Post-condition: BabaYaga object is created with basic information
 * ****************************************************************************/
BabaYaga::BabaYaga(std::string name, int team):Medusa(name, team)
{
   this->strength = 12;
   this->type = "Baba Yaga";
   this->soulCounter = 20;
   this->maxStrength = 12;
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
   int temp, soul,total=0;

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
   
   if (total/3 > 0 && this->soulCounter > 0)
   {
      soul = total/3;
      setStrength(this->strength + soul);
      this->soulCounter--;
   }
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

/*******************************************************************************
 * Function: setSoulCounter()
 * Description: set soulCounter with parameter passed in. Primarily for reseting
 * Baba Yaga soul's ability after winning one round of combat
 * Parameter: int
 * Pre-condition: BabaYaga exists
 * Post-condition: soulCounter is set
 * ****************************************************************************/
void BabaYaga::setSoulCounter(int value)
{
   this->soulCounter = value;
}
  
/*******************************************************************************
 * Function: getSoulCounter()
 * Description: return current soulCounter
 * Pre-condtion: Baba Yaga exists
 * ****************************************************************************/
int BabaYaga::getSoulCounter() const
{
   return this->soulCounter;
}
