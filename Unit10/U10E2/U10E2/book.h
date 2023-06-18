#pragma once
#include <string>
#include <vector>
#ifndef _BOOK_H
#define _BOOK_H
using namespace std;

class book {
private:
	string title;
	double price;
	int copies;
	vector <string> authors;
public:
	book(string, double, int, vector <string>);
	string getTitle();
	double getPrice();
	int getCopies();
	vector <string> getAuthors();
	void setPrice(double);
	void setAuthors(vector <string>);
	void updateCopies(int);
	void printOut();
};
#endif