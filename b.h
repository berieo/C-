#ifndef _B
#define _B

extern class A;//��extern����class A

class B
{
private:
	int b;
	static A* objecta;//ע��2������A��ʱ����Ҫ��ָ��
public:
	B();
	int getb();
	void print();
};

#endif _B