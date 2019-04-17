#include <iostream>
#include "B.h"
#include "A.h"//注意3：在B.cpp里面导入A的头文件</strong>

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