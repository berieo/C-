#include <iostream>
#include "String.h"
using namespace std;

int main()
{
	String x, y;
	cout << "Please enter two strings\n";
	cin >> x >> y;
	cout << "input: " << x << ' ' << y << '\n'; //<< >>·û

	String z = x;
	y = f(x, y);
	if (x != z) cout << "x corrupted!\n";
	x[0] = '!';
	if (x == z) cout << "write failed!\n";
	cout << "exit: " << x << ' ' << y << ' ' << z << '\n';

	cout << "read(3) = " << x.read(3) << endl;
	x.write(3, 'c');
	cout << "write(3,'c') = " << x << endl;
	cout << "size() = " << x.size() << endl;

	return 0;
}