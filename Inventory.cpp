#include <iostream>
#include <cstring>
#include <string>
#include "Inventory.h"
#include "GameLoop.h"

int itemCount = 0;
std::string playerItems[10];


// Add an item to the itemList char array and increase the item cout
void AddToInventory(std::string itemToAdd)
{
	playerItems[itemCount] = itemToAdd;
	itemCount++;
}

// Remove an item to the itemList char array and decrease the item cout
void RemoveFromInventory(std::string itemToRemove)
{
	for (int i = 0; i < itemCount; ++i)
	{
		if (itemToRemove == playerItems[i])
		{
			while(i < itemCount -1)
			{
				playerItems[i] = playerItems[i + 1];
				i++;
			}
			playerItems[i] = '\0';
			break;
		}
	}
	itemCount--;
}

// Check the itemList for a specific item and return the result
bool HasItemCheck(std::string itemToCheck)
{
	bool returnCondition = false;

	for (int i = 0; i < itemCount; ++i)
	{
		if (playerItems[itemCount] == itemToCheck)		returnCondition = true;
	}
	return returnCondition;
}

// Provides a list of usable items from player inventory and returns the one
// that the player chooses.
std::string UseItem()
{
	char choice[32] = "0";
	int itemChoice = 0;
	std::cout << std::endl;
	
	if (itemCount == 0)
	{
		return "0";
	}
	else
	{
		std::cout << "Which item would you like to use?" << std::endl;

		for (int i = 0; i < itemCount; ++i)
		{
			std::cout << i + 1 << " - " << playerItems[i] << std::endl;
		}
		std::cout << std::endl << "Your choice: ";

		while (choice[0] == '0')
		{
			std::cin >> choice;

			if (isdigit(choice[0]))
			{
				itemChoice = choice[0] - 48;

				if (itemChoice > itemCount)
				{
					std::cout << "Invalid.  Choose again: ";
					choice[0] = '0';
				}
				else if (10 > itemChoice && itemChoice > 0)
				{
					return (playerItems[itemChoice - 1]);
				}
				else
				{
					choice[0] = '0';
					system("CLS");
				}
			}
			else
			{
				std::cout << "Invalid.  Choose again: ";
				choice[0] = '0';
			}
		}
	}
	return "0";
}

// Print a list of the items currently in the itemList char array
void PrintInventory()
{
	bool done = false;
	char choice[32];
	int itemChoice = 0;

	system("CLS");
	
	while (!done)
	{
		choice[0] = 'x';

		std::cout << "===============" << std::endl
			<< "   Inventory" << std::endl
			<< "===============" << std::endl;
		if (itemCount == 0)
		{
			std::cout << "Empty" << std::endl << std::endl;
			system("pause");
			system("CLS");
			return;
		}
		else
		{
			for (int i = 0; i < itemCount; ++i)
			{
				std::cout << i + 1 << " - " << playerItems[i] << std::endl;
			}
			std::cout << std::endl << "Choose a number to examine and item, or press 0 to exit: ";
		}
		while (choice[0] == 'x')
		{

			std::cin >> choice;

			if (isdigit(choice[0]))
			{
				itemChoice = choice[0] - 48;

				if (itemChoice > itemCount + 1)
				{
					choice[0] = 'x';
				}
				else if (itemCount >= itemChoice && itemChoice >= 1)
				{
					ExamineHandler(playerItems[itemChoice - 1]);
					system("CLS");
				}
				else if (itemChoice == 0)
				{
					system("CLS");
					done = true;
				}
				else
				{
					choice[0] = 'x';
					system("CLS");
				}
			}
			else
			{
				std::cout << "Invalid.  Choose again: ";
				choice[0] = 'x';
			}
		}
	}
}

