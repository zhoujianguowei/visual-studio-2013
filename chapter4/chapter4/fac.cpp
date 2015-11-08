long getFac(int n)
{
	long mulRes = 1;
	if (n == 0)
		mulRes = 1;
	else
	{
		for (int i = 1; i <= n; i++)
			mulRes *= i;
	}
	return mulRes;

}