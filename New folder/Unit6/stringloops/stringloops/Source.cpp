#include <string>
#include <iostream>
using namespace std;
int main()
{
	string s = "I love C++";
	//PART 1
	cout << "Part 1: \n";
	//print string characters on separate lines:
	//characters go from 0 to s.length()-1
	for (int i = 0; i < s.length(); i++) //condition could be i<=s.length()-1
	{
		cout << s[i] << endl;
	}
	//PART 2
	cout << "\nPart 2: \n";
	//count the number of lowercase 'm's
	s = "Mmmm, this muffin is yummy!";
	int count = 0;
	//Approach 1:
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'm')
		{
			count++;
		}
	}
	cout << "There are " << count << " m's in " << s << endl;
	//Approach 2:
	string temp = s; //hold s in temporary variable so that it doesn't change
	count = 0;
	int pos = temp.find('m'); //find index of the first m
	while (pos >= 0) //Do NOT type while(s.find('m')>=0)
	{
		count++;
		//shorten temp so that the previous m is no longer included in the 
		string
			temp = temp.substr(pos + 1);
		pos = temp.find('m'); //will be -1 when no more m's
	}
	cout << "There are " << count << " m's in " << s << endl;
	//PART 3
	cout << "\nPart 3: \n";
	//Replace all lowercase m's with lowercase w's
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'm')
		{
			s[i] = 'w';
		}
	}
	cout << s << endl;
	//PART 4
	cout << "\nPart 4: \n";
	//Replace all "yeah"s with "no"s
	s = "So yeah, yeah, I like the word yeah, yeah?";
	//This is not a single character replacement, so no bracket notation
	//In general, avoid using a for loop when you are changing the 
	//length of a string. This can mess with your bounds.
	pos = s.find("yeah");
	while (pos >= 0)
	{
		s = s.substr(0, pos) + "no" + s.substr(pos + 4); //4 is the length of "yeah"
			pos = s.find("yeah");
	}
	cout << s << endl;
	//PART 5
	cout << "\nPart 5: \n";
	//Print "yes" if the string contains "yeah", print "no" otherwise
	s = "So yeah, yeah, I like the word yeah, yeah?";
	bool hasYeah = false; //assume that "yeah" is not in the word
	for (int i = 0; i < s.length(); i++)
	{
		if (s.substr(i, 4) == "yeah") //4 is the length of "yeah"
		{
			hasYeah = true;
		}
	}
	cout << "Does the string have a \"yeah\"? ";
	cout << (hasYeah ? "yes" : "no") << endl;
	//PART 6
	cout << "\nPart 6: \n";
	//Add "booyah" to the end of every word
	s = "This totally rocks my socks";
	temp = ""; //instead of changing s right away,
	//just add on to an empty string, temp
	//Approach 1:
	pos = s.find(' '); //pos=4 at the beginning
	while (pos >= 0)
	{
		temp += s.substr(0, pos) + "booyah "; //temp="Thisbooyah "
		s = s.substr(pos + 1); //shortens the string so that the first space is cut off, now s = "totally rocks my socks"
			pos = s.find(' '); //now pos=7
	}
	//after while loop, s="socks" because there are no more spaces
	temp += s + "booyah"; //add on one "socks" and one more "booyah"
	s = temp; //now change s to temp
	cout << s << endl;
	//Approach 2:
	s = "This totally rocks my socks";
	temp = ""; //instead of changing s right away,
	//just add on to an empty string, temp
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ') //if it's a space, add "booyah"
		{
			temp += "booyah ";
		}
		else //Otherwise, just add the character
		{
			temp += s[i];
		}
	}
	temp += "booyah";
	s = temp; //now change s to temp
	cout << s << endl;
	//PART 7
	cout << "\nPart 7: \n";
	//Count the number of "bob" substrings-->This is a substring that has a 'b',
	//any other character, and another 'b'
	s = "Why do bob and his baby need a bib to bob for apples? bob, bob, bob";
	count = 0;
	for (int i = 0; i < s.length() - 2; i++) //Adjust condition to avoid going 
	//out of bounds
	{
		if (s[i] == 'b' && s[i + 2] == 'b')
		{
			count++;
		}
	}
	cout << "There are " << count << " bob strings in " << s << endl;
}