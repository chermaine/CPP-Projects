/**************************************************************************
 * Name: Chermaine Cheang
 * Date: April 14, 2016
 * Description: List class header file
 * ***********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"

class List
{
   private:
      Item** arrayPtr;
      int arraySize;
 
   public:
      List();
      ~List();
      void checkArray();
      void expandArray();
      void userAdd();
      void addItem(std::string, std::string, int, double);
      void userRemove();
      void removeItem(std::string, std::string, int, double);
      void displayList();
      double totalPrice();
      void initialize();
      void setArraySize(int);
      int getArraySize();
      friend bool operator== (std::string, std::string);
};

#endif
