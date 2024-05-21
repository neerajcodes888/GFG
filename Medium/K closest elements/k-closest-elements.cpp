//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int n, int k, int x) {
map<int,vector<int>> mp;
        for(auto it:arr){
            mp[abs(it-x)].push_back(it);
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.first==0){
                continue;
            }
            if(k==0){
                break;
            }
            sort(it.second.rbegin(),it.second.rend());
            for(auto num:it.second){
                ans.push_back(num);
                k--;
                if(k==0){
                    break;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, x;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> k >> x;
        Solution ob;
        auto ans = ob.printKClosest(arr, n, k, x);
        for (auto e : ans) {
            cout << e << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends