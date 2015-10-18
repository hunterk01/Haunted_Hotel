#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <Windows.h>
#include <mmsystem.h>
#include "Menu.h"
#include "GameLoop.h"

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

	PlaySound(TEXT("HouseOnTheHill.wav"), NULL, SND_LOOP | SND_ASYNC);
	TitleScreen();
	system("pause");

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
				std::string line_;
				std::ifstream file_("Instructions.txt");
				if (file_.is_open())
				{
					while (std::getline(file_, line_))
					{
						std::cout << line_ << "\n";
					}
					file_.close();
					system("pause");
				}
				menuChoice[0] = '0';
				system("CLS");
			}
			else if (menuChoice[0] == '2')
			{
				system("CLS");
				PlaySound(NULL, 0, SND_ASYNC);
				PlaySound(TEXT("HarbingerOfDoom.wav"), NULL, SND_LOOP | SND_ASYNC);
				GameProcessor();
				PlaySound(NULL, 0, SND_ASYNC);
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



