#include"chapter6_pointer.h"
int get_str_length(char *p)
{
	char *temp = p;
	while (*p++);
	p--;
	return p - temp;
}