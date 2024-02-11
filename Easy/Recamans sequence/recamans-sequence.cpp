//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> ans(n);
        map<int,int> m;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans.push_back(0);
                m[i]++;
            }
            else
            {
                int temp = ans[i-1] - i;
                if(temp>0 && m[temp]==0)
                {
                    ans[i] = temp;
                    m[temp]++;
                }
                else
                {
                    int temp = ans[i-1]+i;
                    ans[i] = temp;
                    m[temp]++;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends