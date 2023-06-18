#include <iostream>
using namespace std;
int main()
{
	//Use a for loop when you know how many times your code should go.
	for (int i = 1; i <= 10; i++)
		cout << i << " "; //Prints 1-10
	cout << endl << endl;
	for (int i = 10; i >= 1; i--)
		cout << i << " "; //Prints 10-1
	int num, sum = 0;
	double avg;
	cout << "\n\nHow many scores would you like to enter? "; //assume scores are ints
		cin >> num;
	for (int i = 1; i <= num; i++) //loop goes num times
	{
		int score;
		cout << "Enter score #" << i << ": ";
		cin >> score;
		sum += score;
	}
	avg = double(sum) / num; //Don't forget type casting to avoid truncation!
	cout << "The average score is " << avg << ".\n\n";
	int x;
	cout << "Enter a positive integer to see if it's prime. ";
	cin >> x;
	bool prime = true; //Assume prime is true until proven otherwise.
	if (x == 1) //Special case: 1 is not a prime number.
		prime = false;
	for (int i = 2; i < x; i++) //check if x is divisible by any number between 2 and the number itself(exclusive)
	{
		if (x % i == 0) //if x is divisible by i
		{
			prime = false;
			break; //stop the loop
		}
	}
	cout << x << " is" << (prime ? " " : " not ") << "prime!\n";
	return 0;
}