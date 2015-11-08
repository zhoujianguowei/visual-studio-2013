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
		cout << "输入学生姓名 学号 成绩"<<endl;
		cin >> students[i].name >> students[i].number >> students[i].score;
		i++;
	}
	cout << "\n" << "成绩不合格者学生如下：" << endl;
	for (int i = 0; i < n; i++)
	{
		if (students[i].score < 60)
			cout << "姓名：" << students[i].name << "  学号：" << students[i].number << "   成绩：" << students[i].score<<endl;
	}
}