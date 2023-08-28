//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
unordered_map<int,int>m;
for(int i=0;i<n;i++)
{
    ++m[arr[i]];
}
vector<int>v(2,-1);
for(auto i:m)
{
    if(i.second>1)
    v[0]=i.first;
}
for(int i=1;i<=n;i++)
{
    if(m.find(i)==m.end())
    v[1]=i;
}

return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends