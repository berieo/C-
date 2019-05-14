#include <iostream>
using namespace std;

class Base {
public:
	virtual void iam() {
		cout << "Base\n";
	}
};

class Base_A : public Base {
public:
	void iam() {
		cout << "Base_A" << endl;
	}
};

class Base_B : public Base {
public:
	void iam() {
		cout << "Base_B" << endl;
	}
};

int main() {
	Base_A A;
	Base_B B;
	cout << "call from class:" << endl;
	A.iam();
	B.iam();

	cout << "\ncall from pointer:" << endl;
	Base* pointer_A = &A;
	Base* pointer_B = &B;
	pointer_A->iam();
	pointer_B->iam();
	return 0;
}