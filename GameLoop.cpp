#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include "GameLoop.h"
#include "Inventory.h"
#include "TimeKeeper.h"

// Process flow variables
bool gameOn = true, rangBell = false, tookPen = false, elevKeyUsed = false, hasMeat = false, rm237Open = false, hasCoin = false,
hasHandle = false, chainBroken = false, hasGas = false, candleLit = false, brickPressed = false, dogFed = false,
passageOpen = false, bodySearched = false, hasMatches = false, playedRecord = false, shedSearched = false,
coinClue = false, coinInPool = false;

std::string currentState = "INTRO";

// This section will handle all of the game flow
void GameProcessor()
{
	gameOn = true;

	while (gameOn)
	{
		if (!timeCheck())
		{
			if (currentState == "INTRO")			Intro();
			else if (currentState == "FDOOR")		FrontDoor();
			else if (currentState == "LOBBY")		Lobby();
			else if (currentState == "FDESK")		FrontDesk();
			else if (currentState == "GUESTBOOK")	Guestbook();
			else if (currentState == "SIGNBOOK")	Signbook();
			else if (currentState == "ELEV1X")		Elevator1fExt();
			else if (currentState == "ELEVSTART")	ElevatorStart();
			else if (currentState == "ELEV2X")		Elevator2fExt();
			else if (currentState == "ELEV3X")		Elevator3fExt();
			else if (currentState == "ELEVBX")		ElevatorBsmtExt();
			else if (currentState == "ELEVINT")		ElevatorInt();
			else if (currentState == "DINING")		DiningRoom();
			else if (currentState == "KITCHEN")		Kitchen();
			else if (currentState == "BALLROOM")	Ballroom();
			else if (currentState == "RECORD")		RecordPlayer();
			else if (currentState == "HALL2W")		Hallway2fWest();
			else if (currentState == "HALL2E")		Hallway2fEast();
			else if (currentState == "ROOM237")		Room237();
			else if (currentState == "HALL3W")		Hallway3fWest();
			else if (currentState == "HALL3E")		Hallway3fEast();
			else if (currentState == "ROOM305")		Room305();
			else if (currentState == "BOOKS")		BookDrop();
			else if (currentState == "BASEMENT")	Basement();
			else if (currentState == "CHAIN")		ChainBreak();
			else if (currentState == "GARDENENT")	GardenEntrance();
			else if (currentState == "GARDENPATH")	GardenPath();
			else if (currentState == "FOUNTAIN")	Fountain();
			else if (currentState == "SHED")		ShedExterior();
			else if (currentState == "SHEDINT")		ShedInterior();
			else if (currentState == "FEEDDOG")		FeedTheDog();
			else if (currentState == "SECRET")		SecretPassage();
			else if (currentState == "RITUALDIM")	DarkRoom();
			else if (currentState == "RITUALLIT")	LitRoom();
			else if (currentState == "RITUAL")		RitualRoom();
			else if (currentState == "BRICK")		BrickPress();
			else if (currentState == "BURIAL")		BurialChamber();
			else if (currentState == "PARKING")		ParkingLot();
			else if (currentState == "TRUCK")		AbandonnedTruck();
			else if (currentState == "CAR")			YourCar();
			else if (currentState == "WIN")
			{
				WinCondition();
				ResetGame();
				return;
			}
		}
		else
		{
			currentState = "LOSE";
			LoseCondition();
			ResetGame();
			return;
		}
	}
}

// Room class declaration
Room RM_Lobby = { false };
Room RM_FrontDesk = { false };
Room RM_Guestbook = { false };
Room RM_Elev1fExt = { false };
Room RM_ElevStart = { false };
Room RM_ElevInterior = { false };
Room RM_DiningRoom = { false };
Room RM_Kitchen = { false };
Room RM_Ballroom = { false };
Room RM_RecordPlayer = { false };
Room RM_Hallway2fEast = { false };
Room RM_Room237 = { false };
Room RM_Hallway3fWest = { false };
Room RM_Hallway3fEast = { false };
Room RM_Room305 = { false };
Room RM_GardenEntrance = { false };
Room RM_GardenPath = { false };
Room RM_Fountain = { false };
Room RM_ShedExterior = { false };
Room RM_FeedDog = { false };
Room RM_SecretPassage = { false };
Room RM_RitualDim = { false };
Room RM_RitualLit = { false };
Room RM_BurialChamber = { false };
Room RM_ParkingLot = { false };
Room RM_AbandonnedTruck = { false };
Room RM_YourCar = { false };
Room RM_LoseCondition = { false };

////// Intro and first floor rooms /////
void Intro()
{
	PrintRoom(currentState, 1);
	std::cout << std::endl;
	currentState = "FDOOR";
	TimeIncrease(2);
	system("pause");
}

void FrontDoor()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')
		{
			currentState = "LOBBY";
			TimeIncrease(1);
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Lobby()
{
	char choice[32] = "0";

	if (choice[0] = '0')
	{
		if (RM_Lobby.visited == false)
		{
			PrintRoom(currentState, 1);
			std::cout << "Press the D key anytime to bring up the game directions." << std::endl;
			RM_Lobby.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;
		
		if (choice[0] == '1')
		{
			currentState = "FDESK";
			TimeIncrease(1);
		}
		else if (choice[0] == '3')
		{
			currentState = "BALLROOM";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "DINING";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void FrontDesk()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_FrontDesk.visited == false)
		{
			if (rangBell == true)
			{
				currentState == "GUESTBOOK";
			}
			else
			{
				PrintRoom(currentState, 1);
			}
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;
		
		if (choice[0] == '2')
		{
			currentState = "LOBBY";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "ELEV1X";
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			if (RM_FrontDesk.visited == false)
			{
				currentState = "GUESTBOOK";
				TimeIncrease(1);
			}
			else
			{
				std::cout << std::endl << "You already rang the bell.  There's no need to do it again." << std::endl << std::endl;
			}
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the desk and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Guestbook()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_Guestbook.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_Guestbook.visited = true;
		}
		else
		{
			if (tookPen == true)
			{
				PrintRoom(currentState, 3);
			}
			else
			{
				PrintRoom(currentState, 2);
			}
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "LOBBY";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "ELEV1X";
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			if (HasItemCheck("PEN"))
			{
				std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
			else
			{
				AddToInventory("PEN");
				std::cout << std::endl << "You take the pen." << std::endl << std::endl;
				system("pause");
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				if (itemToUse == "PEN")
				{
					currentState = "SIGNBOOK";
					AddToInventory("ROOM237KEY");
					TimeIncrease(1);
				}
				else
				{
					std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
					system("pause");
					choice[0] = '0';
					TimeIncrease(1);
				}
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "You already rang the bell.  There's no need to do it again." << std::endl << std::endl;
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the desk and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Signbook()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		RM_FrontDesk.visited = true;
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "LOBBY";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "ELEV1X";
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
		else
		{
			choice[0] = '0';
			system("CLS");
		}
	}
}

void DiningRoom()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_DiningRoom.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_DiningRoom.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')
		{
			currentState = "KITCHEN";
			TimeIncrease(1);
		}
		else if (choice[0] == '3')
		{
			currentState = "LOBBY";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}

		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Kitchen()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_Kitchen.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_Kitchen.visited = true;
		}
		else
		{
			PrintRoom(currentState, 1);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "DINING";
		}
		else if (choice[0] == 's')
		{
			if (hasMeat == false)
			{
				TimeIncrease(5);
				SearchHandler("CABINET");
				AddToInventory("MEAT");
				hasMeat = true;
			}
			else
			{
				std::cout << "You have already searched this room." << std::endl;
				system("pause");
			}
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Ballroom()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (!playedRecord)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;
		
		if (choice[0] == '1')
		{
			if (!playedRecord)
			{
				choice[0] = '0';
			}
			else
			{
				currentState = "GARDENENT";
				TimeIncrease(1);
			}
		}
		else if (choice[0] == '4')
		{
			currentState = "LOBBY";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(3);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "HANDLE")
			{
				currentState = "RECORD";
				playedRecord = true;
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}

		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void RecordPlayer()
{
	PrintRoom(currentState, 1);
	RemoveFromInventory("HANDLE");
	currentState = "BALLROOM";
	TimeIncrease(5);
	system("pause");
}

///// Elevator exteriors and interior /////

void Elevator1fExt()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_Elev1fExt.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_Elev1fExt.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '3')
		{
			currentState = "FDESK";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'p')
		{
			currentState = "ELEVSTART";
			TimeIncrease(2);
		}

		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void ElevatorStart()
{
	if (RM_ElevStart.visited == false)
	{
		PrintRoom(currentState, 1);
		RM_ElevStart.visited = true;
	}
	else
	{
		PrintRoom(currentState, 2);
	}

	std::cout << std::endl;
	currentState = "ELEVINT";
	system("pause");
}

void Elevator2fExt()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '3')
		{
			currentState = "HALL2E";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "HALL2W";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'p')
		{
			currentState = "ELEVSTART";
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Elevator3fExt()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '3')
		{
			currentState = "HALL3E";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "HALL3W";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'p')
		{
			currentState = "ELEVSTART";
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void ElevatorBsmtExt()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		std::cout << std::endl << "What would you like to do? " << std::endl;
		std::cin >> choice;

		if (choice[0] == '3')
		{
			currentState = "BASEMENT";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'p')
		{
			currentState = "ELEVSTART";
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void ElevatorInt()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_ElevInterior.visited == false)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "There's nothing to search in here." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "SMALLKEY")
			{
				std::cout << std::endl << "You insert the key into the slot next to the B button and turn."
					<< std::endl << "It resists at first, but then gives way and clicks into place.\n\n";
				system("pause");
				RM_ElevInterior.visited = true;
				elevKeyUsed = true;
				TimeIncrease(1);
				system("CLS");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'p')
		{
			ElevatorControls();
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

///// Second floor locations /////

void Hallway2fWest()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '3')
		{
			currentState = "ELEV2X";
		}
		else if (choice[0] == 's')
		{
			if (!hasMatches)
			{
				SearchHandler("CART");
				AddToInventory("MATCHES");
				TimeIncrease(2);
				hasMatches = true;
			}
			else
			{
				std::cout << std::endl << "You have already searched this cart." << std::endl << std::endl;
				system("pause");
				system("CLS");
			}
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Hallway2fEast()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (!rm237Open)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;
		
		if (choice[0] == '1')
		{
			if (rm237Open == true)
			{
				currentState = "ROOM237";
				RM_Hallway2fEast.visited = true;
			}
			else
			{
				choice[0] = '0';
			}
		}
		else if (choice[0] == '4')
		{
			currentState = "ELEV2X";
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "There's nothing to search here." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "ROOM237KEY")
			{
				rm237Open = true;
				std::cout << std::endl << "You unlock the door." << std::endl << std::endl;
				system("pause");
				TimeIncrease(1);
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}

		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Room237()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_Room237.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_Room237.visited = true;
			TimeIncrease(2);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "HALL2E";
			TimeIncrease(1);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

///// Third floor locations /////

void Hallway3fWest()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (hasHandle == false)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')
		{
			if (!hasHandle)
			{
				currentState = "ROOM305";
				TimeIncrease(1);
			}
			else
			{
				choice[0] = '0';
			}
		}
		if (choice[0] == '3')
		{
			currentState = "ELEV3X";
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Hallway3fEast()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (!hasCoin)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '4')
		{
			currentState = "ELEV3X";
		}
		else if (choice[0] == 's')
		{
			if (hasCoin == false)
			{
				SearchHandler("VEND");
				AddToInventory("COIN");
				TimeIncrease(1);
				hasCoin = true;
			}
			else
			{
				std::cout << std::endl << "You have already searched this area." << std::endl << std::endl;
				system("pause");
			}
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Room305() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_Room305.visited == false)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "FDESK";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			currentState = "BOOKS";
			AddToInventory("HANDLE");
			hasHandle = true;
			TimeIncrease(1);
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void BookDrop()
{
	PrintRoom(currentState, 1);
	currentState = "HALL3W";
	TimeIncrease(3);
	system("pause");
}

///// Basement locations /////

void Basement()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (!chainBroken)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '3')
		{
			if (chainBroken == true)
			{
				currentState = "PARKING";
				TimeIncrease(1);
			}
			else
			{
				choice[0] = '0';
			}
		}
		else if (choice[0] == '4')
		{
			currentState = "ELEVBX";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "CROWBAR")
			{
				currentState = "CHAIN";
				TimeIncrease(3);
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void ChainBreak()
{
	PrintRoom(currentState, 1);
	chainBroken = true;
	currentState = "BASEMENT";
	TimeIncrease(3);
	std::cout << std::endl;
	system("pause");
}

///// Garden locations /////

void GardenEntrance()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_GardenEntrance.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_GardenEntrance.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '4')
		{
			currentState = "GARDENPATH";
		}
		else if (choice[0] == '2')
		{
			currentState = "BALLROOM";
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void GardenPath()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')
		{
			currentState = "FOUNTAIN";
		}
		else if (choice[0] == '3')
		{
			currentState = "GARDENENT";
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void Fountain()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (!passageOpen && !coinInPool)
		{
			PrintRoom(currentState, 1);
		}
		else if (coinInPool)
		{
			PrintRoom(currentState, 2);
		}
		else
		{
			PrintRoom(currentState, 3);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')
		{
			if (passageOpen)
			{
				if (!candleLit)
				{
					currentState = "RITUALDIM";
					TimeIncrease(1);
				}
				else
				{
					currentState = "RITUAL";
					TimeIncrease(1);
				}
			}
			else
			{
				choice[0] = '0';
			}
		}
		else if (choice[0] == '2')
		{
			currentState = "GARDENPATH";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "SHED";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			if (coinInPool)
			{
				std::cout << std::endl << "You take the coin out of the fountain pool." << std::endl << std::endl;
				AddToInventory("COIN");
				coinInPool = false;
				system("pause");
				choice[0] = '0';
			}
			else
			{
				std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "COIN")
			{
				if (!passageOpen)
				{
					currentState = "SECRET";
					RemoveFromInventory("COIN");
				}
				else
				{
					choice[0] = '0';
				}
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void ShedExterior()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (!dogFed)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;
		
		if (choice[0] == '1')
		{
			if (dogFed)
			{
				currentState = "SHEDINT";
				TimeIncrease(1);
			}
			else
			{
				choice[0] = '0';
			}
		}
		else if (choice[0] == '3')
		{
			currentState = "FOUNTAIN";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "MEAT")
			{
				if (!dogFed)
				{
					currentState = "FEEDDOG";
					RemoveFromInventory("MEAT");
					TimeIncrease(1);
				}
				else
				{
					choice[0] = '0';
				}
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void ShedInterior()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (!shedSearched)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;
		
		if (choice[0] == '2')
		{
			currentState = "SHED";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			if (!shedSearched)
			{
				SearchHandler("SHED");
				AddToInventory("CROWBAR");
				shedSearched = true;
				TimeIncrease(4);
				choice[0] = '0';
			}
			else
			{
				std::cout << "You have already searched this shed." << std::endl;
				choice[0] = '0';
			}
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void FeedTheDog()
{
	PrintRoom(currentState, 1);
	currentState = "SHED";
	dogFed = true;
	TimeIncrease(3);
	std::cout << std::endl;
	system("pause");
}

void SecretPassage()
{
	if (!coinClue)
	{
		PrintRoom(currentState, 1);
		TimeIncrease(3);
		coinInPool = true;
		std::cout << std::endl;
		system("pause");
	}
	else
	{
		PrintRoom(currentState, 2);
		passageOpen = true;
		TimeIncrease(3);
		std::cout << std::endl;
		system("pause");
	}
	
	currentState = "FOUNTAIN";
}

void DarkRoom()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_RitualDim.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_RitualDim.visited = true;
		}
		else
		{
			PrintRoom(currentState, 1);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "FOUNTAIN";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "The room is too dark to search." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "It's too dark to see if there's anything to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "MATCHES")
			{
				currentState = "RITUALLIT";
				TimeIncrease(1);
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "It's too dark to see if you can do that." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void LitRoom()
{
	if (!RM_RitualLit.visited)
	{
		PrintRoom(currentState, 1);
		RM_RitualLit.visited = true;
		std::cout << std::endl;
		system("pause");
	}
	else
	{
		PrintRoom(currentState, 2);
		currentState = "RITUAL";
		candleLit = true;
		TimeIncrease(5);
		std::cout << std::endl;
		system("pause");
	}
}

void RitualRoom()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (candleLit)
		{
			if (!brickPressed)
			{
				PrintRoom(currentState, 1);
			}
			else
			{
				PrintRoom(currentState, 2);
			}
		}
		else
		{
			currentState = "RITUALDIM";
			return;
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "FOUNTAIN";
			TimeIncrease(1);
		}
		else if (choice[0] == '3')
		{
			if (brickPressed)
			{
				currentState = "BURIAL";
				TimeIncrease(1);
			}
			else
			{
				choice[0] = '0';
			}
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			currentState = "BRICK";
			TimeIncrease(2);
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void BrickPress()
{
	PrintRoom(currentState, 1);
	TimeIncrease(2);
	currentState = "RITUAL";
	brickPressed = true;
	std::cout << std::endl;
	system("pause");
}

void BurialChamber() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_BurialChamber.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_BurialChamber.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;
		
		if (choice[0] == '4')
		{
			currentState = "RITUAL";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			if (!bodySearched)
			{
				SearchHandler("BODY");
				AddToInventory("SMALLKEY");
				bodySearched = true;
				TimeIncrease(2);
			}
			else
			{
				choice[0] = '0';
			}
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}


///// Parking lot locations and win/lose conditions /////

void ParkingLot()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_ParkingLot.visited == false)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')
		{
			currentState = "TRUCK";
			TimeIncrease(1);
		}
		else if (choice[0] == '2')
		{
			currentState = "CAR";
			TimeIncrease(1);
		}
		else if (choice[0] == '3')
		{
			currentState = "BASEMENT";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the room and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void AbandonnedTruck()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_AbandonnedTruck.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_AbandonnedTruck.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "PARKING";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			if (hasGas == false)
			{
				SearchHandler("TRUCK");
				AddToInventory("GAS");
				TimeIncrease(2);
			}
			else
			{
				std::cout << std::endl << "You have already searched this truck.";
				system("pause");
				choice[0] = '0';
			}
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void YourCar()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_YourCar.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_YourCar.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cout << std::endl << "What would you like to do? ";
		std::cin >> choice;

		if (choice[0] == '1')
		{
			currentState = "PARKING";
			TimeIncrease(1);
		}
		else if (choice[0] == 's')
		{
			std::cout << std::endl << "Your search the area and find nothing." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
			TimeIncrease(2);
		}
		else if (choice[0] == 't')
		{
			std::cout << std::endl << "There's nothing here to take." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'u')
		{
			std::string itemToUse = UseItem();
			if (itemToUse == "0")
			{
				std::cout << "You don't have any items to use." << std::endl << std::endl;
				system("Pause");
			}
			else if (itemToUse == "GAS")
			{
				currentState = "WIN";
			}
			else
			{
				std::cout << std::endl << "You can't use that item here." << std::endl << std::endl;
				system("pause");
				choice[0] = '0';
				TimeIncrease(1);
			}
		}
		else if (choice[0] == 'p')
		{
			std::cout << std::endl << "There's nothing here to press." << std::endl << std::endl;
			system("pause");
			choice[0] = '0';
		}
		else if (choice[0] == 'i')
		{
			PrintInventory();
		}
		else if (choice[0] == 'd')
		{
			ShowDirections();
		}
	}
	else
	{
		choice[0] = '0';
		system("CLS");
	}
}

void WinCondition() // Not done yet
{
	PrintRoom(currentState, 1);
	std::cout << std::endl;
	system("pause");
	
	gameOn = false;
}

void LoseCondition() // Not done yet
{
	if (RM_LoseCondition.visited == false)
	{
		PrintRoom(currentState, 1);
		RM_LoseCondition.visited = true;
	}
	else
	{
		PrintRoom(currentState, 2);
	}
	
	std::cout << std::endl;
	system("pause");

	gameOn = false;
}

// Get room descriptions from txt file and output them to console
void PrintRoom(std::string inState, int inDescNum)
{
	system("CLS");
	std::string line_;
	std::ifstream file_("RoomDescriptions.txt");

	PrintTime();
	std::cout << std::endl << std::endl;
	if (file_.is_open())
	{
		while (std::getline(file_, line_))
		{
			if (line_ == inState)
			{
				if (inDescNum == 1)
				{
					while (std::getline(file_, line_))
					{
						if (line_ == "<FirstDesc>")
						{
							while (std::getline(file_, line_))
							{
								if (line_ != "<End>")
								{
									std::cout << line_ << "\n";
								}
								else
								{
									file_.close();
									return;
								}
							}
						}
					}
				}
				else if (inDescNum == 2)
				{
					while (std::getline(file_, line_))
					{
						if (line_ == "<SecondDesc>")
						{
							while (std::getline(file_, line_))
							{
								if (line_ != "<End>")
								{
									std::cout << line_ << "\n";
								}
								else
								{
									file_.close();
									return;
								}
							}
						}
					}
				}
				else if (inDescNum == 3)
				{
					while (std::getline(file_, line_))
					{
						if (line_ == "<ThirdDesc>")
						{
							while (std::getline(file_, line_))
							{
								if (line_ != "<End>")
								{
									std::cout << line_ << "\n";
								}
								else
								{
									file_.close();
									return;
								}
							}
						}
					}
				}
			}
		}
	}
	file_.close();
	system("pause");
}

// Check for searchable object and process results
void SearchHandler(std::string inObject)
{
	system("CLS");
	std::string line_;
	std::ifstream file_("SearchDescriptions.txt");

	PrintTime();
	std::cout << std::endl << std::endl;
	if (file_.is_open())
	{
		while (std::getline(file_, line_))
		{
			if (line_ == inObject)
			{
				while (std::getline(file_, line_))
				{
					if (line_ != "<End>")
					{
						std::cout << line_ << "\n";
					}
					else
					{
						file_.close();
						std::cout << std::endl;
						system("pause");
						return;
					}
				}
			}
		}
	}
	file_.close();
	system("pause");
}

// Check for examinable object and process results
void ExamineHandler(std::string inItem)
{
	system("CLS");
	std::string line_;
	std::ifstream file_("ExamineDescriptions.txt");

	if (inItem == "COIN")	coinClue = true;

	PrintTime();
	std::cout << std::endl << std::endl;
	if (file_.is_open())
	{
		while (std::getline(file_, line_))
		{
			if (line_ == inItem)
			{
				while (std::getline(file_, line_))
				{
					if (line_ != "<End>")
					{
						std::cout << line_ << "\n";
					}
					else
					{
						file_.close();
						std::cout << std::endl;
						system("pause");
						return;
					}
				}
			}
		}
	}
	file_.close();
	system("pause");
}

// Function for controlling elevator button presses
void ElevatorControls()
{
	char buttonChoice[32] = "0";

	while (buttonChoice[0] == '0')
	{
		std::cout << std::endl << "Which button? ";
		std::cin >> buttonChoice;

		if (buttonChoice[0] == '1')
		{
			currentState = "ELEV1X";
			TimeIncrease(1);
		}
		else if (buttonChoice[0] == '2')
		{
			currentState = "ELEV2X";
			TimeIncrease(1);
		}
		else if (buttonChoice[0] == '3')
		{
			currentState = "ELEV3X";
			TimeIncrease(1);
		}
		else if (buttonChoice[0] == 'b')
		{
			if (elevKeyUsed == false)
			{
				std::cout << "That button won't work without a key." << std::endl << std::endl;
				system("pause");
				return;
			}
			else
			{
				currentState = "ELEVBX";
				TimeIncrease(1);
			}
		}
		else
		{
			buttonChoice[0] = '0';
		}
	}
}

// Show command options
void ShowDirections()
{
	system("CLS");

	std::cout << "Directions:" << std::endl << std::endl
		<< "Movement: \n1 - North \n2 - South \n3 - East \n4 - West" << std::endl << std::endl
		<< "Actions: \nS - Search \nT - Take \nU - Use \nP - Press \nI - Inventory \nD - Directions" << std::endl << std::endl;

	system("pause");
}

void ResetGame()
{
	// Reset game flow variables
	rangBell = false, tookPen = false, elevKeyUsed = false, hasMeat = false, rm237Open = false, hasCoin = false,
	hasHandle = false, chainBroken = false, hasGas = false, candleLit = false, brickPressed = false, dogFed = false,
	passageOpen = false, bodySearched = false, hasMatches = false, playedRecord = false, shedSearched = false, 
	coinClue = false, coinInPool = false;
	
	currentState = "INTRO";

	// Reset Room Classes
	RM_Lobby.visited = false;
	RM_FrontDesk.visited = false;
	RM_Guestbook.visited = false;
	RM_Elev1fExt.visited = false;
	RM_ElevStart.visited = false;
	RM_ElevInterior.visited = false;
	RM_DiningRoom.visited = false;
	RM_Kitchen.visited = false;
	RM_Ballroom.visited = false;
	RM_RecordPlayer.visited = false;
	RM_Hallway2fEast.visited = false;
	RM_Room237.visited = false;
	RM_Hallway3fWest.visited = false;
	RM_Hallway3fEast.visited = false;
	RM_Room305.visited = false;
	RM_GardenEntrance.visited = false;
	RM_GardenPath.visited = false;
	RM_Fountain.visited = false;
	RM_ShedExterior.visited = false;
	RM_FeedDog.visited = false;
	RM_SecretPassage.visited = false;
	RM_RitualDim.visited = false;
	RM_RitualLit.visited = false;
	RM_BurialChamber.visited = false;
	RM_ParkingLot.visited = false;
	RM_AbandonnedTruck.visited = false;
	RM_YourCar.visited = false;
	RM_LoseCondition.visited = false;
}