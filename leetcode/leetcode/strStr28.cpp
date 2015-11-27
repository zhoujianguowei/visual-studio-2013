#include"leetcode.h"
/*
算法复杂度是O(n*m)，可以使用KMP算法来实现，算法复杂度是O(n)
*/
int max(int x, int y)
{
	return x>y ? x : y;
}
int strStr(char* haystack, char* needle)
{
	if (*needle == '\0')
		return 0;
	if (*haystack == '\0')
		return -1;
	int i=0, j;
	int hayLength, needleLength;
	hayLength = strlen(haystack);
	needleLength = strlen(needle);
	if (hayLength<needleLength)
		return -1;
	for (i = 0; i <= hayLength - needleLength; i++)
	{
		j = 0;
		while (needle[j] != '\0'&&haystack[i + j] == needle[j])
			j++;
		if (j == needleLength)
			return i;
	}

	return -1;
}

