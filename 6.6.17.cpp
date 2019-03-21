#include<iostream>
using namespace std;
char * itoa(int i, char *b){
    int n = 0;
    int m = 0;
    char temp[10];
    while(i != 0){
        temp[n] = i % 10 + 48;
        std::cout << temp[n];
        n++;
        i = (i - i % 10) / 10;
    }
    while(n >= 0){
        *(b + m++) = temp[n--];
    
    }
    return b;
}
 int main(){
    int i;
    char b[10];
    std::cin >> i;
    itoa(i, b);
    return 0;
 }