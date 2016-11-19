/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Space class specification file
 * ****************************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <queue>
#include "Object.hpp"

class Space
{
   protected:
      Space* doorToN; //pointer to room on the North side of this room
      Space* doorToS; //pointer to room on the South side of this room
      Space* doorToE; //pointer to room on the East side of this room
      Space* doorToW; //pointer to room on the West side of this room
      std::string nameOfSpace; //variable to store name of this room
      std::queue<Object*> objectInSpace; //queue container to hold objects in this room

   public:
      //mutator functions
      void setDoorToN(Space*);
      void setDoorToS(Space*);
      void setDoorToE(Space*);
      void setDoorToW(Space*);
      void setNameOfSpace(std::string);
      void setObjectInSpace(Object*);

      //accessor functions
      Space* getDoorToN() const;
      Space* getDoorToS() const;
      Space* getDoorToE() const;
      Space* getDoorToW() const;
      std::string getNameOfSpace() const;
      Object* getObjectInSpace();
      bool checkObjectInSpace();

      Space();
      ~Space();
      virtual void createObject() = 0;
};

#endif

