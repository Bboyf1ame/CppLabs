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
	for (int i = 0; i < n; i++)
		cin >> mas[i];
	int k;
	cout << "\n¬введите k: ";
	cin >> k;
	int* mas2 = new int[n * 3];
	int ind = 0;
	for (int i = 0; i < n; i++)
	{
		if (mas[i] == k)
		{
			mas2[ind] = 0;
			ind++;
			mas2[ind] = k;
			ind++;
			mas2[ind] = 0;
		}
		else
		{
			mas2[ind] = mas[i];
		}
		ind++;
	}
	int ignore;
	for (int i = 1; i < ind - 1; i++)
		if ((mas2[i] - 1) % 2 == 0 && (mas2[i] + 1) % 2 == 0 && mas2[i] % 2 != 0)
		{
			ignore = i;
			break;
		}

	for (int i = 0; i < ind; i++)
	{
		if (i != ignore)
			cout << mas2[i] << " ";
	}
	system("pause");
	return 0;
}
