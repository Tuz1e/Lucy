#include "Dimension.h"

//TODO: Crashes when out of dimensional gates

Dimension::Dimension()
{
	myEmptyRoom = false;
	myCurrentRoom = 0;
	myDoorLimit = 15;
	myDimensionLimit = 25;
	myDimensionLow = 3;
}


Dimension::~Dimension()
{
}

void Dimension::Run()
{
	Generate();
	int tempCount = 0;
	while (1) 
	{
		Empty();

		//DebugValues-start
		Print
		(
			"Dimension Size: " + std::to_string(myDimensionSize) + "\n"
			"Dimension Location: " + std::to_string(myCurrentRoom) + "\n"
			"Door Amount: " + std::to_string(myDoorAmount[myCurrentRoom]) + "\n"
			"Correct Door: " + std::to_string(myCorrectDoor[myCurrentRoom]) + "\n"
			, 14
		);
		//DebugValuesend

		if (!myEmptyRoom) 
		{
			Print("Which door would you like to go through?\n", 13);
			if (myCurrentRoom > 0)
			{
				Print("[0] Back");
			}
			for (size_t i = 0; i < myDoorAmount[myCurrentRoom]; i++)
			{
				tempCount++;
				PrintCon("[" + std::to_string(tempCount), myDoorColour[myCurrentRoom][i]);
				Print("] " + myRooms[myCurrentRoom][i], myDoorColour[myCurrentRoom][i]);
			}
			tempCount = 0;
		}
		else 
		{
			Print("This room is empty.", 13);
			Print("[0] Back");
		}

		std::getline(std::cin, myChoToConvert);

		Next(Convert(myChoToConvert));
	}
}

void Dimension::Generate()
{
	int tempSize;
	myDimensionSize = (int)Randomize(3, 25);
	for (size_t x = 0; x < myDimensionSize; x++)
	{
		myRoomSize = Randomize(myDimensionLow, myDoorLimit);
		myCorrectDoor[x] = Randomize(1, myRoomSize);
		myDoorAmount[x] = myRoomSize;
		for (size_t y = 0; y < myRoomSize; y++)
		{
			tempSize = (int)Randomize(0, 14);
			myRooms[x][y] = myDoorTypes[tempSize] + " Door";
			myDoorColour[x][y] = (int)Randomize(1, 15);
		}
	}
}

void Dimension::Next(const int &aChoice)
{
	if (aChoice == myCorrectDoor[myCurrentRoom] && !myEmptyRoom) 
	{
		myCurrentRoom += 1;
	}
	else if (aChoice == 0 && myCurrentRoom != 0)
	{
		if (!myEmptyRoom) 
		{
			myCurrentRoom -= 1;
		}
		else
		{
			myEmptyRoom = false;
		}
	}
	else if (myCurrentRoom != 0 && aChoice <= myDoorAmount[myCurrentRoom] && aChoice > 0)
	{
		myEmptyRoom = true;
	}
}