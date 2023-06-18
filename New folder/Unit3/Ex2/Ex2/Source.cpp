#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;
int main() {
	srand(time(0));
	string name;
	string name2;
	string first;
	string last;
	cout << "Welcome to celebrity chef showdown" << endl << endl;
	cout << "Who is the first celebrity in our showdown? ";
	getline(cin, name);
	cout << "Who is the second celebrity in our showdown? ";
	getline(cin, name2);
	int num = rand() % 2;
	int heads = 0;
	int tails = 1;
	cout << "I will flip a coin. If heads, celebrities will compete in alphabetical order. If tails, celebrities will compete in reverse alphabetical order." << endl << endl;
	if (num == heads) {
		cout << "Heads! ";
		if (name < name2) {
			first = name;
			last = name2;
		}
		else {
			first = name2;
			last = name;
		}
	}
	else {
		cout << "Tails! ";
		if (name < name2) {
			first = name2;
			last = name;
		}
		else {
			first = name;
			last = name2;
		}
	}
	cout << first << " goes first!" << endl << endl;
	cout << first << " will be making gazpacho." << endl;
	int rating = rand() % 5 + 1;
	string plural = rating == 1 ? " star." : " stars.";
	cout << "The judges have given " << first << " " << rating << plural << endl;
	switch (rating) {
	case 1:
		cout << "This guy sucks!" << endl;
		break;
	case 2:
		cout << "Terrible at best." << endl;
		break;
	case 3:
		cout << "Meh." << endl;
		break;
	case 4:
		cout << "Pretty good!" << endl;
		break;
	case 5:
		cout << "Amazing!!" << endl;
		break;
	}
	cout << last << " will be making tortilla de patata." << endl;
	int rating2 = rand() % 5 + 1;
	string plural2 = rating2 == 1 ? " star." : " stars.";
	cout << "The judges have given " << last << " " << rating2 << plural2 << endl;
	switch (rating2) {
	case 1:
		cout << "Ewwwwww!" << endl;
		break;
	case 2:
		cout << "Not good in the slightest." << endl;
		break;
	case 3:
		cout << "It was palatable." << endl;
		break;
	case 4:
		cout << "The dish was enjoyable." << endl;
		break;
	case 5:
		cout << "Awesome job!" << endl;
		break;
	}
	if (rating > rating2) {
		cout << first + " wins!";
	}
	else if (rating<rating2) {
		cout << last + " wins!";
	}
	else {
	cout << "A rematch will occur in the next episode";
	}
}