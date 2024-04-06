//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
int solve(int n , int m , int A[] , int B[]){
    if(n<0||m<0)
     return 0;
    int include = A[n]*B[m] + solve(n-1 , m-1, A,B);
    int exclude = (n==m)?0:solve(n-1,m,A,B);
    return max(include , exclude);
}
// memorization 
 
int solveMem(int n , int m , int A[] , int B[], vector<vector<int>>&dp){
    if(n<0||m<0)
     return 0;
    if(dp[n][m]!=-1)
     return dp[n][m];
    int include = A[n]*B[m] + solveMem(n-1 , m-1, A,B,dp);
    int exclude = (n==m)?0:solveMem(n-1,m,A,B,dp);
  dp[n][m]= max(include , exclude);
  return dp[n][m];
}
 

int solveTab(int n , int m,int A[] , int B[]){
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=m; i++){
            for(int j=i; j<=n; j++){
                dp[i][j]=max(A[j-1]*B[i-1]+dp[i-1][j-1], dp[i][j-1]);
            }
        }
        return dp[m][n];
}
 

int solveSpace(int n , int m,int A[] , int B[]){
       vector<int>curr(n+1,0);
       vector<int>prev(n+1,0);
        
        for(int i=1; i<=m; i++){
            for(int j=i; j<=n; j++){
                curr[j]=max(A[j-1]*B[i-1]+prev[j-1], curr[j-1]);
            }
            prev = curr;
        }
        return prev[n];
}
int maxDotProduct(int n, int m, int A[], int B[]) 
{ 
    return solveSpace(n , m, A,B);
    
}  
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends