/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Rooftop class specification file
 * ****************************************************************************/

#ifndef ROOFTOP_HPP
#define ROOFTOP_HPP

#include "Space.hpp"

class Rooftop: public Space
{
   private:
      bool rescued; //variable to indicate if the player has rescued person in this 
                    //room
   public:
      Rooftop();
      ~Rooftop();
      void createObject();
      void setRescued(bool);
      bool getRescued() const;
};

#endif
