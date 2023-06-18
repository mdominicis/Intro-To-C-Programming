


#include "car.h"
#include "parkingSpot.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void printLot(parkingSpot[4][6]);
int main()
{
	srand(time(0));

	//parkingSpot park; //create single parking spot
	//park.printSpot(); //prints a single parking spot

	parkingSpot p[4][6];

	printLot(p);
	car c1("Randy", 7, true);
	car c2("Bob", 20, false);
	car c3("Maria", 12, false);
	car c4("Bill", 9, false);
	car c5("Olivia", 10, true);

	car c[5] = { c1,c2,c3,c4,c5 };

	//check for parking spaces for each driver
	for (int i = 0; i < 4; i++) //rows of parking lot
	{
		for (int j = 0; j < 6; j++) //columns of parking lot
		{
			for (int k = 0; k < 5; k++) //loop through cars
			{
				if (!p[i][j].getOccupied() && !c[k].getSpot()) //if spot is not occupied and the car doesn't already have a spot
				{
					if (c[k].getHand() == p[i][j].getHand() && c[k].getWidth() <= p[i][j].getWidth()) //if handicapped status of driver matches handicap status of spot and the car will fit in the spot
					{
						p[i][j].setOccupied(true); //spot is now occupied
						cout << c[k].getDriver() << " (car width: " << c[k].getWidth() << ") found a spot in row " << (i + 1) << " in spot " << (j + 1) << ".\n"; //print out driver name, width of car, and spot number
						c[k].setSpot(true); //the car now has a spot
					}
				}
			}
		}
	}
	//print out cars that didn't get a spot
	for (int i = 0; i < 5; i++)
	{
		if (!c[i].getSpot())
			cout << c[i].getDriver() << " (car width: " << c[i].getWidth() << ") did not find a spot.\n";
	}

	printLot(p);

}
void printLot(parkingSpot p[4][6])
{
	cout << "\n\nThe Parking Lot:\n\n";
	//print lot, set first column to handicapped
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (j == 0) //if first column
				p[i][j].setHand(true);
			p[i][j].printSpot();
		}
		cout << endl << endl << endl;
	}
}


