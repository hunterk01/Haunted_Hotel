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
			playerItems[i][32] = '\0';
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
	int itemChoice = 0;
	std::cout << std::endl;
	
	if (itemCount == 0)
	{
		return 0;
	}
	else
	{
		while (itemChoice == 0)
		{
			std::cout << "Which item would you like to use?" << std::endl;

			for (int i = 0; i < itemCount; ++i)
			{
				std::cout << i + 1 << " - " << playerItems[itemCount] << std::endl;
				return "0";
			}
			std::cout << "Your choice: ";
			std::cin >> itemChoice;

			if (itemChoice > itemCount + 1)
			{
				itemChoice = 0;
			}
			else if (10 > isdigit(itemChoice) && isdigit(itemChoice) > 0)
			{
				return (playerItems[itemChoice - 1]);
			}
			else
			{
				itemChoice = 0;
				system("CLS");
			}
		}
	}
}

// Print a list of the items currently in the itemList char array
void PrintInventory()
{
	bool done = false;
	int itemChoice = -1;

	system("CLS");
	
	while (!done)
	{
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
		else if (itemChoice == -1)
		{
			for (int i = 0; i < itemCount; ++i)
			{
				std::cout << i + 1 << " - " << playerItems[itemCount - 1] << std::endl;
			}
			std::cout << std::endl << "Choose a number to examine and item, or press 0 to exit: ";
			std::cin >> itemChoice;
				if (itemChoice > itemCount + 1)
			{
				itemChoice = -1;
			}
			else if (10 > isdigit(itemChoice) && isdigit(itemChoice) > 0)
			{
				ExamineHandler(playerItems[itemChoice - 1]);
			}
			else if (itemChoice == 0)
			{
				system("CLS");
				done = true;
			}
			else
			{
				itemChoice = -1;
				system("CLS");
			}
		}
	}
}