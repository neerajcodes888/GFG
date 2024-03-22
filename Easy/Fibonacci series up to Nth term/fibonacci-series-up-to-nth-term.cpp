//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
   private:
    void f(int n, vector<int> &ans, int ind, int prev, int prev2)
    {
        ans.push_back(prev2);
        if(ind == n)  return;
        int curi = (prev+prev2)%MOD;
        prev2 = prev;
        prev = curi;
        f(n,ans,ind+1,prev,prev2);
    }
  public:
    const int MOD = 1e9+7;
    vector<int> Series(int n) {
        vector<int> ans;
        int prev = 1, prev2 = 0;
        f(n,ans,0,prev,prev2);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends