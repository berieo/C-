#include<iostream>

class error {
	public:
		int i = 0;
};
struct error1 {
	char ch;
};
struct error1 e1;
int main() {
	try {
		error e;  //自定义类		
		e.i = 1;
		e1.ch = 'c';
		if (0) {
			throw e;
		}
		else if (e1.ch == 'c')
			throw e1;
	}
	catch (error) {
		std::cout << "class error";
	}
	catch (error1) {
		std::cout << "struct error";
	}
}