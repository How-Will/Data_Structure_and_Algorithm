#include<iostream>
using namespace std;

int fibbocciFunc(int n){
    if(n == 1 || n == 2){
        return 1;
    }
    return fibbocciFunc(n - 2) + fibbocciFunc(n - 1);
}

int main(){
    for(int i = 1; i <= 16; i++)
        cout << fibbocciFunc(i) << endl;

    return 0;
}