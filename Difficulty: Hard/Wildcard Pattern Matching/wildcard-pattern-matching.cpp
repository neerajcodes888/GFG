//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    vector<vector<int>>dp;

  bool helper(string& pattern, int i, string& str, int j) {
        int n = pattern.size(), m = str.size();
        if(j == m) {
            for(int k = i; k < n; k++) 
                if(pattern[k] != '*')
                    return false;
            return true;
        }
        if(i == n) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool res = false;
        
        if(pattern[i] == '?') {
            res = helper(pattern, i+1, str, j+1);
        } else if(pattern[i] == '*') {
            res |= helper(pattern, i, str, j+1);
            res |= helper(pattern, i+1, str, j);
        } else {
            res = (pattern[i] == str[j]) && helper(pattern, i+1, str, j+1);
        }
        
        return dp[i][j] = res;
    }
  
    int wildCard(string pattern, string str) {
        int n = pattern.size(), m = str.size();
        dp = vector<vector<int>>(n, vector<int>(m+1, -1));
        return helper(pattern, 0, str, 0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends