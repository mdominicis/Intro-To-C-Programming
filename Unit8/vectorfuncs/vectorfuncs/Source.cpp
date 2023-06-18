#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//overloaded fill functions (same name and return type, but different parameters)
void fill(vector <int>&); //pass by reference because we are changing the vector
void fill(ifstream&, vector <string>&); //takes an input file stream variable (fin) as a parameter
vector <int> getInts(); //returns a vector (not possible with arrays)
vector <int> findHigh(int[], int);  //returns a vector that holds all elements of an array (size=6) that are higher than the int parameter


template<typename any>
void display(vector <any> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v.at(i) << " ";  //could also do v[i];
	}
	cout << endl << endl;
}

int main()
{
	vector <int> v1; //size=0
	vector <string> v2;
	vector <int> v3;
	int a[] = { 3, 6, 2, 10, 7, 1 };


	cout << "How many integers do you want to enter? ";
	int n;
	cin >> n;
	v1.resize(n); //resizes to n
	fill(v1);
	display(v1);
	cout << "First element: " << v1.front() << endl; //OR v1[0]
	cout << "Last element: " << v1.back() << endl; //OR v1[v1.size()-1]
	v1.pop_back(); //delete last element, OR v1.resize(v1.size()-1);
	cout << "Last element: " << v1.back() << endl;

	ifstream fin;
	fin.open("dogs.txt");
	fill(fin, v2);
	display(v2);

	v3 = getInts();
	display(v3);

	vector <int> v4 = findHigh(a, 5);
	display(v4);




	return 0;
}

void fill(vector <int>& v)
{
	cout << "Enter integers:\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << "Enter element #" << (i + 1) << ": ";
		cin >> v[i];
	}
}

void fill(ifstream& fin, vector <string>& v)
{
	while (!fin.eof())
	{
		string dog;
		getline(fin, dog);
		v.push_back(dog); //adds dog to end of the vector
	}

}
vector <int> getInts()
{
	cout << "Enter integers.  Type q to quit.\n";
	vector <int> v;
	char ch;
	cin.get(ch);
	while (ch != 'q')
	{
		if (isdigit(ch))
		{
			cin.putback(ch); //put it back if it's a number
			int x;
			cin >> x;
			v.push_back(x);
		}
		cin.get(ch);
	}
	return v;
}
vector <int> findHigh(int arr[], int high)
{
	vector <int> v;
	for (int i = 0; i < 6; i++)
	{
		if (arr[i] > high)
		{
			v.push_back(arr[i]);
		}
	}
	return v;
}