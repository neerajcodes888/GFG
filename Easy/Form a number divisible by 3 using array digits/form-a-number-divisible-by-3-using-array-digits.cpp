//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int n, int arr[]) {
    //     string s="";
    //     for(int i=0;i<n;i++)
    //     {
    //       s+=arr[i]; 
    //     }
    //   int  ds=0;
    //     for(int i=0;i<s.size();i++)
    //     {
    //       ds+=int(s[i]-'0'); 
    //     }
    //     return ds%3==0;
    return accumulate(arr, arr + n, 0LL) % 3 == 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends