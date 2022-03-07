#include<iostream>
using namespace std;

void recurse(int time){
    if(time == 0){
        return;
    }else{
        cout << "HELLO" << endl;
        recurse(--time);
        
    }
}

int main(){
    recurse(10);

    return 0;
}
