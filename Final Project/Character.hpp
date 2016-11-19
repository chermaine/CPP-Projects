/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Character class specification file
 * ****************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "Space.hpp"
#include <string>
#include <queue>
#include <stack>

class Character
{
   private:
      std::string name;      //variable to hold name of player
      Space* currentLocation;//variable to hold current location of player
      std::queue<std::string> itemInPocket; //queue container for holding items
      std::string person[3]; //string array for holding order of name tags
      std::stack<std::string> nameTag; //stack container to hold name tag
      int toBeSaved;         //variable to hold number of people the player has to save

   public:
      //mutator functions for data members
      void setName(std::string);
      void setCurrentLocation(Space*);
      bool setItemInPocket(std::string);
      void setPerson(std::string*);
      void setNameTag(std::string);
      void setToBeSaved(int);
   
      //accessor functions for data members
      std::string getName() const;
      Space* getCurrentLocation() const;
      std::string getItemInPocket(std::string);
      std::string getPerson(int) const;
      std::string getNameTag();
      int getToBeSaved() const;
      bool checkIfItemIsInPocket(std::string); 

      //functions to generate an order for name
      void randNameOrder();
      void createName(int, int, int);
  
      //constructors and destructor
      Character();
      Character(std::string, Space*);  
      ~Character();
  
};

#endif
