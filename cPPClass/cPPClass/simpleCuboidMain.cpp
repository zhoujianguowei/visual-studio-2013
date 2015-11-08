#include"cPPClass.h"
template<class T>
class CompareTemplate
{
public:
	T getMin()
	{
		return a > b ? b : a;
	}
	T getMax()
	{
		return a > b ? a : b;
	}
	CompareTemplate(T ah, T bh)
	{
		a = ah;
		b = bh;
	}
private:
	T a, b;
};
int main()
{
	/*int i = 0;

	Cuboid cuboid1(10, 20, 2.5);
	Cuboid cuboid2 = cuboid1;
	cuboid1.setLength(15);
	cout << "cuboid1.length=" << cuboid1.getLength() << "  cuboid2.length=" << cuboid2.getLength();
*/
	/*cuboid.setConfiguration();
	cout << (i + 1) << ": volume=" << cuboid.getVolume();*/
	/*CompareTemplate<int> compare(10, 8);
	cout << "max:" << compare.getMax() << " min:" << compare.getMin() << endl;
	CompareTemplate<double> acury(2.7, 5.8);
	cout << "double min:" << acury.getMin();*/
	Date date(2015, 10, 15);
	Time time;
	time.display(date);

	return 0;
}