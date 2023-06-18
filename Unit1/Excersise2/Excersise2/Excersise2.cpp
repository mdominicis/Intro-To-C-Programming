#include <iostream> //for input/output
#include <string> //for strings

using namespace std;

int main()
{
	cout << "#############################################################" << endl;
	cout << "#                 \t_                                      #\n";
	cout << "#                  -=\\`\\                                    #" << endl;
	cout << "#              |\\ ____\\_\\__                                 #" << endl;
	cout << "#            -=\\c`\"\"\"\"\"\"\" \"`)                               #" << endl;
	cout << "#               `~~~~~/ /~~`\                                #" << endl;
	cout << "#                 -==/ /                                    #" << endl;
	cout << "#                   '-'                                     #" << endl;
	cout << "#                  _  _                                     #" << endl;
	cout << "#                 ( `   )_                                  #" << endl;
	cout << "#                (    )    `)                               #" << endl;
	cout << "#              (_   (_ .  _) _)                             #" << endl;
	cout << "#                                             _             #" << endl;
	cout << "#                                            (  )           #" << endl;
	cout << "#             _ .                         ( `  ) . )        #" << endl;
	cout << "#           (  _ )_                      (_, _(  ,_)_)      #" << endl;
	cout << "#         (_  _(_ ,)                                        #" << endl;
	cout << "#############################################################" << endl;
    string x;
    cout << "Please enter a one word name for my picture.";
    cin >> x;
    char m = 'M';
    char a = 'a';
    char t = 't';
    char h = 'h';
    char e = 'e';
    char w = 'w';
	char d = 'D';
	char o = 'o';
	char i = 'i';
	char n = 'n';
	char c = 'c';
	char s = 's';
	cout << m << "\t" << int(m) << endl;
	cout << a << "\t" << int(a) << endl;
	cout << t << "\t" << int(t) << endl;
	cout << t << "\t" << int(t) << endl;
	cout << h << "\t" << int(h) << endl;
	cout << e << "\t" << int(e) << endl;
	cout << w << "\t" << int(w) << endl;
	cout << d << "\t" << int(d) << endl;
	cout << o << "\t" << int(o) << endl;
	cout << m << "\t" << int(m) << endl;
	cout << i << "\t" << int(i) << endl;
	cout << n << "\t" << int(n) << endl;
	cout << i << "\t" << int(i) << endl;
	cout << c << "\t" << int(c) << endl;
	cout << i << "\t" << int(i) << endl;
	cout << s << "\t" << int(s) << endl;
	int age;
	double salary;
	cout << "How old are you?";
	cin >> age;
	cout << "What is your salary?";
	cin >> salary;
	double sal2 = salary + salary * 0.01 * age;
	cout << "If your age was a percent increase to your salary you would make: $" << sal2;
    return 0;
}


