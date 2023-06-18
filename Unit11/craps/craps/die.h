#pragma once

#ifndef _DIE_H
#define _DIE_H

class die
{
private:
	int value;
public:
	die(); //set value=0;
	int getValue(); //accessor for value
	void rollDie(); //sets value to random 1-6
	void printDie(); //prints pic of die, then sleeps for half a second
};


#endif