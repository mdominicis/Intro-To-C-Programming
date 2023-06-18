#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	const int CODE1 = 10;
	const int CODE2 = 20;
	const char CODECHAR = 'C';
	const double CODE3 = 2.5;
	int num;
	char letter;
	double num2;
	cout << "Lock #1: Enter a positive 3 digit integer: ";
	cin >> num;
	if (num%10+num/100==CODE1) {
		cout << "You have opened the first lock!" << endl;
		cout << "Lock #2: Enter a letter: ";
		cin >> letter;
		if (CODE2 >= abs(int(CODECHAR) - int(letter))) {
			cout << "You have opened the second lock!" << endl;
			cout << "Lock #3: Enter a positive double value: ";
			cin >> num2;
			if (sqrt(pow(num2, 2) + pow(num2, 2)) < pow(CODE3, 3)) {
				cout << "You have opened the third lock!" << endl;
				cout<<"Congratulations! You have opened the cookie jar!"<<endl;
				
			}
			else {
				cout << "Go steal someone else's cookies!";
			}
		}
		else {
			cout << "Go steal someone else's cookies!";
		}
	}
	else {
		cout << "Go steal someone else's cookies!";
	}
}