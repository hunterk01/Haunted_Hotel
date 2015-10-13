#include <iostream>
#include "Rooms.h"
#include "Menu.h"
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <mmsystem.h>

int main()
{
	bool gameOver = false;

	// Set console to larger size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);
	
	// Setup title screen and music
	PlaySound(TEXT("HouseOnTheHill.wav"), NULL, SND_LOOP | SND_ASYNC);
	TitleScreen();
	system("pause");
		
	Menu(gameOver);
	PlaySound(NULL, 0, SND_ASYNC);
	
	PlaySound(TEXT("HarbingerOfDoom.wav"), NULL, SND_LOOP | SND_ASYNC);
	system("pause");
	PlaySound(NULL, 0, SND_ASYNC);
	return 0;
}