#define _CRTDBG_MAP_ALLOC //to check for memory leaks
#include <crtdbg.h>  //to check for memory leaks
#include <iostream>
#include <string>

using namespace std;

//Open output window below. It will state if you have memory leaks with this message:
//"Detected memory leaks!"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memory leaks after program is over

	int* q = new int; //points q to a new memory slot in the heap
	*q = 7;
	delete q; //prevents memory leakage
	q = NULL; //Makes sure q is no longer pointing to anything.

	q = new int; //points q to a new memory slot in the heap
	*q = 9;

	q = new int; //causes memory leakage, never deallocated old memory
	*q = 11;
	delete q;
	q = NULL;

	//Arrays can be declared as pointers!
	//This is called a dynamic array!
	//Example: int *arr = new int[20]; //makes a new array of size 20, allocates memory to the heap
	int size;
	cout << "Enter size of array: ";
	cin >> size; //Remember, C++ doesn't let you put a variable in for the size of an array if you declare it without using a pointer.
	int* arr = new int[size]; //Use a pointer to make an array (dynamic array).
	for (int j = 0; j < size; j++)
	{
		arr[j] = j;
	}
	//*arr refers to the value in the first position (index=0) of the array
	//*(arr+1) refers to second value in the array
	cout << "Array values:\n";
	for (int i = 0; i < size; i++)
	{
		//cout<<arr[i]<<endl; OR
		cout << *(arr + i) << endl;
	}

	delete[] arr; //deallocate memory
	arr = NULL;



	/*while (true)
	{
		int *big = new int[10];
		//delete big; //if you don't delete, there will be memory leakage

	}*/
	return 0;
}
