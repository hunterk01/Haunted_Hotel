#include <iostream>
#include "Menu.h"
#include "Rooms.h"
#define _WIN32_WINNT 0x0500
#include <Windows.h>

int main()
{
	// Set console to larger size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE);
	
	// Menu handles title screen, menu, and music
	// The game loop is called inside the menu
	Menu();
	
	return 0;
}