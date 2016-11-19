/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: kitchen class specification file
 * ****************************************************************************/

#ifndef KITCHEN_HPP
#define KITCHEN_HPP

#include "Space.hpp"

class Kitchen: public Space
{
   private:
      bool rescued; //variable to indicate whether user has saved the person in this room

   public:
      Kitchen();
      ~Kitchen();
      void createObject();
      void setRescued(bool);
      bool getRescued() const;
};

#endif
