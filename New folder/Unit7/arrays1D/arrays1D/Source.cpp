#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

//Two overloaded print() methods--need a different one for each array

void print(int[]);
void print(double[]);

//The int array needs to be passed by reference to permanently change it. 
//Arrays are automatically passed by reference!
void fill(int[], int); //The second parameter is for the size so that the function works for any size array 
void print(int[], int); //print function that takes a size parameter

//common algorithms
double average(double[], int);
int maximum(int[], int);

int main()
{
	srand(time(0));
	double decis[] = { 4.5,6.2,7.3,10.4,9.1,5.0 }; //size=6
	int nums1[4]; //uninitialized array, size=4
	int nums2[7] = { 0 }; //intializes all values to 0, size=7
	cout << decis << endl; //Prints out base address of array (memory address of decis[0])

	print(decis);
	print(nums1); //uninitialized-->weird values
	print(nums2);

	fill(nums1, 4);
	fill(nums2, 7);

	print(nums1, 4);
	print(nums2, 7);

	cout << "Average of double array: " << average(decis, 6) << endl;

	cout << "Maximum of nums1: " << maximum(nums1, 4) << endl;
	cout << "Maximum of nums2: " << maximum(nums2, 7) << endl;

	return 0;
};

void print(int a[])
{
	for (int i = 0; i < 7; i++) //do not do a.length or size-->you have to hard code the size
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void print(double a[])
{
	for (int i = 0; i < 6; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void fill(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int num = rand() % 500 + 1; //random int from 1-500
		a[i] = num;
	}
}

void print(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

double average(double a[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}
	return sum / size;
}
int maximum(int arr[], int size)
{

	int max = arr[0]; //always set max/min to first element
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}