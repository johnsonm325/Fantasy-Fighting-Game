/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the PlayGame class functions
***************************************************************************************************/

#include "PlayGame.h"

/****************************************************************************************************
**								Destructs the player objects
****************************************************************************************************/
PlayGame::~PlayGame()
{
	if (player1 != NULL)
	{
		delete player1;
		player1 = NULL;
	}
	if (player2 != NULL)
	{
		delete player2;
		player2 = NULL;
	}
}


/****************************************************************************************************
**							Secondary menu for players to choose characters
****************************************************************************************************/
void PlayGame::menu()
{
	cout << "1: Vampire" << endl;
	cout << "2: Barbarian" << endl;
	cout << "3: Blue Men" << endl;
	cout << "4: Medusa" << endl;
	cout << "5: Harry Potter" << endl;
	cout << "6: Exit to main menu" << endl;
	cout << endl;
}


/****************************************************************************************************
**								Set character choice for player 1
****************************************************************************************************/
void PlayGame::setChoiceP1()
{
	do
	{
		cout << "Choose your character:" << endl;
		p1Choice = inputVal1.isPosInteger();
	} while (p1Choice > 6 || p1Choice < 1);
	cout << endl;
}


/****************************************************************************************************
**								Set character choice for player 2
****************************************************************************************************/
void PlayGame::setChoiceP2()
{
	do
	{
		cout << "Choose computer's character:" << endl;
		p2Choice = inputVal1.isPosInteger();
	} while (p2Choice > 7 || p2Choice < 1);
	cout << endl;
}


/****************************************************************************************************
**							Starts game with selected characters
****************************************************************************************************/
void PlayGame::playGame()
{
	menu();
	setChoiceP1();
	// Nested if statements ensures that player can exit secondary menu at any time
	// when choosing a character
	if (p1Choice != 6)
	{
		setChoiceP2();
		if (p2Choice != 6)
		{
			setCharacters(p1Choice, p2Choice);
			fight();
		}
	}
}


/****************************************************************************************************
**						Allocates creature object based on player choices
****************************************************************************************************/
void PlayGame::setCharacters(int p1, int p2)
{
	if (p1 == 1)
	{
		player1 = new Vampire();
	}
	else if (p1 == 2)
	{
		player1 = new Barbarian();
	}
	else if (p1 == 3)
	{
		player1 = new BlueMen();
	}
	else if (p1 == 4)
	{
		player1 = new Medusa();
	}
	else if (p1 == 5)
	{
		player1 = new HarryPotter();
	}

	/***************************************/

	if (p2 == 1)
	{
		player2 = new Vampire();
	}
	else if (p2 == 2)
	{
		player2 = new Barbarian();
	}
	else if (p2 == 3)
	{
		player2 = new BlueMen();
	}
	else if (p2 == 4)
	{
		player2 = new Medusa();
	}
	else if (p2 == 5)
	{
		player2 = new HarryPotter();
	}
}


/****************************************************************************************************
**							Implements turned based fighting system
****************************************************************************************************/
void PlayGame::fight()
{
	// Randomly chooses which player will go first
	int playerTurn = rand() % 2 + 1;
	int roundNumber = 1;

	if (playerTurn == 1)
	{
		cout << "Player 1 goes first" << endl << endl;
		// Starts do/while loop that ends when one player's strength points goes below 1
		do
		{
			cout << "**********************************************" << endl;
			cout << "Round number: " << roundNumber << endl;
			cout << "**********************************************" << endl << endl;
			cout << "Player 1: " << endl;
			cout << player1->getType() << " ";
			// Player 1 attacks and stores in variable
			attack = player1->attack();
			cout << player2->getType() << " ";
			// Player 2 defends against attack
			player2->defend(attack);
			// Prints remaining strength points of player 2
			if (player2->getStrengthPoints() < 0)
			{
				cout << player2->getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << player2->getType() << " has " << player2->getStrengthPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			// Breaks to the end of the loop if strength is below 1
			if (player2->getStrengthPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Player 1 won" << endl << endl;
				break;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			cout << "Player 2: " << endl;
			cout << player2->getType() << " ";
			// Player 2 attacks and stores in variable
			attack = player2->attack();
			cout << player1->getType() << " ";
			// Player 1 defends against attack
			player1->defend(attack);
			// Prints remaining strength points of player 1
			if (player1->getStrengthPoints() < 0)
			{
				cout << player1->getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << player1->getType() << " has " << player1->getStrengthPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			// Breaks to the end of the loop if strength is below 1
			if (player1->getStrengthPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Player 2 won" << endl << endl;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			// Increments round number
			roundNumber++;
		} while (player1->getStrengthPoints() > 0 && player2->getStrengthPoints() > 0);
	}

	// Same as do/while loop above, but in reverse, allowing player 2 to go first
	if (playerTurn == 2)
	{
		cout << "Player 2 goes first" << endl << endl;
		do
		{
			cout << "**********************************************" << endl;
			cout << "Round number: " << roundNumber << endl;
			cout << "**********************************************" << endl << endl;
			cout << "Player 2: " << endl;
			cout << player2->getType() << " ";
			attack = player2->attack();
			cout << player1->getType() << " ";
			player1->defend(attack);
			if (player1->getStrengthPoints() < 0)
			{
				cout << player1->getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << player1->getType() << " has " << player1->getStrengthPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			if (player1->getStrengthPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Player 2 won" << endl << endl;
				break;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			cout << "Player 1: " << endl;
			cout << player1->getType() << " ";
			attack = player1->attack();
			cout << player2->getType() << " ";
			player2->defend(attack);
			if (player2->getStrengthPoints() < 0)
			{
				cout << player2->getType() << " has 0 strength points remaining" << endl;
			}
			else
			{
				cout << player2->getType() << " has " << player2->getStrengthPoints() << " strength points remaining" << endl;
			}
			cout << endl;

			if (player2->getStrengthPoints() < 1)
			{
				cout << "Game over" << endl;
				cout << "Player 1 won" << endl << endl;
			}
			else
			{
				cout << "Press a key to roll" << endl << endl;
				cin.get();
			}

			roundNumber++;
		} while (player1->getStrengthPoints() > 0 && player2->getStrengthPoints() > 0);
	}

	// Deletes player pointers
	if (player1 != NULL)
	{
		delete player1;
		player1 = NULL;
	}
	if (player2 != NULL)
	{
		delete player2;
		player2 = NULL;
	}
}