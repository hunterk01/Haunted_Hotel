#pragma once

class Room
{
	const char STATE[32];
	bool visited = false;
	char roomName[128], longDecription[3200], shortDescription[1600];
	
};

void SetCurrentRoom();
void GetRoomExits();
void GetRoomObjects();
void RemoveRoomObject();
void PrintRoom();


/*
Room Introduction;
Room Instructions;
Room FrontDoor;
Room Lobby;
Room FrontDesk;
Room ElevExtBsmt;
Room ElevExt1F;
Room ElevExt2F;
Room ElevExt3F;
Room ElevInterior;
Room DiningRoom;
Room Kitchen;
Room Ballroom;
Room GardenEntrance;
Room GardenPath;
Room Fountain;
Room MaintenanceShed;
Room RitualRoomDark;
Room RitualRoomLight;
Room BurialChamber;
Room Hallway2fWest;
Room Hallway2fEast;
Room Room237;
Room MaidCart;
Room Room304;
Room SodaMachine;
Room BoilerRoom;
Room ParkingLot;
Room AbandonnedTruck;
Room YourCar;
Room WinScreen;
Room LoseScreen;
*/