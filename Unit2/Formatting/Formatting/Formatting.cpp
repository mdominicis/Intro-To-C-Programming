#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main() {
	string pet1, pet2, pet3;
	int age1, age2, age3;
	double bill1, bill2, bill3;
	cout << "Enter pet name: ";
	getline(cin, pet1);
	cout << "Enter age and vet bill: ";
	cin >> age1 >> bill1;
	cout << "Enter pet name: ";
	cin.ignore(100, '\n');
	getline(cin, pet2);
	cout << "Enter age and vet bill: ";
	cin >> age2 >> bill2;
	cin.ignore(100, '\n');
	cout << "Enter pet name: ";
	getline(cin, pet3);
	cout << "Enter age and vet bill: ";
	cin >> age3 >> bill3;
	cout << setprecision(2) << fixed << showpoint;
	cout << setfill(' ') << left << setw(20) << "Pet Name" << right << setw(10) << "Age" <<setfill(' ')<<setw(15) << "Vet Bill" << endl;
	cout << setfill('-') << setw(45)<<'-'<<endl;
	cout << setfill('.') << left << setw(20) << pet1 << right << setw(10) << age1 << setfill(' ')<< setw(15) << bill1<<endl;
	cout << setfill('.') << left << setw(20) << pet2 << right << setw(10) << age2 << setfill(' ')<< setw(15) << bill2<<endl;
	cout << setfill('.') << left << setw(20) << pet3 << right << setw(10) << age3 << setfill(' ')<< setw(15) << bill3;
	return 0;

}