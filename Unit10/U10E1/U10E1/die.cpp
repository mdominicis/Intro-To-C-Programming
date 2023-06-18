#include "die.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;
die::die() {
	value = 0;
	srand(time(0));
}
int die::getValue() {
	return value;
}
void die::rollDie() {
	value = rand() % (6) + 1;
}