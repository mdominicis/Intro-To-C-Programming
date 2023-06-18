#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void print(vector <int> v);
vector <int>process(vector<int> v);

int main() {
	vector <int>v;
	ifstream fin;
	fin.open("nums.txt");
	char num;
	while (!fin.eof()) {
		fin.get(num);
		if (isdigit(num))
		{
			v.push_back(num-48);
		}
		else if (num == '|') {
			fin.ignore(100, '\n');
			print(process(v));
			v.resize(0);
		}
		
	}
	fin.close();
}
void print(vector <int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";
	}
	cout << endl << endl;
}
vector <int> process(vector<int> v) {
	vector <int>temp;
	int counter=0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v.at(i) != 0) {
			temp.push_back(v.at(i));
			i++;
		}
		else {
			counter++;
		}

	}
	for (int i = 0; i < counter; i++) {
		temp.push_back(0);
	}
	return temp;
}