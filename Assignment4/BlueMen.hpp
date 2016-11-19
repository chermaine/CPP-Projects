/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: BlueMen class header file (inherit from Creature)
 * ****************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

class BlueMen: public Creature
{
   public:
      BlueMen(std::string, int);
      int attack();
      int defense(int);
   
};

#endif
