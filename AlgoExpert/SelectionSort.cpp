#include <bits/stdc++.h>

using namespace std;

void swap_util(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void show(vector<int> arr){
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

void selectionSort(vector<int> &arr){
    int n = arr.size(), min;
    for(int i=0; i<n; i++){
        min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min])
                min = j;
        }

        if(min != i)
            swap_util(arr[min], arr[i]);
    }
}

int main(){
    vector<int> arr{5,4,3,2,1};
    selectionSort(arr);
    show(arr);
    return 0;
}