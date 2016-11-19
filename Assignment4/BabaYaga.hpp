/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: BabaYaga class header file (inherit from Medusa)
 * ****************************************************************************/

#ifndef BABAYAGA_HPP
#define BABAYAGA_HPP

#include "Medusa.hpp"

class BabaYaga: public Medusa
{
   private:
      int soulCounter;

   public:
      BabaYaga(std::string name, int team);
      int attack();
      int defense(int);
      void setSoulCounter(int);
      int getSoulCounter() const;
};

#endif
