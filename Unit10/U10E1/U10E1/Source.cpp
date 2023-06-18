#include "die.h"
#include <string>
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;
void prob(int x);
void print(int x, int arr[]);
int main() {
	cout << "Dice Rolling Program"<<endl;
	int rolls = 0;
	cout << "How many rolls of the die? ";
	cin >> rolls;
	prob(rolls);
	return 0;
}
void prob(int x) {
	die d1;
	die d2;
	int arr[11] = { 0 };
	for (int i = 0; i < x; i++) {
		int sum = 0;
		d1.rollDie();
		d2.rollDie();
		sum = d1.getValue() + d2.getValue();
		arr[sum-2]++;
	}
	print(x,arr);
}
void print(int x, int arr[]) {
	cout << setfill(' ') << right << setw(20) << "Roll Value" << right<<setw(20) << "Times Rolled" << right<<setw(20)<<"% Occurance"<<endl;
	cout << setfill('-') << setw(60) << "-"<<endl;
	for (int i = 2; i < 13; i++) {
		double percent = 1.0 * arr[i - 2] / x*100;
		cout << setfill(' ') << right << setw(20) << i<<right<<setw(20)<<arr[i-2]<<right<<setw(20)<<setprecision(2) << fixed << showpoint<<percent<<endl;
	}
}