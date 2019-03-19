#include<iostream> 

int count(char* letters){
    char ch[13] = "xabaacbaxabb";
    int i = 0;
    int count = 0;
    while(i < 12){
        if(*letters == ch[i++])
            if(*(letters + 1) == ch[i++])
                count++;
    }
    return count;
}

int main(){
    char letters[3];
    
    std::cin >> letters;
    std::cout << count(letters);
}