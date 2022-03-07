#include<iostream>
using namespace std;

int func(int numerator, int denominator){
    if(numerator < denominator)
        return numerator;
    return func(numerator - denominator, denominator);
}

int main(){
    cout << func(10, 3) << endl;

    return 0;
}