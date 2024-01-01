//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
         vector<int> f(k);
      for(auto num : nums) ++f[num % k]; 
      bool ok = true;
       for(int i = 0; i < k; i++){
           if(i == (k-i) % k) 
            ok &= (f[i] % 2 == 0);
           else 
            ok &= (f[i] == f[k-i]);
       }
       return ok;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends