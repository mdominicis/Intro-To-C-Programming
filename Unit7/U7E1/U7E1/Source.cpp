#include <string>
#include <iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void randint(int[], int);
void readscores(string[], double[]);
void bubble(int arr[], int size);
void heapify(int arr[], int n, int i);
void heap(int arr[], int n);

template<typename t1>
void print(t1 arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "\t";
	}
}
template<typename t2>
t2 findmin(t2 arr[], int size) {
	t2 min = arr[0];
	for (int i = 0; i < size ; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		return min;
	}
}
int main() {
	srand(time(0));
	int arr1[12];
	string arr2[15];
	double arr3[15];
	randint(arr1, 12);
	readscores(arr2, arr3);
	cout << "Array of ints ==> \t";
	print(arr1, 12);
	cout << endl << "Minimum element: " << findmin(arr1, 12)<<endl<<endl;
	cout << "Array of strings ==> \t";
	print(arr2, 15);
	cout << endl << "Minimum element: " << findmin(arr2, 15) << endl<<endl;
	cout << "Array of doubles ==> \t";
	print(arr3, 15);
	cout << endl << "Minimum element: " << findmin(arr3, 15) << endl<<endl;
	int arr4[15];
	int arr5[15];
	randint(arr4, 15);
	randint(arr5, 15);
	cout << "First Array ==> \t";
	print(arr4, 15);
	cout << endl;
	cout << "Second Array ==> \t";
	print(arr5, 15);
	cout << endl;
	bubble(arr4, 15);
	heap(arr5, 15);
	cout << "First Sorted Array Using Bubble Sort ==> \t";
	print(arr4, 15);
	cout <<endl<< "Second Sorted Array Using Heap Sort ==> \t";
	print(arr5, 15);
}

void randint(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100 + 1;
	}
}

void readscores(string arr[], double arr2[]) {
	ifstream fin;
	fin.open("scores.txt");
	for (int i = 0; i < 15; i++) {
		fin >> arr[i];
		fin >> arr2[i];
	}
	fin.close();
}

void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
/*
Bubble sort is very simple because it uses very little memory as there are few things it needs to know. It really only compares the element to its neighbor. The worst case is if the list is in descending order and the best case is when the list is already sorted.
*/
void bubble(int arr[], int size)
{
	for (int i = 0;i<size-1;i++)
		for (int j=0;j<size-i-1;j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

/*Heap sorting is not as efficient but its middle case is better than bubble's middle case. Despite this, its worst case is much faster (when all elements are unsorted) and its best case is about the same (when all elements are sorted)*/
void heapify(int arr[], int n, int i)
{
	int smallest = i;
	int l = 2 * i + 1; 
	int r = 2 * i + 2;

	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(arr[i], arr[smallest]);

		heapify(arr, n, smallest);
	}
}

void heap(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}