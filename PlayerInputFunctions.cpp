#include <iostream>
#include "PlayerInputFunctions.h"


void CommandProcessor(char inCommand)
{

}

// Directions (N, S, E, W, Up, Down)
void MovementHandler(char inDirection)
{

}

// Actions (Take, Press, Use, Examine)
void ActionsHandler(char inAction)
{

}

// Show command options
void ShowHelp()
{
	std::cout << "Command List:" << std::endl
		<< "Directions: North, South, East, West, Up, Down" << std::endl
		<< "Actions: Go, Take, Use, Examine, Press" << std::endl
		<< "Utility: Iventory, Help" << std::endl << std::endl
		<< "What would you like to do? ";
}