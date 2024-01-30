//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s){
     int res=0, n= s.size();
        stack<int>st;
        stack<int>dist; 
        for (int i=0; i<n; i++){
            if (!st.empty() && st.top()=='(' && s[i]==')'){
                st.pop();
                dist.pop();
                dist.empty() ? res= i+1 : res= max(res, i-dist.top());
            } 
            else {
                st.push(s[i]);
                dist.push(i);
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends