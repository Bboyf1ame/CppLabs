#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

bool gameOver;
const long width = 70;
const long height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
char *buf = new char[255];
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
void Draw()
{
	system("cls");
	cout << "This Is SNAKEGAME!!!" << endl;
	for (int i = -3; i < width; i++)
		cout << "|";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "|}";
			if (i == y && j == x)
				cout << "0";
			else if (i == fruitY && j == fruitX)
				cout << "@";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "o";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
			if (j == width - 1)
				cout << "{|";
			if (i == height - 20 && j == width - 1)
			{
				cout << "Твой счет: " << score;
			}
			if (i == height - 13 && j == width - 1)
			{
				cout << "Управление питоном: ";
			}
			if (i == height - 12 && j == width - 1)
			{
				cout << "W - вверх";
			}
			if (i == height - 11 && j == width - 1)
			{
				cout << "S - вниз";
			}
			if (i == height - 10 && j == width - 1)
			{
				cout << "D - вправо";
			}
			if (i == height - 9 && j == width - 1)
			{
				cout << "A - влево";
			}
			if (i == height - 8 && j == width - 1)
			{
				cout << "Внимание! Питон чувствует только ";
			}
			if (i == height - 7 && j == width - 1)
			{
				cout << "английскую раскладку.";
			}
		}
		cout << endl;
	}
	for (int i = -2; i < width + 2; i++)
		cout << "|";
}
void Input()
{
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
			gameOver = true;
			break;
		case 'p':
			system("cls");
			cout << "Ты в режиме Паузы" << endl;
			cout << endl << "Твой счет: " << score << endl;
			cout << endl << "Нажми любую клавишу, чтобы продолжить..." << endl;
			_getch();
			break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	if (x > width - 1 || x < 0 || y > height - 1 || y < 0)
	{
		system("cls");
		cout << "Поражение!" << endl;
		cout << endl << "Твой счет: " << score << endl << endl;
		gameOver = true;
		system("pause");
	}
	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
		{
			system("cls");
			cout << "Поражение!" << endl;
			cout << endl << "Твой счет: " << score << endl << endl;
			gameOver = true;
			system("pause");
		}

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
void Achievements()
{
	cout << endl << "Введи свое имя: " << endl;
	cin.getline(buf, 255);
	ofstream ach("achievements.txt", ios::app);
	ach << buf << "  " << score << endl;
	ach.close();
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Setup();
	while (!gameOver)
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