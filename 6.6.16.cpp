#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

//To decimalism
int atoi_d(char* ch){
    int d = strlen(ch);
    int count_d = 0;
    int j = 0;
	while(d > 0){
        count_d += (*(ch + d-- - 1) - 48) * pow(10, j++);
    }
    return count_d;
}

//To hctonary
int atoi_h(char* ch) {
	int d = strlen(ch);
	int count_d = 0;
	int count_h = 0;
	int j = 0;
	int h = d;
	//To hctonary
	j = 0;
	while (h > 0) {
		if ((*(ch + h - 1) - 48) >= 0 && (*(ch + h - 1) - 48) < 10) {
			count_h += (*(ch + h-- - 1) - 48) * pow(16, j++);
		}
		else {
			count_h += (*(ch + h-- - 1) - 55) * pow(16, j++);
		}
	}
	return count_h;
}

int atoi_o(char* ch) {
	int d = strlen(ch);
	int count_d = 0;
	int count_o = 0;
	int j = 0;
	int o = d;
	while(o > 0){

		count_o += (*(ch + o-- - 1) - 48) * pow(8, j++);
	}
	return count_o;
}

int main(){
    char ch[10];
    cin >> ch;
	//printf("%d", atoi_d(ch));
	//printf("%o", atoi_o(ch));
	printf("%X", atoi_h(ch));
    return 0;
}
