//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    int c=0;
	    sort(arr,arr+n);
	   for(int i=0;i<n;i++)
	   {
	       int left=i+1,right=n-1;
	       while(left<right)
	       {
	           long long s = arr[i]+arr[left]+arr[right];
	           if(s<sum)
	           {
	               c+=(right-left);
	               left++;
	           }
	           else
	            right--;
	       }
	   }
	   return c;
	}
		 

};

//{ Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends