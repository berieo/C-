#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int atoi(char* ch){
    int d = strlen(ch);
    int count_d = 0;
    int count_o = 0;
    int count_h = 0;
    int j = 0;
    int o = d;
    int h = d;

    //To decimalism
    while(d > 0){
        count_d += (*(ch + d-- - 1) - 48) * pow(10, j++);
    }
    cout << "Decimalim:" << count_d << endl;

    //To octonary
    j = 0;
    while(o > 0){
        count_o += (*(ch + o-- - 1) - 48) * pow(8, j++);
    }
    cout << "Octonary:" << count_o << endl;

    //To hexadecimal
    j = 0;
    while(h > 0){
        count_h += (*(ch + h-- - 1) - 48) * pow(16, j++);
    }
    cout << "Hexadecimal:" << count_h << endl;
    
}

int main(){
    char ch[10];
    cin >> ch;
    atoi(ch);
    return 0;
}
