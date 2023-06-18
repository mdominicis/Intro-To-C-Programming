#include <iostream>
#include <string>
using namespace std;
int countDouble(string); //Takes a string parameter and counts how many double
//characters it has (Ex: "oo", "tt", etc.)
bool palindrome(string&); //Converts string so that chars are in reverse order
//Returns true if it's a palindrome (reverse is the same as original)
string addInt(string,string, int); //Adds the integer value after every 
//character in the string
int main()
{
	string str = "Toodaloo little bee in the tree";
	int doubles = countDouble(str);
	cout << str << " has " << doubles << " doubles.\n";
	string str1 = "racecar", str2 = "steam train";
	cout << "Original strings: " << str1 << " " << str2 << endl;
	bool pal1 = palindrome(str1);
	bool pal2 = palindrome(str2);
	cout << "Reverse strings: " << str1 << " " << str2 << endl;
	cout << "The first string " << (pal1 ? "is" : "is not")
		<< " a palindrome.\n";
	cout << "The second string " << (pal2 ? "is" : "is not")
		<< " a palindrome.\n";
	string str3 = "ooga Booga";
	string str5 = "oo";
	int x = 91;
	string str4 = addInt(str3,str5, x);
	cout << str4 << endl;
	return 0;
}
int countDouble(string s)
{
	int count = 0;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == s[i + 1])
			count++;
	}
	return count;
}
bool palindrome(string& s) //Pass by reference because parameter will change
{
	string temp = "";
	for (int i = s.length() - 1; i >= 0; i--)
	{
		temp += s[i];
	}
	bool ispal = (temp == s);
	s = temp;
	return ispal;
}
string addInt(string a,string s, int x)
{
	string temp = "";
	string z = to_string(x);
	for (int i = 0; i < a.length(); i++) {
		bool y = a.substr(i, s.length()) == s;
		if (y) {
			a.substr(i, s.length())+z;
		}
	}
	temp = a;
	return temp;
}