//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    int longest=0,start=-1;
    vector<int>v(256,-1);
    for(int i=0;i<S.size();i++)
    {
        if(v[S[i]]>start)
        start=v[S[i]];
        v[S[i]]=i;
        longest=max(longest,i-start);
    }
    return longest;
}