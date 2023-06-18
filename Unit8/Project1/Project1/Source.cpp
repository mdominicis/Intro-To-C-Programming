#include <iostream>
#include <vector>
#include <string>

using namespace std;

//overloaded fill functions (same name and return type, but different parameters)
void fill(vector <int>&); //pass by reference because we are changing the vector
void fill(vector <string>&);


template<typename any>
void display(vector <any> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl << endl;
}

int main()
{
	vector <int> v1(8); //size=8
	vector <string> v2(3); //size=3
	vector <double> v3(6, 2.5); //size=6, all elements are 2.5

	fill(v1);
	display(v1);

	fill(v2);
	display(v2);

	display(v3);


	return 0;
}

void fill(vector <int>& v) //fill v with random ints from 1-10
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = rand() % 10 + 1;
	}
}
void fill(vector <string>& v) //ask the user for strings
{
	cout << "Enter strings:\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Enter element #" << (i + 1) << ": ";
		getline(cin, v[i]);
	}
}

