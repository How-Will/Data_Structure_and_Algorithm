#include<iostream>
using namespace std;

int power(int num, int index){
    if(index == 1)
        return num;
    return power(num, index - 1) * num;
}

int main(){
    cout << power(2, 5) << endl;

    return 0;
}