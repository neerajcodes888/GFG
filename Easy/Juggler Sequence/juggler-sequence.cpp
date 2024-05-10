//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> jugglerSequence(int n) {
     vector<int>ans;
        ans.push_back(n);
        
        while(ans[ans.size()-1] > 1){
            
            double s = pow(ans[ans.size()-1],0.5);
            int c = s * s * s;
            
            if(ans[ans.size()-1] % 2 == 0){
                ans.push_back((int)s);
            }   
            else{
                ans.push_back(c);
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
        int n;
        cin >> n;

        Solution ob;
        vector<int> ans = ob.jugglerSequence(n);
        for (int u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends