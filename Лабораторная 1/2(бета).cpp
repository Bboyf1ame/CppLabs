//  	Даны действительные числа a1, b1, c1, a2, b2, c2.Выяснить, верно ли, что | a1b2 - a2b1 | ≥0.0001, и если верно, то найти решение системы линейных уравнений :
//      a1x + b1y + c1 = 0,
//      a2x + b2y + c2 = 0.
//      (при выполнении выписанного неравенства система заведомо совместна и имеет единственное решение).

#include <iostream> 
#include <cmath> 
using namespace std;
int main()
{
	double a1, b1, c1, a2, b2, c2;
	cout << Write "a1" << "\n"; cin >> a1;
	cout << Write "b1" << "\n"; cin >> b1;
	cout << Write "a2" << "\n"; cin >> a2;
	cout << Write "b2" << "\n"; cin >> b2;
	if (abs(a1*b2 - a2*b1) >= 0.0001)
	{
		cout << a1*b1 - a2*b1;
		x = ((b2*c1 - b1*c2) / a1*b2 + a2*b1);
		y = ((a2*c1 - a1*c2) / b1*a2 + a1*b2);
		cout << "x=" << x;
		cout << "y=" << y;
	}
	system("pause");
	return 0;
}