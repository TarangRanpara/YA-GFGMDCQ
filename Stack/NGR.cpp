#include <bits/stdc++.h>

using namespace std;

//nearest greatest element RIGHT

/*
    suppose you're given an array of 1 3 2 4
    answer should be                 3 4 4 -1

    input 100 99 88 77
    o/p   -1 -1 -1 -1

    input 100 99 66 88 77
    o/p   -1  -1 88 -1 -1

*/
vector<int> NGR(vector<int> arr){
    vector<int> v;
    stack<int> s;

    //size
    int length = arr.size();

    for (int i = length - 1; i >= 0; i--)
    {
        //if stack is empty
        if(s.size() == 0)
            v.push_back(-1);
        

        //if top > arr element
        else if(s.size() > 0 && s.top() > arr[i])
            v.push_back(s.top());

        //if arr element > top
        else if(s.size() > 0 && s.top() <= arr[i]){
            
            //until stack becomes empty or top element is smaller than array element
            while(s.size() > 0 && s.top() < arr[i]){
                s.pop();
            }

            //now loop stops, there can be two reasons
            if(s.size() == 0)
                v.push_back(-1);
            
            else if(s.top() > arr[i])
                v.push_back(s.top());
        }

        s.push(arr[i]);
    }

    reverse(v.begin(), v.end());
    return v;
    
    
}

int main(){
    
    vector<int> ptr = {1,3,2,4};
    vector<int> v = NGR(ptr);

    for(int i=v.size()-1; i>=0; i--)
        cout<<v[i]<<" ";
        
    return 0;
}