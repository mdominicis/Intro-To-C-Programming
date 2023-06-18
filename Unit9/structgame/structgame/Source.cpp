#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <vector>


using namespace std;

struct player
{
	string firstName;
	int age;
	int points = 0;
};
struct  game
{
	player playerFirst;
	player playerSecond;
	string gameName;
	int dieSides;
	vector<int> rolls;
};

game createGame(string name, int sides, player p1, player p2);

void takeTurn(game& g, int pNum);

player getWinner(game g);


int main()
{
	srand(time(0));
	player p1 = { "Bob",22 };
	player p2 = { "Carol",43 };
	game games[4];
	for (int i = 0; i < 4; i++) {
		games[i].gameName = "Fun Game";
		games[i].dieSides = rand() % 15 + 6;
		games[i].playerFirst = p1;
		games[i].playerSecond = p2;
	}
	for (int i = 0; i < 4; i++) {
		while (games[i].playerFirst.points < 5 && games[i].playerSecond.points < 5) {
			takeTurn(games[i], 1);
			takeTurn(games[i], 2);
		}
		cout << games[i].playerFirst.firstName << ": " << games[i].playerFirst.points << endl;
		cout << games[i].playerSecond.firstName << ": " << games[i].playerSecond.points << endl;
		cout << getWinner(games[i]).firstName << " wins!!!!!";
		int count = 0;
		for (int j = 0; j < games[i].rolls.size(); j++) {
			count += games[i].rolls[i];
		}
		cout << "The sum of rolls is:" << count << "!\n\n";
	}
	
	return 0;
}

game createGame(string name, int sides, player p1, player p2) {
	game g;
	g.gameName = name;
	g.dieSides = sides;
	if (p1.age > p2.age) {
		g.playerFirst = p1;
		g.playerSecond = p2;
	}
	else {
		g.playerFirst = p2;
		g.playerSecond = p1;
	}
	return g;
}

void takeTurn(game& g, int pNum) {
	if (pNum == 1) {
		cout << endl << g.playerFirst.firstName << " goes first!\n";
		int roll = rand() % g.dieSides + 1;
		cout << "Die roll: " << roll << endl;
		g.rolls.push_back(roll);
		if (roll % 2 == 0) {
			cout << g.playerFirst.firstName << " gets the point!\n";
			g.playerFirst.points++;
		}
		else {
			cout << g.playerSecond.firstName << " gets the point!\n";
			g.playerSecond.points++;
		}
	}
	else {
		cout << endl << g.playerSecond.firstName << " goes second!\n";
		int roll = rand() % g.dieSides + 1;
		if (roll % 2 == 0) {
			cout << g.playerFirst.firstName << " gets the point!\n";
			g.playerFirst.points++;
		}
		else {
			cout << g.playerSecond.firstName << " gets the point!\n";
			g.playerSecond.points++;
		}
		
	}
}

player getWinner(game g) {
	return((g.playerFirst.points >= g.playerSecond.points) ? g.playerFirst : g.playerSecond);
}