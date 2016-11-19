/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Medusa class header file (inherit from Creature)
 * ****************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa: public Creature
{
   public:
      Medusa(std::string name, int team);
      int attack();
      int defense(int);
};

#endif
