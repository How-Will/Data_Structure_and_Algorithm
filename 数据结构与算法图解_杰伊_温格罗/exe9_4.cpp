#include<iostream>
using namespace std;

int arrSum(int* num, int index){
    if(index == 0)
        return num[index];
    else
        return num[index] + arrSum(num, index - 1);
}

int main(){
    int numbers[] = {1, 3, 5, 7, 8};
    cout << arrSum(numbers, sizeof(numbers) / sizeof(numbers[0]) - 1) << endl;

    return 0;
}

