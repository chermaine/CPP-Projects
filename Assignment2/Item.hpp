/***********************************************************************
 * Name: Chermaine Cheang
 * Date: April 14, 2016
 * Description: Item class header file
 * *******************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP
#include <iostream>
#include <string>
class Item
{
   private: 
      std::string itemName;
      std::string itemUnit;
      int numberNeeded;
      double unitPrice;
      double exPrice;

   public:
      Item();
      Item(std::string name, std::string unit, int, double);
      void extendedPrice();
      void setItemName(std::string);
      void setItemUnit(std::string);
      void setNumberNeeded(int);
      void setUnitPrice(double);
      std::string getItemName();
      std::string getItemUnit();
      int getNumberNeeded();
      double getUnitPrice();
      double getExtendedPrice();
};

#endif
