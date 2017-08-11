/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the HarryPotter class functions
***************************************************************************************************/

#include "HarryPotter.h"

/****************************************************************************************************
**						Sets HarryPotter object armor and strengthPoints
****************************************************************************************************/
HarryPotter::HarryPotter() : Creature(armor, strengthPoints, "Harry Potter")
{
	armor = 0;
	strengthPoints = 10;
}


/****************************************************************************************************
**							Rolls attack dice and returns the value
****************************************************************************************************/
int HarryPotter::attack()
{
	// Two random numbers between 1 and 6 are added together and returned
	int attackRoll1 = rand() % 6 + 1;
	int attackRoll2 = rand() % 6 + 1;
	int attackRoll = (attackRoll1 + attackRoll2);

	cout << "attacks for " << (attackRoll) << " points" << endl;;
	return (attackRoll);
}


/****************************************************************************************************
**	Rolls defend dice and subtracts attack from total defense, uses remaining attack to determine
**								remaining strength points
****************************************************************************************************/
void HarryPotter::defend(int attack)
{
	// Rolls defense dice. 2 random numbers between 1 and 6
	int roll1 = rand() % 6 + 1;
	int roll2 = rand() % 6 + 1;
	int roll = roll1 + roll2;

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

	// Calls hogwarts function when strength points goes below 1
	if (strengthPoints < 1)
	{
		if (hogwarts == false)
		{
			Hogwarts();
		}
	}
}


/****************************************************************************************************
**			Resets Harry's strength points to 20. Will only be called once
****************************************************************************************************/
void HarryPotter::Hogwarts()
{
	cout << "Harry Potter has been restored to life!" << endl;
	strengthPoints = 20;
	// Return of true ensures this function is only called once.
	hogwarts = true;
}