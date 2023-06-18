#include <iostream> //for input/output
#include <string> //for strings

using namespace std;

int main()
{
    cout << "Hello World!" << endl; //endl ends a line
    cout << "What's up?";

    /*
    Block/multi-line comment
    Escape sequences
    \n-new line
    \t-tab
    \\-backslash
    \"-quotation marks
    */
    cout << "\"Matthew\"\tlikes \\\n";
    cout << "yeah\n";

    /*
    Primative data types
    int - integer (no decimals)
    double - decimals
    char - character (single quotes)
    bool - true/false

    Object Data Type:
    string - set of characters (double quotes)
    */

    string name;
    cout << "What's your first name? ";
    cin >> name; //cin is for console input
    int age;
    cout << "What is your age? ";
    cin >> age;

    cout << "Your name is " << name 
        << ", and you are "
        << age << "years old." << endl;

    char x = 'a'; 
    int y, z;
    double a = 1, b = 0.0;
    string s = "Matthew!";
    return 0;
}


