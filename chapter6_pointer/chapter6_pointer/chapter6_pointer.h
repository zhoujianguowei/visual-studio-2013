#include<cmath>
#include<iostream>
#include<iomanip>
#include<new.h>
//#include<>
using namespace std;
void integer_sort(int, int, int);
void change(int&, int &);
void change_value(int*, int*);
int get_str_length(char*);
double get_sqrt(int);
struct NODE
{
	int data;
	struct NODE *next;
};
NODE *create(int*, int);
void print(NODE*);
void del(NODE*, int);
void free(NODE*);
