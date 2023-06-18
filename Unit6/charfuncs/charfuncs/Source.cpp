#include <string>
#include <iostream>
using namespace std;
int main()
{
	string s = "ThiS IS CoOl!";
	//PART 1
	cout << "Part 1: \n";
	//convert lowercase letters to uppercase and vice versa
	for (int i = 0; i < s.length(); i++)
	{
		if (isupper(s[i])) //if uppercase
		{
			s[i] = tolower(s[i]); //convert char to lowercase
		}
		else
		{
			s[i] = toupper(s[i]); //convert char to lowercase
		}
	}
	//Note: toupper and tolower will not affect non-alphabetic characters
	cout << s << endl;
	//PART 2
	cout << "\nPart 2: \n";
	//count the number of letters, numbers, and punctuation chars in a string
	s = "Can't you see 1, 2, 3...you are my destiny!!";
	int countL = 0, countN = 0, countP = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (isalpha(s[i])) //if alphabetic
		{
			countL++;
		}
		if (isdigit(s[i])) //if numeric
		{
			countN++;
		}
		if (ispunct(s[i])) //if punctuation
		{
			countP++;
		}
	}
	cout << "There are " << countL << " letters.\n";
	cout << "There are " << countN << " numbers.\n";
	cout << "There are " << countP << " punctuation marks.\n";
	//PART 3
	cout << "\nPart 3: \n";
	//Replace character entered by user with '*' (NOT case sensitive)
	cout << "Please enter a character: ";
	char ch;
	cin >> ch;
	s = "She sells seaShells by the Seashore.";
	for (int i = 0; i < s.length(); i++)
	{
		if (tolower(s[i]) == tolower(ch)) //could do toupper instead
		{
			s[i] = '*';
		}
	}
	cout << s << endl;
	return 0;
}