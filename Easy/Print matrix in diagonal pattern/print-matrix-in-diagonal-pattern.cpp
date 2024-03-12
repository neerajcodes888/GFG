//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
  vector<pair<pair<int,int>,int>>res;
         int n=mat.size();
         for(int i=0;i<n;i++)
         {
             for(int j=0;j<n;j++)
             {
                 if((i+j)%2==0)
                 {
                     res.push_back({{(i+j),j},mat[i][j]});
                 }
                 else
                 {
                     res.push_back({{(i+j),i},mat[i][j]});
                 }
             }
         }
         sort(res.begin(),res.end());
         vector<int>v;
         for(int i=0;i<res.size();i++)
         {
             v.push_back(res[i].second);
         }
         return v;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends