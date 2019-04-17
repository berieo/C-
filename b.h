#ifndef _B
#define _B

extern class A;//用extern声明class A

class B
{
private:
	int b;
	static A* objecta;//注意2：调用A的时候需要用指针
public:
	B();
	int getb();
	void print();
};

#endif _B