#include<bits/stdc++.h>

using namespace std;

vector<int> NSR(vector<int> arr){

    vector<int> v;
    stack<int> s;

    int length = arr.size();

    for (int i = length - 1; i >= 0; i--)
    {
        if(s.size() == 0)
            v.push_back(-1);

        else if(s.size() > 0 && s.top() < arr[i])
            v.push_back(s.top());
        
        else if(s.size() > 0 && s.top() >= arr[i]){    
            while(s.size() > 0 && s.top() >= arr[i])
                s.pop();

            if(s.size() == 0)
                v.push_back(-1);
            else if(s.top() < arr[i])
                v.push_back(s.top());
        }

        s.push(arr[i]); 
    }

    reverse(v.begin(), v.end());
    return v;

       
}

int main(){

    vector<int> arr = {1,3,2,4};
    vector<int> v = NSR(arr);

    for(int i=v.size()-1; i>=0; i--)
        cout<<v[i]<<" ";
    return 0;
}