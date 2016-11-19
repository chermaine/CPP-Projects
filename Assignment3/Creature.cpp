/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: Creature class implementation file
 * ****************************************************************************/

#include "Creature.hpp"

/*******************************************************************************
 * Function: Creature()
 * Description: Creature class constructor. Set initial data members
 * Post-condition: Creature object is created with basic data
 * ****************************************************************************/
Creature::Creature()
{
   this->attPoint = 2;
   this->defPoint = 2;
   this->armor = 0;
   this->strength = 12;
   this->name = "Creature";
   this->alive = true;
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
