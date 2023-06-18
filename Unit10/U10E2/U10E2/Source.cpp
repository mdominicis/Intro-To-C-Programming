
#include "book.h"
#include "customer.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void readBooksFile(vector<book>&);
void readCustomersFile(vector<customer>&, vector<book>&);
void updateBookFile(vector<book>);

int main()
{
	vector <book> Books;
	vector <customer> Customers;

	readBooksFile(Books);

	cout << "Books in Stock:\n\n";
	for (int i = 0; i < Books.size(); i++)
	{
		Books[i].printOut(); //print books
	}

	readCustomersFile(Customers, Books);

	cout << "Customer List:\n\n";
	for (int i = 0; i < Customers.size(); i++)
	{
		Customers[i].printOut(); //print customers
	}

	updateBookFile(Books);
}
void readBooksFile(vector<book>& books)
{
	ifstream fin;
	fin.open("Books.txt");
	while (!fin.eof()) {
		string title;
		vector <string> author;
		double price;
		int copies;
		string x;
		getline(fin, title);
		fin >> price;
		fin >> copies;
		fin.ignore(100, '\n');
		getline(fin, x);
		while (x!="") {
			author.push_back(x);
			getline(fin, x);
		}
		book a(title, price, copies, author);
		books.push_back(a);
	}
	//Keep reading through the file until you reach the end.
	//Make sure to do ignore when going from a primitive to a string!!!
	//When reading through the authors, keep reading until the author is an empty string ""
	//Make sure not to add the empty string to the vector of authors.

	fin.close();
}
void readCustomersFile(vector<customer>& customers, vector<book>& books)
{
	ifstream fin;
	fin.open("Customers.txt");
	while (!fin.eof())
	{
		string n, bTitle; //name of customer and book title
		int custPos; //position of customer in vector of customers
		bool there = false; //true if customer is already in vector, false otherwise
		getline(fin, n);
		getline(fin, bTitle);
		fin.ignore(100, '\n');
		for (int i = 0; i < customers.size(); i++) {
			if (n == customers.at(i).getName()) {
				there = true;
				custPos = i;
			}
		}
		if (there == false) {
			customer c(n);
			customers.push_back(c);
			custPos = customers.size() - 1;
		}
		for (int i = 0; i < books.size(); i++) {
			if (bTitle == books.at(i).getTitle()) {
				customers.at(custPos).updateBooks(1);
				customers.at(custPos).updateAmount(books.at(i).getPrice());
				books.at(i).updateCopies(-1);
			}
		}
		//read in customer name and title

		//determine if customer is already in the vector
		//if the customer is already in the vector, set there to true and custPos to 
		//the position of the customer in the vector


		//if customer is not in the vector, add new customer to the vector
		//Make sure to set custPos to the position of the new customer in the vector


		//Look for the title in books. Once found, update books purchased and amount spent 
		//for customer at position custPos. 
		//Also, update copies for the book title.
	}
	fin.close();
}
void updateBookFile(vector<book> books)
{
	ofstream fout;
	fout.open("Books.txt");
	for (int i = 0; i < books.size(); i++)
	{
		fout << setprecision(2) << fixed;
		fout << books[i].getTitle() << endl;
		fout << books[i].getPrice() << endl;
		fout << books[i].getCopies() << endl;
		for (int j = 0; j < books[i].getAuthors().size(); j++) //loop through authors of the book
		{
			if (j < books[i].getAuthors().size() - 1)
				fout << books[i].getAuthors()[j] << endl; //go to next line between each author
			else if (j == books[i].getAuthors().size() - 1 && i == books.size() - 1)
				fout << books[i].getAuthors()[j] << endl; //go to next line at end of file
			else
				fout << books[i].getAuthors()[j] << endl << endl; //go to next line and skip a line between each list of book information
		}
	}
	fout.close();
}