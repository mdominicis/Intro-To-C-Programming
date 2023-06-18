#include <vector>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct menuItemType {
	string menuItem;
	double menuPrice;
};

void getMenu(menuItemType p[]);
void showMenu(menuItemType p[]);
void getOrders(menuItemType p[], vector <menuItemType>& v);
void printCheck(vector <menuItemType> v);

int main() {
	menuItemType arr[8];
	vector <menuItemType> v;
	cout << "Welcome to Matt's Cafe!" << endl << "Please select the items you want. Due to a limited supply, you can only choose one of each item." << endl;
	getMenu(arr);
	showMenu(arr);
	getOrders(arr, v);
	printCheck(v);
}

void getMenu(menuItemType p[]) {
	ifstream fin;
	fin.open("menu.txt");
	int i = 0;
	while (!fin.eof()) {
		getline(fin, p[i].menuItem);
		fin >> p[i].menuPrice;
		fin.ignore(100, '\n');
		fin.ignore(100, '\n');
		i++;
	}
	fin.close();
}
void showMenu(menuItemType p[]) {
	for (int i = 0; i < 8; i++) {
		cout << fixed << setprecision(2) << (i + 1) << ". " << left << setw(20) << p[i].menuItem << "$" << p[i].menuPrice << endl;
	}
}
void getOrders(menuItemType p[], vector <menuItemType> &v) {
	int x = 0;
	cout << "9. Exit" << endl << "Choose an item: ";
	while (x != 9) {
		cin >> x;
		if (x > 9 || x < 1) {
			cout << "That is an invalid choice. Please try again.";
			continue;
		}
		if (x != 9) {
			v.push_back(p[x - 1]);
		}
	}
}
void printCheck(vector <menuItemType> v) {
	double tax, total = 0;
	const double rate = 0.05;
	for (int i = 0; i < v.size(); i++) {
		cout << left << setw(15) << fixed << setprecision(2) << v[i].menuItem << "$" << v[i].menuPrice << endl;
		total += v[i].menuPrice;
	}
	tax = rate * total;
	cout << setw(15) << "Tax" << "$" << tax << endl << setw(20) << setfill('-') << "-" << endl;
	total += tax;
	cout << setw(15) << setfill(' ') << "Amount Due:" << "$" << total;
}