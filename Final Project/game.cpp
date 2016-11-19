/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: functions facilitating game implementation file
 * ****************************************************************************/

#include "game.hpp"
#include "Office.hpp"
#include "BreakRoom.hpp"
#include "Lobby.hpp"
#include "Cafeteria.hpp"
#include "ConferenceRoom.hpp"
#include "Kitchen.hpp"
#include "Basement.hpp"
#include "Rooftop.hpp"
#include <iostream>
#include <unistd.h>

/*******************************************************************************
 * Function: createSpace()
 * Description: create all the initial rooms necessary for the game, i.e. Office, 
 * Cafeteria, Lobby, Break Room and Conference Room, and return the first room the
 * player will be at the beginning of the game - Office
 * Pre-condition: User wants to start the game
 * Post-condition: All rooms necessary for the game are created
 * ****************************************************************************/
Space* createSpace()
{
   //create the five main spaces
   Space* office = new Office();
   Space* breakRoom = new BreakRoom();
   Space* conferenceRoom = new ConferenceRoom();
   Space* lobby = new Lobby();
   Space* cafeteria = new Cafeteria();

   //link these five spaces together
   setDoors(office, lobby, cafeteria, breakRoom, conferenceRoom);
   setDoors(breakRoom, office, lobby, conferenceRoom, cafeteria);
   setDoors(conferenceRoom, office, lobby, cafeteria, breakRoom);
   setDoors(lobby, cafeteria, office, breakRoom, conferenceRoom);
   setDoors(cafeteria, office, lobby, breakRoom, conferenceRoom);

   //since player starts in the Office, hence return pointer to Office
   return office;
}
/*******************************************************************************
 * Function: setDoors()
 * Description: set doors connected to this room, by calling their mutator functions
 * Parameter: Space*
 * Pre-condition: All Spaces exist
 * Post-condition: Spaces are linked
 * ****************************************************************************/
void setDoors(Space* space, Space* doorN, Space* doorS, Space* doorE, Space* doorW)
{
   space->setDoorToN(doorN);
   space->setDoorToS(doorS);
   space->setDoorToE(doorE);
   space->setDoorToW(doorW);
}

/*******************************************************************************
 * Function: interactWithSpace()
 * Description: facilitate interaction of player with object in current space. Player
 * is passed by reference so that item collected in this space will remain in scope
 * when this function ends. Update player's location to next space and return true
 * if player saved a person in this room
 * Parameter: Character&
 * Pre-condition: All spaces and character exists
 * Post-condition: player interacted with current space
 * ****************************************************************************/
void interactWithSpace(Character& player)
{
   int next;
   char move;
   bool flag;

   Space* current = player.getCurrentLocation();
   usleep(2000000);

   //display player's current location
   printCurrentLocation(player.getCurrentLocation()->getNameOfSpace());

   //have player interact with objects in this space by calling interactWithObject
   flag = interactWithObject(player);

   //if player still has people to be saved in the game, ask if they want to move
   //to another space once they finished interacting with objects in this space
   if (player.getToBeSaved() > 0)
   {   
      move = moveToNextSpace();

      //if player wants to move to another space, display list of rooms connected
      //to this space and move player accordingly
      if (move == 'Y' || move == 'y')
      {
         next = doorsToNextSpace(current);
         movePlayerToNext(player.getCurrentLocation(), next, player);

         //after moving player to the new location, if this new location is lobby
         //or cafeteria, call addNewSpace to check if Kitchen, basement and rooftop
         //had been built. If not, add these nodes and link them accordingly
         if (player.getCurrentLocation()->getNameOfSpace() == "Lobby" ||
             player.getCurrentLocation()->getNameOfSpace() == "Cafeteria")
         {
            addNewSpace(player.getCurrentLocation()->getNameOfSpace(), player);
         }
      }
      //if player do not want to move to another space
      else
      {
         //check if player is currently in Kitchen, Basement or Rooftop
         if (player.getCurrentLocation()->getNameOfSpace()=="Kitchen" ||
             player.getCurrentLocation()->getNameOfSpace()=="Basement" ||
             player.getCurrentLocation()->getNameOfSpace()=="Rooftop")
         {
            //print out the message below and prompt user to move to another room
            //iterate the loop again if player still wants to stay in either of this 
            //room
            do 
            {
               std::cout << "\nNothing else in this room" << std::endl;
               move = moveToNextSpace();
               if (move == 'Y' || move == 'y')
               {
                  next = doorsToNextSpace(player.getCurrentLocation());
                  movePlayerToNext(player.getCurrentLocation(), next, player);
               }
            } while (move == 'N' || move == 'n');
         }
      }
   } 
}

/*******************************************************************************
 * Function: interactWithObject()
 * Description: facilitate the interaction of player with objects in this space
 * by asking if user wants to look through one object and move on to another
 * Parameter: Pointer to a queue, Character
 * Pre-condition: space and character exist
 * Post-condition: interaction of player with objects are displayed
 * ****************************************************************************/
bool interactWithObject(Character& player)
{
   bool saved;
   char next='Y', choice;

   //get first object in this space
   Object* obj = player.getCurrentLocation()->getObjectInSpace();

   while (next == 'Y' || next == 'y')
   {
      //if object is not interacted yet, mainly for object associated to name tags
      if (!obj->getInteracted())
      {
         //if object is a body, call foundBody to check if user will be able to save
         //this person
         if (obj->getNameOfObject() == "Body")
         {
            saved = foundBody(player);

            //if player saved this person, decrement player's to be saved counter
            //and set object's interacted to true
            if (saved==true)
            {
               player.setToBeSaved(player.getToBeSaved()-1);
               obj->setInteracted(true);
               next = 'N';
            }
            else
               next = 'N';
         }
         //for all other objects
         else
         {  //ask if user wants to interact with this object
            choice = printObjectNAsk(obj);

            //if yes, call interacting object and ask if user wants to move on
            if (choice == 'Y' || choice == 'y')
            {
               interactingObj(obj, player);
               next = moveToNextObject();
            }
            //if not, ask if user wants to move on to another object
            else
               next = moveToNextObject();
         }

         //if user wants to move on to another object, add current object back to 
         //queue and get the next object from the container
         if (next == 'Y' || next == 'y')
         {
            player.getCurrentLocation()->setObjectInSpace(obj);
            obj = player.getCurrentLocation()->getObjectInSpace();
         }
         //if user does not want to move on, add current object back to queue
         else
         {
            player.getCurrentLocation()->setObjectInSpace(obj);
            next = 'n';      
         }
      }
      //if object's interacted is true, then add object back to queue container
      //and move on to the next automatically
      else
      {
         player.getCurrentLocation()->setObjectInSpace(obj);
         obj = player.getCurrentLocation()->getObjectInSpace();
         next = 'y';
      }   
   }
   return saved;
}

/*******************************************************************************
 * Function: interactingObj()
 * Description: this function is called when the player wishs to interact with 
 * the object currently right in front of them. Print out if user finds anything
 * Parameter: Object, Character
 * Pre-condition: player wants to interact with this object
 * Post-condition: any findings is displayed
 * ****************************************************************************/
void interactingObj(Object* obj, Character &player)
{
   bool kept;
   std::cout << "\n" << obj->getInitialDescription() << "..." << std::endl;
   usleep(2000000);

   //if object's getNext() is true, then player has found a name tag
   if (obj->getNext())
   {
      kept = foundNameTag(player);
      //if player kept the name tag, set object's interacted to true to prevent
      //any other interaction with this object
      if (kept)
         obj->setInteracted(true);
   }

   //else tell user they did not find anything
   else
   {
      usleep(2000000);
      std::cout << "\nYou did not find anything..." << std::endl;
   }
}

/*******************************************************************************
 * Function: foundNameTag()
 * Description: let user's know that they have found a name tag
 * Parameter: Character&
 * Pre-condition: object.getNext() return true
 * Post-condition: user knows that they have found a name tag
 * ****************************************************************************/
bool foundNameTag(Character& player)
{
   std::string name = player.getNameTag();
   usleep(2000000);
   std::cout << "\nFound " << name << "'s nameTag" << std::endl;
   bool kept = keepNameTag(name, player);

   //if user did not keep the name tag, add the name tag back into its stack 
   //container
   if (!kept)
      player.setNameTag(name);

   return kept;
}

/*******************************************************************************
 * Function: keepNameTag()
 * Description: ask user if they want to keep the name tag just found, if yes, 
 * add name tag to player's pocket
 * Parameter: string, Character&
 * Pre-condition: user just found a name tag
 * Post-condition: name tag is pushed into Queue container
 * ****************************************************************************/
bool keepNameTag(std::string name, Character& player)
{
   char input;

   do 
   {
      usleep(2000000);
      std::cout << "\nDo you want to keep " << name << "'s name tag in your pocket?"
                << std::endl;
      std::cout << "Y or N" << std::endl;
      std::cin >> input;
   } while (!yesNoValidate(input));
   
   //if user wants to keep the name tag, add it into player's queue container
   //for holding items
   if (input == 'Y' || input == 'y')
   {
      player.setItemInPocket(name);
      return true;
   }
   else
      return false;
}

/*******************************************************************************
 * Function: movePlayerToNext()
 * Description: move player to next space based on input received
 * Parameter: Space*, int, Character&
 * Pre-condition: user selected a room to go next
 * Post-condition: user's current location is updated
 * ****************************************************************************/
void movePlayerToNext(Space* current, int next, Character& player)
{
   switch (next)
   {  //move player to the room on the North of current room 
      case 1: player.setCurrentLocation(current->getDoorToN());
              break;

      //move player to room on the South
      case 2: player.setCurrentLocation(current->getDoorToS());
              break;

      //move player to room on the East
      case 3: player.setCurrentLocation(current->getDoorToE());
              break;

      //move player to room on the West
      case 4: player.setCurrentLocation(current->getDoorToW());
              break;

      //if current room is cafeteria, check if fifth pointer is valid, if valid, move
      //player to this space
      //if current room is lobby, check if pointer to basement is valid. if valid, 
      //move player to basement
      //if current room is lobby, check if pointer to rooftop is valid, if valid, move
      //player to rooftop
      case 5: if (current->getNameOfSpace() == "Cafeteria")
              {
                 if (static_cast<Cafeteria*>(current)->getNewSpace() != NULL);
                 {
                    player.setCurrentLocation(static_cast<Cafeteria*>(current)->getNewSpace());
                    break;
                 }
              }
              if (current->getNameOfSpace() == "Lobby")
              {
                 if (static_cast<Lobby*>(current)->getDoorToBasement() != NULL)
                 {
                    player.setCurrentLocation(static_cast<Lobby*>(current)->getDoorToBasement());
                    break;
                 }
                 else if (static_cast<Lobby*>(current)->getDoorToRooftop() != NULL)
                 {
                    player.setCurrentLocation(static_cast<Lobby*>(current)->getDoorToRooftop());
                    break;
                 }
              }
              break;

      //if current room is lobby, if pointer to rooftop is valid, move player
      //to rooftop
      case 6: if (current->getNameOfSpace() == "Lobby")
              {
                 if (static_cast<Lobby*>(current)->getDoorToRooftop() != NULL)
                 {
                    player.setCurrentLocation(static_cast<Lobby*>(current)->getDoorToRooftop());
                    break;
                 }
              }
              break;
   }
}

/*******************************************************************************
 * Function: addNewSpace()
 * Description: create the new space required and assign pointers to this space
 * Parameter: string, Character&
 * Pre-condition: player moved to a new location
 * Post-condition: new room is added depending on player's new location
 * ****************************************************************************/
void addNewSpace(std::string room, Character& player)
{
   //if current room is Cafeteria and has not built kitchen yet. 
   //Build kitchen, set cafeteria's fifth pointer to kitchen and set kitchen's
   //doorToN pointer to Cafeteria
   if (room == "Cafeteria") 
   {
      if (static_cast<Cafeteria*>(player.getCurrentLocation())->getBuiltKitchen() == false)
      {
         Space* kitchen = new Kitchen();
         kitchen->setDoorToN(player.getCurrentLocation());
         static_cast<Cafeteria*>(player.getCurrentLocation())->setNewSpace(kitchen);
         static_cast<Cafeteria*>(player.getCurrentLocation())->setBuiltKitchen(true);
      }
   }

   //if current room is lobby
   if (room == "Lobby" )
   {
      //if basement has not been built.
      //built basement, set pointer to basement and basement's N pointer
      if (static_cast<Lobby*>(player.getCurrentLocation())->getBuiltBasement() == false)
      {
         Space* basement = new Basement();
         basement->setDoorToN(player.getCurrentLocation());
         static_cast<Lobby*>(player.getCurrentLocation())->setDoorToBasement(basement);
         static_cast<Lobby*>(player.getCurrentLocation())->setBuiltBasement(true);
      }
      //if rooftop has not been built
      //built rooftop, set pointer to rooftop and rooftop's N pointer
      if (static_cast<Lobby*>(player.getCurrentLocation())->getBuiltRooftop() == false)
      {
         Space* rooftop = new Rooftop();
         rooftop->setDoorToN(player.getCurrentLocation());
         static_cast<Lobby*>(player.getCurrentLocation())->setDoorToRooftop(rooftop);
         static_cast<Lobby*>(player.getCurrentLocation())->setBuiltRooftop(true);
      }
   } 
}

/*******************************************************************************
 * Function: deleteKitchen()
 * Description: delete Kitchen space not needed anymore once player saved the person 
 * in the space
 * Parameter: Space*
 * Pre-condition: player finished interacting with the space
 * Post-condition: this space is deleted
 * ****************************************************************************/
void deleteKitchen(Space* space)
{
   Space* temp = space;
   //delete objects first
   deleteObject(temp);
   //set Cafeteria's fifth pointer to NULL
   static_cast<Cafeteria*>(temp->getDoorToN())->setNewSpace(NULL);
   //deallocated memory
   delete temp;
   temp = NULL;
   std::cout << "Deleted kitchen" << std::endl;
}

/*******************************************************************************
 * Function: deleteBasement()
 * Description: delete Basement space not needed anymore once player saved the person 
 * in the space
 * Parameter: Space*
 * Pre-condition: player finished interacting with the space
 * Post-condition: this space is deleted
 * ****************************************************************************/
void deleteBasement(Space* space)
{
   Space* temp = space;
   deleteObject(temp);
   static_cast<Lobby*>(temp->getDoorToN())->setDoorToBasement(NULL);
   delete temp;
   temp = NULL;
   std::cout << "Deleted basement" << std::endl;
}

/*******************************************************************************
 * Function: deleteRooftop()
 * Description: delete Rooftop space not needed anymore once player saved the person 
 * in the space
 * Parameter: Space*
 * Pre-condition: player finished interacting with the space
 * Post-condition: this space is deleted
 * ****************************************************************************/
void deleteRooftop(Space* space)
{
   Space* temp = space;
   deleteObject(temp);
   static_cast<Lobby*>(space->getDoorToN())->setDoorToRooftop(NULL);
   delete temp;
   temp = NULL;
   std::cout << "Deleted rooftop " << std::endl;
}

/*******************************************************************************
 * Function: foundBody()
 * Description: if the player enters a space in which he/she will find a body,
 * this function will be called to facilitate the process of saving this person
 * player will be asked if they have the name tag for this person, if they do
 * look for it and put it on the person back, if not tell player to go look this
 * person name tag
 * Parameter: Character&
 * Pre-condition: player found a body
 * Post-condition: player either rescue this person or not
 * ****************************************************************************/
bool foundBody(Character& player)
{
   bool saved;
   char input;
   usleep(2000000);
   std::cout << "\nSomeone is there..." << std::endl;
   usleep(2000000);
   std::cout << "\nIt's " << player.getPerson(player.getToBeSaved()-1) << "!!!" << std::endl;
   do
   {
      std::cout << "\nDo you have " << player.getPerson(player.getToBeSaved()-1) 
                << "'s name tag?" << std::endl;
      std::cout << "Look through your pockets? " << std::endl;
      std::cout << "Y or N" << std::endl;
      std::cin >> input;
   } while (!yesNoValidate(input));

   if (input == 'Y' || input == 'y')
   {
      //check if user has the name tag required
      bool found = player.checkIfItemIsInPocket(player.getPerson(player.getToBeSaved()-1));
      if (found)
      {
         usleep(2000000);
         std::cout << "\nYes!!! You have " << player.getPerson(player.getToBeSaved()-1) 
                   << "'s name tag!" << std::endl;
         std::cout << "Place " << player.getPerson(player.getToBeSaved()-1) << "'s name tag on "
                   << player.getPerson(player.getToBeSaved()-1) << "'s back to save him." << std::endl;
         usleep(2000000);
         std::cout << "\nGood job!!! You saved " << player.getPerson(player.getToBeSaved()-1) 
                   << "!!" << std::endl;
         saved = true;
         //set Kitchen, Basement or Rooftop's rescued variable to true
         if (player.getCurrentLocation()->getNameOfSpace() == "Kitchen")
            static_cast<Kitchen*>(player.getCurrentLocation())->setRescued(saved);
         if (player.getCurrentLocation()->getNameOfSpace() == "Basement")
            static_cast<Basement*>(player.getCurrentLocation())->setRescued(saved);
         if (player.getCurrentLocation()->getNameOfSpace() == "Rooftop")
            static_cast<Rooftop*>(player.getCurrentLocation())->setRescued(saved);
      }
      //if user does not have the name tag
      else
      {
         usleep(2000000);
         std::cout << "\nYou do not have " << player.getPerson(player.getToBeSaved()-1)
                   << "'s name tag.\nYou have to look for " << player.getPerson(player.getToBeSaved()-1) 
                   << "'s name tag to save him." << std::endl;
         saved = false;
      }
   }
   //user does not want to look through their pockets because they do not have the name tag
   else
   {
      std::cout << "\nYou have to look for " << player.getPerson(player.getToBeSaved()-1) 
                 << "'s name tag to save him." << std::endl;
      std::cout << "Come back when you found it!" << std::endl;
      saved = false;
   }
   return saved;
}

/*******************************************************************************
 * Function: freeMemory()
 * Description: free dynamically allocated memory for the game
 * Parameter: Space*
 * Pre-condition: the end of the game
 * Post-condition: all memory freed
 * ****************************************************************************/
void freeMemory(Space* current)
{  //check if current space is cafeteria and if cafeteria's fifth pointer is valid
   //if yes, delete objects in this room and delete this room
   if (current->getNameOfSpace() == "Cafeteria")
   {
      if (static_cast<Cafeteria*>(current)->getNewSpace() != NULL)
      {
         deleteObject(static_cast<Cafeteria*>(current)->getNewSpace());
         delete (static_cast<Cafeteria*>(current)->getNewSpace());
         static_cast<Cafeteria*>(current)->setNewSpace(NULL);
         std::cout << "Deleted kitchen" << std::endl;
      }
   }
   //check if current space is lobby and if pointers to basement and rooftop are
   //valid. If valid, delete objects in these rooms, and deallocate memory for
   //these rooms
   if (current->getNameOfSpace() == "Lobby")
   {
      if (static_cast<Lobby*>(current)->getDoorToBasement() != NULL)
      {
         deleteObject(static_cast<Lobby*>(current)->getDoorToBasement());
         delete (static_cast<Lobby*>(current)->getDoorToBasement()); 
         static_cast<Lobby*>(current)->setDoorToBasement(NULL); 
         std::cout << "Deleted basement" << std::endl;
      }
      if (static_cast<Lobby*>(current)->getDoorToRooftop() != NULL)
      {
         deleteObject(static_cast<Lobby*>(current)->getDoorToRooftop());
         delete (static_cast<Lobby*>(current)->getDoorToRooftop());
         static_cast<Lobby*>(current)->setDoorToRooftop(NULL); 
         std::cout << "Deleted rooftop" << std::endl;
      }
   }

   //check if other pointers are valid. If valid, delete objects in these spaces
   //and deallocated memory for these spaces
   if (current->getDoorToN() != NULL)
   { 
      deleteObject(current->getDoorToN());
      std::cout << "Deleted " << current->getDoorToN()->getNameOfSpace()<< std::endl;
      delete current->getDoorToN();
      current->setDoorToN(NULL);
   }
   if (current->getDoorToS() != NULL)
   {
      deleteObject(current->getDoorToS());
      std::cout << "Deleted " << current->getDoorToS()->getNameOfSpace()<< std::endl;
      delete current->getDoorToS();
      current->setDoorToS(NULL);
   }
   if (current->getDoorToE() != NULL)
   {
      deleteObject(current->getDoorToE());
      std::cout << "Deleted " << current->getDoorToE()->getNameOfSpace()<< std::endl;
      delete current->getDoorToE();
      current->setDoorToE(NULL);
   }
   if (current->getDoorToW() != NULL)
   {
      deleteObject(current->getDoorToW());
      std::cout << "Deleted " << current->getDoorToW()->getNameOfSpace()<< std::endl;
      delete current->getDoorToW();
      current->setDoorToW(NULL);
   }
}

/*******************************************************************************
 * Function: deleteObject()
 * Description: free memory allocated for object in each room
 * Parameter: Space*
 * Pre-condition: end of the game
 * Post-condition: all memory freed
 * ****************************************************************************/
void deleteObject(Space* current)
{
   std::cout << std::endl;
   while (!current->checkObjectInSpace())
   {
      delete current->getObjectInSpace();
      std::cout << "Deleting objects in " << current->getNameOfSpace() << std::endl;
   }
}


