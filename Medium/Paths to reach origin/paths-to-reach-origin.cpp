//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
    const int MOD = 1000000007;
    vector<vector<int>>memo;

    int solve(int x, int y) {
        if (x == 0 && y == 0) return 1;
        if (memo[x][y] != -1) return memo[x][y];

        int l = 0, r = 0;
        if (x>0) l = solve(x-1, y);
        if (y>0) r = solve(x, y-1);

        return memo[x][y] = (l+r) % MOD;
    }

public:
    int ways(int x, int y) {
        memo.assign(x+1, vector<int>(y+1, -1));
        return solve(x, y);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends