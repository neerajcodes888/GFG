//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
         int l=0,h=n-1;
        int res;
        while(h>=l)
        {
            int m=(l+h)/2;
            if(arr[m]<=k)
            {
                res=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
        }
        if(res<n-1) 
        {
            if(abs(arr[res]-k)==abs(arr[res+1]-k)) return arr[res+1];
            if(abs(arr[res]-k)>abs(arr[res+1]-k)) return arr[res+1];
        }
        return arr[res];
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends