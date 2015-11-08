//#include<cppClass.h>
#include"cPPClass.h"
void Cuboid::setConfiguration()
{
	/*this.length = length;
	this.width = width;
	this.height = height;*/
	cin >> length >> width >> height;
}
double Cuboid::getVolume()
{
	return length*width*height;
}
int Cuboid::getLength()
{
	return length;
}