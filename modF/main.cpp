/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 20, 2016
 * Description: 4 way traffic intersection (State class program), with Queue 
 * structure
 * ****************************************************************************/

#include "State.hpp"
#include "Queue.hpp"
#include "validate.hpp"
#include <iomanip>

int State::numAtN = 0;
int State::numAtS = 0;
int State::numAtE = 0;
int State::numAtW = 0;

int State::totalDepartN =0;
int State::totalDepartS =0;
int State::totalDepartE =0;
int State::totalDepartW =0;

Queue State::NorthBound;
Queue State::SouthBound;
Queue State::EastBound;
Queue State::WestBound;

int State::totalWaitAtN = 0;
int State::totalWaitAtS = 0;
int State::totalWaitAtE = 0;
int State::totalWaitAtW = 0;

int main()
{
   unsigned seed = time(0);
   srand(seed);

   int input;

   //create the four nodes 
   State* currentState = new State('N', 'S', Green, Green, Red, Red, NULL);
   currentState->setNext(new State(' ', ' ', Yellow, Yellow, Red, Red, NULL));
   currentState->getNext()->setNext(new State('E', 'W', Red, Red, Green, Green, NULL));
   currentState->getNext()->getNext()->setNext(new State(' ', ' ', Red, Red, Yellow, Yellow, currentState));

   system("clear");

   //prompt user for number of cycles and validate input
   do
   {
      std::cout << "How many cycles do you want to simulate?" << std::endl;
      std::cout << "(Intersection cycles once every minute)" << std::endl;
      std::cin >> input;
   } while (!validate(input));         

   int count = 4;
   int cycle = 1;
  
   //iterate through the loop x number of times according to user's input
   while (cycle <= input)
   {
      //iterate through the loop to go through each state
      while (count > 0)
      {  
         //simulate the first node
         currentState->simulate(cycle);
         //decrement count
         count--;
         //set currentState to the next node before iterating through the loop again
         currentState = currentState->getNext();
      }
      //increment cycle
      cycle++;
      //reset count to 4 for next cycle
      count = 4;
   }
 
   //calculate average wait time at each lane
   //totalWait time at each lane / total car departed from each lane
   double averageWait = 0;
   std::cout << std::setprecision(3);
   averageWait = currentState->getTotalWaitAtN() / static_cast<double>(currentState->getTotalDepartN());
   std::cout << "Average wait time at N lane: " << averageWait << "cycle\n" << std::endl;

   averageWait = currentState->getTotalWaitAtS() / static_cast<double>(currentState->getTotalDepartS());  
   std::cout << "Average wait time at S lane: " << averageWait << "cycle\n" << std::endl;

   averageWait = currentState->getTotalWaitAtE() / static_cast<double>(currentState->getTotalDepartE());  
   std::cout << "Average wait time at E lane: " << averageWait << "cycle\n" << std::endl;

   averageWait = currentState->getTotalWaitAtW() / static_cast<double>(currentState->getTotalDepartW());  
   std::cout << "Average wait time at W lane: " << averageWait << "cycle\n" << std::endl;

   //set last node's pointer to NULL to mark end of links
   currentState->getNext()->getNext()->getNext()->setNext(NULL);
   State* temp = NULL;

   //free memory allocated for each nodes
   while (currentState!=NULL)
   {
      temp = currentState;
      currentState = currentState->getNext();
      //free memory allocated for cars remaining in each Queue before deleting the node
      currentState->deleteRemainingCars();
      delete temp;
      temp = NULL;
   }

   return 0;  
}
