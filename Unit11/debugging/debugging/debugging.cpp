//For diagnostic tools, go to Debug->Windows->Show Diagnostic Tools
//Click in the grey bar on the left to add a break point.
#include <iostream>
#include <string>

using namespace std;

struct person
{
	string name;
	int age;

};

int main()
{




	//This is just a simple loop to show you how the debugger works.
	int sum = 0;
	int i = 0;
	for (i = 0; i < 5; i++)
		sum += i;


	int x = 8;
	int* p = &x;
	*p = 3;
	int* q = new int; //points q to a new memory slot in the heap
	*q = 7;
	delete q; //prevents memory leakage
	q = NULL; //Makes sure q is no longer pointing to anything.  Technically, this line is not needed here because we immediately allocate new memory to q.  However, many programmers think that it is a sin to leave it out.

	q = new int; //points q to a new memory slot in the heap
	*q = 9;

	q = new int;  //causes memory leak, never deallocated old memory
	*q = 11;

	delete q;
	q = NULL;


	person* guy = new person;
	guy->name = "Kevin";
	guy->age = 18;
	cout << "Person info:\nName: " << guy->name << "\nAge: " << guy->age << endl;
	delete guy; //free memory 
	guy = NULL; //set guy to point to nothing


	//If you look at the heap at the end, there is still one integer in there because we didn't deallocate q that one time!

	return 0;
}
