//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
          vector<int> v;
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            int k = i;
            int j = 0;
            while(k>=0 && j<n &&k<n)
            {
                v.push_back(matrix[j++][k--]);
            }
            
        }
        int k = n-1;
        int i = 1;
        while(i<n)
        {
            int l = k; 
            for(int j = i;j<n;j++)
            {
                v.push_back(matrix[j][l--]);
            }
            i++;
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
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends