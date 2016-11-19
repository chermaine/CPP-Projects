/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Conference room class implementation file
 * ****************************************************************************/

#include "ConferenceRoom.hpp"

/*******************************************************************************
 * Function: ConferenceRoom()
 * Description: default constructor
 * ****************************************************************************/
ConferenceRoom::ConferenceRoom():Space()
{
   this->nameOfSpace = "Conference Room";
   createObject();
}

/*******************************************************************************
 * Function: ~ConferenceRoom()
 * Description: default destructor
 * ****************************************************************************/
ConferenceRoom::~ConferenceRoom()
{
}

/*******************************************************************************
 * Function: createObject()
 * Description: create object needed in conference room and add to queue container
 * Pre-condition: conference room exists
 * Post-condition: objects are created and added to queue
 * ****************************************************************************/
void ConferenceRoom::createObject()
{
   Object* conferenceTable = new Object("Conference Table", 
                             "There's a pile of documents on the far end of the table.",
                             false, "");
   Object* papers = new Object("The pile of documents", "These were the files we were using last night.", 
                               true, "Found a name tag");
   setObjectInSpace(conferenceTable);
   setObjectInSpace(papers);
}
