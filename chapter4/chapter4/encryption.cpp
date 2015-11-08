#include"chapter4.h"
using namespace std;
void encryption(int change,char* str)
{

	char character;
	if (!change)
	while ((character = *(str++)) != 0)
	{
		cout<< character;
	}
	else
	while ((character = *(str++)) != 0)
	{
		if (character == 'z')
			character = 'a';
		else
		character += 1;
		cout << character;
	}
	cout << endl;

		
}