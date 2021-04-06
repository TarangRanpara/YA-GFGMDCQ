#include <bits/stdc++.h>

using namespace std;

pair<int, int> closest_pair(vector<int> a1, vector<int> a2){
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());

    int n1 = a1.size(), n2 = a2.size();
    int idx1=0, idx2=0;

    int smallest = INT_MAX;
    
    int first, second;
    pair<int, int> ans;
    while(idx1 < n1 && idx2 < n2){
        first = a1[idx1];
        second = a2[idx2];

        cout << first << " " << second << " " << smallest << endl;

        if(first == second)
            return make_pair(first, second);

        else if(first > second)
            idx2++;

        else if(second > first)
            idx1++;


        if(abs(first - second) < smallest){
            smallest = abs(first - second);
            ans = make_pair(first, second);
        }

    }

    return ans;
}

int main(){
    vector<int> a1{-1, 5, 10, 20, 28, 3}, a2{26, 134, 135, 15, 17};
    pair<int, int> ans = closest_pair(a1, a2);
    cout<<ans.first<<"\t"<<ans.second<<endl;
    return 0;
}