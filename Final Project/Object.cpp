/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Object class implementation file
 * ****************************************************************************/

#include "Object.hpp"
#include <iostream>

/*******************************************************************************
 * Function: getNameOfObject()
 * Description: return the name of this object
 * Pre-condition: object exists
 * ****************************************************************************/
std::string Object::getNameOfObject() const
{
   return this->nameOfObject;
}

/*******************************************************************************
 * Function: getInitialDescription()
 * Description: return initial description of this object
 * Pre-condition: object exists
 * ****************************************************************************/
std::string Object::getInitialDescription() const
{
   return this->initialDescription;
}

/*******************************************************************************
 * Function: getNext()
 * Description: return true if name tag is in this object, or false if no name
 * tag is in this object
 * Pre-condition: object exists
 * ****************************************************************************/
bool Object::getNext() const
{
   return this->next;
}

/*******************************************************************************
 * Function: getNextDescription()
 * Description: return object's addtional description if any
 * Pre-condition: object exists
 * ****************************************************************************/
std::string Object::getNextDescription() const
{
   return this->nextDescription;
}

void Object::setInteracted(bool val)
{
   this->interacted = val;
}

bool Object::getInteracted() const
{
   return this->interacted;
}

/*******************************************************************************
 * Function: Object()
 * Description: default constructor
 * ****************************************************************************/
Object::Object()
{
   this->nameOfObject = "";
   this->initialDescription = "";
   this->next = false;
   this->nextDescription = "";
   this->interacted = false;
}

/*******************************************************************************
 * Function: Object()
 * Description: default constructor with parameters
 * Parameter: std::string, std::string, bool, std::string
 * ****************************************************************************/
Object::Object(std::string name, std::string iniD, bool found, std::string nextD)
{
   this->nameOfObject = name;
   this->initialDescription = iniD;
   this->next = found;
   this->nextDescription = nextD;
   this->interacted = false;
}

/*******************************************************************************
 * Function: ~Object()
 * Description: destructor
 * ****************************************************************************/
Object::~Object()
{
}

