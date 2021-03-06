/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: HarryPotter class header file (inherit from Barbarian)
 * ****************************************************************************/

#include "HarryPotter.hpp"

/*******************************************************************************
 * Function: HarryPotter()
 * Description: constructor for Harry Potter
 * Parameter: string, int
 * Post-condition: HarryPotter object is created with basic informaiton
 * ****************************************************************************/
HarryPotter::HarryPotter(std::string name, int team):Barbarian(name, team)
{
   this->death = 0;
   this->strength = 10;
   this->type = "Harry Potter";
   this->maxStrength = 10;
}

/*******************************************************************************
 * Function: setDeath()
 * Description: set current number of death
 * Parameter: int
 * Pre-condition: HarryPotter exists
 * Post-condition: death is set
 * ****************************************************************************/
void HarryPotter::setDeath(int val)
{
   this->death = val;
}

/*******************************************************************************
 * Function: getDeath()
 * Description: return current number of death
 * Pre-condition: HarryPotter exisits
 * ****************************************************************************/
int HarryPotter::getDeath()
{
   return this->death;
}

/*******************************************************************************
 * Function: defense()
 * Description: override Barbarian defense() to take into account Hogwarts special
 * ability - if Harry dies for the first time, he will recover immediately
 * and have a strength of 20; if Harry dies again, he will not recover and will 
 * lose the battle
 * Parameter: int
 * Pre-condition: HarryPotter exists
 * Post-condition: damage is calculated for this round of combat, HarryPotter's
 * strength is updated, death is updated if HarryPotter dies.
 * ****************************************************************************/
int HarryPotter::defense(int att)
{
   int temp=0, total=0, damage=0;
   
   while (defPoint > 0)
   {
      temp = rand()%6 + 1;
      total += temp;
      defPoint--;
   } 

   setDefPoint(2);

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

   //check if Harry is still alive
   //if not, check if this is the first time Harry dies
   //first time dying, reincarnate Harry by setting strength to 20 and death to 1
   //else delete Harry
   if (this->strength <= 0)
   {
      if (this->death == 0)
      {
         setStrength(20);
         setDeath(1);

         usleep(3000000);
         std::cout <<  this->name << "'s the Harry Potter Hogwarts super power is activated"
                   << std::endl;
      }
      else
         this->alive = false;
   }
   return damage;
}
