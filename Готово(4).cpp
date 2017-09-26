#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	double sum = 0;
	cin >> n;
	for (int i = n; i > 0; i--)
	{
		sum = sqrt(3 * i + sum);
	}
	cout << sum;
	return 0;
}