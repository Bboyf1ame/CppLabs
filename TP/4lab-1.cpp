#include <iostream>
using namespace std;

long double sum(int N)
{
	if (N == 0)
		return 0;
	if (N == 1)
		return 1;
	while ((1 / N) > 0)
		return 1 / N + sum(1 / (N - 1));

}

int main()
{
	int N;
	cin >> N;

	cout << sum(N) << endl;
	system("pause");
	return 0;
}