#include <iostream>
#include <cmath> //for math functions (pow(), sqrt()), Visual Studio lets you leave this header out, but many programs don't (Online GDB)

using namespace std;

int main()
{
	cout << "Enter three integers, and I will tell you the average. ";
	int a, b, c;
	cin >> a >> b >> c;

	double avg1 = (a + b + c) / 3; //not correct, int/int, will truncate (cut off the decimal)
	cout << "Incorrect Average: " << avg1 << endl;
	double avg2 = (a + b + c) / 3.0; //make 3 a decimal, now it is int/double which is a double
	//OR use explicit type casting:
	//double avg2 = double(a + b + c) / 3; This would work too.

	cout << "Correct Average: " << avg2 << endl;

	//What if I want to decrease the value of avg2 by 20%?
	//avg2 = .8 * avg2;

	//OR use compound assignment operator
	avg2 *= .8;

	cout << "Average decreased by 20%: " << avg2 << endl;


	//What about exponents and square root?

	cout << "Enter the length of two legs of a right triangle, and I will tell you the length of the hypotenuse. ";

	double leg1, leg2, hyp;
	cin >> leg1 >> leg2;

	hyp = sqrt(pow(leg1, 2) + pow(leg2, 2)); //Pythagorean Theorem

	cout << "The hypotenuse is " << hyp << "!\n";

	//Can you put an int into a double? Can you put a double into an int?

	int num1 = 3.7; //This is allowed. It will just truncate it to 3.
	double num2 = 5; //This will be stored as 5.0.

	cout << num1 << " " << num2 << endl;

	//Using Mod (%): The mod operator finds the remainder between two ints.

	/*
	* Suppose the user enters an integer length in inches... Print out the
	* length in yds, ft, inches (Example 124 inches will be 3 yds. 1 ft, 4 inches (3 ft in a yd, 12 inches in a foot)
	*/
	cout << "Enter a length in inches: ";
	int inches;
	cin >> inches;


	int yds = inches / 36; //How many times does 36 go into inches?
	//inches=inches%36;
	inches %= 36; //Find the leftover inches after removing groups of 36.
	int ft = inches / 12; //How many times does 12 go into inches?
	inches %= 12; //Find the leftover inches after removing groups of 12.

	cout << "Length: " << yds << " yard(s), " << ft << " foot(feet), " << inches << " inch(es)\n";
	cout << "Enter the height and 2 bases of a trapezoid.";
	int h, base1, base2;
	double area;
	cin >> h >> base1 >> base2;
	area = 1 / 2.0 * h * (base1 + base2);
	cout <<"Area:"<< area << endl;
	return 0;
}