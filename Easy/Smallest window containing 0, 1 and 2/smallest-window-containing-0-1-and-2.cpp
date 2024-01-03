//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string S) {
        // Code here
         int n = S.length();
    int z = 0, o = 0, t = 0;
    int left = 0, minlen = INT_MAX;

    for (int right = 0; right < n; right++) {
        if (S[right] == '0') z++;
        else if (S[right] == '1') o++;
        else if (S[right] == '2') t++;

        while (z > 0 && o > 0 && t > 0) {
            minlen = min(minlen, right - left + 1);

            if (S[left] == '0') z--;
            else if (S[left] == '1') o--;
            else if (S[left] == '2') t--;

            left++;
        }
    }

    return (minlen == INT_MAX) ? -1 : minlen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends