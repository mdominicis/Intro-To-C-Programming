#include <iostream>
#include <string>
using namespace std;
int main()
{
	int x=0;
	cout << "Loop Practice:" << endl << "1) Kaboom" << endl << "2) Perfect Numbers" << endl << "3) Draw Triangle" << endl << "4) Lottery Ticket" << endl << "5) Quit" << endl;
	cout << "Choose a number: ";
	cin >> x;
	int y;
	int sum = 0;
	while (x != 5) {
		switch (x) {
		case 1:
			cout << "Enter a positive integer: ";
			cin >> y;
			while (y <= 0) {
				cout << "Invalid integer, try again." << endl;
				cin >> y;
			}
			for (int i = y; i > 0; i--) {
				cout << i << "...";
			}
			cout << "Kaboom!" << endl;
			cout << "Loop Practice:" << endl << "1) Kaboom" << endl << "2) Perfect Numbers" << endl << "3) Draw Triangle" << endl << "4) Lottery Ticket" << endl << "5) Quit" << endl;
			cout << "Choose a number: ";
			cin >> x;
			break;
		case 2:
			cout << "Enter a positive integer to see if its perfect: ";
			cin >> y;
			while (y <= 0) {
				cout << "Invalid integer, try again." << endl;
				cin >> y;
			}
			for (int i = 1; i < y; i++) {
				if (y % i == 0) {
					sum += i;
				}
			}
			if (sum == y) {
				cout << "This integer is perfect!" << endl;
			}
			else {
				cout << "That number is imperfect!";
			}
			cout << "Loop Practice:" << endl << "1) Kaboom" << endl << "2) Perfect Numbers" << endl << "3) Draw Triangle" << endl << "4) Lottery Ticket" << endl << "5) Quit" << endl;
			cout << "Choose a number: ";
			cin >> x;
			break;
		case 3:
			cout << "Enter the height of an isosceles triangle, it must be greater than 1: ";
			cin >> y;
			while (y <= 1) {
				cout << "Invalid integer, try again." << endl;
				cin >> y;
			}
			for (int i =1; i <= y; i++)
			{
				for (int j = 1; j <= i; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			for (int i = y-1; i >= 1; i--)
			{
				for (int j = i; j>= 1; j--)
				{
					cout << "* ";
				}
				cout << endl;
			}
				cout << "Loop Practice:" << endl << "1) Kaboom" << endl << "2) Perfect Numbers" << endl << "3) Draw Triangle" << endl << "4) Lottery Ticket" << endl << "5) Quit" << endl;
				cout << "Choose a number: ";
				cin >> x;
				break;
			case 4:
				cout << "How many lottery tickets would you like to buy today? ";
				cin >> y;
				while (y <= 0) {
					cout << "Invalid integer, try again." << endl;
					cin >> y;
				}
				for (int i = 1; i <= y; i++) {
					cout << "Ticket #" << i<<": ";
					for (int j = 0; j < 6; j++) {
						cout<<rand()%50+1<<" ";
					}
					cout << endl;
				}
				cout << "Loop Practice:" << endl << "1) Kaboom" << endl << "2) Perfect Numbers" << endl << "3) Draw Triangle" << endl << "4) Lottery Ticket" << endl << "5) Quit" << endl;
				cout << "Choose a number: ";
				cin >> x;
				break;
			case 5:
				break;
			default:
				cout << "That is not a valid integer! Please try again!"<<endl;
				cout << "Loop Practice:" << endl << "1) Kaboom" << endl << "2) Perfect Numbers" << endl << "3) Draw Triangle" << endl << "4) Lottery Ticket" << endl << "5) Quit" << endl;
				cout << "Choose a number: ";
				cin >> x;

		}
	}
	cout << "Bye!!";
}