/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: HarryPotter class header file (inherit from Barbarian)
 * ****************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Barbarian.hpp"

class HarryPotter: public Barbarian
{
   private:
      int death;

   public:
      HarryPotter();
      void setDeath(int);
      int getDeath();
      int defense(int);
};

#endif
