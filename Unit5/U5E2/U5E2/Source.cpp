#include <iostream>
#include <fstream>
using namespace std;
bool checkReceiver(double speed, int weight, int strength, int& total);
bool checkQuarterback(double speed, int weight, int strength, int& total);
bool checkGuard(double speed, int weight, int strength, int& total);
void select(int totalplayers, string position);
void select(int totalplayers);
int main() {
	int receiver = 0, quarterback = 0, guard = 0;
	ifstream fin;
	fin.open("football.txt");
	while (!fin.eof()) {
		string name,position;
		double speed;
		int weight, strength;
		fin >> name;
		fin >> speed;
		fin >> weight;
		fin >> strength;
		cout << name<<" ";
		bool r = checkReceiver(speed, weight, strength, receiver);
		bool q = checkQuarterback(speed, weight, strength, quarterback);
		bool g = checkGuard(speed, weight, strength, receiver);
		if (r) {
			cout<<"Wide Reciever ";
		}
		if (q) {
			cout<<"Quarterback ";
		}
		if (g) {
			cout<<"Guard";
		}
		if (!r&&!q&&!g) {
			cout<<"No positions";
		}
		cout << endl;
	}
	string input = "";
	cout << "Does your team need a receiver(y/n)";
	cin >> input;
	if (input == "y") {
		select(receiver, "wide receiver");
	}
	else {
		select(receiver);
	}
	cout << "Does your team need a quarterback(y/n)";
	cin >> input;
	if (input == "y") {
		select(quarterback, "quarterback");
	}
	else {
		select(quarterback);
	}
	cout << "Does your team need a guard(y/n)";
	cin >> input;
	if (input == "y") {
		select(guard, "guard");
	}
	else {
		select(guard);
	}
}
bool checkReceiver(double speed, int weight, int strength, int& total) {
	if (speed <= 4.5 && weight >= 150 && strength >= 200) {
		return ++total;
	}
	return false;
}
bool checkQuarterback(double speed, int weight, int strength, int& total) {
	if (speed <= 5.0 && weight >= 200 && strength >=300) {
		return ++total;
	}
	return false;
}
bool checkGuard(double speed, int weight, int strength, int& total) {
	if (speed <= 6.0 && weight >= 300 && strength >= 500) {
		return ++total;
	}
	return false;
}
void select(int totalplayers, string position) {
	cout << "There " << (totalplayers != 1 ? "are " : "is ") << totalplayers << " potential " << position << (totalplayers > 1 ? "s" : "") << endl;
}
void select(int totalplayers) {
	if (totalplayers == 0) {
		cout << "That's okay, because there aren't any available.";
	}
	else {
		cout << "There are some available if you change your mind.\n";
	}
}