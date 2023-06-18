#include "car.h"
#include <iostream>
#include <string>
using namespace std;
int main() {
	car c1;
	car c2("Jenny", 7, true);
	c2.setSpot(true);
	c1.print();
	c2.print();
	return 0;
}