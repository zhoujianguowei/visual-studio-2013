#include"chapter4.h"
//#define UPPPER 1;
using namespace std;
#define CHANGE 0

int main()
{

	/*int a, b;
	cin >> a >> b;

	int maxchild = getMaxChild(a, b);
	int minparent = getMinParent(a, b);
	cout << "child=" << maxchild<<" parent=" << minparent<<"\n";*/

	/*int a, b, c;
	cin >> a >> b >> c;
	cout << (getFac(a) + getFac(b) + getFac(c)) << endl;
	return 0;*/
	//hanoi(8, 'A', 'B', 'C');
	char str[] = "nice day and good";
#ifdef CHANGE
	if (CHANGE == 0)
		encryption(0, str);
	else
		encryption(1, str);
#endif
	

}


