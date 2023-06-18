#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
double getdiscount(int num, double price);
double getEquipCost(int num, double price);
double getInstCost(int num, double price);
void printReceipt(int num, double base, double discount, double instruct, double equip);
int main() {
	int x = 0, basecharge = 0, instructcharge = 0, equipcharge = 0, base = 0, instruct = 0, equip = 0;
	double discount = 0, instprice = 0, equipprice = 0,baseprice=0;
	cout << "High Adventure Travel Agency" << endl << endl;
	cout << "1) Scuba Bahama" << endl;
	cout << "2) Devil's Courthouse Adventure Weekend" << endl;
	cout << "3) Barron Cliff Spelunk" << endl;
	cout << "4) Exit Program" << endl;
	cout << "Enter 1, 2, 3 or 4: ";
	cin >> x;
	switch (x) {
	case 1:
		basecharge = 350;
		instructcharge = 100;
		equipcharge = 120;
		cout << "How many people are going on the trip? ";
		cin >> base;
		cout << "How many people will need instructions? ";
		cin >> instruct;
		cout << "How many people will need equipment? ";
		cin >> equip;
		break;
	case 2:
		basecharge = 1000;
		instructcharge = 100;
		cout << "How many people are going on the trip? ";
		cin >> base;
		cout << "How many people will need instructions? ";
		cin >> instruct;
		break;
	case 3:
		basecharge = 700;
		equipcharge = 240;
		cout << "How many people are going on the trip? ";
		cin >> base;
		cout << "How many people will need equipment? ";
		cin >> equip;
		break;
	case 4:
		break;
	}
	if (x != 4) {
		discount = getdiscount(base, basecharge);
		instprice = getInstCost(instruct, instructcharge);
		equipprice = getEquipCost(equip, equipcharge);
		baseprice = 1.0 * base * basecharge;
		printReceipt(base,baseprice,discount,instprice,equipprice);
	}
}
double getdiscount(int num,double price){
	if (num < 5) {
		return 0.0;
	}
	return num*price*0.1;
}
double getEquipCost(int num, double price) {
	return 1.0*num * price;
}
double getInstCost(int num, double price) {
	return 1.0*num*price;
}
void printReceipt(int num, double base,double discount, double instruct, double equip) {
	ofstream fout;
	fout.open("reciept.txt");
	fout << setprecision(2) << showpoint << fixed;
	double total = base - discount + instruct + equip;
	fout << setfill('.')<<left<<setw(20)<<"Number in Party"  <<right<<setw(10)<< setfill(' ')<< num<< endl;
	fout << setfill('.')<<left << setw(20) << "Base Charges" << "$" << right << setw(10) << setfill(' ') << base << endl;
	fout << setfill('.') << left << setw(20) << "Discount" << "$" << right << setw(10) << setfill(' ') << discount << endl;
	fout << setfill('.') << left << setw(20) << "Instruction Cost" << "$" << right << setw(10) << setfill(' ') << instruct << endl;
	fout << setfill('.') << left << setw(20) << "Equipment Rental" << "$" << right << setw(10) << setfill(' ') << equip << endl;
	fout << setfill('-')<<setw(31) << '-'<<endl;
	fout << setfill('.') << left << setw(20) << "Subtotal" << "$" << right << setw(10) << setfill(' ') << total << endl;
	fout << setfill('.') << left << setw(20) << "Tax" << "$" << right << setw(10) << setfill(' ') << total*0.05 << endl;
	fout << setfill('.') << left << setw(20) << "Total Bill" << "$" << right << setw(10) << setfill(' ') << total+total*0.05 << endl;
	fout << setfill('.') << left << setw(20) << "Required Deposit" << "$" << right << setw(10) << setfill(' ') << total*0.5 << endl;
}