#include"chapter5_array.h"
#define MAXNSTU 500
typedef struct student
{
	string name;
	int number;
	unsigned int score;
}STUDENT;
STUDENT students[MAXNSTU];
void student_analize(int n)
{
	int i = 0;
	while (i < n)
	{
		cout << "����ѧ������ ѧ�� �ɼ�"<<endl;
		cin >> students[i].name >> students[i].number >> students[i].score;
		i++;
	}
	cout << "\n" << "�ɼ����ϸ���ѧ�����£�" << endl;
	for (int i = 0; i < n; i++)
	{
		if (students[i].score < 60)
			cout << "������" << students[i].name << "  ѧ�ţ�" << students[i].number << "   �ɼ���" << students[i].score<<endl;
	}
}