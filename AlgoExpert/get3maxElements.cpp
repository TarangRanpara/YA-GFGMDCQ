#include <bits/stdc++.h>

#define FIRST 0
#define SECOND 1
#define THIRD 2

using namespace std;

vector<int> findMax3(vector<int> arr){
    vector<int> max_arr{INT_MIN, INT_MIN, INT_MIN};
    for(auto element:arr){
        if(element > max_arr[THIRD]){
            max_arr[FIRST] = max_arr[SECOND];
            max_arr[SECOND] = max_arr[THIRD];
            max_arr[THIRD] = element;
        }

        else if(element > max_arr[SECOND]){
            max_arr[FIRST] = max_arr[SECOND];
            max_arr[SECOND] = element;
        }

        else
            max_arr[FIRST] = element;
    }

    return max_arr;
}

int main(){
    vector<int> arr{1,2,3,4,5,6,7};
    for(int i:findMax3(arr)){
        cout<<i<<endl;
    }
    return 0;
}
