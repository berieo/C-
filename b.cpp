#include <iostream>
#include "B.h"
#include "A.h"//ע��3����B.cpp���浼��A��ͷ�ļ�</strong>

using namespace std;

B::B()
{
	this->b = 40;
}

int B::getb()
{
	return b;
}

void B::print()
{
	cout << "the value a in Class b: " << objecta->geta() << endl;
}

A* B::objecta = new A();