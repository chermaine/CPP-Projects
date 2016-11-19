/**********************************************************************
 * Name: Chermaine Cheang
 * Date: April 28, 2016
 * Description: Doodlebug class specification class
 * ******************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP
#include "Critter.hpp"

class Doodlebug:public Critter
{
   private:
      int count;      //hold number of steps taken including attempted moved
      bool starve;    //indicate whether Doodlebug is starving
                      //true = Doodlebug is starving
                      //false = Doodlebug is not starving (just eaten)
      int starveCount;//hold number of steps Doodlebug is starving

   public:
      Doodlebug();
      void setCount(int&);
      int getCount();
      Doodlebug* Breed(int, int); //create a new doodlebug if count is 8
      char getID();       //return 'D' for Doodlebug
      void Eat(Critter*); //eat the Ant if Doodlebug is moving to a cell with Ant
      void setStarve(bool);
      bool getStarve();
      bool Starve(Critter*);//Check if Doodlebug has been starving for 3 consecutive steps
                            //if yes, Doodlebug will die
                            //if not, do nothing
      void setStarveCount(int);//reset starveCount to 0 once Doodlebug has eaten
};

#endif
