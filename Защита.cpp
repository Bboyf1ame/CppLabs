#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	char halo[255*2];
	ifstream in("INPUT.TXT");
	ofstream out("OUTPUT.TXT");
	int IV, PE, SI, BO, finish, vvod, a, b, c, d;
	IV = 1952.10000, PE = 1995.8000, SI = 1991.15000, BO = 1993.12000;
	a = IV = 1, b = PE = 2, c = SI = 3, BO = d = 4;
	cout << "Введите значение: ";
	cin >> finish;
	if (finish > c)
	{
		cout << "Ответ: " << SI << endl;
	}
	system("pause");
	return 0;
}