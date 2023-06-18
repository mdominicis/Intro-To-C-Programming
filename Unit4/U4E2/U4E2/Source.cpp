#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
int main() {
	int x=0,score=0,total=0;
	ifstream fin;
	ofstream fout;
	string statement,output;
	char tf,correct;
	while (x != 3) {
		cout << "Welcome to T/F." << endl<<"1: Add new T/F statement"<<endl<<"2: Take T/F quiz"<<endl<<"3: Quit."<<endl;
		cin >> x;
		cin.ignore(100, '\n');
		switch (x) {
		case 1:
			fout.open("quiz.txt", ios::app);
			cout << "What T/F statement do you want to add?" << endl;
			getline(cin, statement);
			fout <<endl<< statement << endl;
			cout << "Is this T/F? ";
			cin >> tf;
			switch (tf) {
			case 'T':case't':
				fout << 'T';
				break;
			case 'F':case'f':
				fout << 'F' ;
				break;
			}
			break;
		case 2:
			fin.open("quiz.txt");
			while (fin.eof() == false) {
				getline(fin, output);
				fin >> correct;
				cout<<output<<endl<<"T/F? ";
				cin >> tf;
				cin.ignore(100, '\n');
				fin.ignore(100, '\n');
				switch (tf) {
				case 'T':case't':
					tf = 'T';
					break;
				case 'F':case'f':
					tf = 'F';
					break;
				}
				if (tf == correct) {
					score++;
				}
				cout << (tf == correct ? "Nice!" : "Wrong!") << endl;
				total++;
			}
			cout <<setprecision(1)<<fixed<< "Your score was " << score << "/" << total<<"="<<double(score)/total*100<<"%" << endl;
			break;
		case 3:
			break;
		default:
			cout << "Thats not a valid input. Try again: ";
			cin >> x;
		}
	}
}