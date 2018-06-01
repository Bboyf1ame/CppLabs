#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	unsigned long long s;

	cin >> s;

	for (unsigned long long i = 2; i < sqrt(s) + 0.00001;)
	{
		 if (s % i == 0) 
		 {
			cout << i << ' ';
			s /= i;
		 }
	     else 
	     {
			++i;
	     }
 }

	if (s > 1)

		cout << s << endl;

	system("pause");
	return 0;
}