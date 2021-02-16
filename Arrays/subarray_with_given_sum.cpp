#include <bits/stdc++.h>

// Question link: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

using namespace std;

void find_subarray(vector<int> arr, int n, int s){
    int start=0, end=0, sum=0;
    if(s == 0){
        cout<<-1;
        return;
    }
    
    for(int i=0; i<n; i++){
        sum += arr[i];
        end++;
        
        if(sum == s){
            cout<<(start+1)<<" "<<(end);
            return;
        }
        
        if(sum > s){
            while(sum > s){
                sum -= arr[start];
                start++;
            }
            
            if(sum == s){
                cout<<(start+1)<<" "<<(end);
                return;
            }
        }
    }
    
    cout<<-1;
    return;
}

int main(){
    int t;  cin>>t;
    while(t--){
        int n,s;    cin>>n>>s;
        vector<int> arr;
        for(int i=0; i<n; i++){
            int temp;   cin>>temp;  arr.push_back(temp);
        }
        
        find_subarray(arr, n, s);   cout<<endl;
    }
}