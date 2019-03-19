#include<iostream>
#include<string.h>
int main() {
	char ch[10][10];
	int i = 0;
	int j = 0;
	while (1) {
		std::cin >> ch[i];
		if (!(strcmp(ch[i++],"Quit\0"))) break;
	}
	while (j < i - 1) {
		std::cout << ch[j++] << std::endl;
	}
	return 0;
}