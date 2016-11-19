/*******************************************************************************
 * Name: Chermaine Cheang
 * Date: May 3, 2016
 * Description: Creature's game facilitating functions header file
 * ****************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Creature.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "utility.hpp"

   Creature* createCreature(int, int, std::string);
   void createTeam(Queue&, int, int);
   void combatBetwFighters(Creature*, Creature*);
   Stack startTournament(Queue&, Queue&);
   void recover(Creature* );
   void resetAbility(Creature*);
   void sameTeamBattle(Queue&, Stack&);
#endif
