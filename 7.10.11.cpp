#include<iostream>
#include<cstdarg>
#include<string>
void error(const char* ch, ...) {
	va_list args;
	va_start(args, ch);//args未知参数的第一个指针，fmt为fmt后的第一个参数作为未知参数的第一个参数
	vprintf(ch, args);
	va_end(args);
	/*if (ch == 's') {

	}
	else if (ch == 'c') {

	}
	else if (ch == 'd') {

	}*/
}
int main() {
	error("%d %c %s", 1, 'c', "hello");
	return 0;
}