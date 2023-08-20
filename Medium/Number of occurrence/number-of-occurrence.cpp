//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	int count(int arr[], int n, int x) {
	    int c=0;
	    map<int,int>m;
	    for(int i=0;i<n;i++)
	    ++m[arr[i]];
for(auto it:m)
{
    if(it.first==x)
    c=it.second;
}
return c;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends