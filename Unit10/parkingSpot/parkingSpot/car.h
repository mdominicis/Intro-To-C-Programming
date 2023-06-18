#pragma once

#ifndef _CAR_H
#define _CAR_H

#include <string>
using namespace std;
class car
{
private:
	//member variables
	string driver; //driver's name
	int width; //width of car
	bool isHand; //true if driver is handicapped
	bool hasSpot; //true if driver has found a parking spot

public:
	//constructors

	car(string, int, bool); //sets member variables to first three parameters and hasSpot to false

	//getters 
	string getDriver();
	int getWidth();
	bool getHand();
	bool getSpot();

	//setter
	void setSpot(bool);






};



#endif
