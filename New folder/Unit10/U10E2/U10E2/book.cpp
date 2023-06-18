#include "book.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

book::book(string t, double p, int c, vector <string> a) {
	title = t;
	price = p;
	copies = c;
	authors = a;
}
string book::getTitle() {
	return title;
}
double book::getPrice() {
	return price;
}
int book::getCopies() {
	return copies;
}
vector <string> book::getAuthors() {
	return authors;
}
void book::setPrice(double p) {
	price = p;
}
void book::setAuthors(vector <string> a) {
	authors = a;
}
void book::updateCopies(int c) {
	copies += c;
}
void book::printOut() {
	cout << "Title: " << title<<endl;
	cout << "Price: $" << price<<endl;
	cout << "Copies: " << copies<<endl;
	cout << "Authors: ";
	for (int i = 0; i < authors.size(); i++) {
		cout << authors[i];
		if (i == authors.size() - 1) {
		}
		else {
			cout << ", ";
		}
	}
	cout << endl<<endl;
}