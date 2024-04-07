//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int help(int arr[], int start, int end, vector<vector<int>> &dp)
    {
        if(end == start) return arr[start];
        if(start>end) return 0;
        
        if(dp[start][end] != -1) return dp[start][end];
        
        int left = arr[start] + min( help(arr, start+1, end-1, dp), help(arr, start+2, end, dp) );
        int right = arr[end] + min( help(arr, start, end-2, dp), help(arr, start+1, end-1, dp) );
        
        return dp[start][end] = max(left, right);
    }
    
    long long maximumAmount(int n,int arr[]){
        // Your code here
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return help(arr, 0, n-1, dp);
        
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends