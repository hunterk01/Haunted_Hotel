#pragma once

class Room
{
public:
	bool visited;
};

// Main game loop function
void GameProcessor();

// Room functions
void Intro();
void FrontDoor();
void Lobby();
void FrontDesk();
void Guestbook();
void Signbook();
void Elevator1fExt();
void ElevatorStart();
void Elevator2fExt();
void Elevator3fExt();
void ElevatorBsmtExt();
void ElevatorInt();
void DiningRoom();
void Ktichen();
void Ballroom();
void RecordPlayer();
void Hallway2fWest();
void Hallway2fEast();
void Room237();
void Hallway2fWest();
void Hallway2fEast();
void Room305();
void BookDrop();
void Basement();
void ChainBreak();
void GardenEntrance();
void GardenPath();
void Fountain();
void ShedExterior();
void ShedInterior();
void FeedTheDog();
void SecretPassage();
void DarkRoom();
void LitRoom();
void RitualRoom();
void BurialChamber();
void ParkingLot();
void AbandonnedTruck();
void YourCar();
void WinCondition();
void LoseCondition();

// Information display functions
void PrintRoom(std::string inState, int inDescNum);
void PrintCommands();
void SearchHandler(std::string inObject);
void ExamineHandler(std::string inItem);
void ElevatorControls();
void ShowDirections();