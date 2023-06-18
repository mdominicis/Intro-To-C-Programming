#include <iostream>
#include <string>
#include <time.h>
using namespace std;
int main() {
	srand(time(0));
	cout << "Enter full name. ";
	string name, SSN, password, SSN1,initials;
	getline(cin, name);
	cout << "Enter SSN. ";
	getline(cin, SSN);
	int x = SSN.length();
	for (int i = 0; i < x; i++) {
		if (SSN.substr(i, 1) == "-") {
			i++;
		}
		SSN1 += SSN[i];
	}
	x = SSN1.find('5');
	if (x > 0) {
		password += SSN1.substr(5, 3);
	}
	else {
		password += SSN1.substr(2, 2);
	}
	cout << "Password part 1: "<<password<<endl;
	initials += name.substr(0, 1);
	initials += name.substr(name.find(' ') + 1,1);
	cout <<"Initials: "<< initials<<endl;
	int y = rand() % 10 + 1;
	cout << "R Value: " << y<<endl;
	char a = initials[0];
	char b = initials[1];
	if (a+y> 'Z') {
		a -= 26 - y;
	}
	else {
		a += y;
	}
	if (b-y < 'A'){
		b += 26 - y;
	}
	else {
		b -= y;
	}
	password +=a;
	password += b;
	cout <<"Password part 2: "<< password<<endl;
	int counter = 0;
	for (int i = 0; i < SSN1.length(); i++) {
		if (SSN1[i] > '6') {
			counter++;
		}
	}
	if (counter > 2) {
		password += "!!";
	}
	else {
		password += "**";
	}
	string security = "security";
	cout << "Password part 3: " << password<<endl;
	for (int i = 0; i < name.length(); i++) {
		int found = security.find(name[i]);
		if (found >= 0) {
			password += name[i];
		}
	}
	cout << "Password part 4:" << password << endl;
	password += to_string(name.length()-1);
	cout << "Your final password is: " << password;
	}