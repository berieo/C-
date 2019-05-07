#include <iostream>
using namespace std;

struct X {
	int i;
	X() {}
	X(int value) : i(value) {}

	//x + y + i;
	X operator+ (int m) {            
		X operator1;
		operator1 = i + m;
		return operator1;
	}
	X operator* (X x1) {
		X operator2;
		operator2 = i * x1.i;
		return operator2;
	}
	
};

struct Y {
	int i;
	Y() {}
	Y(X x): i(x.i) {}
	/*Y operator+ (X x) {
		Y operator1;
		operator1.i = x.i + i;
	}*/

	//y + 10
	Y operator+ (int m) {       
		Y operator2;
	    operator2.i = m + i;
		return operator2;
	}

	//y + 10 * y
	Y operator* (int n) {        
		Y operator3;
		operator3.i = n * i;
		return operator3;
	}

	//y + 10 * y
	Y operator+ (Y y3) {        
		Y operator4;
		operator4.i = i + y3.i;
		return operator4;
	}

	Y operator+ (X x4) {
		Y operator5;
		operator5.i = i + x4.i;
		return operator5;
	}
	//operator int() {}
};

extern X operator* (X x, Y y) {
	X out;
	out.i = x.i * y.i;
	return out;
};

extern int f(X x) {
	return x.i;
};

extern int f(Y y) {
	return y.i;
}

int operator+ (int num, Y y4) {
	int ans;
	ans = num + y4.i;
	return ans;
}
X x = 1;
Y y = x;
int i = 2;

int main(){
	printf("x.i = 1\n");
	printf("y.i = 1\n");
	printf("i = 2\n\n");
	printf("i + 10 = %d\n\n", i + 10);
	printf("y + 10 = %d\n\n", y + 10);
	y.i = 1;
	printf("y + 10 * y = %d\n\n", y + 10 * y);
	y.i = 1;
	printf("x + y + i = %d\n\n", y + x + 1);
	y.i = 1;
	printf("x * x + i = %d\n\n", x * x + i);
	x.i = 1;
	printf("f(7) = %d\n\n", f(7));
	printf("f(y) = %d\n\n", f(y));
	printf("y + y = %d\n\n", y + y);
	y.i = 1;
	printf("106 + y = %d\n\n", 106 + y);
	
    return 0;
}