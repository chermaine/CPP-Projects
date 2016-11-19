/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Basement class specification file
 * ****************************************************************************/

#ifndef BASEMENT_HPP
#define BASEMENT_HPP

#include "Space.hpp"

class Basement: public Space
{
   private:
      bool rescued; //variable indicating whether the person in this room has been 
                    //rescued

   public:
      Basement();
      ~Basement();
      void createObject();
      void setRescued(bool);
      bool getRescued() const;
};

#endif




