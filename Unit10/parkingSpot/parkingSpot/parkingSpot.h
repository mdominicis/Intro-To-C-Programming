#pragma once

#ifndef _PARKINGSPOT_H
#define _PARKINGSPOT_H

class parkingSpot
{
private:
	int width; //width of parkingSpot
	bool isOccupied; //true if spot is occupied
	bool isHand; //true if handicapped spot
public:
	parkingSpot(); //sets width to random number from 5-15, sets isOccupied to a random value, sets isHand to false
	int getWidth();
	bool getOccupied();
	bool getHand();
	void setHand(bool);
	void setOccupied(bool);
	void printSpot();
};
#endif