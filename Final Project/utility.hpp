/*******************************************************************************
 * Name:Chermaine Cheang
 * Date: Jun 1, 2016
 * Description: Utility functions specification file for final project
 * ****************************************************************************/

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include "Character.hpp"
#include "Object.hpp"
#include "Space.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

//menus 
char startOption();
void solutionMenu(Character);
char printObjectNAsk(Object*);
char moveToNextObject();
char moveToNextSpace();
int doorsToNextSpace(Space*);
std::string playerName();

//validation functions
bool yesNoValidate(char);
bool validate(int, int);

//printing functions
void printSolution(Character);
void printCurrentLocation(std::string);
void printWon(Character);
void displayObjective();

#endif
