
#include "parkingSpot.h"
#include <iostream>

using namespace std;

parkingSpot::parkingSpot()
{
	isOccupied = rand() % 2; //0 or 1 (false or true)
	width = rand() % 11 + 5; //random number from 5-15
	isHand = false;
}
int parkingSpot::getWidth()
{
	return width;
}
bool parkingSpot::getOccupied()
{
	return isOccupied;
}
bool parkingSpot::getHand()
{
	return isHand;
}
void parkingSpot::setHand(bool h)
{
	isHand = h;
}
void parkingSpot::setOccupied(bool occ)
{
	isOccupied = occ;
}
void parkingSpot::printSpot()
{
	char spot = 'O'; //set to an empty spot
	if (isHand)
		spot = '$'; //unoccupied handicapped spot
	if (isOccupied)
		spot = '#'; //occupied spot

	int half = width / 2;
	for (int i = 0; i < width; i++)
	{
		if (i == half)
			cout << spot;
		else
			cout << "-";
	}
	cout << "  |  ";
}