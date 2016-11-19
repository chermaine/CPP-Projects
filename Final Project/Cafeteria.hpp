/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Cafeteria class specification file 
 * ****************************************************************************/

#ifndef CAFETERIA_HPP
#define CAFETERIA_HPP

#include "Space.hpp"

class Cafeteria: public Space
{
   private:
      Space* newSpace;  //pointer to fifth space
      bool builtKitchen;//variable to keep track of whether Kitchen has been built

   public:
      Cafeteria();
      ~Cafeteria();
      void createObject();

      void setNewSpace(Space*);
      void setBuiltKitchen(bool);

      Space* getNewSpace() const;
      bool getBuiltKitchen() const;
};


#endif
