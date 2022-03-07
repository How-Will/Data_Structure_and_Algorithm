#include<stack>
#include<string>
#include<iostream>
using namespace std;

int main(){
    stack<char> c_stack;    

    string word = "hello";

    for(string::size_type i = 0; i < word.size(); i++){
        c_stack.push(word[i]);
    }

    word.erase();
    while(!c_stack.empty()){
        word.push_back(c_stack.top());
        c_stack.pop();
    }

    cout << word << endl;

    return 0;
}