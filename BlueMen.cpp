/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the BlueMen class functions
***************************************************************************************************/

#include "BlueMen.h"

/****************************************************************************************************
**							Sets BlueMen object armor and strengthPoints
****************************************************************************************************/
BlueMen::BlueMen() : Creature(armor, strengthPoints, "Blue Men")
{
	armor = 3;
	strengthPoints = 12;
}


/****************************************************************************************************
**							Rolls attack dice and returns the value
****************************************************************************************************/
int BlueMen::attack()
{
	// Two random numbers between 1 and 10 are added together and returned
	int attackRoll1 = rand() % 10 + 1;
	int attackRoll2 = rand() % 10 + 1;
	cout << "attacks for " << (attackRoll1 + attackRoll2) << " points" << endl;;
	return (attackRoll1 + attackRoll2);
}


/****************************************************************************************************
** Subtracts attack from total defense, uses remaining attack to determine remaining strength points
****************************************************************************************************/
void BlueMen::defend(int attack)
{
	// Add defense numbers together and subtract them and armor from attack
	int roll = mob();
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
**			Rolls defense dice and returns the value based on remaining strength points
****************************************************************************************************/
int BlueMen::mob()
{
	int roll,
		roll1,
		roll2,
		roll3;

	// Rolls 3 defense dice until strength points is less than 9, then rolls 2.
	// When strength points goes below 5, rolls 1 die.
	if (strengthPoints > 8)
	{
		roll1 = rand() % 6 + 1;
		roll2 = rand() % 6 + 1;
		roll3 = rand() % 6 + 1;

		roll = roll1 + roll2 + roll3;
		return roll;
	}

	else if (strengthPoints > 4 && strengthPoints < 9)
	{
		roll1 = rand() % 6 + 1;
		roll2 = rand() % 6 + 1;

		roll = roll1 + roll2;
		return roll;
	}

	else if (strengthPoints < 5)
	{
		roll = rand() % 6 + 1;

		return roll;
	}
}