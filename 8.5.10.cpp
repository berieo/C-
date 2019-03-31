#include<iostream>
using namespace std;
int plus_func(int a, int b) {
	int ans = a + b;
	try {
		if (a > 0 && b > 0 && ans < 0)
			throw 1;
		else if (a < 0 && b < 0 && ans > 0)
			throw - 1;
	}
	catch (int i) {
		switch (i) {
		case 1:cout << "plus is overflow" << endl; break;
		case -1:cout << "plus is underflow" << endl; break;
		}
	}
	return a + b;
}

int minus_func(int a, int b) {
	int ans = a - b;
	try {
		if (a > 0 && b < 0 && ans < 0)
			throw 1; //overflow
		else if (a < 0 && b > 0 && ans > 0)
			throw - 1; //underflow

	}
	catch (int i) {
		switch (i) {
		case 1:cout << "minus is overflow" << endl; break;
		case -1:cout << "minus is underflow" << endl; break;
		}
	}
	return a + b;
}

int multiply_func(int a, int b) {
	int ans = a * b;
	try {
		if (a * b / b != a)
			throw - 1;
	}
	catch (int) {
		cout << "muliply is overflow" << endl;
	}
	return ans;
}

int divide_func(int a, int b) {
	int ans = a / b;
	try {
		if (a / b * b != a)
			throw - 1;
	}
	catch (int) {
		cout << "divide is overflow" << endl;
	}
	return ans;
}

int main() {
	double a;
	double b;
	cin >> a;
	cin >> b;
	plus_func(a, b);
	minus_func(a, b);
	multiply_func(a, b);
	divide_func(a, b);
	return 0;
}