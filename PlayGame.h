/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Header file for PlayGame class
***************************************************************************************************/

#ifndef PLAYGAME_H
#define PLAYGAME_H

#include "HarryPotter.h"

class PlayGame
{
private:
	Creature *player1;
	Creature *player2;
	InputValid inputVal1;
	int p1Choice,
		p2Choice,
		attack,
		totalAttack;

public:
	~PlayGame();
	void menu();
	void setChoiceP1();
	void setChoiceP2();
	void playGame();
	void setCharacters(int, int);
	void fight();
};

#endif