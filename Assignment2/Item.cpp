/*************************************************************************
 * Name: Chermaine Cheang
 * Date: April 14, 2016
 * Description: Item class implementation file
 * ***********************************************************************/

#include "Item.hpp"

/**************************************************************************
 * Function: Item()
 * Description: Item class default constructor. Set all string variables to
 * empty string and all other variables to 0
 * Post-condition: an Item object is created
 * **********************************************************************/
Item::Item()
{
   itemName = "";
   itemUnit = "";
   numberNeeded = 0;
   unitPrice = 0;
   exPrice = 0;
}

/*************************************************************************
 * Function: Item()
 * Description: Item class constructor. Set all variables with parameter
 * passed in.
 * Parameter: string itemName, string itemUnit, int numberNeeded, double 
 * unitPrice
 * Pre-condition: All parameters are validated
 * Post-condition: an Item object is created with information from user
 * ***********************************************************************/
Item::Item(std::string name, std::string unit, int num, double price)
{
   itemName = name;
   itemUnit = unit;
   numberNeeded = num;
   unitPrice = price;
   extendedPrice();
}

/*************************************************************************
 * Function: extendedPrice()
 * Description: calculate extended price of item using item's unit price 
 * and number needed
 * Pre-condition: Item exists. Item's unit price and number needed is valid
 * Post-condition: item's extended price is calculated and set
 * **********************************************************************/
void Item::extendedPrice()
{
   exPrice = numberNeeded * unitPrice;
}

/*************************************************************************
 * Function: setItemName()
 * Description: set itemName with parameter passed in
 * Parameter: string
 * Pre-condition: Item exists
 * Post-condition: itemName is set
 * **********************************************************************/
void Item::setItemName(std::string name)
{
   itemName = name;
}

/*************************************************************************
 * Function: setItemUnit()
 * Description: set itemUnit with parameter passed in
 * Parameter: string
 * Pre-condition: Item exists
 * Post-condition: itemUnit is set
 * **********************************************************************/
void Item::setItemUnit(std::string unit)
{
   itemUnit = unit;
}

/*************************************************************************
 * Function: setNumberNeeded()
 * Description: set numberNeeded with parameter passed in
 * Parameter: int
 * Pre-condition: Item exists
 * Post-condition: numberNeeded is set
 * **********************************************************************/
void Item::setNumberNeeded(int num)
{
   numberNeeded = num;
}

/*************************************************************************
 * Function: setUnitPrice()
 * Description: set unitPrice with parameter passed in
 * Parameter: double
 * Pre-condition: Item exists
 * Post-condition: unitPrice is set
 * **********************************************************************/
void Item::setUnitPrice(double price)
{
   unitPrice = price;
}

/*************************************************************************
 * Function: getItemName()
 * Description: return item name
 * Pre-condition: item exists
 * ***********************************************************************/
std::string Item::getItemName()
{
   return itemName;
}

/*************************************************************************
 * Function: getItemUnit()
 * Description: return item unit
 * Pre-condition: item exists
 * ***********************************************************************/
std::string Item::getItemUnit()
{
   return itemUnit;
}

/*************************************************************************
 * Function: getNumberNeeded()
 * Description: return number of item needed
 * Pre-condition: item exists
 * ***********************************************************************/
int Item::getNumberNeeded()
{
   return numberNeeded;
}

/*************************************************************************
 * Function: getUnitPrice()
 * Description: return item's unit price
 * Pre-condition: item exists
 * ***********************************************************************/
double Item::getUnitPrice()
{
   return unitPrice;
}

/*************************************************************************
 * Function: getExtendedPrice()
 * Description: return item's extended price
 * Pre-condition: item exists, extended price is calculated
 * ***********************************************************************/
double Item::getExtendedPrice()
{
   return exPrice;
}


