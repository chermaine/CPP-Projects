/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 11, 2016
 * Description: Dynamic Stack class specification file
 * ****************************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include "Creature.hpp"

class Stack
{
   private:
      struct StackNode 
      {
         Creature* value;
         StackNode* next;
         // Constructor
         StackNode(Creature* in, StackNode* nextNode=NULL)
         {
            value = in;
            next = nextNode;
         }
      };
      StackNode* top;
      int numFighter;

   public:
      Stack(); 
      void add (Creature*);
      Creature* remove();
      bool isEmpty() const;
      int getNumFighter() const;
};

#endif
