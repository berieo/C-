#include<iostream>
#include<cstdarg>
#include<string>
void error(const char* ch, ...) {
	va_list args;
	va_start(args, ch);//argsδ֪�����ĵ�һ��ָ�룬fmtΪfmt��ĵ�һ��������Ϊδ֪�����ĵ�һ������
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