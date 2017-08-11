/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Main function
***************************************************************************************************/

#include "PlayGame.h"

int main()
{
	Menu menu1;
	InputValid inputVal2;
	PlayGame game;
	
	// Random number seed
	srand(size_t(time(NULL)));

	do
	{
		menu1.displayMenu();
		menu1.setChoice();

		if (menu1.getChoice() == 1)
		{
			game.playGame();
		}
	} while (menu1.getChoice() != 2);

	cout << "... Shutting down game ..." << endl;

	cin.get();
	return 0;
}