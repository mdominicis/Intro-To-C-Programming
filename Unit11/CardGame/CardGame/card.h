#pragma once
#include <string>

using namespace std;

#ifndef _CARD_H
#define _CARD_H

class card
{
private:
	int position;
	string values[10] = {"cat","dog","fish","parrot","lizard","hamster","snake","frog","crab","gerbil"};
	int maxLength();
public:
	card();
	string getValue();
	void printCard();
};


#endif