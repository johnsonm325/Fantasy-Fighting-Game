/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Header file for Medusa class
***************************************************************************************************/

#ifndef MEDUSA_H
#define MEDUSA_H

#include "BlueMen.h"

class Medusa : public Creature
{
private:
	int defense;

public:
	Medusa();
	int attack();
	void defend(int);
	int glare();
};
#endif
