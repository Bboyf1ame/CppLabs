#include <iostream>
using namespace std;
int main()
{
	int sum = 0;
	for (int n = 21; n < 100; n++)
	{
		if (n % 3 == 0)
		{
			if (n % 10 == 2 || n % 10 == 4 || n % 10 == 8)
				sum += n;
		}
	}
	cout << sum << endl;
	system("pause");
}