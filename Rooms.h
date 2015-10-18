#pragma once

class Room
{
public:
	char STATE[16];
	char item[32];
	char usable[32];
	char searchable[32];
	char pressable[32];
	char adjacentRooms[6][16];
	bool visited;
};
