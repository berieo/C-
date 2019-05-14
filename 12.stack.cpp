#include<iostream>
using namespace std;

template<class C> 
class Stack {
private:
	vector<C> elems;
public:
	void push();
	void pop();
	T top() const;            // 返回栈顶元素
	bool empty() const {       // 如果为空则返回真。
		return elems.empty();
	}
};


int main() {

	return 0;
}