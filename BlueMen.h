/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Header file for BlueMen class
***************************************************************************************************/

#ifndef BLUEMEN_H
#define BLUEMEN_H

#include "Barbarian.h"

class BlueMen : public Creature
{
private:
	int defense;

public:
	BlueMen();
	int attack();
	void defend(int);
	int mob();
};
#endif
