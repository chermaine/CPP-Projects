/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 20, 2016
 * Description: Queue Class specification file for traffic stimulation
 * ****************************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <cstdlib>

class Queue
{
   private:
      struct QueueNode
      {
         int value;
         QueueNode* next;
         QueueNode* prev;
         //constructor
         QueueNode (int in, QueueNode* nextNode, QueueNode* prevNode)
         {
            value = in;
            next = nextNode;
            prev = prevNode;
         }
      };
      QueueNode* front;
      QueueNode* back;
      int numItem;
   
   public:
      Queue();
      void add(int);
      int remove();
      bool isEmpty() const;
      int getNumItem() const;
};
   
#endif
