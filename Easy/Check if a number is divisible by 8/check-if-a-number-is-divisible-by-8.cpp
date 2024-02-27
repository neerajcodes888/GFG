//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
string str="";
int c=0;
for(int i=s.size()-1;i>=0 && c<3;i--){
    str+=s[i];
    c++;
}
reverse(str.begin(),str.end());
return stoi(str)%8==0?1:-1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends