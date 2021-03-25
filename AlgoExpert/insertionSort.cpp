#include <bits/stdc++.h>

using namespace std;

void swap_pos(vector<int> &arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void print_arr(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<"\t";

    cout<<endl;
}

vector<int> insertionSort(vector<int> arr){
    for(int i=1; i<arr.size(); i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]){
            swap_pos(arr, j, j-1);
            j--;
        }
    }
    return arr;
}

int main(){
    vector<int> arr{5,4,3,2,1,0};
    auto res = insertionSort(arr);
    print_arr(res);
    return 0;
}
