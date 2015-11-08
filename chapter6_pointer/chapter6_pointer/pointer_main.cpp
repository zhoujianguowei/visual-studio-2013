#include"chapter6_pointer.h"

int main()
{
	/*int a, b, c;
	cin>>a >>b>> c;
	integer_sort(a, b, c);
*/
	/*char str[100];
	cin.getline(str, 100);
	cout << get_str_length(str);*/
	//int n;
	//cin >> n;
	//cout << get_sqrt(n) << endl;
	int array[] = { 3, 1, 4, 8, 7 };
	NODE *head = create(array, 5);
	print(head);
	cout << endl;
	del(head, 2);
	cout << endl;
	print(head);
	free(head);


}