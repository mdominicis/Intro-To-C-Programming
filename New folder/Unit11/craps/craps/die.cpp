
#include "die.h"
#include <iostream>


using namespace std;

die::die()
{
	value = 0;
}
int die::getValue()
{
	return value;
}
void die::rollDie()
{
	value = rand() % 6 + 1;
}

void die::printDie()
{
	cout << "\n-------\n";
	switch (value)
	{
	case 1:
		cout << "|     |\n"
			<< "|  o  |\n"
			<< "|     |\n";
		break;
	case 2:
		cout << "|o    |\n"
			<< "|     |\n"
			<< "|    o|\n";
		break;
	case 3:
		cout << "|o    |\n"
			<< "|  o  |\n"
			<< "|    o|\n";
		break;
	case 4:
		cout << "|o   o|\n"
			<< "|     |\n"
			<< "|o   o|\n";
		break;
	case 5:
		cout << "|o   o|\n"
			<< "|  o  |\n"
			<< "|o   o|\n";
		break;
	case 6:
		cout << "|o   o|\n"
			<< "|o   o|\n"
			<< "|o   o|\n";
		break;
	}
	cout << "-------\n\n";



}


