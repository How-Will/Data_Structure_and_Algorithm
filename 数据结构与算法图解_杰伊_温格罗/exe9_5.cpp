#include<iostream>
#include<string>
using namespace std;

void swap(char& c_1, char& c_2){
    char temp = c_1;
    c_1 = c_2;
    c_2 = temp;
}

void reverseStr(string& s, int i, int j){
    if(i >= j)
        return;
    reverseStr(s, i + 1, j - 1);
    swap(s[i], s[j]);
}

int main(){
    string word = "hello world";
    reverseStr(word, 0, word.size() - 1);
    cout << word << endl;

    return 0;
}