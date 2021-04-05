#include <bits/stdc++.h>

using namespace std;

char cipher_util(char curr, int key){
    return ('a' + ((curr - 'a' + key) % 26));
}

string ceaser_cipher(string str, int key){
    string result = "";
    for(int i=0; i<str.length(); i++)
        result += cipher_util(str[i], key);

    return result;
}


int main(){
    int key = 2;
    cout<<ceaser_cipher("abcxyz", key);
    return 0;
}