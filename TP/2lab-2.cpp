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
	cout << "Компуктер загадал число от 1 до 1000, попробуй его угадать. У тебя есть три попытки. Поехали!" << endl;
	for (int i = 1; i < 4; i++)
	{
		cin >> a;
		if (c > a)
		{
			cout << "Ваше число меньше загаданного. Пробуй еще раз!" << endl;
			continue;
		}
		if (c < a)
		{
			cout << "Ваше число больше загаданного. Пробуй еще раз!" << endl;
			continue;
		}
		if (c == a)
		{
			cout << "Ну вот ты и угадал число. С  " << i << "-ой попытки! " << "Ответ = " << c << endl;
			s = true;
			break;
		}

	}
	if (s == false)
	{
		cout << endl << "Жаль, но ты не угадал. Правильный ответ = " << c << endl << endl;
	}
	system("pause");
	return 0;
}