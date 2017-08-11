/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Header file for HarryPotter class
***************************************************************************************************/

#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H

#include "Medusa.h"

class HarryPotter : public Creature
{
private:
	int defense;
	bool hogwarts = false;

public:
	HarryPotter();
	int attack();
	void defend(int);
	void Hogwarts();
};
#endif
