//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
 void permut(vector<int>&ds,vector<int>arr,set<vector<int>>&res,int freq[]){
      if(ds.size()==arr.size()){
          res.insert(ds);
          return;
      }
      for(int i=0;i<arr.size();i++){
          if(!freq[i]){
              ds.push_back(arr[i]);
              freq[i]=1;
              permut(ds,arr,res,freq);
              freq[i]=0;
              ds.pop_back();
          }
      }
  }
    vector<vector<int>> uniquePerms(vector<int> arr ,int n) {
         vector<int>ds;
         int freq[n]={0};
         set<vector<int>>res;
         for(int i=0;i<n;i++)freq[i]=0;
         permut(ds,arr,res,freq);
         
         vector<vector<int>>ans(res.begin(),res.end());
         
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends