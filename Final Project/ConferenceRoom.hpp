/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Conference room specification file
 * ****************************************************************************/

#ifndef CONFERENCEROOM_HPP
#define CONFERENCEROOM_HPP

#include "Space.hpp"

class ConferenceRoom: public Space
{
   public:
      ConferenceRoom();
      ~ConferenceRoom();
      void createObject();
};


#endif




