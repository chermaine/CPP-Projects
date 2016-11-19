/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Office class implementation file
 * ****************************************************************************/

#include "Office.hpp"

/*******************************************************************************
 * Function: Office()
 * Description: default constructor
 * ****************************************************************************/
Office::Office():Space()
{
   this->nameOfSpace = "Office";
   createObject();
}

/*******************************************************************************
 * Function: ~Office()
 * Description: default destructor
 * ****************************************************************************/
Office::~Office()
{
}

/*******************************************************************************
 * Function: createObject()
 * Description: create the necessary object needed in a space and add them to
 * the queue holding these objects
 * Pre-condition: Office exists
 * Post-condition: objects in office are created and added to queue container
 * ****************************************************************************/
void Office::createObject()
{
   Object* desk1 = new Object("Jon's Desk", "There are a bunch of files on his desk", false, "");
   setObjectInSpace(desk1);

   Object* bookcase = new Object("Bookcase", 
   "Each shelf is full with folders storing files and reports from previous years up till now", false, "");
   setObjectInSpace(bookcase);

   Object* desk2 = new Object("Brandon's Desk", 
   "A picture of him and his family is on the desk, and his space is very organized", false, "");
   setObjectInSpace(desk2);
}




