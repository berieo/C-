#include<iostream>
using namespace std;

template<class C> 
class Stack {
private:
	vector<C> elems;
public:
	void push();
	void pop();
	T top() const;            // ����ջ��Ԫ��
	bool empty() const {       // ���Ϊ���򷵻��档
		return elems.empty();
	}
};


int main() {

	return 0;
}