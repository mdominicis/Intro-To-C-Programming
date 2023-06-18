#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s = "Mrs. Frizzle";
	//Length/Size
	//s.length() or s.size() finds length of string, start counting at 1!
	//EXAMPLE: s=Mrs. Frizzle, s.length()=12
	cout << "The length of that string is " << s.length() << "!\n";
	//Bracket Notation ([])
	//s[a] returns the character at position a in s, start counting at 0!
	cout << "First letter of s: " << s[0] << endl;
	cout << "Last letter of s: " << s[s.length() - 1] << endl;
	//Concatenation
	//Use + or += to concatenate (put together) strings 
	//with other strings or characters
	string str = s + ": Teacher"; //str="Mrs. Frizzle: Teacher"
	str += '!'; //str="Mrs. Frizzle: Teacher!"
	cout << str << endl;
	//Do not try to add any primitive data types to strings except characters.
	//If you want to add a number to a string, use the to_string() function.
	str += to_string(777); //str="Mrs. Frizzle: Teacher!777"
	cout << str << endl;
	//Substrings
	//s.substr(a, b)-->returns string starting at position a 
	//and b characters long
	//s.substr(a)-->returns string starting at position a and goes 
	//to the end of the string 
	//What if I want ". Friz"? Starts at 3, 6 chars long
	cout << s.substr(3, 6) << endl;
	//What if I want "izzle"? Starts at 7, goes to the end
	//Don't put a second parameter if you don't have to! 
	//This can prevent mistakes!
	cout << s.substr(7) << endl;
	//Find function
	//s.find(a) returns the position of the first occurrence of a in s
	//a can be a character or a string
	//What if I want to find the position of the first 'r'? 
	int x = s.find('r'); //always set find to an integer before putting it in a condition, x will be - 1 if there are no r's
		if (x >= 0)
			cout << "The letter r is at position " << x << "!\n"; //should be 1
		else
			cout << "There is no letter r in that string!\n";
	//What if I want to find the position of the first "frizz"?
	int y = s.find("frizz"); //y should be -1 because find() is case sensitive
	if (y >= 0)
		cout << "The string \"frizz\" is at position " << y << "!\n";
	else
		cout << "There is no \"frizz\" in that string!\n";
	//Comparison:
	cout << s.find("frizz") << endl; //4294967295
	cout << y << endl; //-1
	//Why? See a detailed explanation in the notes.
	return 0;
}