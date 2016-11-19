/**************************************************************************
 * Name: Chermaine Cheang
 * Date: April 6, 2016
 * Description: Critter class (abstract class)specification file
 * ***********************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP

class Grid;

class Critter
{
   protected:
      int numMoves; //variable to hold number of moves by critter
      int xCoor;    //varible to hold x-coordinate of critter
      int yCoor;    //variable to hold y-coordinate of critter
      bool marker;  //marker to see if critter is moved
                    //false = not moved
                    //true = moved
   public: 
      Critter();    //default constructor
      void setXCoor(int&); //set xCoor
      void setYCoor(int&); //set yCoor
      int getNumMoves();   //return numMoves
      int getXCoor();      //return xCoor
      int getYCoor();      //return yCoor
      void setMarker(bool);//set marker 
      bool getMarker();    //return marker
      bool randMove(int, int); //generate random movement of critter
      virtual Critter* Breed(int, int)=0; //pure virtual function for Breed() 
      virtual char getID();  //return 'C' for Critter
      virtual void setCount(int&) =0; //pure virtual function for setCount()
      virtual int getCount()=0; //pure virtual function for getCount()
      virtual void Eat(Critter*)=0; //pure virtual function for Eat()
};

#endif

