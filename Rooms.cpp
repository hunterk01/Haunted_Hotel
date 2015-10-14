#include <iostream>
#include <string>
#include <fstream>
#include "Rooms.h"


void Room::GetRoomExits()
{

}

char Room::CheckRoomObject()
{
	return '\0';
}

void Room::RemoveRoomObject()
{

}

void SetCurrentRoom(int inState)
{

}

void PrintRoom()
{
	system("CLS");
	std::string line_;
	std::ifstream file_("RoomDescriptions.txt");
	if (file_.is_open())
	{
		while (std::getline(file_, line_))
		{
			if (line_ == "<LongDesc:Test>")
			{
				while (std::getline(file_, line_))
				{
					if (line_ != "<End>")
					{
						std::cout << line_ << "\n";
					}
					else break;
				}
			}
		}
		file_.close();
		system("pause");
	}
}