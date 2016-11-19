/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Creature class implementation file
 * ****************************************************************************/

#include "Creature.hpp"

/*******************************************************************************
 * Function: Creature()
 * Description: Creature class default constructor. Set initial data members
 * Post-condition: Creature object is created with basic data
 * ****************************************************************************/
Creature::Creature()
{
   this->attPoint = 0;
   this->defPoint = 0;
   this->armor = 0;
   this->strength = 0;
   this->alive = true;
   this->type = "Creature";
   this->name = "";
   this->teamNum = 0;
   this->maxStrength = 0;
}

/*******************************************************************************
 * Function: Creature()
 * Description: Creature class constructor. Set initial data members to default
 * values, and set name and teamNum to user's input
 * Post-condition: Creature object is created with basic data
 * ****************************************************************************/
Creature::Creature(std::string name, int team)
{
   this->attPoint = 2;
   this->defPoint = 2;
   this->armor = 0;
   this->strength = 12;
   this->alive = true;
   this->type = "Creature";
   this->name = name;
   this->teamNum = team;
   this->maxStrength = 12;
}

/*******************************************************************************
 * Function: setStrength()
 * Description: function to set current's creature strength value
 * Parameter: int
 * Pre-condition: Creature exists
 * Post-condition: Creature's strength is updated
 * ****************************************************************************/
void Creature::setStrength(int val)
{
   this->strength = val;
}

/*******************************************************************************
 * Function: setAttPoint()
 * Description: function to set creature number of dice for attack
 * Parameter: int
 * Pre-condition: Creature exists
 * Post-condition: Creature's attPoint is updated
 * ****************************************************************************/
void Creature::setAttPoint(int val)
{
   this->attPoint = val;
}

/*******************************************************************************
 * Function: setDefPoint()
 * Description: function to set creature number of dice for defense
 * Parameter: int
 * Pre-condition: Creature exists
 * Post-condition: Creature's defPoint is updated
 * ****************************************************************************/
void Creature::setDefPoint(int val)
{
   this->defPoint = val;
}

/*******************************************************************************
 * Function: setAlive()
 * Description: function to set creature current status; true = alive, false = dead
 * Parameter: bool
 * Pre-condition: Creature exists
 * Post-condition: Creature's alive is updated
 * ****************************************************************************/
void Creature::setAlive(bool val)
{
   this->alive = val;
}

/*******************************************************************************
 * Function: getStrength()
 * Description: return creature's current strength
 * Pre-condition: Creature exists
 * ****************************************************************************/
int Creature::getStrength()const
{
   return this->strength;
}

/*******************************************************************************
 * Function: getAttPoint()
 * Description: return creature's attPoint (number of dice)
 * Pre-condition: Creature exists
 * ****************************************************************************/
int Creature::getAttPoint()const
{
   return this->attPoint;
}

/*******************************************************************************
 * Function: getDefPoint()
 * Description: return creature's defPoint(number of dice)
 * Pre-condition: Creature exists
 * ****************************************************************************/
int Creature::getDefPoint()const
{
   return this->defPoint;
}

/*******************************************************************************
 * Function: getArmor()
 * Description: return creature's armor points
 * Pre-condition: Creature exists
 * ****************************************************************************/
int Creature::getArmor()const
{
   return this->armor;
}

/*******************************************************************************
 * Function: getName()
 * Description: return creature's name
 * Pre-condition: Creature exists
 * ****************************************************************************/
std::string Creature::getName()const
{
   return this->name;
}

/*******************************************************************************
 * Function: getAlive()
 * Description: return creature's status; true = alive; false = dead
 * Pre-condition: Creature exists
 * ****************************************************************************/
bool Creature::getAlive() const
{
   return this->alive;
}

/*******************************************************************************
 * Function: getType()
 * Description: return creature's type
 * Pre-condition: Creature exists
 * ****************************************************************************/
std::string Creature::getType()const
{
   return this->type;
}

/*******************************************************************************
 * Function: getTeamNum()
 * Description: return creature's team 
 * Pre-condition: Creature exists
 * ****************************************************************************/
int Creature::getTeamNum()const
{
   return this->teamNum;
}

/*******************************************************************************
 * Function: randRecover()
 * Description: randomly generate a recovery percentage by rolling a 10 face die, 
 * and calculate recovery points based on damage lost (round down)
 * Pre-condition: Creature exists
 * Post-condition: return the calculated recovery points.
 * ****************************************************************************/
int Creature::randRecover()
{
   int temp = 0;
   int recoverPoint = 0;

   //randomly generated a number from 1 to 10
   temp = rand() % 10 + 1;

   //change temp to percentage by multiplying with 10
   temp *= 10;

   //calculate recoverPoint
   recoverPoint = (this->maxStrength - this->strength) * (temp/100.0);

   return recoverPoint;
} 
