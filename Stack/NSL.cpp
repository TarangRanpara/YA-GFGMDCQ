#include<bits/stdc++.h>

using namespace std;

//NEAREST SMALL ELEMENT LEFT

vector<int> NSL(vector<int> arr){

    vector<int> v;
    stack<int> s;

    int length = arr.size();

    for (int i = 0; i < length; i++)
    {
        if(s.size() == 0)
            v.push_back(-1);

        else if(s.size() > 0 && s.top() < arr[i])
            v.push_back(s.top());

        else if(s.size() > 0 && s.top() >= arr[i]){

            while(s.size()>0 && s.top() >= arr[i])
                s.pop();

            if(s.size() == 0)
                v.push_back(-1);

            else if(s.top() < arr[i])
                v.push_back(s.top());
        }

        s.push(arr[i]);
    }

    return v;
}

int main(){
    vector<int> arr = {6,2,5,4,5,1,6};
    
    vector<int> v = NSL(arr);

    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";

    return 0;
}