#include "card.h"
#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>

using namespace std;
card::card() {
	int r = rand() % (10);
	position = r;
}
int card::maxLength() {
	int max = 0;
	for (int i = 0; i < 10; i++) {
		if (values[i].length() > max) {
			max = values[i].length();
		}
	}
	return max;
}
string card::getValue() {
	return values[position];
}
void card::printCard() {
	int length = maxLength();
	cout << "| " << left << setw(length) << values[position] << " |";
}