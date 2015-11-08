#include"chapter6_pointer.h"
double get_sqrt(int n)
{
	double a=1, b=n;
	double middle;
	if (n <= 0)
		return 0; 
	while (b-a>0.001)
	{
		middle = (a + b) / 2;
		if (middle*middle > n)
			b = middle;
		else
			a = middle;

	}
	return (a + b) / 2;
}