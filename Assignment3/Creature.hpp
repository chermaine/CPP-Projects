/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: Creature class header file
 * ****************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Creature 
{
   protected:
      int strength;
      int attPoint;
      int defPoint;
      int armor;
      std::string name;
      bool alive;
   public:
      Creature(); //default constructor

      //mutator functions
      void setStrength(int);
      void setAttPoint(int);
      void setDefPoint(int);
      void setAlive(bool);

      //accessor functionr
      int getStrength()const;
      int getAttPoint()const;
      int getDefPoint()const;
      int getArmor() const;
      std::string getName() const;
      bool getAlive() const;

      //pure virtual functions
      virtual int attack()=0;
      virtual int defense(int)=0;
};

#endif
