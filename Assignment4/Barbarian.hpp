/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Barbarian class header file (inherit from Creature)
 * ****************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian: public Creature
{
   public:
      Barbarian(std::string name, int);
      int attack();
      int defense(int );
};

#endif
