/***************************************************************************************************
** Author: Michael Johnson
** Date: 8/4/2017
** Description: Definitions of the menu class functions
***************************************************************************************************/

#include "Menu.h"


/****************************************************************************************************
**                                         displayMenu
**                       Displays the menu of game options on the screen.
**                        I pulled this function idea from the textbook.
****************************************************************************************************/
void Menu::displayMenu()
{
	cout << "\tFantasy Battle Time!" << endl;
	cout << "1: Play Game" << endl;
	cout << "2: Exit" << endl;
	cout << endl;
}


/****************************************************************************************************
**                                          setChoice
**                              Sets the menu choice from the user
****************************************************************************************************/
void Menu::setChoice()
{
	do
	{
		cout << "Choose an option: " << endl;
		choice = inputVal1.isPosInteger();
	} while (choice > 2 || choice < 1);
}


/****************************************************************************************************
**                                          getChoice
**                       Gets the menu choice from the user and returns it
****************************************************************************************************/
int Menu::getChoice()
{
	return choice;
}