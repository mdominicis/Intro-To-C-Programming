#include <iostream>
#include <string>
using namespace std;

int main()
{

	cout << "Please enter your grade as a percentage: ";

	double score;
	cin >> score;
	char grade; //letter grade

	if (score >= 89.5)
		grade = 'A';
	else if (score >= 79.5)
		grade = 'B';
	else if (score >= 69.5)
		grade = 'C';
	else if (score >= 59.5)
		grade = 'D';
	else
		grade = 'F';

	/*
		Ternary operator:
		(condition ? result if true : result if false)

		This is frequently used in a cout or a string. It allows you to put the result of an if..else inside of the string/output.
	*/

	//Common application--grammar
	//for A or F, you want "an", not "a"
	cout << "You have "
		<< (grade == 'A' || grade == 'F' ? "an " : "a ") << grade
		<< ".\n";
	cout << "Is this an AP class? (y/n) ";
	char ap;
	cin >> ap;
	if (ap == 'y' || ap == 'Y')
	{
		string message = (score >= 79.5 ? "You should take the AP test." : "You should not take the AP test.");
		cout << message << endl;
	}

	//switch statements--used when you have a small, finite number of choices
	switch (grade) //this variable should be of an integral type-->int, char, or bool
	{
	case 'A':
		cout << "You're awesome!\n";
		break; //Without break, it will run through all of the choices until it hits a break.
	case 'B':
		cout << "Pretty good.\n";
		break;
	case 'C':
		cout << "You need to study more.\n";
		break;
	case 'D':
		cout << "You're in trouble!\n";
		break;
	case 'F':
		cout << "Drop the class!\n";
		break;
	default: //like an else, optional
		cout << "That's impossible!\n";
	}

	/*Try this on your own!

	Allow the user to enter 2 non-negative integers through the keyboard and always divide the largest number by the smallest. The result should be displayed as a quotient and remainder.  Only show the remainder if it is not zero--try to use the ternary operator for this part. The program should not allow division by zero. If a user enters 0, display a message that says you cannot divide by zero.*/

	//Concatenating strings and numbers-->
	//string s="Remainder: " + to_string(remainder);






	return 0;
}