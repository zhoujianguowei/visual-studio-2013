#include<cstdio>
#include<iostream>
using namespace std;
class Time;
class Date;

class Cuboid
{
private:
	double length;
	double width;
	double height;
public:
	void setConfiguration();
	void setLength(int l)
	{
		length = l;
	}
	int getLength();
	double getVolume();
	Cuboid()
	{

	}
	Cuboid(int l, int w, int h)
	{
		length = l;
		width = w;
		height = h;
	}

};
class Date
{
	friend Time;
public:
	Date(int year, int month, int day) :y(year), m(month), d(day) {}
private:
	int y, m, d;
};
class Time
{
public :
	void display(Date& date)
	{
		cout << date.y << "/" << date.m << "/" << date.d;
	}
};