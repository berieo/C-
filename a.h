#ifndef _A
#define _A
#include "B.h"//A��ͷ�ļ�������B��ͷ�ļ�</strong>
//extern class B;

class A
{
private:
	int a;
	static B* objectb;//A��ͷ�ļ�������B��ͷ�ļ����ڵ���B��ʱ��Ϳ��Բ���ָ��

public:
	A();
	int geta();
	void print();
};

#endif _A