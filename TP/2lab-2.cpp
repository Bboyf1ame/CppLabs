#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	bool s = false;
	srand(time(NULL));
	int c = 1 + rand() % 1000;
	int a;
	cout << "��������� ������� ����� �� 1 �� 1000, �������� ��� �������. � ���� ���� ��� �������. �������!" << endl;
	for (int i = 1; i < 4; i++)
	{
		cin >> a;
		if (c > a)
		{
			cout << "���� ����� ������ �����������. ������ ��� ���!" << endl;
			continue;
		}
		if (c < a)
		{
			cout << "���� ����� ������ �����������. ������ ��� ���!" << endl;
			continue;
		}
		if (c == a)
		{
			cout << "�� ��� �� � ������ �����. �  " << i << "-�� �������! " << "����� = " << c << endl;
			s = true;
			break;
		}

	}
	if (s == false)
	{
		cout << endl << "����, �� �� �� ������. ���������� ����� = " << c << endl << endl;
	}
	system("pause");
	return 0;
}