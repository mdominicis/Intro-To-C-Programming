#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
int main() {
	ifstream fin;
	fin.open("Billionaires.txt");
	int age;
	string name, occupation;
	cout << "Please input your name: ";
	getline(cin, name);
	cout << "Please input your age: ";
	cin >> age;
	cout << "Please input your occupation: ";
	cin.ignore(100, '\n');
	getline(cin, occupation);
	cout << "Hello " << name << " the " << age << " year old " << occupation << "." << endl;
	cout << "Want to know something cool? Here is a list of the top 5 billionaires." << endl;
	string bname;
	double bval,total=0,counter=0;
	cout << setfill('-') << left << setw(70) << "-" << endl;
	cout << setfill(' ') << left << setw(30) << "Name" << right << setw(30) << "Net Worth" << endl;
	cout << setfill('-') << left << setw(70) << "-" << setfill(' ')<<endl;
	while (!fin.eof())
	{
		getline(fin, bname);
		fin >> bval;
		fin.ignore(100, '\n');
		cout << setprecision(2) << fixed;
		cout << left << setw(30) << bname << right << setw(30)<< bval << endl;
		total += bval;
		counter++;
	}
	fin.close(); 
	cout << setfill('-') << left << setw(70) << "-" << endl;
	cout << "Average salary: " << (total / counter);
	return 0;
}