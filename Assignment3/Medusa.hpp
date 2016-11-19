/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: Medusa class header file (inherit from Creature)
 * ****************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

class Medusa: public Creature
{
   public:
      Medusa();
      int attack();
      int defense(int);
};

#endif
