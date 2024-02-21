//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
int mod = 1e9+7;
    int solve(int i, int j, string& S, string& T,vector<vector<int>>&dp){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j]%mod;
        if(S[i-1]==T[j-1]) return dp[i][j] = (solve(i-1,j-1,S,T,dp)%mod + solve(i-1,j,S,T,dp)%mod)%mod;
        return dp[i][j] = solve(i-1,j,S,T,dp)%mod;
    }
    int subsequenceCount(string S, string T)
    {
      int n = S.length();
      int m = T.length();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      return solve(n,m,S,T,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends