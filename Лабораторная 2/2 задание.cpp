#include <iostream>
using namespace std;
int main()
{
	setlocale(0, "");
	int n;
	cout << "¬ведите n: ";
	cin >> n;
	cout << "¬ведите массив: \n";
	int* mas = new int[n];
	cin >> mas[0];
	int max = mas[0], min;
	min = max;
	int i1max = 0, i2max;
	for (int i = 1; i < n; i++)
	{
		cin >> mas[i];
		if (mas[i] >= max)
		{
			max = mas[i];
			i2max = i;
		}
		if (mas[i] < min)
		{
			min = mas[i];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (max == mas[i])
		{
			i1max = i;
			break;
		}
	}

	int pr = 1;
	for (int i = 0; i < n; i++)
		if (min == mas[i])
			pr *= min;
	mas[(i2max + i1max) / 2] = pr;
	for (int i = 0; i < n; i++)
		cout << mas[i] << " ";
	system("pause");
	return 0;
}