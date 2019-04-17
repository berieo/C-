#include <iostream>
#include "A.h"

using namespace std;

A::A()
{
	this->a = 50;
}

int A::geta()
{
	return a;
}

void A::print()
{
	cout << "the value b in Class A : " << objectb->getb() << endl;
}

B* A::objectb = new B();