#include <bits/stdc++.h>

using namespace std;

void swap_util(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &arr){
    int temp, n = arr.size(), swaps = 0;
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1]){
                swap_util(arr[j], arr[j+1]);
                swaps++;
            }

           if(swaps == 0)
                break;
    }

 
}

void show(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

int main(){
    vector<int> arr{5,4,3,2,1};
    bubbleSort(arr);
    show(arr);
    return 0;
}