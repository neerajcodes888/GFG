//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string S){
 int maxLength=0,start=-1;
 vector<int>v(256,-1);
 for(int i=0;i<S.size();i++)
 {
     if(v[S[i]]>start)
     start=v[S[i]];
     v[S[i]]=i;
     maxLength=max(maxLength,i-start);
 }
        return maxLength;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}
// } Driver Code Ends