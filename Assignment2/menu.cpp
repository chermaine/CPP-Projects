/**************************************************************************
 * Name:Chermaine Cheang
 * Date: April 5, 2016
 * Description: Menu function
 * ***********************************************************************/

#include <iostream>
#include <string>
/**************************************************************************
 * Function: startMenu()
 * Description: menu options for Grocery Shopping program
 * ***********************************************************************/
int startMenu()
{
   int choice;
   std::cout<<"What do you wish to do? " << std::endl;
   std::cout<<"1 - Add item to shopping cart " << std::endl;
   std::cout<<"2 - Remove item from shopping cart" << std::endl;
   std::cout<<"3 - Display all item in cart" << std::endl;
   std::cout<<"4 - Quit" << std::endl;
   std::cout<<"Enter 1, 2, 3 or 4 as your choice." << std::endl;
   std::cin>>choice;
   return choice;
}

   
