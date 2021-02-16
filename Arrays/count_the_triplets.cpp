#include <bits/stdc++.h>
using namespace std;



 // Question Link: https://practice.geeksforgeeks.org/problems/count-the-triplets4615/1


//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    sort(arr, arr+n);
	    int triplets = 0;
	    for(int i=n-1; i>=0; i--){
	        int j = 0; 
	        int k = i - 1;
	        
	        while(j < k){
	            int sum = arr[j] + arr[k];
	            if(sum == arr[i]){
	                triplets++;
	                j++;
	                k--;
	            }
	            else if(sum > arr[i])
	                k--;
	            else
	                j++;
	        }
	    }
	    
	    return triplets;
	    
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends