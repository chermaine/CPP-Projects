/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Creature class header file
 * ****************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

class Creature 
{
   protected:
      int strength;
      int attPoint;
      int defPoint;
      int armor;
      bool alive;
      std::string type;
      std::string name;
      int teamNum;
      int maxStrength;

   public:
      Creature(); //default constructor
      Creature(std::string, int); //constructor

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
      bool getAlive() const;
      std::string getType() const;
      std::string getName() const;
      int getTeamNum() const;

      //pure virtual functions
      virtual int attack()=0;
      virtual int defense(int)=0;

      //randRecover() not a pure virtual functions because how a creature get recover is 
      //the same for all creature types
      int randRecover();
};

#endif
