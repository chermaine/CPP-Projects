/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: functions facilitating game specification file 
 * ****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include "utility.hpp"

//functions for creating required spaces and linking them 
Space* createSpace();
void setDoors(Space*, Space*, Space*, Space*, Space*);

//functions to facilitate interaction of player with space and objects
void interactWithSpace(Character&);
bool interactWithObject(Character&);
void interactingObj(Object*, Character&);
bool foundNameTag(Character&);
bool keepNameTag(std::string, Character&);
void movePlayerToNext(Space*, int, Character&);
bool foundBody(Character&);

//function to add a node and delete a node during run time
void addNewSpace(std::string, Character&);
void deleteKitchen(Space*);
void deleteBasement(Space*);
void deleteRooftop(Space*);

//functions to free all memory allocated at the end of the program
void freeMemory(Space*);
void deleteObject(Space*);

#endif
