#include <iostream>

using namespace std;

/*
*	This program shows different forms of if statements. It also uses nested if statements (if statements inside of if statements)
*/

int main()
{
	cout << "Hello. I'm going to ask you questions to see if I want to be your friend.\n\n";
	cout << "Do you like dogs? (y/n) ";
	char dogs;
	cin >> dogs;
	if (dogs == 'y')
	{
		cout << "So far, so good. How old are you? ";
		int age;
		cin >> age;
		if (age < 20)
			cout << "You are too young to be my friend.\n\n";
		else if(age>60) //only runs if first condition is false
			cout << "You are too old to be my friend.\n\n";
		else //only runs if both previous conditions are false
		{
			cout << "You are an appropriate age to be my friend.\n\n";
			cout << "On a scale of 1-10, how much do you like programming? ";
			int scale;
			cin >> scale;
			if (scale < 10)//This if doesn't have an else and that's okay!
			{
				cout << "Wrong answer! Everyone should choose 10!\n\n";
			}
			if (scale >= 7) //if scale is 7, 8, or 9 both if statements will run
			//if scale is 10 or above, only this statement will run
			{
				cout << "I guess we can be friends.\n\n";
			}
			else //this only goes with the previous if statement
			//if scale is below 7, the "Wrong answer!" statement and this statement will run
			{
				cout << "Sorry. I don't think we were meant to be friends.\n\n";
			}
		}

	}
	else //anything but 'y' is entered
	{
		cout << "You either don't like dogs or you can't follow directions. It would be best for us to part ways.\n\n";
		cout << "Would you like me to find a different friend for you? ";
		char response;
		cin >> response;
		bool newFriend = (response == 'y'); //You can set a bool variable to a bool expression!
		if (newFriend) //shorthand for if(newFriend==true)
			cout << "Okay. I'll see what I can do.\n";
		if (!newFriend) //shorthand for if(newFriend==false)
			cout << "Okay. Good luck.\n";
	}

	




}