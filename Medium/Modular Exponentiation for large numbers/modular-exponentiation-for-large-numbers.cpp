//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    if(n==1){
		        return x%M;
		    }
		    else if(n==0){
		        return 1;
		    }
		    long long int a = PowMod(x,n/2,M);
		    if(n%2==1){
		        return ((((a%M) * (x%M))%M * (a%M))%M)%M;
		    }
		    return ((a%M) * (a%M))%M;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends