#pragma once
#include <string>
#ifndef _DIE_H
#define _DIE_H
using namespace std;

class die {
private:
	int value;
public:
	die();
	int getValue();
	void rollDie();
};
#endif