/**************************************************************************
 * Name: Chermaine Cheang
 * Date: April 14, 2016
 * Description: List class implementation file
 * ***********************************************************************/

#include "List.hpp"
#include "validate.hpp"
#include <iomanip>
#include <cstdlib>

/**************************************************************************
 * Function: List()
 * Description: List class default constructor. Set initial array size to 4
 * and dynamically allocated memory for array of pointers to item objects
 * Post-condition: List object is created
 * ***********************************************************************/
List::List()
{
   setArraySize(4);
   arrayPtr =  new Item*[4];
   initialize();
}

/**************************************************************************
 * Function: ~List()
 * Description: List class destructor. To free dynamically allocated memory
 * Pre-condition: Program terminating
 * Post-condition: No memory leak
 * ***********************************************************************/
List::~List()
{
   for (int i=0; i < arraySize; i++)
   {
      delete arrayPtr[i];
   }
   delete [] arrayPtr;
   arrayPtr = NULL;
}

/**************************************************************************
 * Function: checkArray()
 * Description: check if array is full
 * Pre-condition: List exists
 * Post-condition: return true for array is full, false for array is not full
 * ***********************************************************************/
void List::checkArray()
{
   bool full;

   //loop through every cell of the array
   for (int i=0; i<arraySize; i++)
   {
      //if there is an empty cell, then array is not full
      if (arrayPtr[i] == NULL)
         full = false;
      //else array is full
      else
         full = true;
   }

   //if array is full, call expandArray() to expand the size of the array
   if (full == true)
      expandArray();
}

/**************************************************************************
 * Function: expandArray()
 * Description: Increase the size of current array by 1 by dynamically 
 * allocating a new array with arraySize + 1, then copying content of the
 * old array to the new array and freeing the memory allocated for the old 
 * array.
 * Pre-condition:List exists and list is full
 * Post-condition: A bigger array is created
 * ***********************************************************************/
void List::expandArray()
{ 
   //get current array's size, increment size by 1 and dynamically allocated
   //a new memory of this size
   int size = getArraySize();
   size += 1;
   Item** temp = new Item*[size];

   //copy content of smaller array to this new bigger array
   for (int i=0; i< arraySize; i++)
   {
      if (arrayPtr[i] != NULL)
            temp[i] = arrayPtr[i];
   }

   //set last content of new bigger array to NULL pointer
   temp[size-1] = NULL;

   //delete the old smaller array
   delete [] arrayPtr;

   //assign arrayPtr to hold current address of this new bigger array
   arrayPtr = temp;

   //reset size of arraySize 
   setArraySize(size);
}

/**************************************************************************
 * Function: userAdd()
 * Description: prompt user for item's name, item's unit, number needed, 
 * and item's unit price, and then add this to the list
 * Pre-condition: user wants to add item to list
 * Post-condition: item added to list
 * ***********************************************************************/
void List::userAdd()
{
   std::string name;
   std::string unit;
   int num;
   double price;
   bool valid, add=true;
   char choice;

   //clear content in buffer and clear the screen
   std::cin.ignore();
   system("clear");

   //prompt user for item's name and capitalize input 
   std::cout << "Enter item's name: " << std::endl;
   getline(std::cin, name);
   for (int i=0; i < name.size(); i++)
      name.at(i) = toupper(name.at(i));

   //prompt user for item's unit of sale and capitalize input
   std::cout << "\nEnter item's unit of sale: " << std::endl;
   getline(std::cin, unit);
   for (int i=0; i < unit.size(); i++)
      unit.at(i) = toupper(unit.at(i));

   //prompt user for unit price and validate input. If input is not valid
   //prompt user to re-enter unit price
   do{
      std::cout << "\nEnter item's unit price: " << std::endl;
      std::cin >> price;
      valid = validate(price);
   } while (!valid);

   //prompt user for number needed and validate input. If input is not valid
   //prompt user to re-enter number needed
   do{
      std::cout << "\nEnter number needed: " << std::endl;
      std::cin >> num;
      valid = validate(num);
   } while (!valid); 
                  
   //loop through all cell of array
   for (int i=0; i<arraySize; i++)
   {
      //if cell is pointing to an Item
      if (arrayPtr[i] != NULL)
      {
         //check if the item user wants to add is already in the list
         if (arrayPtr[i]->getItemName() == name && arrayPtr[i]->getItemUnit() == unit
             && arrayPtr[i]->getUnitPrice() == price)
         {
            //if item already in cart, ask user whether they want to update the number
            //of this item to buy
            std::cout << "\nItem already in cart." << std::endl;
            std::cout << "Do you want to update the number of " << unit 
                      << " of " << name << " to buy?" << std::endl;
            do
            {  std::cin.ignore();
               std::cout << "\nEnter Y for YES or N for NO. " << std::endl;
               std::cin >> choice;
               choice = toupper(choice);
               valid = yesNoValidate(choice);
            } while (!valid);

            //update the number needed and re-calculate extended price for this item
            //set add to false so system will not add the same item to the list twice
            if (choice == 'Y')
            {
               arrayPtr[i]->setNumberNeeded(arrayPtr[i]->getNumberNeeded() + num);
               arrayPtr[i]->extendedPrice();
               add = false;
            }
            else
               add = false;
         }
      }
   }
 
   //call addItem() to add item to List if add is true
   if (add)
      addItem(name, unit, num, price);
}

/**************************************************************************
 * Function: addItem()
 * Description: add item with information given into list array by creating
 * a new Item object
 * Parameter: string itemName, string itemUnit, int numberNeeded, double 
 * unitPrice
 * Pre-condition: List is not full. 
 * Post-condition: Item added to List
 * ***********************************************************************/
void List::addItem(std::string name, std::string unit, int num, double price)
{
   //check if array is full
   checkArray();

   //loop through all cell of array, if cell is empty, create a new Item
   //with user's entered information
   for (int i=0; i<arraySize; i++)
   {
      if (arrayPtr[i]== NULL)
      {
         arrayPtr[i] = new Item(name, unit, num, price);
         //forced exit the loop so item is only added once when more than one
         //cell is NULL
         break;
      }
   }
}

/**************************************************************************
 * Function: userRemove()
 * Description: prompt user for item to be removed
 * Pre-condition: List exists
 * Post-condition: item specified by user is removed from list
 * ***********************************************************************/
void List::userRemove()
{
   std::string name;
   std::string unit;
   int num;
   double price;
   bool valid;

   //clear content in buffer and clear displayed screen
   std::cin.ignore();
   system("clear");

   //prompt user for item to remove and capitalize the input
   std::cout << "Enter item to be removed: " << std::endl;
   getline(std::cin, name);
   for (int i=0; i<name.size(); i++)
      name.at(i) = toupper(name.at(i));

   //prompt user for item's unit of sale to be removed and capitalize input
   std::cout << "\nEnter item's unit of sale: " << std::endl;
   getline(std::cin, unit);
   for (int i=0; i<unit.size(); i++)
      unit.at(i) = toupper(unit.at(i));

   //prompt user for item's unit price and validate input
   do
   {
      std::cout << "\nEnter item's unit price: " << std::endl;
      std::cin >> price;
      valid = validate(price);
   } while (!valid);

   int itemNum=0;
   bool removed=false;

   //loop through all cell in array
   for (int i=0; i<arraySize; i++)
   {
      //if cell is pointing to an Item object
      if (arrayPtr[i] != NULL)
      {
         //check if the item user wants to remove is in the list
         if (arrayPtr[i]->getItemName()==name && 
             arrayPtr[i]->getItemUnit()==unit  &&
             arrayPtr[i]->getUnitPrice()==price)
         {
            //if item is in the list, get numberNeeded
            itemNum = arrayPtr[i]->getNumberNeeded();
            do
            {  //prompt user for number to remove, validate input
               std::cout << "\nEnter number of " <<unit<< " of "<< name << " to be removed: " << std::endl;
               std::cin >> num;
               valid = validate(num); 

               //if user's entered number is greater than current item's number
               //prompt user to re-enter number to remove
               if ((itemNum - num)<0)
               {
                  valid = false;
                  std::cout << "\nInvalid input. " << std::endl;
                  std::cout << "Number to remove is bigger than number needed in List." << std::endl;
                  std::cout << "Number to buy cannot be negative." << std::endl;
               }
            } while(!valid);
           
            //set flag to true
            removed = true;
         }
      }
   }
    
   //if flag is true, call removeItem() to remove item from list
   if (removed)
      removeItem(name, unit, num, price);

   //if flag is false, clear screen, and print out "item not in cart" and display current contents 
   //of cart by calling displayList()
   else
   {
      system("clear");
      std::cout << "Item ($" << price <<"/"<<unit<<" of " << name << ") is not in cart! \n\n" << std::endl;
      displayList();
      std::cin.get();
   }
}

/**************************************************************************
 * Function: removeItem()
 * Description: search for item to be removed by comparing item's name with
 * name passed in. Then get the remaining number of that number needed. If 
 * all of the item were to be removed, remove the item by freeing the memory
 * allocated for that item. If only certain number of the item were to be 
 * removed, update the item's number needed. If item to be removed is not 
 * in the list, print out item not in list to screen.
 * Parameter: string item's name, string item's unit, int number to be removed
 * Pre-condition: List exists
 * Post-condition: Item is either removed completely or number needed is updated
 * ***********************************************************************/  
void List::removeItem(std::string name, std::string unit, int num, double price)
{
   int temp;

   //loop through all cell of array, look for the item to be removed
   for (int i=0; i < arraySize; i++)
   {
      if (arrayPtr[i] != NULL)
      {
         if (arrayPtr[i]->getItemName() == name && 
             arrayPtr[i]->getItemUnit() == unit &&
             arrayPtr[i]->getUnitPrice() == price)
         {
            //calculate number needed after removing user's specified number to remove
            temp = arrayPtr[i]->getNumberNeeded() - num;

            //if number needed after removing is 0, delete Item from List
            if (temp == 0)
            {
               delete arrayPtr[i];
               arrayPtr[i] = NULL;
            }
            //if number needed after removing is not 0, update numberNeeded to remaining number
            //and update extended price
            else
            {
               arrayPtr[i]->setNumberNeeded(temp);
               arrayPtr[i]->extendedPrice();
            }
         }
      }
   }
}

/**************************************************************************
 * Function: displayList()
 * Description: Print out contents of List with Item's name, unit of sale
 * number needed, unit price, extended price and total price for entire list
 * Pre-condition: List must contains at least one Item
 * Post-condition: Contents of list are printed out
 * ***********************************************************************/
void List::displayList()
{
   //set output to print out at least 2 decimal points
   std::cout << std::fixed << std::setprecision(2);   
   std::cout << "Item(s) currently in shopping cart: " << std::endl;
   std::cout << "_____________________________________________________ \n" << std::endl;

   //loop through array
   for (int i=0; i<arraySize; i++)
   {
      //if current cell is pointing to an Item, print out item's name, unit of sale, unit price, 
      //number to buy and extended price
      if (arrayPtr[i] != NULL)
      {
         std::cout << "Item's name"<<std::setw(12)<<": " << arrayPtr[i]->getItemName() << std::endl;
         std::cout << "Item's unit of sales"<<std::setw(3)<<": " <<arrayPtr[i]->getItemUnit() << std::endl;
         std::cout << "Number needed" <<std::setw(10)<<": " << arrayPtr[i]->getNumberNeeded() << std::endl;
         std::cout << "Item's unit price" << std::setw(7)<<": $" << arrayPtr[i]->getUnitPrice() << std::endl;
         std::cout <<"Item's extended price" <<std::setw(15)<<": $" << arrayPtr[i]->getExtendedPrice() << std::endl;
         std::cout << std::endl;
      }
   }
   std::cout << "_____________________________________________________ \n" << std::endl;
   
   //print out total cost of all items in cart
   std::cout << "Total cost of all items " <<std::setw(12)<<": $" << totalPrice() << std::endl;
   std::cout << std::endl;
   std::cout << "(Enter to continue) " << std::endl;
}

/**************************************************************************
 * Function: totalPrice()
 * Description: calculate the total price of all items in the list
 * Pre-condition: List exists
 * Post-condition: total price of list is calculated
 * ************************************************************************/
double List::totalPrice()
{
   double total = 0;
   for (int i=0; i<arraySize; i++)
   {
      if (arrayPtr[i] != NULL)
         total += arrayPtr[i]->getExtendedPrice();
   }
   return total;
}

/**************************************************************************
 * Function: initialize()
 * Description: Initialize dynamically allocated array of pointers to NULL 
 * Pre-condition: List object is created
 * Post-condition: all pointers are pointing to NULL
 * ***********************************************************************/
void List::initialize()
{
   for (int i=0; i<arraySize; i++)
   {
      arrayPtr[i] = NULL;
   }
}

/**************************************************************************
 * Function: setArraySize()
 * Description: set size of array
 * Parameter: int
 * Pre-condition: List object exists
 * Post-condition: size of array is set
 * ***********************************************************************/
void List::setArraySize(int size)
{
   arraySize = size;
}

/**************************************************************************
 * Function: getArraySize()
 * Description: return size of array
 * Pre-condition: array size is set
 * ***********************************************************************/ 
int List::getArraySize()
{
   return arraySize;
}

/**************************************************************************
 * Function: operator==()
 * Description: overloading == operator to compare two strings
 * Parameter: string
 * Pre-condition: List exists
 * Post-condition: return true if both strings are the same, return false
 * if strings are different
 * ***********************************************************************/
bool operator==(std::string a, std::string b)
{
   return !(a.compare(b));
}
