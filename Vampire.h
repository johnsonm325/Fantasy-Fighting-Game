/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Header file for Vampire class
***************************************************************************************************/

#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Creature.h"

class Vampire : public Creature
{
private:
	int defense;

public:
	Vampire();
	int attack();
	void defend(int);
	bool charm();
};
#endif
