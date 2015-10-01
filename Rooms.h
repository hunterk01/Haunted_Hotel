#pragma once

class Room
{
	const char STATE[32];
	bool visited = false;
	char longDecription[3200], shortDescription[1600], items[10][32];
	enum directions {north, south, east, west, up, down};
	
	void checkAdjacentRooms();

};
