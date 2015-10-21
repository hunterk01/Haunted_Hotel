#include <iostream>
#include "TimeKeeper.h"

Time doomClock = { 9, 26 };

void TimeIncrease(int timeChange)
{
	doomClock.minute += timeChange;
	if (doomClock.minute >= 60)
	{
		doomClock.hour += 1;
		doomClock.minute = doomClock.minute % 60;
	}
}

void PrintTime()
{
	std::cout << "The time is " << doomClock.hour << ":";
	if (doomClock.minute <= 9)
	{
		std::cout << "0" << doomClock.minute;
	}
	else
	{
		std::cout << doomClock.minute;
	}
	std::cout << " pm.";
}

bool timeCheck()
{
	if (doomClock.hour >= 12) return true;
	else return false;
}