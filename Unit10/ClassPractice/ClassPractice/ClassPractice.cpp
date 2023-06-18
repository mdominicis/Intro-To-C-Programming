#include "point.h"
#include <iostream>
using namespace std;
int main()
{
    point p1;    
    int x = 0, y = 0;
    cout << "Enter an x coordinate (integer): ";
    cin >> x;
    cout << "Enter a y coordinate (integer): ";
    cin >> y;
    point p2(x, y);
    cout << "Point 1: (" << p1.getX() << ", " << p1.getY() << ")" << endl;
    cout << "Point 2: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
    cout << "Moving point 2 and resetting point 1...." << endl;
    p2.moveHor(-3);     
    p2.moveVer(-1);
    p1.setX(-5); 
    p1.setY(8); 
    cout << "Point 1: (" << p1.getX() << ", " << p1.getY() << ")" << endl;
    cout << "Point 2: (" << p2.getX() << ", " << p2.getY() << ")" << endl;
    return 0;
}