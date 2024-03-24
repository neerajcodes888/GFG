//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
void solve(int n, int one, int zero, vector<string> &ans, string s){
        if(one + zero == n){
            ans.push_back(s);
            return ;
        }
        
        if(one < n){
            solve(n,one+1,zero,ans,s+'1');
        }
        if(zero <one){
            solve(n,one,zero+1,ans,s+'0');
        }
    }
    
vector<string> NBitBinary(int n)
{
    // Your code goes here
    vector<string> ans ;
    string s ;
    solve(n,0,0,ans,s);
    return ans ;
}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends