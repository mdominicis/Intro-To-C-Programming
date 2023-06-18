#include "customer.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

customer::customer(string n){
	name = n;
	booksPurchased = 0;
	amountSpent = 0;
}
customer::customer(string n, int b, double a){
	name = n;
	booksPurchased = b;
	amountSpent = a;
}
string customer::getName(){
	return name;
}
int customer::getBooks(){
	return booksPurchased;
}
double customer::getAmount(){
	return amountSpent;
}
void customer::setName(string n) {
	name = n;
}
void customer::updateBooks(int b){
	booksPurchased += b;
}
void customer::updateAmount(double a){
	amountSpent += a;
}
void customer::printOut(){
	cout << "Name: " << name<<endl;
	cout << "Books Purchased: " << booksPurchased<<endl;
	cout << "Amount Spent: $" << amountSpent<<endl<<endl;
}