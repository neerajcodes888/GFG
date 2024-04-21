//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
 int countOnes(vector<int>arr , int m){
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            if(arr[i] == 1){
                count++;
            }
        }
        return count;
    }
    int minRow(int n, int m, vector<vector<int>> arr) {
        int prevCount = INT_MAX;
        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            int count  = countOnes(arr[i] , m);
            if(count < prevCount){
                ans = i;
            }
            prevCount = min(count , prevCount);
        }
        return ans+1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        Solution ob;
        cout << ob.minRow(N, M, A) << "\n";
    }
}
// } Driver Code Ends