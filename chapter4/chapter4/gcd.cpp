int getMaxChild(int a, int b)
{
	int temp = a, child = 1;
	if (a < b)
	{
		a = b;
		b = temp;
	}
	while (b != 0)
	{
		temp = b;
		b = a%b;
		a = temp;

	}
	return a;


}
int getMinParent(int a, int b)
{
	int child = getMaxChild(a, b);
	return child*(a / child)*(b / child);

}