/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the Medusa class functions
***************************************************************************************************/

#include "Medusa.h"

/****************************************************************************************************
**							Sets Medusa object armor and strengthPoints
****************************************************************************************************/
Medusa::Medusa() : Creature(armor, strengthPoints, "Medusa")
{
	armor = 3;
	strengthPoints = 8;
}


/****************************************************************************************************
**							Rolls attack dice and returns the value
****************************************************************************************************/
int Medusa::attack()
{
	// Two random numbers between 1 and 6 are added together and returned
	int attackRoll1 = rand() % 6 + 1;
	int attackRoll2 = rand() % 6 + 1;
	int attackRoll = (attackRoll1 + attackRoll2);

	// Uses glare if roll equals 12
	if (attackRoll == 12)
	{
		attackRoll = glare();
		return attackRoll;
	}
	cout << "attacks for " << (attackRoll1 + attackRoll2) << " points" << endl;;
	return (attackRoll1 + attackRoll2);
}


/****************************************************************************************************
**	Rolls defend die and subtracts attack from total defense, uses remaining attack to determine
**								remaining strength points
****************************************************************************************************/
void Medusa::defend(int attack)
{
	// Rolls defense die. Random numbers between 1 and 6
	int roll = rand() % 6 + 1;

	// Add defense numbers together and subtract them and armor from attack
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


/****************************************************************************************************
**				If attack roll is 12, then glare is used and enemy is instantly killed
****************************************************************************************************/
int Medusa::glare()
{
	cout << "uses glare on enemy. Enemy turns to stone." << endl;
	return 100;
}