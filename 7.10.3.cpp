//дһ����Hello,world�ĳ���������Ϊ�����в�������д��hello,name
//�����������ȥ��Ӧ�κ�������name��Ϊ��������д��hello��ÿһ��

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
	cout << "����name����END����:" << endl;
	do {
		cin >> ch[i];
		//cout << ch[i] << endl;
	} while (strcmp(ch[i++], end));
	hello(ch, i);
	return 0;
}