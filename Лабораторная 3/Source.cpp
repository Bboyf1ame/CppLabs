#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{

	char buff[255 * 2];
	int size = 0;
	ifstream in("INPUT.txt");
	ofstream out("OUTPUT.txt");
	int* a = new int[255];
	int ch, k;
	cout << "Vvedite chislo: ";
	cin >> k;
	cout << "Vvedite chislo dlya vstavki: ";
	cin >> ch;
	while (!in.eof())

	{

		in.getline(buff, 255);
		char* tmp = buff;
		for (int i = 0; i < 255; i++)

		{

			a[size] = atoi(tmp);
			if (strchr(tmp, ' ') == NULL)
				break;
			else
				tmp = strchr(tmp, ' ') + 1;
			if (a[size] == k)

			{

				size++;
				a[size] = ch;

			}
			size++;

		}

	}
	size++;
	for (int i = 0; i < size; i++)

	{

		out << a[i] << " ";

	}

	in.close();
	out.close();
	return 0;
	system("pause");
}