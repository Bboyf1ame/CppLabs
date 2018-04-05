#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

class Options
{
public:
	bool gameOver;
	int x, y, fruitX, fruitY, score, tailX, tailY, nTail;
	int k, i, j;
	long width;
	long height;
};

char *buf = new char[255];
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void Setup()
{
	Options function;
	function.gameOver = false;
	function.x = function.width / 2;
	function.y = function.height / 2;
	function.fruitX = rand() % function.width;
	function.fruitY = rand() % function.height;
	function.score = 0;
	dir = STOP;
}
void Draw()
{
	Options function;
	function.gameOver = false;
	function.x = function.width / 2;
	function.y = function.height / 2;
	function.fruitX = rand() % function.width;
	function.fruitY = rand() % function.height;
	function.score = 0;
	system("cls");
	cout << "This Is SNAKEGAME!!!" << endl;
	for (int i = -3; i < function.width; i++)
		cout << "|";
	cout << endl;

	for (int i = 0; i < function.height; i++)
	{
		for (int j = 0; j < function.width; j++)
		{
			if (j == 0)
				cout << "|}";
			if (i == function.y && j == function.x)
				cout << "0";
			else if (i == function.fruitY && j == function.fruitX)
				cout << "@";
			else
			{
				bool print = false;
				for (int k = 0; k < function.nTail; k++)
				{
					if (function.tailX[function.k] == j && function.tailY[function.k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == function.width - 1)
				cout << "{|";
			if (i == function.height - 20 && j == function.width - 1)
			{
				cout << "Твой счет: " << function.score;
			}
			if (i == function.height - 13 && j == function.width - 1)
			{
				cout << "Управление питоном: ";
			}
			if (i == function.height - 12 && j == function.width - 1)
			{
				cout << "W - вверх";
			}
			if (i == function.height - 11 && j == function.width - 1)
			{
				cout << "S - вниз";
			}
			if (i == function.height - 10 && j == function.width - 1)
			{
				cout << "D - вправо";
			}
			if (i == function.height - 9 && j == function.width - 1)
			{
				cout << "A - влево";
			}
			if (i == function.height - 8 && j == function.width - 1)
			{
				cout << "Внимание! Питон чувствует только ";
			}
			if (i == function.height - 7 && j == function.width - 1)
			{
				cout << "английскую раскладку.";
			}
		}
		cout << endl;
	}
	for (int i = -2; i < function.width + 2; i++)
		cout << "|";
}
void Input()
{
	Options function;
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			function.gameOver = true;
			break;
		case 'p':
			system("cls");
			cout << "Ты в режиме Паузы" << endl;
			cout << endl << "Твой счет: " << function.score << endl;
			cout << endl << "Нажми любую клавишу, чтобы продолжить..." << endl;
			_getch();
			break;
		}
	}
}
void Logic()
{
	Options function;
	int prevX = function.tailX[0];
	int prevY = function.tailY[0];
	int prev2X, prev2Y;
	function.tailX[0] = function.x;
	function.tailY[0] = function.y;
	for (int i = 1; i < function.nTail; i++)
	{
		prev2X = function.tailX[function.i];
		prev2Y = function.tailY[function.i];
		function.tailX[function.i] = prevX;
		function.tailY[function.i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		function.x--;
		break;
	case RIGHT:
		function.x++;
		break;
	case UP:
		function.y--;
		break;
	case DOWN:
		function.y++;
		break;
	default:
		break;
	}
	if (function.x > function.width - 1 || function.x < 0 || function.y > function.height - 1 || y < 0)
	{
		system("cls");
		cout << "Поражение!" << endl;
		cout << endl << "Твой счет: " << function.score << endl << endl;
		function.gameOver = true;
		system("pause");
	}
	for (int i = 0; i < function.nTail; i++)
		if (function.tailX[function.i] == function.x && function.tailY[function.i] == y)
		{
			system("cls");
			cout << "Поражение!" << endl;
			cout << endl << "Твой счет: " << function.score << endl << endl;
			function.gameOver = true;
			system("pause");
		}

	if (function.x == function.fruitX && y == function.fruitY)
	{
		function.score += 10;
		function.fruitX = rand() % function.width;
		function.fruitY = rand() % function.height;
		function.nTail++;
	}
}
void Achievements()
{
	cout << endl << "Введи свое имя: " << endl;
	cin.getline(buf, 255);
	ofstream ach("achievements.txt", ios::app);
	ach << buf << "  " << function.score << endl;
	ach.close();
}
int main()
{
	Options function;
	setlocale(LC_ALL, "Russian");
	Setup();
	while (!function.gameOver)
	{
		Draw();
		Sleep(30);
		Input();
		Logic();
	}
	Achievements();
	system("cls");
	cout << "Таблица рекордов:" << endl << endl;
	ifstream ach("achievements.txt");
	while (!ach.eof())
	{
		ach.getline(buf, 255);
		cout << buf << endl << endl;
	}
	_getch();
	ach.close();

	return 0;
	delete[] buf;
}