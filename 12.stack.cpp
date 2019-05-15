#include<iostream>
#include<vector>
using namespace std;

template<class T> 
class Stack {
private:
	T* elems;
	int size;
	int position = -1;
public:
	Stack(int num);           //构造函数
	void push(T elem); //压栈
	void pop();               //出栈
	bool empty();             //判断是否为空
	int length();               //读取长度信息
	bool check();             //检查是否越界
	void print();             //打印栈中值
};

template<class T>
Stack<T>::Stack(int num) : size(num),elems(new T[size]) {}

template<class T>
void Stack<T>::push (T elem) {
	int error = 1;
	try {
		if (check() == 1)
			throw error;
	}
	catch (int) {
		cout << "The stack is full";     //catch the full error
	}
	elems[++position] = elem;
}

template<class T>
void Stack<T>::pop() {
	int error = 1;
	try {
		if (empty() == 1)
			throw error;
	}
	catch (int) {
		cout << "The stack is empty";    //catch the empty error
	}
	elems[position--] = NULL;
}

template<class T>
bool Stack<T>::empty() {
	return (position == -1) ? 1 : 0;
}

template<class T>
int Stack<T>::length() {
	return position + 1;
}

template<class T>
bool Stack<T>::check() {
	return (position == size - 1) ? 1 : 0;
}

template<class T>
void Stack<T>::print() {
	int i;
	for (i = 0; i <= position; i++) {
		cout << elems[i] << " ";
	}
}

int main() {
	Stack<int> object(20);
	object.push(1);
	object.push(2);
	object.push(3);
	object.push(4);
	object.push(5);
	object.push(6);
	object.push(7);
	object.push(8);
	object.push(9);
	object.push(10);
	cout << "After push stack: " << endl;
	object.print();
	object.pop();
	cout << "\n\nAfter pop stack: " << endl;
	object.print();
	cout << "\n\nThe length of Stack:" << endl;
	cout << object.length();
	object.pop();
	object.pop();
	object.pop();
	object.pop();
	object.pop();
	object.pop();
	object.pop();
	object.pop();
	object.pop();
	cout << "\n\nAfter pop all elems: " << endl;
	if (object.empty() == 1) {
		cout << "The Stack is empty";
	}
	return 0;
}