/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Character class implementation file
 * ****************************************************************************/

#include "Character.hpp"
#include <iostream>
#include <cstdlib>

/******************************************************************************
 * Function: setName()
 * Description: set name of player
 * Parameter: string
 * Pre-condition: player exists
 * Post-condition: name of player is set
 * ****************************************************************************/
void Character::setName(std::string name)
{
   this->name = name;
}

/*******************************************************************************
 * Function: setCurrentLocation()
 * Description: set player's current location
 * Parameter: Space*
 * Pre-condition: Player and space exist
 * Post-condition: Player's current location is set
 * ****************************************************************************/
void Character::setCurrentLocation(Space* location)
{
   this->currentLocation = location;
}

/*******************************************************************************
 * Function: setItemInPocket()
 * Description: add item collected throughout the game into pocket (queue), 
 * queue is limited to a size of 5; return true if item is added successfully into 
 * the queue, return false if item is not added into queue because exceeded size
 * Parameter: string
 * Pre-condition: player exists and vector is not full
 * Post-condition: item is added into vector
 * ****************************************************************************/
bool Character::setItemInPocket(std::string item)
{
   bool added;

   //check if Queue has space for more items
   if (itemInPocket.size() <= 5)
   {
      //push item into Queue if Queue still has space
      itemInPocket.push(item);
      added = true;
   }
   else
   {
      std::cout << "Pocket is full!" << std::endl;
      added = false;
   }
   return added;
}

/*******************************************************************************
 * Function: setPerson()
 * Description: set the array of names in order which the player will find the 
 * name tag (for printing solution)
 * Parameter: string*
 * Pre-condition: order of name tags has been determined
 * Post-condition: array is set
 * ****************************************************************************/
void Character::setPerson(std::string* array)
{
   for (int i=0; i< 3; i++)
   {
      person[i] = array[i];
   }
}

/*******************************************************************************
 * Function: setNameTag()
 * Description: add name passed into the function to the stack holding the order
 * of name tags
 * Parameter: string
 * Pre-condition: player exists
 * Post-condition: name is added to stack
 * ****************************************************************************/
void Character::setNameTag(std::string name)
{
   nameTag.push(name);
}

/*******************************************************************************
 * Function: getName()
 * Description: return the name of current player
 * Pre-condition: player exists
 * ****************************************************************************/
std::string Character::getName() const
{
   return this->name;
}

/*******************************************************************************
 * Function: getCurrentLocation()
 * Description: return the pointer to the current location the player is in
 * Pre-condition: player and space exists
 * ****************************************************************************/
Space* Character::getCurrentLocation() const
{
   return this->currentLocation;
}

/*******************************************************************************
 * Function: getItemInPocket()
 * Description: check if the item needed is in the queue, if it is in the queue
 * return the item and remove the item from the queue
 * Parameter: std::string
 * Pre-condition: player exists
 * ****************************************************************************/
std::string Character::getItemInPocket(std::string item)
{
   std::string temp = itemInPocket.front();
   int count = 5;

   //locate the item needed by popping and pushing elements starting from the first
   while (temp != item && count > 0)
   {
      itemInPocket.pop();
      itemInPocket.push(temp);
      temp = itemInPocket.front();
      count--;
   }
   //if item is in Queue, return item
   if (temp == item)
      return temp;

   else
      return "Item not in pocket!";
}

/*******************************************************************************
 * Function: getPerson()
 * Description: return the name in this element of the array
 * Parameter: int
 * Pre-condtion: player exists
 * ****************************************************************************/
std::string Character::getPerson(int index) const
{
   return this->person[index];
}

/*******************************************************************************
 * Function: getNameTag()
 * Description: remove and return the last name tag in the stack container
 * Pre-condition: stack is not empty
 * Post-condition: last element in stack is returned and removed
 * ****************************************************************************/
std::string Character::getNameTag()
{
   std::string temp ="";
   //check if Stack container is empty before calling top and pop functions
   if (!nameTag.empty())
   {
      //get the last element in the stack
      temp = nameTag.top();
      //remove the last element from the stack
      nameTag.pop();
   }
   else
   {
      std::cout << "NameTag's stack is empty!" << std::endl;
   }
   return temp;
}

/*******************************************************************************
 * Function: randNameOrder()
 * Description: Randomly generated a number between 1-3 three times to determine 
 * the order of the names that will be used for the game
 * Pre-condition: player exists
 * Post-condition: the names in which the player will find is determined
 * ****************************************************************************/
void Character::randNameOrder()
{
   int num1, num2, num3;
   
   //generate a random number between the range of 1-3
   num1 = rand()%3 + 1;
   num2 = rand()%3 + 1;

   //if num1 == num2, regenerate num2 to get a different number
   while (num1 == num2)
   {
      num2 = rand()%3 + 1;
   }

   //if num1 and num2 are 1 and 2, then num3 is 3
   if ((num1 == 1 && num2 == 2) || (num1 == 2 && num2 == 1))
      num3 = 3;
   //if num1 and num2 are 1 and 3, then num3 is 2
   if ((num1 == 1 && num2 == 3) || (num1 == 3 && num2 == 1))
      num3 = 2;
   //if num1 and num2 are 2 and 3, then num3 is 1
   if ((num1 == 2 && num2 == 3) || (num1 == 3 && num2 == 2))
      num3 = 1;

   //call createName function to get the names
   createName(num1, num2, num3);
}

/*******************************************************************************
 * Function: createName()
 * Description: call randNameOrder() to generate the order of names and add the 
 * name to stack container
 * Pre-condition: player exists
 * Post-condition: order of name tag is determined and added to stack
 * ****************************************************************************/
void Character::createName(int a, int b, int c)
{
   //store the parameters in an array for accessing using a for loop
   int array[3] = {a, b, c};

   for (int i=0; i<3; i++)
   {
      //if element is 1, then add "Jon" to Stack holding name tag and array 
      //person
      if (array[i] == 1)
      {
         nameTag.push("Jon");
         person[i] = "Jon";
      }
      //if element is 2, add "Brandon" to stack and array
      if (array[i] == 2)
      {
         nameTag.push("Brandon");
         person[i] = "Brandon";
      }
      //if element is 3, add "Rickon" to stack and array
      if (array[i] == 3)
      {
         nameTag.push("Rickon");
         person[i] = "Rickon";
      }

   }
}

/*******************************************************************************
 * Function: Character()
 * Description: default constructor
 * ****************************************************************************/
Character::Character()
{
   this->name = "";
   this->currentLocation = NULL;
   this->toBeSaved = 0;
}

/*******************************************************************************
 * Function: Character()
 * Description: default constructor
 * ****************************************************************************/
Character::Character(std::string name, Space* location)
{
   this->name = name;
   this->currentLocation = location;
   this->toBeSaved = 3;
   randNameOrder();
}

/*******************************************************************************
 * Function: setToBeSaved()
 * Description: set the variable toBeSaved
 * Parameter: int
 * Pre-condition: Character exists
 * Post-condition: toBeSaved is updated
 * ****************************************************************************/
void Character::setToBeSaved(int count)
{
   this->toBeSaved = count;
}

/*******************************************************************************
 * Function: getToBeSaved()
 * Description: return toBeSaved value
 * Pre-condition: Character exists
 * ****************************************************************************/
int Character::getToBeSaved() const
{
   return this->toBeSaved;
}

/*******************************************************************************
 * Function: checkIfItemIsInPocket()
 * Description: return true if item player is looking for is in the container
 * holding items in player's pocket. Return false if item is not in the container
 * Parameter: String
 * Pre-condition: Character exists
 * Post-condition: item is either found or not found
 * ****************************************************************************/
bool Character::checkIfItemIsInPocket(std::string item)
{
   bool itemFound;
   std::string temp = itemInPocket.front();
   int count = 5;
   while (temp != item && count > 0)
   {
      itemInPocket.pop();
      itemInPocket.push(temp);
      temp = itemInPocket.front();
      count--;
   }
   if (temp == item)
      itemFound = true;
   else
      itemFound = false;
   return itemFound;
}

/*******************************************************************************
 * Function: ~Character()
 * Description: destructor
 * Pre-condition: program terminating
 * ****************************************************************************/
Character::~Character()
{
}
