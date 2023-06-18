#include "card.h"
#include <iostream>
#include <time.h>
#include <string>
#include <iomanip>
#define _CRTDBG_MAP_ALLOC

using namespace std;
void printCard(bool x, card y);
void fillCard(string &x, card* y);
int main() {
	srand(time(NULL));
	string s;
	do {
		char r;
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		cout << "Can you match the secret card? Here are your cards: " << endl;
		string arr[5];
		card* secret = new card;
		for (int i = 0; i < 5; i++) {
			card* c = new card;
			fillCard(arr[i], c);
			delete c;
			c = NULL;
		}
		cout << endl << "Press enter to see the secret card!";
		cin.get(r);
		bool x = false;
		for (int i = 0; i < 5; i++) {
			if (secret->getValue() == arr[i]) {
				x = true;
			}
		}
		printCard(x, *secret);
		cout << endl << "Do you want to play again?(y/n)" << endl;
		cin >> s;
		delete secret;
		secret = NULL;
		if (s == "y") {
			system("cls");
			cin.ignore(80, '\n');
		}
	} while (s != "n");
}
void fillCard(string &x, card *y) {
	x = y->getValue();
	y->printCard();
}
void printCard(bool x, card y) {
	y.printCard();
	if (x) {
		cout << "You got a match. You win!";
	}
	else {
		cout << "You did not get a match. You lose!";
	}
}