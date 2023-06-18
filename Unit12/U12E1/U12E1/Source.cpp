#define _CRTDBG_MAP_ALLOC //to check for memory leaks

#include <crtdbg.h>  //to check for memory leaks
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct school
{
	string sname;   //name of school
	string mascot;  //mascot
	school* next;   //link to next node... next school on the list!
};

//global pointer variables
school* headptr = NULL;    //pointer to head of the list
school* currentptr = NULL;  //pointer to current node

void addschool(string); //adds school to the end of the list
void printall(); //prints list of schools
school* search(string, int&);//searches for school, school name is first parameter, second parameter is position in the list (starting at 1), returns NULL if school not found
void removeLast(); //removes last school in the list


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); //checks for memory leaks after program is over (in the output window)
	string look4 = ""; //for search
	school* r = NULL; //for search
	string n = ""; //for add
	int pos = 0; //for search
	char c = 0; //user's choice
	while (c != '5')
	{
		cout << "\n------Welcome to my linked list of high schools!-------"
			<< "\n\nPlease enter the number of your choice:\n"
			<< "1. Add schools\n2. Delete last school\n3. Search for a school \n4. Print all schools \n5. Exit\n\n";
		cin >> c;
		cin.ignore(100, '\n');
		currentptr = headptr; //make sure currptr starts at the beginning

		switch (c)
		{
		case '1':

			do
			{
				cout << "Enter name of school. Leave school name blank to stop.";
				getline(cin, n);
				if (n != "")
					addschool(n);
			} while (n != "");
			break;
		case '2':
			removeLast();
			break;
		case '3':
			pos = 0; //start position at 0
			if (headptr == NULL) //list is empty
				cout << "The list is empty!  Nothing to search for!";
			else
			{
				do
				{
					cout << "What school are you looking for?" << endl;
					getline(cin, look4);
				} while (look4 == "");

				//r points to the school being searched for
				//r will be null if the school is not in the list.
				r = search(look4, pos); //pos holds position of returned school (starting at 1)
				if (r != NULL)
				{
					cout << "School found at position: " << pos << endl;
					cout << pos << ". " << setw(33) << r->sname << setw(25) << r->mascot << endl;
				}
				else
					cout << "Sorry - that school is not on the list!" << endl;
			}
			break;
		case '4':
			printall();
			break;
		case '5':
			//Clear the linked list or memory leaks will show up
			while (headptr != NULL)
				removeLast(); //keep removing from end until headptr=NULL.
			cout << "Press enter to continue...";
			cin.get();
			break;
		default:
			cout << "Error!  Try again...\n\n";
		};
	}
	return 0;
}


void addschool(string x)
{
	school* newschool = new school; //create a pointer to a new school
	//set name and mascot (using ->)
	newschool->sname = x;
	cout << "School mascot? ";
	getline(cin, newschool->mascot);
	newschool->next = NULL; //this node will go at the end of the list, so the next pointer must point to NULL
	currentptr = headptr;//set currentptr to beginning of list
	if (headptr != NULL) //if the list is not empty
	{
		while (currentptr->next != NULL) //stop when at the last node
			currentptr = currentptr->next; //moves the currentptr through the list
		currentptr->next = newschool;  //new node is added to the end of the list
	}
	else //if list is empty, then headptr should point to the new node
		headptr = newschool;
}

void removeLast()
{

	if (headptr == NULL) //list is empty
	{
		cout << "There are no schools to delete!\n";
		return; //end function
	}
	currentptr = headptr; //currentptr needs to start at the beginning
	if (headptr->next == NULL) //if ONE item is in the list
	{
		delete headptr; //empty the list by deallocating memory for headptr
		headptr = NULL;
	}
	else
	{
		while (currentptr->next->next != NULL) //go until you are on second to last node
		{
			currentptr = currentptr->next;
		}
		delete currentptr->next; //deallocate memory for last node
		currentptr->next = NULL; //make new last node point to NULL
	}

}
void printall()
{

	if (headptr != NULL) //if the list is not empty
	{
		currentptr = headptr; //currentptr needs to start at the beginning
		int x = 0;
		cout << left << setw(35) << "School Name " << setw(25) << "Mascot" << endl;
		cout << setfill('-') << setw(60) << "-" << endl;
		cout << setfill(' ');
		do
		{
			x++;
			cout << x << ". " << setw(32) << currentptr->sname << setw(25) << currentptr->mascot << endl;
			currentptr = currentptr->next; //move through list
		} while (currentptr != NULL); //stop when you have gone through the whole list
	}
	else
		cout << "There are no schools to print!" << endl << endl;
}

school* search(string x, int& y){
	y = 1;
	while(currentptr!=NULL) {
		if (currentptr->sname==x) {
			return currentptr;
		}
		else {
			currentptr = currentptr->next;
			y++;
		}
	}
	return NULL;
}