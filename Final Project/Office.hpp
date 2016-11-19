/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Office class specification file (inherit Space) 
 * ****************************************************************************/

#ifndef OFFICE_HPP
#define OFFICE_HPP

#include "Space.hpp"

class Office: public Space
{
   public:
      Office();
      ~Office();
      void createObject();
};


#endif
