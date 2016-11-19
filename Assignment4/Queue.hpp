/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 12, 2016
 * Description: Dynamic Queue Class specification file
 * ****************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Creature.hpp"

class Queue
{
   private:
      struct QueueNode
      {
         Creature* value;
         QueueNode* next;
         QueueNode* prev;
         //constructor
         QueueNode (Creature* in, QueueNode* nextNode, QueueNode* prevNode)
         {
            value = in;
            next = nextNode;
            prev = prevNode;
         }
      };
      QueueNode* front;
      QueueNode* back;
      int numFighter;
   
   public:
      Queue();
      void add(Creature *);
      Creature* remove();
      bool isEmpty() const;
      int getNumFighter() const;
};
   
#endif
