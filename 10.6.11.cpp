#include <iostream>
#include "start.h"
#include <string>
#include <fstream>
#pragma warning(disable:4996)
using namespace std;
class Expr {
	char* ch;
public:
	Expr(char* expr);
	int eval();
	void print();
};

Expr::Expr(char* expr) {
	strcpy(ch, expr);
}

int Expr::eval() {
	return start_calculator();
}

int main() {
	char* ch = (char*)malloc(sizeof(char*)*10);
	cin >> ch;
	Expr x(ch);
	cout << x.eval();
	return 0;
}