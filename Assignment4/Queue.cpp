/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 17, 2016
 * Description: Queue Class implementation file
 * ****************************************************************************/

#include "Queue.hpp"

/*******************************************************************************
 * Function: Queue()
 * Description: Queue class default constructor
 * Post-condition: Queue object is created
 * ****************************************************************************/
Queue::Queue()
{
   front = NULL;
   back = NULL;
   numFighter = 0;
}

/*******************************************************************************
 * Function: add()
 * Description: create a node with data passed in and adjust back pointer to 
 * point to this node
 * Parameter: Creature*
 * Pre-condition: queue exists
 * Post-condition: a new node is created, back is now pointing to this node
 * ****************************************************************************/
void Queue::add(Creature* in)
{
   if (isEmpty())
   {
      front = new QueueNode(in, front, back);
      back = front;
   }
   else
   {
      back->next = new QueueNode(in, NULL, back);
      back = back->next;
   }
   numFighter++;
}

/*******************************************************************************
 * Function: remove()
 * Description: return data in the front node, remove the front node and adjust
 * front pointer
 * Pre-condition: Queue exisits
 * Post-condition: front node is removed, front now pointing to the next node
 * ****************************************************************************/ 
Creature* Queue::remove()
{
   QueueNode* temp = NULL;
   Creature* fighter;

   if (isEmpty())
   {
      std::cout << "Queue is empty!" << std::endl;
      fighter = NULL;
   }
   else
   {
      fighter = front->value;
      temp = front;
      front = front->next;
      delete temp;
      numFighter--;
   }

   return fighter;            
}

/*******************************************************************************
 * Fuction: isEmpty()
 * Description: check if queue is empty; true = queue is empty, false = queue is
 * not empty
 * Pre-condition: queue exist
 * ****************************************************************************/
bool Queue::isEmpty()const
{
   if (front == NULL)
      return true;
   else
      return false;
}

/*******************************************************************************
 * Function: getNumFighter()
 * Description: return number of items currently in queue
 * Pre-condition: queue exists
 * ****************************************************************************/
int Queue::getNumFighter() const
{
   return numFighter;
}
