#include <iostream>
#include <cstring>
#include "Inventory.h"

int itemCount = 0;
char itemList[10][32];

// Add an item to the itemList char array and increase the item cout
void AddToInventory(char itemToAdd)
{
	itemList[itemCount][32] = itemToAdd;
	itemCount++;
}

// Remove an item to the itemList char array and decrease the item cout
void RemoveFromInventory(char itemToRemove)
{
	itemList[itemCount][32] = NULL;
	itemCount--;
}

// Check the itemList for a specific item and return the result
bool HasItemCheck(char itemToCheck)
{
	bool returnCondition = false;

	for (int i = 0; i < itemCount; ++i)
	{
		if (itemList[itemCount][32] == itemToCheck)		returnCondition = true;
	}
	return returnCondition;
}

// Check if the item can be used in the current room and return the result
bool ValidItemUseCheck(char itemToCheck)
{
	// TODO
	return true;
}

// Print a list of the items currently in the itemList char array
void PrintInventory()
{
	system("CLS");

	std::cout << "===============" << std::endl
		<< "   Inventory" << std::endl
		<< "===============" << std::endl;

	for (int i = 0; i < itemCount; ++i)
	{
		std::cout << itemList[itemCount][32] << std::endl;
	}

	system("pause");
	system("CLS");
}