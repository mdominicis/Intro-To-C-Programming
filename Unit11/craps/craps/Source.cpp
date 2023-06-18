#define _CRTDBG_MAP_ALLOC //to check for memory leaks
#include "die.h"
#include <crtdbg.h>  
#include <iostream>
#include <time.h>

using namespace std;


void rollDice(die*, die*); //roll two dice, takes 2 pointers to die objects
void rollDice(die&, die&); //roll two dice, take 2 die objects
int main()
{
	srand(time(0));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memory leaks after program is over
	/*
		First Roll--
		7 or 11 wins
		2,3,12 loses
		Anything else becomes the "point"

		Other Rolls--
		7 loses
		"point" wins
	*/

	char choice = 'y';
	while (choice == 'y' || choice == 'Y')
	{
		char r;
		cout << "Press enter to roll.";
		cin.get(r); //gets character, but doesn't use it, basically pauses program until key is pressed
		int point = 0; //holds the point
		die* d1 = new die;//allocates memory in the heap
		die* d2 = new die();//you can do the default constructor with or without ()

		//d1 and d2 are pointers, so this calls the version of rollDice
		//that takes two pointers
		rollDice(d1, d2);

		//Find sum of dice
		int sum = d1->getValue() + d2->getValue();


		if (sum == 2 || sum == 3 || sum == 12)
		{
			cout << "\n\nYou lose!\n\n";
		}
		else if (sum == 7 || sum == 11)
		{
			cout << "\n\nYou win!\n\n";
		}
		else
		{
			point = sum; //set the point to sum
			bool over = false; //determines if game is over
			while (!over)
			{
				cout << "\n\nRoll again!\n\n";
				cout << "You need to roll a " << point << " to win. If you roll a 7 you lose.\n";
				cout << "Press enter to roll.";
				cin.get(r);
				//*d1 and *d2 are not pointers, so this calls the version of rollDice
				//that takes two non-pointer dice
				rollDice(*d1, *d2);

				//Find sum of dice
				sum = d1->getValue() + d2->getValue();


				if (sum == point)
				{
					cout << "\n\nYou win!\n\n";
					over = true;
				}
				else if (sum == 7)
				{
					cout << "\n\nYou lose!\n\n";
					over = true;
				}
			}
		}
		cout << "Do you want to play again?(y/n) ";
		cin >> choice;
		system("cls"); //clear screen try clrscr() if using a different compiler
		cin.ignore(80, '\n');//need for pressing enter to work
		//if I don't deallocate here, the dice will be created at the beginning of the loop at a new location. The old locations will no longer be reachable.
		delete d1; //deallocate memory from heap
		delete d2;
		d1 = NULL; //good practice to set a pointer to NULL after using delete
		d2 = NULL;
	}


	return 0;
}
void rollDice(die* d1, die* d2)
{
	//Roll the dice
	d1->rollDie(); //these are pointers, so use ->
	d2->rollDie();

	//Print the dice
	d1->printDie();
	d2->printDie();
}
void rollDice(die& d1, die& d2)
{
	//Roll the dice
	d1.rollDie(); //these are not pointers, so use .
	d2.rollDie();

	//Print the dice
	d1.printDie();
	d2.printDie();
}