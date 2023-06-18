#pragma once
#include <string>
#ifndef _CAR_H
#define _CAR_H
using namespace std;

class car {
private:
	string driver;
	int width;
	bool isHand;
	bool hasSpot;
public:
	car();
	car(string, int, bool);
	string getDriver();
	int getWidth();
	bool getHand();
	bool getSpot();
	void setSpot(bool);
	void print();
};
#endif