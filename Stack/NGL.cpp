#include <bits/stdc++.h>

using namespace std;

//nearest greatest element LEFT

vector<int> NGL(vector<int> arr){

    vector<int> v;
    stack<int> s;

    int length = arr.size();

    for (int i = 0; i < length; i++)
    {
        if(s.size() == 0)
            v.push_back(-1);

        else if(s.size()>0 && s.top() > arr[i])
            v.push_back(s.top());

        else if(s.size()>0 && s.top() <= arr[i]){

            while(s.size() > 0 && s.top() <= arr[i])
                s.pop();

            if(s.size() == 0)
                v.push_back(-1);
            else if(s.top() > arr[i])
                v.push_back(s.top());
        }

        s.push(arr[i]);
    }


    return v;
    
}

int main(){

    vector<int> arr= {1,3,2,4};
    vector<int> v = NGL(arr);
    
    
    for (int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    
    return 0;
}