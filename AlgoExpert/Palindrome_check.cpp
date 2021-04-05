#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string str, int i){
    int j = str.length() - 1 - i;
    if(i >= j)
        return true;
    else
        if(str[i] == str[j])
            return isPalindrome(str, i+1);
        else
            return false; 
}

int main(){
    cout<<isPalindrome("abcba", 0)<<endl;
    cout<<isPalindrome("abctcba", 0)<<endl;
    cout<<isPalindrome("ab", 0)<<endl;
    return 0;
}