/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Header file for Barbarian class
***************************************************************************************************/

#ifndef BARBARIAN_H
#define BARBARIAN_H

#include "Vampire.h"

class Barbarian : public Creature
{
private:
	int defense;

public:
	Barbarian();
	int attack();
	void defend(int);
};
#endif
