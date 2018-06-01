#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int n = 9;
	int m = n;
	int sum = 0;
	int** mas = new int*[n];
	cout << "Изначальная матрица: " << endl << endl;
	for (int i = 1; i <= n; i++)
	{
		mas[i] = new int[m];
		for (int j = 1; j <= m; j++)
		{
			mas[i][j] = 0 + rand() % 50;
			if (mas[i][j] < 10)
			{
				cout << mas[i][j] << "   ";
			}
			else
			{
				cout << mas[i][j] << "  ";
			}
			if (j == m)
			{
				cout << endl;
			}
		}
	}
	cout << endl << "Новая матрица: " << endl << endl;
	short a = 9;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum += mas[j][i];
		}

		for (int k = 1; k <= m; k++)
		{
			sum += mas[a][k];
		}
		sum -= mas[a][i];
		mas[a][i] = sum;
		a--;
		sum = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mas[i][j] < 10)
			{
				cout << mas[i][j] << "   ";
			}
			else if (mas[i][j] < 100 && mas[i][j] >= 10)
			{
				cout << mas[i][j] << "  ";
			}
			else if (mas[i][j] >= 100)
			{
				cout << mas[i][j] << " ";
			}
			if (j == m)
			{
				cout << endl;
			}
		}
	}

	system("pause");
	return 0;
}