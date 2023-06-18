#pragma once
#include <string>
#include <vector>
#ifndef _CUSTOMER_H
#define _CUSTOMER_H
using namespace std;

class customer {
private:
	string name;
	int booksPurchased;
	double amountSpent;
public:
	customer(string);
	customer(string,int,double);
	string getName();
	int getBooks();
	double getAmount();
	void setName(string);
	void updateBooks(int);
	void updateAmount(double);
	void printOut();
};
#endif