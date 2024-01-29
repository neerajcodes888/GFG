//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
int solveTabSO(string&s1,string&s2,string&s3){
    int n1=s1.length();
    int n2=s2.length();
    int n3=s3.length();
    vector<vector<int>> curr(n2+1,vector<int>(n3+1,0));
    vector<vector<int>> next(n2+1,vector<int>(n3+1,0));
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            for(int k=n3-1; k>=0; k--){
                int ans=0;
                if(s1[i]==s2[j] && s1[i]==s3[k]){
                    ans=1+next[j+1][k+1];
                }
                else{
                    int a=next[j][k];
                    int b=curr[j+1][k];
                    int c=curr[j][k+1];
                    int d=next[j+1][k];
                    int e=curr[j+1][k+1];
                    int f=next[j][k+1];
                    int maxi=a;
                    if(b>maxi) maxi=b;
                    if(c>maxi) maxi=c;
                    if(d>maxi) maxi=d;
                    if(e>maxi) maxi=e;
                    if(f>maxi) maxi=f;
                    ans=maxi;
                }
                curr[j][k]=ans;
            }
        }
        next=curr;
    }
    return next[0][0];
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    return solveTabSO(A,B,C);
}
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends