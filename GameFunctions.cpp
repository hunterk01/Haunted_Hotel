#include <iostream>
#include <cstring>
#include "GameFunctions.h"
#include "Rooms.h"
#include "Inventory.h"
#include "PlayerInputFunctions.h"

void TitleScreen()
{
	// Display title screen
	std::cout << std::endl;
	std::cout << "  @@@  @@@   @@@@@@   @@@  @@@  @@@  @@@  @@@@@@@  @@@@@@@@  @@@@@@@" << std::endl;
	std::cout << "  @@@  @@@  @@@@@@@@  @@@  @@@  @@@@ @@@  @@@@@@@  @@@@@@@@  @@@@@@@@" << std::endl;
	std::cout << "  @@!  @@@  @@!  @@@  @@!  @@@  @@!@!@@@    @@!    @@!       @@!  @@@" << std::endl;
	std::cout << "  !@!  @!@  !@!  @!@  !@!  @!@  !@!!@!@!    !@!    !@!       !@!  @!@" << std::endl;
	std::cout << "  @!@!@!@!  @!@!@!@!  @!@  !@!  @!@ !!@!    @!!    @!!!:!    @!@  !@!" << std::endl;
	std::cout << "  !!!@!!!!  !!!@!!!!  !@!  !!!  !@!  !!!    !!!    !!!!!:    !@!  !!!" << std::endl;
	std::cout << "  !!:  !!!  !!:  !!!  !!:  !!!  !!:  !!!    !!:    !!:       !!:  !!!" << std::endl;
	std::cout << "  :!:  !:!  :!:  !:!  :!:  !:!  :!:  !:!    :!:    :!:       :!:  !:!" << std::endl;
	std::cout << "  ::   :::  ::   :::  ::::: ::  ::    ::     ::    :: ::::   :::: ::" << std::endl;
	std::cout << "   :   : :   :   : :   : :  :   ::    :      :     : :: ::   :: :  :" << std::endl << std::endl << std::endl;
	
	std::cout << "  @@@  @@@   @@@@@@   @@@@@@@  @@@@@@@@  @@@" << std::endl;
	std::cout << "  @@@  @@@  @@@@@@@@  @@@@@@@  @@@@@@@@  @@@" << std::endl;
	std::cout << "  @@!  @@@  @@!  @@@    @@!    @@!       @@!" << std::endl;
	std::cout << "  !@!  @!@  !@!  @!@    !@!    !@!       !@!" << std::endl;
	std::cout << "  @!@!@!@!  @!@  !@!    @!!    @!!!:!    @!!" << std::endl;
	std::cout << "  !!!@!!!!  !@!  !!!    !!!    !!!!!:    !!!" << std::endl;
	std::cout << "  !!:  !!!  !!:  !!!    !!:    !!:       !!:" << std::endl;
	std::cout << "  :!:  !:!  :!:  !:!    :!:    :!:       :!:" << std::endl;
	std::cout << "  ::   :::  ::::: ::     ::    :: ::::   :: ::::" << std::endl;
	std::cout << "   :   : :   : :  :      :     : :: ::   : :: ::" << std::endl << std::endl << std::endl;
	std::cout << "  ";
}

void Menu(bool &gameOver)
{
	char menuChoice[32] = "0";
	bool exitMenu = false;

	while (!exitMenu)
	{
		if (!(gameOver))
		{
			system("CLS");

			if (menuChoice[0] == '0')
			{
				std::cout << std::endl;
				std::cout << "  1 - Instructions" << std::endl;
				std::cout << "  2 - Start Game" << std::endl;
				std::cout << "  3 - Exit Game" << std::endl;
				std::cout << "  4 - Credits" << std::endl << std::endl;
				std::cout << "  Select an option: ";
				std::cin >> menuChoice;
			}
			else if (menuChoice[0] == '1')
			{
				system("CLS");
				std::cout << std::endl;
				std::cout << "  Instructions:" << std::endl << std::endl
					<< "  Haunted Hotel is a text adventure game where you play a traveler who" << std::endl
					<< "  has been trapped inside an abandonned hotel.  Using simple word commands" << std::endl
					<< "  you must figure out how to escape before the spirit that haunts the hotel" << std::endl
					<< "  takes your soul." << std::endl << std::endl
					<< "  To make things worse, there's a curse upon this hotel that makes those" << std::endl
					<< "  trapped inside weary.  If you don't escape by midnight, the curse will" << std::endl
					<< "  overtake you and send you into a deep sleep.  Once that happens, the spirit" << std::endl
					<< "  will have full access toyou and your soul will be lost forever." << std::endl << std::endl
					<< "  As you travel through the hotel, you will find many items that might help." << std::endl
					<< "  you  These will be put into your inventory, which you can view anytime by" << std::endl
					<< "  pressing the <F1> key.  All other actions will be controlled by using the" << std::endl
					<< "  commands listed below." << std::endl << std::endl << std::endl;

				std::cout << "  Commands:" << std::endl << std::endl
					<< "  North - This will move you through North facing exits" << std::endl
					<< "  South - This will move you through South facing exits" << std::endl
					<< "  East - This will move you through East facing exits" << std::endl
					<< "  West - This will move you through Up facing exits" << std::endl
					<< "  Up - This will move you through exits heading up" << std::endl
					<< "  Down - This will move you through exits heading down" << std::endl
					<< "  Take - This is used in combination with item names to pickup an item, such" << std::endl
					<< "         as 'Take Meathook'." << std::endl
					<< "  Use - This will be used in combination with item names to use an item, such" << std::endl
					<< "        as 'Use Meathook'.  It can also be used to interact with evironmental" << std::endl
					<< "        objects that can't be picked up." << std::endl
					<< "  Press - This is used in combination with objects that need to be pressed" << std::endl << std::endl
					<< "  That's all the commands there are.  A simple set of commands to guide you" << std::endl
					<< "  on your way.  If you need to view the command list on your adventure, press" << std::endl
					<< "  the <F2> key." << std::endl << std::endl
					<< "  ";

				menuChoice[0] = '0';
				system("pause");
				system("CLS");
			}
			else if (menuChoice[0] == '2')
			{
				exitMenu = true;
				system("CLS");
			}
			else if (menuChoice[0] == '3')
			{
				exitMenu = true;
				system("CLS");
				std::cout << "Thank you for playing!" << std::endl << std::endl;
				system("pause");
			}
			else if (menuChoice[0] == '4')
			{
				system("CLS");

				TitleScreen();
				std::cout << std::endl;
				std::cout << "  Story by Kevin Hunter" << std::endl << std::endl
					<< "  Game design and programming by Kevin Hunter" << std::endl << std::endl
					<< "  Ascii title posion font created at www.network-science.de/ascii/" << std::endl << std::endl
					<< "  Music from www.purple-planet.com" << std::endl
					<< "  Title screen and menu music: House on the Hill" << std::endl
					<< "  In game music: Harbinger of Doom" << std::endl << std::endl << std::endl
					<< "  ";
				
				menuChoice[0] = '0';
				system("pause");
				system("CLS");
			}
			else
			{
				menuChoice[0] = '0';
			}
			system("CLS");
		}
	}
}

void DisplayRoomInfo()
{

}

void CheckAdjacentRooms()
{

}

void ProcessCommands()
{

}



