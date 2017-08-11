/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the Vampire class functions
***************************************************************************************************/

#include "Vampire.h"

/****************************************************************************************************
**							Sets Vampire object armor and strengthPoints
****************************************************************************************************/
Vampire::Vampire() : Creature(armor, strengthPoints, "Vampire")
{
	armor = 1;
	strengthPoints = 18;
}

/****************************************************************************************************
**							Rolls attack die and returns the value
****************************************************************************************************/
int Vampire::attack()
{
	// Random number between 1 and 12
	int attackRoll = rand() % 12 + 1;
	cout << "attacks for " << attackRoll << " points" << endl;;
	return attackRoll;
}

/****************************************************************************************************
**	Rolls defend die and subtracts attack from total defense, uses remaining attack to determine
**								remaining strength points
****************************************************************************************************/
void Vampire::defend(int attack)
{
	// Determines if charm ability is used, if so, no damage is taken
	if (charm() == true)
	{
		cout << "charms and the other player deals no damage" << endl;
	}

	else
	{
		// Rolls defense die
		int roll = rand() % 6 + 1;

		// Subtracts defense and armor from attack
		attack -= roll;
		attack -= armor;
		if (attack > -1)
		{
			// Deducts attack from strength
			strengthPoints -= attack;
		}

		// Prints total defense
		cout << "defends for " << (roll + armor) << " points";

		if (attack < 1)
		{
			// Prints no damage taken if attack is less than 1
			cout << " and loses 0 strength points" << endl;
		}
		else
		{
			// Prints the number of strength points lost
			cout << " and loses " << attack << " strength points" << endl;
		}
		
		// Prints defense roll and armor
		cout << "Defense roll: " << roll << endl;
		cout << "Armor: " << armor << endl;
		cout << endl;
	}
}

/****************************************************************************************************
**				Rolls random number of 1 or 2, if 1, then charm is used
****************************************************************************************************/
bool Vampire::charm()
{
	int cNum = rand() % 2 + 1;

	if (cNum == 1)
	{
		return true;
	}

	return false;
}