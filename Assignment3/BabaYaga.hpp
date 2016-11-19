/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: BabaYaga class header file (inherit from Medusa)
 * ****************************************************************************/

#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP

#include "Medusa.hpp"

class BabaYaga: public Medusa
{
   public:
      BabaYaga();
      int attack();
      int defense(int);
};

#endif
