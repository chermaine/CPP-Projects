/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Lobby class specification file 
 * ****************************************************************************/

#ifndef LOBBY_HPP
#define LOBBY_HPP

#include "Space.hpp"

class Lobby: public Space
{
   private:
      Space* doorToBasement;//pointer to Basement
      Space* doorToRooftop; //pointer to Rooftop
      bool builtBasement;   //variable to indicate if Basement has been built
      bool builtRooftop;    //variable to indicate if Rooftop has been built

   public:
      Lobby();
      ~Lobby();
 
      //mutator functions
      void setDoorToBasement(Space*);
      void setDoorToRooftop(Space*);
      void setBuiltBasement(bool);
      void setBuiltRooftop(bool);

      //accessor functions
      Space* getDoorToBasement() const;
      Space* getDoorToRooftop() const;
      bool getBuiltBasement() const;
      bool getBuiltRooftop() const;

      void createObject();
};

#endif
