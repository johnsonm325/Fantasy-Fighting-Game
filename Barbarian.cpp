/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the Barbarian class functions
***************************************************************************************************/

#include "Barbarian.h"

/****************************************************************************************************
**							Sets Barbarian object armor and strengthPoints
****************************************************************************************************/
Barbarian::Barbarian() : Creature(armor, strengthPoints, "Barbarian")
{
	armor = 0;
	strengthPoints = 12;
}


/****************************************************************************************************
**							Rolls attack dice and returns the value
****************************************************************************************************/
int Barbarian::attack()
{
	// Two random numbers between 1 and 6 are added together and returned
	int attackRoll1 = rand() % 6 + 1;
	int attackRoll2 = rand() % 6 + 1;
	cout << "attacks for " << (attackRoll1 + attackRoll2) << " points" << endl;;
	return (attackRoll1 + attackRoll2);
}


/****************************************************************************************************
**	Rolls defend die and subtracts attack from total defense, uses remaining attack to determine
**								remaining strength points
****************************************************************************************************/
void Barbarian::defend(int attack)
{
	// Rolls defense dice. 2 random numbers between 1 and 6
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;

	// Add defense numbers together and subtract them and armor from attack
	int roll = roll1 + roll2;
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
