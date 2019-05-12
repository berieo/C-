#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	String x, y;
	cout << "Please enter two strings\n";
	cin >> x >> y;
	cout << "input: " << x << ' ' << y << '\n';

	String z = x;
	y = f(x, y);
	if (x != z) cout << "x corrupted!\n";
	x[0] = '!';
	if (x == z) cout << "write failed!\n";
	cout << "exit: " << x << ' ' << y << ' ' << z << '\n';
	return 0;
}