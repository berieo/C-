#include<iostream>

enum MONTH{
    Jan = 1,Feb,Mar,Apr,May,June,July,Aug,Sep,Octo,Nov,Dec
}

enum WEEKDAY{
    Mon = 1,Tues,Wed,Thur,Fri,Satu,Sun
}

struct Date{
    int Year;
    MONTH month;
    WEEKDAY weekday;
}

int input(){
    int i,j;
    Data calender;
    std::cout <<  "input the data";
    std::cin >> calender.Year;
    std::cin >> calender.month;
    std::cin >> calender.day;
}

int output(){
    std::cout << calender.Year;
    std::cout << calender.month;
    std::cout << calender.day;
}

int main(){
    input();
    output();
    return 0;
}