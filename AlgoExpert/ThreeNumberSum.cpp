#include <bits/stdc++.h>

using namespace std;

void show(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
        
    cout<<endl;
}

void twoNumberSum(vector<int> arr, int start, int target, vector<pair<int, int>> &ans){
    int fin = arr.size() - 1;

    while(start != fin){
        if(arr[start] + arr[fin] == target){
            ans.push_back(make_pair(arr[start], arr[fin]));
        }

        if(arr[start] + arr[fin] < target)
            start++;
        else
            fin--;
    }

    // returns -inf if not found
    return;
}

// Time Complexity: O(N^2)
void threeNumberSum(vector<int> arr, int sum){
    int curr;
    for(int i=0; i<=arr.size()-3; i++){
        vector<pair<int, int>> ans;
        curr = arr[i];
        twoNumberSum(arr, i+1, sum-curr, ans);

        for(auto i: ans){
            cout<<i.first<<"\t"<<i.second<<"\t"<<curr<<endl;
        }
    }
}

int main(){
    vector<int> arr{-8, -6, 1, 2, 3, 5, 6, 12};
    show(arr);
    threeNumberSum(arr, 1);
    return 0;
}