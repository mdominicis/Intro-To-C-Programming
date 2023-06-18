#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
bool check(int secret, int guess, int guesses);
//global variables--The scope of a global variable is the entire program.
int main()
{
	srand(time(0));
	char choice = 'y';//Local variable--the scope is the main() function
	int guesses = 0;
	int wins = 0;
	while (choice == 'y' || choice == 'Y')
	{
		cout << "\nGuess a number between 1-50.\n\n";
		int num = rand() % 50 + 1; //Local variable--the scope is the while  loop that is controlled by choice
		guesses = 1;
		cout << "Secret Number: " << num << endl; //Print this out for testing. Remove in final version.
			int guess = 0; //Local variable--the scope is the while loop that is controlled by choice
			do
			{
				cout << "Guess # " << guesses << ": ";
				cin >> guess;
				while (guess < 1 || guess>50) {
					cout << "Invalid input.";
					cin >> guess;
				}
				guesses++;
			} while (!check(num, guess,guesses));
			wins++;
			cout << "Do you want to play again? (y/n) ";
			cin >> choice;
	}
	cout << "\nYou won " << wins << (wins == 1 ? " time!" : " times!") << "\n";
}
bool check(int secret, int guess, int guesses)
{
	//Assume game isn't over. 
	bool over = false;//Local variable--the scope is the check() function 
	if (guess < secret)
	{
		cout << "\nYour guess is too low. Try again.\n\n";
	}
	else if (guess > secret)
	{
		cout << "\nYour guess is too high. Try again.\n\n";
	}
	else
	{
		cout << "\nYou guessed the secret number in " << guesses <<
			(guesses == 1 ? " guess!" : " guesses!") << "\n\n";
		over = true; //game is over
	}
	return over;
}