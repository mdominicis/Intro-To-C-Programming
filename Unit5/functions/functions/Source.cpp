#include <iostream>
#include <time.h>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;
//function prototypes
void welcome(); //returns nothing (void) and has no parameters (stuff in parentheses), prints a welcome message
void message(string); //returns nothing, one string parameters, prints out the string parameter
void printName(int, string); //returns nothing, has one int parameter and one string parameter, stores a name in the string parameterand prints it an integernumber of times
int getRandom(); //returns an int, no parameters (also called arguments), returns an int between 1 and 100 (inclusive)
double distance(double, double, double, double); //takes two points--x1,y1,x2,y2 and returns the distance between them
bool isTri(double, double, double); //returns true if three parameters can form a triangle, false otherwise
int findMax(); //generates two random integers between 1 and 100 and returns the highest one
int findSum(double, double);
int main()
{
	double test, test2;
	cin >> test >> test2;
	cout<<findSum(test, test2);
}
void welcome()
{
	cout << "Welcome to my program!\n";
}
void message(string msg) //msg is a formal parameter
{
	cout << msg << endl;
}
void printName(int x, string user)
{
	for (int i = 0; i < x; i++) //loop goes x times
	{
		//cout << user << endl; I could do this, but I should use functions I make when possible.
			message(user); //prints user
	}
}
int getRandom()
{
	int r = rand() % 100 + 1;
	return r;
}
double distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
bool isTri(double x, double y, double z)
{
	/*if (x + y > z && y + z > x && x + z > y)
	return true;
	else
	return false;*/
	return (x + y > z && y + z > x && x + z > y);
}
int findMax()
{
	int x = getRandom();
	int y = getRandom();
	cout << "Random number 1: " << x << endl;
	cout << "Random number 2: " << y << endl;
	if (x > y)
		return x;
	else
		return y;
}
int findSum(double x,double y) {
	int min=0, max=0,sum=0;
	if (x < y) {
		max = floor(y);
		min = ceil(x);
	}
	else {
		max = floor(x);
		min = ceil(y);
	}
	for (int i = min; i <= max; i++) {
		sum += i;
	}
	return sum;
}
