#include "car.h"
#include <string>
#include <iostream>
using namespace std;
car::car() {
	driver = "Ethan";
	width = 20;
	isHand = false;
	hasSpot = false;
}
car::car(string d, int w, bool h) {
	driver = d;
	width = w;
	isHand = h;
}
string car::getDriver() {
	return driver;
}
int car::getWidth() {
	return width;
}
bool car::getHand() {
	return isHand;
}
bool car::getSpot() {
	return hasSpot;
}
void car::setSpot(bool s) {
	hasSpot = s;
}
void car::print(){
	cout << "Driver: " << driver << "\nWidth:" << width << "\nHandicapped? " << (isHand ? "yes" : "no") << "\nParking spot? " << (hasSpot ? "yes" : "no") << endl << endl;
}