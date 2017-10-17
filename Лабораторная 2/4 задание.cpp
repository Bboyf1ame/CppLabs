#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int n;
	cout << "¬ведите размер квадратной матрицы nxn: ";
	cin >> n;
	cout << "¬ведите массив: \n";
	int** mas = new int*[n];
	for (int i = 0; i < n; i++)
	{
		mas[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			cin >> mas[i][j];
		}
	}
	int* sum = new int[n];
	for (int i = 0; i < n; i++)
		sum[i] = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum[i] += mas[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum[i] += mas[j][i];
		}
	}
	for (int i = 0; i < n; i++)
		sum[i] += mas[i][i];
	for (int i = 0; i < n; i++)
	{
		cout << sum[i] << " ";
	}
	system("pause");
	return 0;
}