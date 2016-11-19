/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 5, 2016
 * Description: State class implementation file
 * ****************************************************************************/
 
#include "State.hpp"

/*******************************************************************************
 * Function: State()
 * Description: State class default constructor
 * ****************************************************************************/
State::State()
{
   this->direction1 = ' ';
   this->direction2 = ' ';
   this->N = NoColor;
   this->S = NoColor;
   this->E = NoColor;
   this->W = NoColor;
   this->next = NULL;
}

/*******************************************************************************
 * Function: State()
 * Description: State class constructor
 * Parameter: two char for direction, 4 Color for color of lights, pointer to State
 * Post-condition: specific state is created
 * ****************************************************************************/
State::State(char d1, char d2, Color n, Color s, Color e, Color w, State* nextNode)
{
   this->direction1 = d1;
   this->direction2 = d2;
   this->N = n;
   this->S = s;
   this->E = e;
   this->W = w;
   this->next = nextNode;
}

/*******************************************************************************
 * Function: setNext()
 * Description: set pointer next
 * Parameter: State pointer
 * Post-condition: pointer next is set to pointing to next instance of State
 * ****************************************************************************/
void State::setNext(State* nextNode)
{
   this->next = nextNode;
}

/*******************************************************************************
 * Function: getNext()
 * Description: return next pointer
 * Pre-condition: State exisits
 * ****************************************************************************/
State* State::getNext() const
{
   return this->next;
}

/*******************************************************************************
 * Function: getDirection1()
 * Description: return current traffic light which is Green
 * Pre-condition: State exists
 * ****************************************************************************/
char State::getDirection1() const
{
   return this->direction1;
}

/*******************************************************************************
 * Function: getDirection2()
 * Description: return current traffic light which is Green
 * Pre-condition: State exists
 * ****************************************************************************/
char State:: getDirection2() const
{
   return this->direction2;
}

/*******************************************************************************
 * Function: getNColor()
 * Description: return color of N traffic light
 * Pre-condition: State exists
 * ****************************************************************************/
Color State:: getNColor() const
{
   return this->N;
}

/*******************************************************************************
 * Function: getSColor()
 * Description: return color of S traffic light
 * Pre-condition: State exists
 * ****************************************************************************/
Color State:: getSColor() const
{
   return this->S;
}

/*******************************************************************************
 * Function: getEColor()
 * Description: return color of E traffic light
 * Pre-condition: State exists
 * ****************************************************************************/
Color State:: getEColor() const
{
   return this->E;
}

/*******************************************************************************
 * Function: getWColor()
 * Description: return color of W traffic light
 * Pre-condition: State exists
 * ****************************************************************************/
Color State:: getWColor() const
{
   return this->W;
}

/*******************************************************************************
 * Function: getTotalDepartN()
 * Description: return total number of vehicles departed N
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getTotalDepartN() 
{
   return totalDepartN;
}

/*******************************************************************************
 * Function: getTotalDepartS()
 * Description: return total number of vehicles departed S
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getTotalDepartS() 
{
   return totalDepartS;
}

/*******************************************************************************
 * Function: getTotalDepartE()
 * Description: return total number of vehicles departed E
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getTotalDepartE() 
{
   return totalDepartE;
}

/*******************************************************************************
 * Function: getTotalDepartW()
 * Description: return total number of vehicles departed W
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getTotalDepartW() 
{
   return totalDepartW;
}

/*******************************************************************************
 * Function: getNumAtN()
 * Description: return number of vehicles waiting at N
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getNumAtN() 
{
   return numAtN;
}

/*******************************************************************************
 * Function: getNumAtS()
 * Description: return number of vehicles waiting at S
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getNumAtS() 
{
   return numAtS;
}

/*******************************************************************************
 * Function: getNumAtE()
 * Description: return number of vehicles waiting at E
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getNumAtE()
{
   return numAtE;
}

/*******************************************************************************
 * Function: getNumAtW()
 * Description: return number of vehicles waiting at W
 * Pre-condition: State exists
 * ****************************************************************************/
int State:: getNumAtW() 
{
   return numAtW;
}

/*******************************************************************************
 * Function: numArrive()
 * Description: randomly generate the number of vehicles arrive at this light, 
 * and add the number of cars into Queue
 * Parameter: char (indicating which traffic light called this function)
 * Pre-condition: State exists
 * Post-condition: number of vehicles arrived is returned and displayed
 * ****************************************************************************/
int State:: numArrive(char light, int cycle)
{
   int total = 0, count = 2;
   int numCarsArrived;

   while (light!= ' ' && count > 0)
   {
      total += rand()%6 + 1;
      count--;
   }

   std::cout << "Total number of vehicles arriving light " << light << ": " 
             << total << std::endl;

   numCarsArrived = total;

   //iterate through the loop based on the number of cars arriving
   //check which lane is green and add the number of cars into that Queue
   while (numCarsArrived > 0)
   {
      if (light == 'N')
         NorthBound.add(cycle);
      if (light == 'S')
         SouthBound.add(cycle);
      if (light == 'E')
         EastBound.add(cycle);
      if (light == 'W')
         WestBound.add(cycle);

      numCarsArrived--;
   }
   usleep(2000000);

   return total;
}

/*******************************************************************************
 * Function: numDepart()
 * Description: randomly generate a number between 4, 5, 6, 7, and 8 for number
 * of vehicles departing this lane, and remove this number of cars from respective
 * Queue
 * Parameter: char (indicating which traffic light called this function), int
 * Pre-condition: state exists
 * Post-condition: number of vehicles departing is returned and displayed
 * ****************************************************************************/
int State:: numDepart(char light, int cycle)
{
   int total=0;
   
   if (light=='N' || light=='S' || light=='E' || light=='W')   
   {
      total = rand()%5 + 4;
   }

   std::cout << "Total number of vehicles departing light " << light << ": "
             << total << std::endl;

   int numCarsDeparted = total;

   //iterate through the loop for the number of cars departing
   //check which light is Green and check if the Queue for this lane is empty
   //if Queue is not empty, remove a car from that Queue
   while (numCarsDeparted > 0)
   {
      if (light == 'N' && !NorthBound.isEmpty())
         totalWaitAtN += (cycle - NorthBound.remove());
      if (light == 'S' && !SouthBound.isEmpty())
         totalWaitAtS += (cycle - SouthBound.remove());
      if (light == 'E' && !EastBound.isEmpty())
         totalWaitAtE += (cycle - EastBound.remove());
      if (light == 'W' && !WestBound.isEmpty())
         totalWaitAtW += (cycle - WestBound.remove());

      numCarsDeparted--;
   }

   usleep(2000000);
   
   return total;
}

/*******************************************************************************
 * Function: simulate()
 * Description: facilitate mechanism of traffic light. that is call numArrive and 
 * numDepart for each light that is Green, update number of vehicles left at
 * each traffic light, have a timer for how long the traffic stay at this state
 * Pre-condition: state exists
 * Post-condition: vehicles at each lanes are updated, state of traffic stay for
 * certain amount of time before returning to main
 * ****************************************************************************/
void State::simulate(int cycle)
{
   int startTime, endTime, arrive, depart;
   startTime = time(0);

   //print out current State
   information();

   char dir = getDirection1();
   int count = 0;

   //iterate twice because lights are in pairs, first determine numArrive, numDepart
   //etc for direction1, then for direction2
   for (int i = 2; i > count; i--)
   {
      //if no lights are Green, do nothing
      if (dir != ' ')
      {
         //determine which light is Green
         //if light is Green, call numArrive, numDepart, calculate difference, and
         //update appropriate counter
         switch (dir)
         {
            //current Green is N
            case 'N': numAtN += numArrive(dir, cycle);
                      depart = numDepart(dir, cycle);
                      totalDepartN += depart;
                      if ((numAtN - depart) < 0)
                         numAtN = 0;
                      else
                         numAtN -= depart; 
                      std::cout << "Number of vehicles remaining at N: " <<numAtN << std::endl;
                      break;

            //current Green is S
            case 'S': numAtS += numArrive(dir, cycle);
                      depart = numDepart(dir, cycle);
                      totalDepartS += depart;

                      if ((numAtS - depart) < 0)
                         numAtS = 0;
                      else
                         numAtS -= depart; 
                      std::cout << "Number of vehicles remaining at S: " <<numAtS << std::endl;
                      break;

            //current Green is E
            case 'E': numAtE += numArrive(dir, cycle);
	              depart = numDepart(dir, cycle);
                      totalDepartE += depart;
                      if ((numAtE - depart) < 0)
                         numAtE = 0;
                      else
                         numAtE -= depart; 
                      std::cout << "Number of vehicles remaining at E: " <<numAtE << std::endl;
                      break;

            //current Green is W
            case 'W': numAtW += numArrive(dir, cycle);
	              depart = numDepart(dir, cycle);
                      totalDepartW += depart;
                      if ((numAtW - depart) < 0)
                         numAtW = 0;
                      else
                         numAtW -= depart; 
                      std::cout << "Number of vehicles remaining at W: " <<numAtW << std::endl;
                      break;
         }
         //set dir to the direction2 for iterating through the loop again
         dir = getDirection2();
         usleep(1500000);
      }
   }      

   std::cout << std::endl;

   endTime = time(0);

   //check if system has enter this function for 10s (time for each state)
   //if not, have system sleep for a total of 10s
   if ((endTime - startTime) < 15)
      usleep(15000000-(endTime-startTime)*1000000);
}

/*******************************************************************************
 * Function: information()
 * Description: print out current state
 * Pre-condition: state exists
 * ****************************************************************************/
void State::information()
{
   //if current Green is E and W
   if (getDirection1()=='E' && getDirection2()=='W')
      std::cout << "*** Currently in state where E & W are Green, N & S are Red ***" << std::endl;

   //current Green is N and S
   else if (getDirection1()=='N' && getDirection2()=='S')
      std::cout << "*** Currently in state where N & S are Green, E & W are Red ***" << std::endl;
 
   //no lights are Green
   else
   {
      //if N and S are now Yellow
      if (getNColor()==Yellow && getSColor()==Yellow)
         std::cout << "*** Currently in state where N & S are Yellow, E & W are Red ***" << std::endl;
      //E and W are now Yellow
      else
	 std::cout << "*** Currently in state where E & W are Yellow, N & S are Red ***" << std::endl;
   }

   std::cout << std::endl;
   usleep(1500000);
}

/*******************************************************************************
 * Function: getTotalWaitAtN()
 * Description: get total wait time at N lane
 * Pre-condition: Queue exists
 * ****************************************************************************/
int State::getTotalWaitAtN()
{
   return totalWaitAtN;
}

/*******************************************************************************
 * Function: getTotalWaitAtS()
 * Description: get total wait time at S lane
 * Pre-condition: Queue exists
 * ****************************************************************************/
int State::getTotalWaitAtS()
{
   return totalWaitAtS;
}
 
/*******************************************************************************
 * Function: getTotalWaitAtE()
 * Description: get total wait time at E lane
 * Pre-condition: Queue exists
 * ****************************************************************************/
int State::getTotalWaitAtE()
{
   return totalWaitAtE;
}
 
/*******************************************************************************
 * Function: getTotalWaitAtW()
 * Description: get total wait time at W lane
 * Pre-condition: Queue exists
 * ****************************************************************************/
int State::getTotalWaitAtW()
{
   return totalWaitAtW;
}

/*******************************************************************************
 * Function: deleteRemainingCars()
 * Description: free allocated memory for each cars still in each lane
 * Pre-condition: at the end of the simulation
 * Post-condition: free all memory allocated for Queue
 * ****************************************************************************/
void State::deleteRemainingCars()
{
   while (!NorthBound.isEmpty())
      NorthBound.remove();
   while (!SouthBound.isEmpty())
      SouthBound.remove();
   while (!EastBound.isEmpty())
      EastBound.remove();
   while (!WestBound.isEmpty())
      WestBound.remove();
}

