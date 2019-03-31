#include<iostream>
using namespace std;
//error1() throw
void error1() {
	throw -1;
}
//error2() catch
void error2() {
	try {
		error1();
	}catch (int i) {
		cout << "fun2()int´¦ÀíÒì³£" << endl;
	}
}
int main() {
	error2();
}