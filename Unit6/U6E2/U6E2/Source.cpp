#include <iostream>
#include <string>
using namespace std;
bool isVowel(char x);
int changeVowels(string &x);
int changeCons(string& x);
int changePunct(string& x);
string everyThird(string& x);
int main() {
	string message;
	cout << "Enter a message: ";
	getline(cin,message);
	cout << changeVowels(message)<<" vowels were replaced."<<endl<<"Message part 1: "<<message<<endl;
	cout << changeCons(message) << " consonants were replaced." << endl << "Message part 2: " << message<<endl;
	cout << changePunct(message) << " punctuation marks were replaced." << endl << "Message part 3: " << message << endl<<"\n\n\n\n\n\n";
	cout << "Encoded message: " << everyThird(message) << endl<<endl;
	cout << "All you need to do is simply decipher this message and get back to me, good luck!";

}
bool isVowel(char x) {
	x = tolower(x);
	if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
		return true;
	}
	return false;
}
int changeVowels(string &x) {
	string temp="";
	int count = 0;
	for (int i = 0; i < x.length(); i++) {
		temp += x.substr(i, 1);
		if (isVowel(x[i])) {
			temp += tolower(x[i]);
			count++;
		}
	}
	x = temp;
	return count;
}
int changeCons(string& x) {
	string temp = "";
	int count = 0;
	for (int i = 0; i < x.length(); i++) {
		if (!isVowel(x[i])&&toupper(x[i])>='B' && toupper(x[i]) <= 'N') {
			temp += x.substr(i, 1);
			temp+= 'x';
			count++;
		}
		else if(!isVowel(x[i]) && toupper(x[i]) >= 'P' && toupper(x[i]) <= 'Z') {
			temp += 'X';
			temp += x.substr(i, 1);
			count++;
		}
		else {
			temp += x.substr(i, 1);
		}
	}
	x = temp;
	return count;
}
int changePunct(string& x) {
	string temp = "";
	int count = 0;
	for (int i = 0; i < x.length(); i++) {
		if (ispunct(x[i])) {
			temp += to_string(int(x[i]));
			count++;
		}
		else {
			temp += x.substr(i, 1);
		}
	}
	x = temp;
	return count;
}
string everyThird(string& x) {
	string temp = "";
	for (int i = 0; i < x.length(); i+=3) {
			temp += x[i];
	}
	return temp;
}