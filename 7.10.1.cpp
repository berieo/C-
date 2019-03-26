//写一个如下的函数声明：一个函数有char*型的元素和int&型，并且返回void型
//一个指针指向这样的函数;一个函数有这样一个指针作为元素，并且一个函数返回
//这样一个指针，写一个这样的函数有这样的指针作为元素并且返回这个这个值。

#include<iostream>
using namespace std;

//一个函数，他以指向字符的指针和整型的引用为参数，不返回值
void func(char * ch, int& i){ return; }

//一个指向这个函数的指针
typedef void (*func1)(char * ch, int& i);

//一个以这种指针为参数的函数
void func2(func1 argu){ return; }

//返回这种指针的函数
func1 func3(func1 argu){ return argu; }


int main(){

    return 0;
}

