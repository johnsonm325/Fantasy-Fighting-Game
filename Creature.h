/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Header file for Creature class
***************************************************************************************************/

#ifndef CREATURE_H
#define CREATURE_H

#include "Menu.h"

class Creature
{
protected:
	int armor,
		strengthPoints;
	string type;

public:
	Creature(int, int, string);
	virtual ~Creature();
	virtual int attack() = 0;		// For abstract class
	virtual void defend(int) = 0;	// For abstract class
	virtual int getArmor();
	virtual int getStrengthPoints();
	virtual string getType();
};
#endif