#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
#include "GameLoop.h"
#include "Inventory.h"
#include "TimeKeeper.h"

// Process flow variables
bool rangBell = false, tookPen = false, elevKeyUsed = false;
std::string currentState = "INTRO";

// This section will handle all of the game flow
void GameProcessor()
{
	bool gameOn = true;

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
			else if (currentState == "KITCHEN")		Ktichen();
			else if (currentState == "BALLROOM")	Ballroom();
			else if (currentState == "RECORD")		RecordPlayer();
			else if (currentState == "HALL2W")		Hallway2fWest();
			else if (currentState == "HALL2E")		Hallway2fEast();
			else if (currentState == "ROOM237")		Room237();
			else if (currentState == "HALL2W")		Hallway2fWest();
			else if (currentState == "HALL2E")		Hallway2fEast();
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
			else if (currentState == "BURIAL")		BurialChamber();
			else if (currentState == "PARKING")		ParkingLot();
			else if (currentState == "TRUCK")		AbandonnedTruck();
			else if (currentState == "CAR")			YourCar();
			else if (currentState == "WIN")			WinCondition();
		}
		else
		{
			currentState = "LOSE";
			LoseCondition();
		}
	}
}

// Room class declaration
Room RM_Lobby = { false };
Room RM_FrontDesk = { false };
Room RM_Guestbook = { false };
Room RM_Elev1fExt = { false };
Room RM_ElevStart = { false };
Room RM_Elev2fExt = { false };
Room RM_Elev3fExt = { false };
Room RM_ElevBsmtExt = { false };
Room RM_ElevInterior = { false };
Room RM_DiningRoom = { false };
Room RM_Kitchen = { false };
Room RM_Ballroom = { false };
Room RM_RecordPlayer = { false };
Room RM_Hallway2fWest = { false };
Room RM_Hallway2fEast = { false };
Room RM_Room237 = { false };
Room RM_Hallway3fWest = { false };
Room RM_Hallway3fEast = { false };
Room RM_Room305 = { false };
Room RM_BooksFall = { false };
Room RM_Basement = { false };
Room RM_ChainBreak = { false };
Room RM_GardenEntrance = { false };
Room RM_GardenPath = { false };
Room RM_Fountain = { false };
Room RM_ShedExterior = { false };
Room RM_ShedInterior = { false };
Room RM_FeedDog = { false };
Room RM_SecretPassage = { false };
Room RM_RitualDim = { false };
Room RM_RitualLit = { false };
Room RM_RitualRoom = { false };
Room RM_BurialChamber = { false };
Room RM_ParkingLot = { false };
Room RM_AbandonnedTruck = { false };
Room RM_YourCar = { false };
Room RM_WinCondition = { false };
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
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')
		{
			currentState = "FDESK";
			TimeIncrease(1);
		}
		else if (choice[0] == '3')
		{
			currentState = "BALLROOOM";
			TimeIncrease(1);
		}
		else if (choice[0] == '4')
		{
			currentState = "DINING";
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
		PrintCommands();
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

void Guestbook() // Need to define the useItem() function, then test it here
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
		PrintCommands();
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
			AddToInventory("Pen");
			std::cout << std::endl << "You take the pen." << std::endl << std::endl;
			system("pause");
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
				if (itemToUse == "Pen")
				{
					currentState = "SIGNBOOK";
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
		AddToInventory("Room 237 Key");
		RM_FrontDesk.visited = true;
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
		std::cin >> choice;

		if (choice[0] == '2')
		{
			currentState = "DINING";
		}
		else if (choice[0] == 's')
		{
			SearchHandler("MEAT");
			AddToInventory("MEAT");
			TimeIncrease(5);
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
		if (RM_Ballroom.visited == false)
		{
			PrintRoom(currentState, 1);
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cin >> choice;
		
		if (choice[0] == '1')
		{
			if (RM_Ballroom.visited == false)
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
				currentState == "RECORD";
				RM_Ballroom.visited = true;
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
	currentState = "BALLROOM";
	TimeIncrease(5);
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

	currentState = "ELEVINT";
	system("pause");
}

void Elevator2fExt()
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		if (RM_Elev2fExt.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_Elev2fExt.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cin >> choice;

		if (choice[0] == '3')
		{
			currentState = "HALL2E";
			TimeIncrease(1);
		}
		else if (choice[0] == '3')
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
		if (RM_Elev3fExt.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_Elev3fExt.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
		std::cin >> choice;

		if (choice[0] == '3')
		{
			currentState = "HALL3E";
			TimeIncrease(1);
		}
		else if (choice[0] == '3')
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
		if (RM_ElevBsmtExt.visited == false)
		{
			PrintRoom(currentState, 1);
			RM_ElevBsmtExt.visited = true;
		}
		else
		{
			PrintRoom(currentState, 2);
		}
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

void ElevatorInt() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
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
			// Add item check and key usage
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

void Hallway2fWest() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void Hallway2fEast() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void Room237() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void Hallway3fWest() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void Hallway3fEast() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void BookDrop() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

///// Basement locations /////

void Basement() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void ChainBreak() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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


///// Garden locations /////

void GardenEntrance() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void GardenPath() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void Fountain() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void ShedExterior() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void ShedInterior() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void FeedTheDog() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void SecretPassage() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void DarkRoom() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void LitRoom() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void RitualRoom() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void BurialChamber() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void ParkingLot() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void AbandonnedTruck() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void YourCar() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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

void LoseCondition() // Not done yet
{
	char choice[32] = "0";
	if (choice[0] = '0')
	{
		PrintRoom(currentState, 1);
		PrintCommands();
		std::cin >> choice;
		if (choice[0] == '1')  currentState = "FDESK";
		else if (choice[0] == 's')
		{

		}
		else if (choice[0] == 't')
		{

		}
		else if (choice[0] == 'u')
		{

		}
		else if (choice[0] == 'p')
		{

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
								else return;
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
								else return;
							}
						}
					}
				}
				else if (inDescNum == 3)
				{
					std::getline(file_, line_);
					if (line_ == "<ThirdDesc>")
					{
						while (std::getline(file_, line_))
						{
							if (line_ != "<End>")
							{
								std::cout << line_ << "\n";
							}
							else return;
						}
					}
				}
			}
		}
		file_.close();
		system("pause");
	}
}

void PrintCommands()
{
	std::cout << "Commands: <T>ake, <U>se, <S>earch, <I>nventory, <P>ress" << std::endl << std::endl;
	std::cout << "What would you like to do? ";
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

	}
}

// Check for examinable object and process results
void ExamineHandler(std::string inItem)
{
	system("CLS");
	std::string line_;
	std::ifstream file_("ExamineDescriptions.txt");

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
					else return;
				}
			}
		}
	}
}

void ElevatorControls()
{
	char buttonChoice[32] = "0";

	std::cout << std::endl << "Which button? ";
	std::cin >> buttonChoice[32];

	while (buttonChoice[0] == '0')
	{
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
				std::cout << "That button won't work without a key." << std::endl
					<< "Which button? ";
				std::cin >> buttonChoice[32];
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