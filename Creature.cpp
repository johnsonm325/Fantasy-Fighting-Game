/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the Creature class functions
***************************************************************************************************/

#include "Creature.h"

/****************************************************************************************************
**							Sets creature object for use in fight
****************************************************************************************************/
Creature::Creature(int a, int s, string r)
{
	armor = a;
	strengthPoints = s;
	type = r;
}


Creature::~Creature()
{

}


int Creature::getArmor()
{
	return armor;
}


int Creature::getStrengthPoints()
{
	return strengthPoints;
}


string Creature::getType()
{
	return type;
}