#include <bits/stdc++.h>

using namespace std;

int BinarySearchRecursive(vector<int> arr, int element, int low, int high){
    if(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == element)
            return mid;

        if(element > arr[mid])
            return BinarySearchRecursive(arr, element, mid+1, high);

        if(element < arr[mid])
            return BinarySearchRecursive(arr, element, low, mid-1);
    }
    else
        return -1;
}

int BinarySearchIterative(vector<int> arr, int element){
    int mid;
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        mid = low + (high - low)/2;

        if(arr[mid] == element)
            return mid;

        if(element > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}



int main(){
    vector<int> arr{1,2,3,4,5};
    cout<<"Recursive:"<<endl;
    cout<<BinarySearchRecursive(arr, 1, 0, arr.size()-1)<<endl;
    cout<<BinarySearchRecursive(arr, 2, 0, arr.size()-1)<<endl;
    cout<<BinarySearchRecursive(arr, 3, 0, arr.size()-1)<<endl;
    cout<<BinarySearchRecursive(arr, 4, 0, arr.size()-1)<<endl;
    cout<<BinarySearchRecursive(arr, 5, 0, arr.size()-1)<<endl;
    cout<<BinarySearchRecursive(arr, 99, 0, arr.size()-1)<<endl;

    cout<<"Iterative:"<<endl;
    cout<<BinarySearchIterative(arr, 1)<<endl;
    cout<<BinarySearchIterative(arr, 2)<<endl;
    cout<<BinarySearchIterative(arr, 3)<<endl;
    cout<<BinarySearchIterative(arr, 4)<<endl;
    cout<<BinarySearchIterative(arr, 5)<<endl;
    cout<<BinarySearchIterative(arr, 99)<<endl;
    return 0;
}
