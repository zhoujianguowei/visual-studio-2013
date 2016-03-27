#define _CRT_SECURE_NO_WARNINGS
#include"fond.h"
void bigEndianGet(FILE *bFile)
{
	if (bFile == NULL)
	{
		cout << "no such file\n";
		return;
	}
	bFile = fopen("d:\\binary.bin", "rb");
	int ch;
	vector<int> biCharSet;
	int readCount = 0;
	while ((ch=fgetc(bFile))!=EOF)
	{
		//cout << ch << endl;
		biCharSet.push_back(ch);
		readCount++;
		readCount = readCount % 8;
		if (readCount == 0)
		{
			cout << (char)transferBiCharToAsi(biCharSet);
			biCharSet.clear();
		}
	}


}
void bigEndianPut(FILE *file)
{
	if (file == NULL)
	{
		cout << "no such file\n";
		return;
	}
	FILE *newFile = fopen("d:\\binary.bin", "wb+");
	int buffer[8];
	int ch, i;
	while ((ch = fgetc(file)) != EOF)
	{
		vector<int> biCharSet = transferAsiToBiChar(ch);
		/*for (i = 0; i < biCharSet.size(); i++)
			buffer[i] = biCharSet.at(i);
			fwrite(buffer, sizeof(unsigned char), 8, newFile);*/
		i = 0;
		while (i < biCharSet.size())
		{
			fputc(biCharSet.at(i), newFile);
			i++;
		}
	}
	//fflush(newFile);
	fclose(file);
	fclose(newFile);
}
int transferBiCharToAsi(vector<int> biCharSet)
{
	if (biCharSet.size() != 8)
	{
		cout << "cann't convert ,the biCharSet's size must be 8" << endl;
		exit(1);
	}
	int asi = 0;
	int i = 0;
	while (i < biCharSet.size())
	{
		asi = asi * 2 + biCharSet.at(i) - '0';
		i++;
	}
	return asi;
}
vector<int> transferAsiToBinary(int asi)
{
	vector<int> byteSet;
	if (asi < 0 || asi>257)
	{
		cout << "wrong asi " << endl;
		exit(1);
	}
	stack<int> stackSet;
	int i = asi;
	while (i > 0)
	{
		stackSet.push(i % 2);
		i = i / 2;
	}
	int size = stackSet.size();
	while (size++ < 8)
	{
		byteSet.push_back(0);
	}
	while (!stackSet.empty())
	{
		i = stackSet.top();
		byteSet.push_back(i);
		stackSet.pop();
	}
	return byteSet;
}
vector<int> transferAsiToBiChar(int asi)
{
	vector<int> byteSet = transferAsiToBinary(asi);
	vector<int> biCharSet;
	int i, bi;
	for (i = 0; i < byteSet.size(); i++)
	{
		bi = byteSet.at(i);
		biCharSet.push_back(bi + '0');
	}
	return biCharSet;
}