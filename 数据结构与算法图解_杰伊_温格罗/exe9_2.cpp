#include<iostream>
using namespace std;

void printEven(int number){
    if(number <= 0){
        return;
    }else{
        if(number % 2 == 0){
            cout << number << endl;
        }
        printEven(number - 2);
    }
}

int main(){
    printEven(100);

    return 0;
}