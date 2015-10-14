#pragma once



class Room
{
public:
	char STATE[32], roomName[64], longDecription[3200], shortDescription[1600];
	bool visited;
	
	void GetRoomExits();
	char CheckRoomObject();
	void RemoveRoomObject();
};

void SetCurrentRoom(int inState);
void PrintRoom();

/*
Room FrontDoor = {
	"Front Door", 
	"Long Description", 
	"Short Description", 
	false
};

Room Lobby = {
	"Lobby",
	"You're in the lobby, plus some other text",
	"It's the lobby",
	false
};
*/
