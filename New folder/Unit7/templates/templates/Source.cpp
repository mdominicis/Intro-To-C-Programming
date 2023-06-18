#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>

using namespace std;

void fill(int[], int size);



//You must put the definitions of template functions here-->No prototypes!

template<typename any>
void print(any arr[], int size) //"any" stands for any data type
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}

template<typename what>
what maximum(what arr[], int size)
{
	what max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}

template<typename dupe>
bool licate(dupe arr[], int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (arr[j] == arr[i]) {
				return true;
			}
		}
	}
	return false;
}

int main()
{
	srand(time(0));
	int nums[] = {2,5,3,8,1,2,7,5,0};
	string names[5] = { "William", "Bill", "Billy", "Mac", "Buddy" };
	double decis[6] = { 7.2, 8.3 }; //decis[0]=7.2, decis[1]=8.3, decis[2-5]=0.0

	print(nums, 7);
	print(names, 5);
	print(decis, 6);

	cout << "Maximum of nums: " << maximum(nums, 7) << endl;
	cout << "Maximum of names: " << maximum(names, 5) << endl;
	cout << "Maximum of decis: " << maximum(decis, 6) << endl;
	cout << licate(nums, 7) << endl;
	cout << licate(names, 5) << endl;
	cout << licate(decis, 6) << endl;

	return 0;
}

void fill(int arr[], int size)
{
	//set array to random values from 1-50
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50 + 1;
	}
}
