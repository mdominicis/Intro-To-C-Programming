#include <iostream>
#include <string>
using namespace std;

int main()
{
	cout << "Please enter your full name: ";
	string name;
	getline(cin, name); //Must use getline() to read a string with spaces
	cout << "Please enter your age: ";
	int age;
	cin >> age;
	cout << "Please enter your favorite subject: ";
	string subject;
	cin.ignore(100, '\n'); //when going from a cin to a getline() you must use cin.ignore to ignore the rest of the line that you used cin on
	getline(cin, subject);


	cout << "Hello, " << name << "! You are " << age << " years old, and your favorite subject is " << subject << ".\n\n";
	int favnum;
	char tester; //character to be read
	bool good = false; //assume that the input is not good (not a number)
	while (good == false) //keeps going while input is not good
	{
		cout << "Please enter your favorite number: ";

		cin.get(tester);//removes character from input stream and stores it in tester
		//tester = cin.peek(); //You could do this and then remove the cin.get() and the cin.putback()
		if (isdigit(tester)) //tests if a character is a number
		{
			good = true;
			cin.putback(tester);//puts character back into input stream
			cin >> favnum;
		}
		cin.ignore(100, '\n'); //ignores the rest of the line because the get function will try to read any other characters that are in the stream

	}
	cout << "Your favorite number is " << favnum << "!\n";

}

