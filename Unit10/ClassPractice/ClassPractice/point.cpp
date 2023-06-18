#include "point.h"
#include <iostream>
using namespace std;

point::point()
{
	myX = 0;
	myY = 0;
}
point::point(int x, int y)
{
	myX = x;
	myY = y;
}
int point::getX()
{
	return myX;
}
int point::getY()
{
	return myY;
}void point::setX(int x)
{
	myX = x;
}
void point::setY(int y)
{
	myY = y;
}
void point::moveHor(int d)
{
	myX += d;
}
void point::moveVer(int d)
{
	myY += d;
}