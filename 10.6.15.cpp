#include <iostream>

class Hello {
public:
	Hello() { std::cout << "Initialize" << std::endl; }
	~Hello() { std::cout << "Clean up\n" << std::endl; }
};

struct holla {
	holla(){ std::cout << "Initialize" << std::endl; }
	~holla() { std::cout << "Clean up\n" << std::endl; }
};

Hello hello;
struct holla holla;

int main() {
   std::cout << "Hello, world!\n";
}


