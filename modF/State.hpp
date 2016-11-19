/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 5, 2016
 * Description: State class specification file
 * ****************************************************************************/

#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Queue.hpp"

enum Color {NoColor, Red, Green, Yellow};

class State
{
   private:
      State* next; //pointer to next class 
      char direction1;
      char direction2;
      Color E;
      Color W;
      Color N;
      Color S;
      static int numAtE;
      static int numAtN;
      static int numAtW;
      static int numAtS;

      //data variables for calculating wait time
      static int totalDepartN;
      static int totalDepartS;
      static int totalDepartE;
      static int totalDepartW;

      //queue for each lane
      static Queue NorthBound;
      static Queue SouthBound;
      static Queue EastBound;
      static Queue WestBound;

      //data variables for total wait time at each lane
      static int totalWaitAtN;
      static int totalWaitAtS;
      static int totalWaitAtE;
      static int totalWaitAtW;

   public:
      //constructors
      State();
      State(char, char, Color, Color, Color, Color, State*);

      //set next pointer
      void setNext(State*);

      //accessor functions for member variables
      State* getNext() const;
      char getDirection1() const;
      char getDirection2() const;

      Color getEColor() const;
      Color getWColor() const;
      Color getNColor() const;
      Color getSColor() const;

      static int getTotalDepartN() ;
      static int getTotalDepartS() ;
      static int getTotalDepartE() ;
      static int getTotalDepartW() ;

      static int getNumAtE();
      static int getNumAtN();
      static int getNumAtW();
      static int getNumAtS();

      static int getTotalWaitAtN();
      static int getTotalWaitAtS();
      static int getTotalWaitAtE();
      static int getTotalWaitAtW();
      
      //functions for simulating traffic condition
      int numArrive(char, int);
      int numDepart(char, int);
      void simulate(int);
      void information();
      void deleteRemainingCars();
};

#endif

