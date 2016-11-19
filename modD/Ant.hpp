/**********************************************************************
 * Name: Chermaine Cheang
 * Date: April 12, 2016
 * Description: Ant class specification class
 * ******************************************************************/

#ifndef ANT_HPP
#define ANT_HPP
#include "Critter.hpp"

class Ant:public Critter
{
   private:
      int count; 
   
   public:
      Ant();
      void setCount(int&);
      int getCount();
      Ant* Breed(int, int); //create a new ant is count is 3
      char getID(); //return 'A' for Ant
      void Eat(Critter*);//an empty function to avoid being an abstract class
};

#endif
