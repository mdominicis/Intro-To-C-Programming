#pragma once
class point
{
public:
    point();
    point(int, int);
    void setX(int);
    void setY(int);
    int getX();
    int getY();
    void moveHor(int);
    void moveVer(int);
private:
    int myX;
    int myY;
};