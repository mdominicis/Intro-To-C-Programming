#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include<iomanip>

using namespace std;


void print(int[3][5]);//you have to put in the number of columns (the second number)
void shuffle(int[][5]); //shuffle values in the array
string firstLets(string[]);//returns a string that contains the first letter of every string in the array parameter

void print(int[4][6]);
void fill(int[4][6]);//fills array with decreasing odd integers starting at 47

int main()
{
	srand(time(0));

	int x[3][5] =
	{
		{3,7,1,2,4},
		{5,9,2,6,7},
		{2,3,9,4,8}

	}; //rows=3 columns=5
	int y[4][6]; //uninitialized array
	print(x);
	shuffle(x);
	print(x);
	string colors[] = { "red", "green", "blue", "orange", "yellow", "purple" };
	string lets = firstLets(colors);
	cout << lets << endl;
	fill(y);
	print(y);
}
void print(int arr[3][5])
{
	for (int i = 0; i < 3; i++) //goes "rows" times
	{
		for (int j = 0; j < 5; j++) //goes "columns" times
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void shuffle(int arr[][5])
{
	for (int i = 0; i < 100; i++) //100 is just a number I picked
	{
		int row1 = rand() % 3;
		int col1 = rand() % 5;
		int row2 = rand() % 3;
		int col2 = rand() % 5;

		/*
		* Algorithm to switch a and b
			temp=a;
			a=b;
			b=temp;
		*/
		int temp = arr[row1][col1];
		arr[row1][col1] = arr[row2][col2];
		arr[row2][col2] = temp;
	}
}

string firstLets(string str[]) //an array of strings is similar to a 2D array of chars
{
	string s = "";
	for (int i = 0; i < 6; i++)
	{
		s += str[i][0]; //1st char of each string in str
	}
	return s;
}
void print(int arr[4][6]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			cout <<setw(3)<< arr[i][j];
		}
		cout << endl;
	}
}
void fill(int arr[4][6]) {
	int counter = 47;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			arr[i][j] = counter;
			counter -= 2;
		}
	}
}