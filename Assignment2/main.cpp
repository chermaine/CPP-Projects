/**************************************************************************
 * Name: Chermaine Cheang
 * Date: April 14, 2016
 * Description: Grocery shopping program with Item and List class
 * ***********************************************************************/

#include "Item.hpp"
#include "List.hpp"
#include "menu.hpp"
#include "validate.hpp"
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
   List list1;

   int choice;
   bool valid;

   do
   {
      system("clear");

      //display startMenu() and validate user's input
      choice = startMenu();
      valid = startVal(choice);

      if (valid)
      {
         switch (choice)
         {
            //if user chose option 1, call userAdd() to prompt user for item's information 
            //to be added  
            case 1: list1.userAdd();
                    break;
    
            //if user chose option 2, call userRemove() to prompt user for item's information
            //to be removed
            case 2: list1.userRemove();
                    cin.get();
                    break;

            //if user chose option 3, display current content of List
            case 3: cin.ignore();
                    system("clear");
                    list1.displayList();
                    cin.get();
                    break;

            //if user chose option 4, quit program
            case 4: system("clear");
                    cout << "Program terminating. Goodbye!" << endl;
                    break;
         }
      }
  
   } while (choice != 4 || !valid);

   return 0;
}
