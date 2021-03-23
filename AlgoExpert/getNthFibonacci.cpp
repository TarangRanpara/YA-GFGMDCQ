#include <bits/stdc++.h>

using namespace std;

// Time: O(2^N) Space: O(N)
int getNthFib1(int n){
    if(n==2)
        return 1;
    if(n==1)
        return 0;

    else
        return getNthFib1(n-1) + getNthFib1(n-2);
}

// Time: O(N), Space: O(N)
unordered_map<int, int> dict;
int getNthFib2(int n){
    if(dict.find(n) != dict.end())
        return dict[n];
    dict[n]= getNthFib2(n-1) + getNthFib2(n-2);
    return dict[n];
}

// Time: 0(N), Space: O(N)
int getNthFib3(int n){

    pair<int, int> prev;
    prev.first = 0;
    prev.second = 1;

    int i = 3, ans;
    while(i <= n){
        ans = prev.first + prev.second;
        prev.first = prev.second;
        prev.second = ans;
        i++;
    }

    if(n>1)
        return prev.second;
    else
        return prev.first;

}

int main(){
    dict[1] = 0;
    dict[2] = 1;

    cout<<getNthFib1(10)<<endl;
    cout<<getNthFib2(10)<<endl;
    cout<<getNthFib3(10)<<endl;


    return 0;
}
