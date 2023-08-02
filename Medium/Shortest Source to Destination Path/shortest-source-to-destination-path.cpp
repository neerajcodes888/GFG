//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
int solve(int i,int j,int n,int m,vector<vector<int>> &A,vector<vector<int>> lvl)
    {
        if(i==0 && j==0 )return 0;
        
        int ans=1000;
        
        int id1[4] = { 0 , 0, 1, -1};
        int id2[4] = { 1 ,-1, 0,  0};
        
        queue<pair<int,int>> q;
        
        q.push({i,j});
        
        
        while(!q.empty())
        {
            int i1=q.front().first;
            int j1=q.front().second;
            
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int ind1= i1 + id1[k];
                int ind2= j1 + id2[k];
                
                if(ind1>=0 && ind1<n && ind2>=0 && ind2<m && lvl[ind1][ind2]==-1 && A[ind1][ind2]==1)
                {
                    lvl[ind1][ind2]= lvl[i1][j1] + 1;
                    
                    q.push({ind1,ind2});
                }
                
                if(lvl[0][0]!=-1)return lvl[0][0];
                
            }
        }
        return -1;
        
    }
  
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        if(N==X && M==Y)return 0;
        if(A[X][Y]==0)return -1;
       
        vector<vector<int>> dp(N,vector<int>(M,-1));
        dp[X][Y]=0;
        
        return solve(X,Y,N,M,A,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends