//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        int total_sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                total_sum+=matrix[i][j];
            }
        }
        int row_maxi=INT_MIN;
        int col_maxi=INT_MIN;
        int total_max=0;
        for(int i=0;i<n;i++)
        {
            int row_sum=0;
            for(int j=0;j<n;j++)
            {
                row_sum+=matrix[i][j];
            }
            row_maxi=max(row_maxi,row_sum);
            int col_sum=0;
            for(int j=0;j<n;j++)
            {
                col_sum+=matrix[j][i];
            }
            col_maxi=max(col_maxi,col_sum);
            total_max=max(col_maxi,row_maxi);
        }
        int ans=(total_max*n)-total_sum;
        return ans;
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends