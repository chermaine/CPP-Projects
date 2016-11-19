/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: BreakRoom class specification file 
 * ****************************************************************************/

#ifndef BREAKROOM_HPP
#define BREAKROOM_HPP

#include "Space.hpp"

class BreakRoom:public Space
{
   public:
      BreakRoom();
      ~BreakRoom();
      void createObject();
};

#endif
