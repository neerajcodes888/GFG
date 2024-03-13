//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int N, vector<vector<char>> A) {
  vector<vector<int>> dp1(N,vector<int>(N,0));

        vector<vector<int>> dp2(N,vector<int>(N,0));

        for (int i=0;i<N;i++) {

            for (int j=0;j<N;j++) {

                if (A[i][j] == 'X') {

                    if (i!=0)

                        dp1[i][j] = dp1[i-1][j]+1;

                    else 

                        dp1[i][j] = 1;

                }

            }

        }


        for (int i=0;i<N;i++) {

            for (int j=0;j<N;j++) {

                if (A[i][j] == 'X') {

                    if (j!=0)

                        dp2[i][j] = dp2[i][j-1]+1;
                    else 

                        dp2[i][j] = 1;
                }

            }

        }
        int ans = 0;
        for (int i=0;i<N;i++) {

            for (int j=0;j<N;j++) {

                int cur = min(dp1[i][j],dp2[i][j]);

           

                while (cur>0) {

                    int a = i-cur +1;

                    int b = j-cur + 1;

                    if ((dp2[a][j] >= cur) && (dp1[i][b] >= cur)) {

                  ans = max(ans,cur);

                        break;

                    }

                    cur--;

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
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends