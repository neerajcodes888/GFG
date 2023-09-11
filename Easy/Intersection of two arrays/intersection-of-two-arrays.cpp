//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
    // unordered_set<int>s;
    // for(int i=0;i<n;i++)
    // s.insert(a[i]);
    // int c=0;
    // for(int i=0;i<m;i++)
    // {
    //  int key = b[i];
    //  if(s.find(key)!=s.end())
    //  {
    //      c++;
    //      s.erase(key);
    //  }
    // }
    // return c;
    sort(a,a+n);
    sort(b,b+m);
    int c=0;
    int i=0,j=0;
    vector<int>v;
    while(i<n && j<m)
    {
        if(a[i]==b[j])
        {
           v.push_back(a[i]);
            i++;
            j++;
        }
        else if(a[i]<b[j])
        i++;
        else
        j++;
    }
 int ans = unique(v.begin(),v.end())-v.begin();
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends