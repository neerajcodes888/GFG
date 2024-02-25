//{ Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    // Complete this function
    long long int count(long long int n)
    {
    	vector<int>arr={3,5,10};
    vector<vector<long long int>>dp(4,vector<long long int>(n+1,0));
    dp[0][0]=1;
    
    
    for(int i=0;i<=n;i++){
        if(i%arr[0]==0){
            dp[0][i]=1;
        }
    }
   
    
    for(int index=1;index<3;index++){
        for(int tar=0;tar<=n;tar++){
            
            int take=0;
         if(tar>=arr[index]){
    
      take=dp[index][tar-arr[index]];
          }
    
        int notake=dp[index-1][tar];
    
         dp[index][tar]= take+notake;
    
            
            
        }
    }
    return dp[2][n];
    	
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		Solution obj;
		cout<<obj.count(n)<<endl;
	}
	return 0;
}
// } Driver Code Ends