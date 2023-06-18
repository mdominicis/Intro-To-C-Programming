#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
using namespace std;
int main() {
	ofstream fout;
	fout.open("money.txt");
	string name;
	int gross;
	cout << "Enter employee name: ";
	getline(cin, name);
	cout << "Enter gross pay: ";
	cin >> gross;
	const double fedtax = 0.15, statetax = 0.035, socsectax = 0.0575, medtax = 0.0275, pension = 0.05, insurance = 75.00;
	fout << name<<endl;
	fout << setprecision(2) << fixed << showpoint;
	fout << setfill('.') << left << setw(25) << "Gross Amount: " << right <<setw(10)<< gross << endl;
	fout << setfill('.') << left << setw(25) <<"Federal Tax: "<< right << setw(10) << gross*fedtax<<endl;
	fout << setfill('.') << left << setw(25) << "State Tax: " << right << setw(10) << gross*statetax<< endl;
	fout << setfill('.') << left << setw(25) << "Social Security Tax: " << right << setw(10) << gross*socsectax<< endl;
	fout << setfill('.') << left << setw(25) << "Medical Tax: " << right << setw(10) << gross*medtax << endl;
	fout << setfill('.') << left << setw(25) << "Pension: " << right << setw(10) << gross*pension << endl;
	fout << setfill('.') << left << setw(25) << "Healthcare Insurance: " << right << setw(10) << insurance << endl;
	fout << setfill('.') << left << setw(25) << "Net Pay: " << right << setw(10) << gross-gross*fedtax-gross*statetax-gross*socsectax-gross*medtax-gross*pension-insurance << endl;
	return 0;
}