//写一个像Hello,world的程序，名字作为命令行参数并且写出hello,name
//调整这个程序去适应任何数量的name作为参数并且写出hello对每一个

#include<iostream>
#include<string>
using namespace std;
void hello(char ch[][10], int length) {
	int i = 0;
	cout << endl;
	for (; i < length - 1; i++)
		cout << "Hello, " << ch[i] << "!" << endl;
}
int main() {
	char ch[10][10];
	char name[10];
	char end[] = "END";
	int i = 0;
	cout << "输入name，以END结束:" << endl;
	do {
		cin >> ch[i];
		//cout << ch[i] << endl;
	} while (strcmp(ch[i++], end));
	hello(ch, i);
	return 0;
}