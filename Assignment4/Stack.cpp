/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 11, 2016
 * Description: Dynamic Stack Class implementation file
 * ****************************************************************************/

#include "Stack.hpp"

/*******************************************************************************
 * Function: Stack()
 * Description: Stack class default constructor
 * Post-condition: a stack object is created with default data
 * ****************************************************************************/
Stack:: Stack()
{
   top = NULL;
   numFighter = 0;
}

/*******************************************************************************
 * Function: add()
 * Description: create a node with char value passed in and adjust top pointer
 * Parameter: Creature*
 * Pre-condition: Stack exists
 * Post-condition: new node is created and top now points to the new node
 * ****************************************************************************/
void Stack::add(Creature* in)
{
   top = new StackNode(in, top);
   numFighter++;
}

/*******************************************************************************
 * Function: remove()
 * Description: return data at the top node, remove the node and adjust pointer
 * Pre-condition: Stack exists, node exists
 * Post-condition: top node value is returned, and this node is deleted
 * ****************************************************************************/
Creature* Stack::remove()
{
   StackNode* temp = NULL;
   Creature* removed;

   if (isEmpty())
   {
//      std::cout << "Stack is empty!" << std::endl;
      removed = NULL;
   }
   else 
   {
      removed = top->value;
      numFighter--;
      temp = top;
      top = top->next;
      delete temp;
   }
 
   return removed;      
}

/*******************************************************************************
 * Function: isEmpty()
 * Description: check if the stack is empty; true = stack is empty, false = stack
 * is not empty
 * Post-condition: true or false
 * ****************************************************************************/
bool Stack::isEmpty()const
{
   if (top == NULL)
      return true;
   else
      return false;
}

/*******************************************************************************
 * Function: getNumFighter()
 * Description: return current number of fighters in stack, use mainly for testing
 * purposes
 * Pre-condition: stack exists
 * ****************************************************************************/
int Stack::getNumFighter() const
{
   return numFighter;
}

