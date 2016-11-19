/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Object class specification file
 * ****************************************************************************/

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>

class Object
{
   private:
      std::string nameOfObject;
      std::string initialDescription;
      bool next;
      std::string nextDescription;
      bool interacted;

   public:
      void setInteracted(bool);
      bool getInteracted() const;
      std::string getNameOfObject() const;
      std::string getInitialDescription() const;
      bool getNext() const;
      std::string getNextDescription() const;
      Object();
      Object(std::string, std::string, bool, std::string);
      ~Object();
};


#endif



