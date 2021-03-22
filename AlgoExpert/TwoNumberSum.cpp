#include <bits/stdc++.h>

using namespace std;

// problem: given an array of distinct integers and target sum, you've to find if there's pair which sum up to target sum


//Time complexity: O(N^2), Space complexity: O(1)
pair<int, int> two_number_sum1(vector<int> arr, int target){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr.size(); j++){
            if(arr[i] + arr[j] == target)
                //return nums
                return make_pair(arr[i], arr[j]);
        }
    }

    // returns -inf if not found
    return make_pair(INT_MIN, INT_MIN);
}

// Time complexity: 0(N), Space complexity: O(N^2)
pair<int, int> two_number_sum2(vector<int> arr, int target){
    unordered_map<int, int> dict;
    for(int i=0; i<arr.size(); i++){
        int curr = arr[i];
        if(dict.find(target - curr) != dict.end()){
            // returns nums if found
            return make_pair(target - curr, curr);
        }

        dict.insert({curr, 1});
    }

    // returns -inf if not found
    return make_pair(INT_MIN, INT_MIN);
}

// Time Complexity: O(N*log(N)), Space Complexity: O(1)
pair<int, int> two_number_sum3(vector<int> arr, int target){
    sort(arr.begin(), arr.end());
    int start = 0;
    int fin = arr.size() - 1;

    while(start != fin){
        if(arr[start] + arr[fin] == target)
            return make_pair(arr[start], arr[fin]);

        if(arr[start] + arr[fin] < target)
            start++;
        else
            fin--;
    }

    // returns -inf if not found
    return make_pair(INT_MIN, INT_MIN);
}

int main(){
    vector<int> arr{-4, -1, 1, 3, 5, 6, 8, 11};

    auto pos = two_number_sum1(arr, 10);
    cout<<pos.first<<"\t"<<pos.second<<endl;

    pos = two_number_sum2(arr, 13);
    cout<<pos.first<<"\t"<<pos.second<<endl;

    pos = two_number_sum3(arr, 10);
    cout<<pos.first<<"\t"<<pos.second;
}
