/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Utility functions for final project specification file
 * ****************************************************************************/

#include "utility.hpp"
#include "Cafeteria.hpp"
#include "Lobby.hpp"

/*******************************************************************************
 * Function: startOption()
 * Description: prompt user if they want to start the game
 * Pre-condition: program is running
 * Post-condition: Menu is displayed and received user's input
 * *****************************************************************************/
char startOption()
{
   char input;
   do
   {
      std::cout << std::endl;
      std::cout << "Start the game?" << std::endl;
      std::cout << "Y or N" << std::endl;
      std::cin >> input;
   } while (!yesNoValidate(input));
   return input;
}

/*******************************************************************************
 * Function: yesNoValidate()
 * Description: validate user's input on Yes or No questions
 * Parameter: char
 * Pre-conditoin: user entered input
 * Post-condition: user's input is validated
 * *****************************************************************************/
bool yesNoValidate(char input)
{
   bool valid; 
   if (input != 'Y' && input != 'y' && input != 'n' && input != 'N') 
   {
      system("clear");
      std::cout<< "Invalid input." << std::endl;
      valid = false;
   }
   else
      valid = true;

   return valid;
}

/*******************************************************************************
 * Function: solutionMenu()
 * Description: prompt user if they want to know the solution for this game
 * Pre-condition: the game is started
 * *****************************************************************************/
void solutionMenu(Character player)
{
   char input;
   do 
   {
      std::cout << "\nDo you want to know the solution?" << std::endl;
      std::cout << "Y or N" << std::endl;
      std::cin >> input;
   } while (!yesNoValidate(input));

   if (input == 'Y' || input == 'y')
   {
      printSolution(player);
   }
}

/*******************************************************************************
 * Function: printSolution()
 * Description: display the solution of the game. This will be in reversed order
 * of the person array data member in each player
 * Parameter: Charater
 * Pre-condition: Character exists
 * Post-condition: solution is printed
 * ****************************************************************************/
void printSolution(Character player)
{
   std::cout << std::endl;
   std::cout << "Look for " << player.getPerson(2) << ", " << player.getPerson(1)
             << " and " << player.getPerson(0) << "'s name tags in Lobby, Cafeteria,"
             << " and Conference Room." << std::endl;
   std::cout << "Look for their bodies in Kitchen, Basement and Rooftop." << std::endl;
}
 
/*******************************************************************************
 * Function: printCurrentLocation()
 * Description: print out player's current location
 * Parameter: string
 * Pre-condition: game started
 * Post-condition: player's current location is printed
 * ****************************************************************************/
void printCurrentLocation(std::string location)
{
   std::cout << "\n********** Currently in " << location << " **********" << std::endl;
}

/*******************************************************************************
 * Function: printObjectNAsk()
 * Description: print out the object right in front of the player and ask if the 
 * player wants to interact with the object
 * Parameter: object*
 * Pre-condiiton: object exists, game started
 * Post-condition: return y or n
 * ****************************************************************************/
char printObjectNAsk(Object* obj)
{
   char input;
   do 
   {
      std::cout << std::endl;
      std::cout << obj->getNameOfObject() << " is right in front of you."
                << std::endl;
      std::cout << "Do you want to search through " << obj->getNameOfObject() << "?"
                << std::endl;
      std::cout << "Y or N" << std::endl;
      std::cin >> input;
   } while (!yesNoValidate(input));
   return input;
}

/*******************************************************************************
 * Function: moveToNextObject()
 * Description: ask if user wants to move on to the next object
 * Pre-condition: user is done with one object
 * Post-condition: return y or n
 * ****************************************************************************/
char moveToNextObject()
{
   char input;
   do 
   {
      std::cout << "\nMove on to the next object?" << std::endl;
      std::cout << "Y or N" << std::endl;
      std::cin >> input;
   } while (!yesNoValidate(input));
   return input;
}

/*******************************************************************************
 * Function: moveToNextSpace()
 * Description: ask if user wants to move on to the next space
 * Pre-condition: user is done with one space
 * Post-condition: return y or n
 * ****************************************************************************/
char moveToNextSpace()
{
   char input;
   do 
   {
      std::cout << "\nMove to another room?" << std::endl;
      std::cout << "Y or N" << std::endl;
      std::cin >> input;
   } while (!yesNoValidate(input));
   return input;
}

/*******************************************************************************
 * Function: doorsToNextSpace()
 * Description: display a list of rooms connected to current location
 * Parameter: Space*
 * Pre-condition: user is done with this space
 * Post-condition: return user's choice
 * ****************************************************************************/
int doorsToNextSpace(Space* current)
{
   int input, count;
   bool valid;
   do
   {
      std::cout << "\nThis room is connected to " << std::endl;
      count = 0; //counter for number of doors available, min = 4, max = 6

      //check if pointers are pointing to valid address (not NULL)
      //if valid, printout the name of the space the pointer is pointing at
      if (current->getDoorToN() != NULL)
      {
         std::cout << count+1 << " - " << current->getDoorToN()->getNameOfSpace()
                   << std::endl;
         count++;
      }
      if (current->getDoorToS() != NULL)
      {
         std::cout << count+1 << " - " << current->getDoorToS()->getNameOfSpace()
                   << std::endl;
         count++;
      }
      if (current->getDoorToE() != NULL)
      {
         std::cout << count+1 << " - " << current->getDoorToE()->getNameOfSpace()
                   << std::endl;
         count++;
      }
      if (current->getDoorToW() != NULL)
      {
         std::cout << count+1 << " - " << current->getDoorToW()->getNameOfSpace()
                   << std::endl;
         count++;
      }

      //if current space is Cafeteria, also check if pointer to the fifth space is valid
      if (current->getNameOfSpace() == "Cafeteria" && 
          static_cast<Cafeteria*>(current)->getNewSpace() != NULL)
      {
         std::cout << count+1 << " - "  
                 << static_cast<Cafeteria*>(current)->getNewSpace()->getNameOfSpace()
                 << std::endl;
         count++;
      }   
   
      //if current space is Lobby, check if pointers to Basement and Rooftop are valid
      if (current->getNameOfSpace() == "Lobby")
      {
         if (static_cast<Lobby*>(current)->getDoorToBasement() != NULL)
         {
            std::cout << count+1 << " - "  
                 << static_cast<Lobby*>(current)->getDoorToBasement()->getNameOfSpace()
                 << std::endl;
            count++;
         }
         if (static_cast<Lobby*>(current)->getDoorToRooftop() != NULL)
         {
            std::cout << count+1 << " - "  
                 << static_cast<Lobby*>(current)->getDoorToRooftop()->getNameOfSpace()
                 << std::endl;
            count++;
         }
      }   

      //print out number of options available
      std::cout << "Enter ";
      if (count == 1)
         std::cout << count << " to proceed." << std::endl;
      else
      {
         for (int i=1; i< count; i++)
         {
            std::cout << i << ", ";
         }
         std::cout << "or " << count << " only." << std::endl;
      }
      std::cin >> input;
     //reiterate if input is not valid
   } while (!validate(count, input));
   return input;
}

/*******************************************************************************
 * Function: validate()
 * Description: validate user's input, first parameter is used for determining upper
 * limit
 * Parameter: int, int
 * Pre-condition: user entered a choice for next room
 * Post-condition: user choice validated
 * ****************************************************************************/
bool validate(int count, int input)
{
   bool valid;
      if (!std::cin.good())
      {
         system("clear");
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
         std::cout <<"Invalid input. Input must be NUMERIC" << std::endl;
         valid = false;
      }      
      else
      {
         if (input < 1 || input > count)
         {
            system("clear");
            std::cout <<"Invalid choice. " << std::endl;
            valid = false;
         }
         else
            valid = true;
      }
   return valid;
}

/*******************************************************************************
 * Function: printWon()
 * Description: print out a message telling user they have won the game when they
 * saved all the three people in the game
 * Parameter: Character
 * Pre-condition: player's toBeSaved is 0
 * Post-condition: winning message is displayed
 * ****************************************************************************/
void printWon(Character player)
{
   std::cout << std::endl;
   std::cout << std::string(50,'*') << std::endl;
   std::cout << "\tCongratulation, " << player.getName() << "!" << std::endl;
   std::cout << "\tYou saved all your friends!" << std::endl;
   std::cout << std::string(50,'*') << std::endl;
   std::cout << std::endl;
}

/******************************************************************************
 * Function: displayObjective()
 * Desription: print out the objective of the game
 * Pre-condition: program is running
 * ****************************************************************************/
void displayObjective()
{
   std::cout << "Your team (Jon, Brandon, Rickon and yourself) has decided to";
   std::cout << "stay overnight working\non a project in the office. Halfway";
   std::cout << "through the night, you were very tired and you \nfell asleep ";
   std::cout << "in the breakroom. When you woke up the next morning, you ";
   std::cout << "realized all \nyour team members are gone. They are no way to ";
   std::cout << "be found. You tried calling them, \nbut realized they left their";
   std::cout << "phones and keys in the office. You looked around and \nfound ";
   std::cout << "a note on one of your co-worker desk." << std::endl;
   std::cout << std::endl;
   std::cout << "\tHahaha!!! I have captured all your team members and put a"
             << "\n\tput a curse on them! Save your friends by rescuing them from"
             << "\n\twhere they are being confined before time is up. \n"
             << "\tTo save your friends, look for their name tags and place it "
             << "\n\ton their back..." << std::endl;
}

/*******************************************************************************
 * Function: playerName()
 * Description: ask user for their name and validate input
 * Pre-condition: game started
 * POst-condition: user's name inputted
 * ****************************************************************************/
std::string playerName()
{
   std::string name;
   bool valid;
   do 
   {
      std::cout << "\n\nEnter your name: " << std::endl;
      std::getline(std::cin, name);
      if (name == "\n" || name == "" || name == " ")
      {
         std::cout << "\nInvalid input. Name cannot be an empty character or string."  
                   << std::endl;
         valid = false;
      }
      else
         valid = true;
   } while (!valid);
   return name;
}


