#define _CRTDBG_MAP_ALLOC   
#include <crtdbg.h>  
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct card
{
	string title;
	card* next;
};
void addcard();
void removecard();
void split();
int getCount();
void print();
void deletelast();

card* headptr = NULL;
card* currptr = NULL;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char ans = ' ';
	while (ans != '6')
	{
		int x; //for counting cards
		cout << "\n\n1. Add a card.\n2. Remove a card.\n3. Print cards.\n4. Count cards.\n5. Split collection.\n6. Exit\n";
		cin >> ans;
		cin.ignore(100, '\n');
		switch (ans)
		{
		case '1':
			addcard();
			break;
		case '2':
			removecard();
			break;
		case '3':
			print();
			break;
		case '4':
			x = getCount();
			cout << "You have " << x << " cards in your collection.\n";
			break;
		case '5':
			split();
			break;
		case '6':
			while (headptr != NULL)
				deletelast();
			cout << "Press enter to continue...";
			cin.get();
			break;
		default:
			cout << "Invalid choice!\n";
		}
	}
	return 0;
}
void addcard() //inserts new card in alphabetical order
{
	char c = 'y';
	while (c == 'y' || c == 'Y')
	{
		string n;
		bool isinlist = false;
		cout << "Enter the name of your new card: ";
		getline(cin, n);
		//Create new card and set title to n and next to NULL
		//Make sure currptr starts at headptr
		card* x = new card;
		x->title = n;
		x->next = NULL;
		currptr = headptr;
		if (headptr != NULL)
		{
			if (headptr->title > x->title) {
				x->next = headptr;
				headptr = x;
			}
			else {
				while (currptr->next != NULL) {
					if (currptr->next->title > x->title) {
						x->next = currptr->next;
						currptr->next = x;
						isinlist = true;
						break;
					}
					currptr = currptr->next;
				}
				if (isinlist == false) {
					currptr->next = x;
				}
			}
		}
		else
			headptr = x;
		/*
		4 Cases:
			--list is empty, set headptr to new card
			--the new card belongs at the beginning of the list
			--card belongs in the middle
			--card belongs at the end--I suggest using a bool variable initialized to false,
			  set it to true if the card is inserted somewhere, if it's still false at the end
			  it belongs at the end of the list
		*/

		cout << "Would you like to enter another card (y/n)? ";
		cin >> c;
		cin.ignore(100, '\n');
	}
}
void removecard() //deletes card entered by user, print message if list is empty or the card is not in the collection 
{
	card* precurrptr = headptr; //will hold node that is before the currptr (for case 3)
	currptr = headptr; //Make sure currptr starts at headptr
	string title;
	bool found = false; //set to true if card is found
	cout << "Which card do you want to delete? ";
	cin >> title;
	if (headptr != NULL) {
		if (currptr->title == title) {
			headptr=headptr->next;
			delete currptr;
			currptr = headptr;
		}
		else{
			while (currptr->next != NULL&&currptr->next->title!=title) {
				precurrptr = currptr;
				currptr = currptr->next;
			}
			currptr->next=NULL;
			currptr = precurrptr;
		}
		cout << title << " was deleted.";
	}
	else {
		cout << "List is empty or card is not found!";
	}
	/*
		3 cases:
			--the list is empty
			--the first node is to be deleted
			--the node to be deleted is in the middle or at the end
			  set precurrptr to currptr before moving currptr for each iteration

			At the end, if the card is found, set the next pointer of the card before currptr
			to the next pointer of currptr and deallocate currptr
	*/
}
void split() //deletes second half of collection--calls deleteLast() count/2 times, gives message if no cards or only one card, print all cards at the end
{
	currptr = headptr;
	if (currptr != NULL && currptr->next != NULL) {
		//Make sure currptr starts at headptr
		int count = 0;
		while (currptr != NULL) {
			currptr = currptr->next;
			count++;
		}
		for (int i = 0; i < count / 2; i++) {
			deletelast();
		}
		print();
	}
	else {
		cout << "No cards or only 1 card!";
	}
}
int getCount() //returns the number of cards 
{
	currptr = headptr;
	//Make sure currptr starts at headptr
	int count = 0;

	while (currptr != NULL){
		currptr = currptr->next;
		count++;
	}



	return count;
}
void print() //print list (use schools as an example), prints a message if list is empty
{
	//Make sure currptr starts at headptr
	cout << endl << endl;
	cout << "Pokemon Cards:" << endl;
	if (headptr != NULL) //if the list is not empty
	{
		currptr = headptr; //currentptr needs to start at the beginning
		int x = 0;
		do
		{
			x++;
			cout << x <<". " << currptr->title<< endl;
			currptr = currptr->next; //move through list
		} while (currptr != NULL); //stop when you have gone through the whole list
	}
	else
		cout << "There are no cards to print!" << endl << endl;
}
void deletelast() //deletes last card (use schools as an example), do nothing if list is empty
{
	//Make sure currptr starts at headptr

	if (headptr == NULL) //list is empty
	{
		cout << "There are no cards to delete!\n";
		return; //end function
	}
	currptr = headptr; //currentptr needs to start at the beginning
	if (headptr->next == NULL) //if ONE item is in the list
	{
		delete headptr; //empty the list by deallocating memory for headptr
		headptr = NULL;
	}
	else
	{
		while (currptr->next->next != NULL) //go until you are on second to last node
		{
			currptr = currptr->next;
		}
		delete currptr->next; //deallocate memory for last node
		currptr->next = NULL; //make new last node point to NULL
	}


}