#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	int sum;

	cout << "Введите сумму: " << endl;

	cin >> sum;

	if (sum != 0)
	{
		int kop;
		kop = sum % 100;
		cout << "Вы потратили: ";
		if (sum >= 100)
		{
			int rub = sum /= 100;
			cout << rub;
			if ((rub < 10 || rub > 20) && rub % 10 == 1)
			{
				cout << " рубль ";
			}
			if ((rub < 10 || rub > 20) && rub % 10 >= 2 && rub % 10 <= 4)
			{
				cout << " рубля ";

			}
			if (rub % 10 >= 5 && rub % 10 <= 9 || rub % 10 == 0 || (rub > 9 && rub < 21))
			{
				cout << " рублей ";
			}
		}
		if (kop != 0)
		{
			cout << kop;
			if ((kop < 10 || kop > 20) && kop % 10 == 1)
			{
				cout << " копейку." << endl;

			}
			if ((kop < 10 || kop > 20) && kop % 10 >= 2 && kop % 10 <= 4)
			{
				cout << " копейки." << endl;

			}
			if (kop % 10 >= 5 && kop % 10 <= 9 || kop % 10 == 0 || (kop > 9 && kop < 21))
			{
				cout << " копеек." << endl;
			}
		}
	}

	else
	{
		cout << "Вы не потратили ничего." << endl;
	}
	cout << endl;

	main();

	system("pause");
	return 0;
} 
