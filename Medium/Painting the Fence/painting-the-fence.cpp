//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
   long long mod=1e9+7;
    
    public:
    
    long long countWays(int n, int k){
        // code here
        // if(n==1)return k;
        if(n==1)return k;
        long long a=k;
        // long long K=k;
        long long b=(1LL*k*(k))%mod;
       
        for(int i=3;i<=n;i++){
            
            long long ans=((a*(k-1))%mod+(b*(k-1))%mod)%mod;
            a=b;
            b=ans;
        }
       return b;
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
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends