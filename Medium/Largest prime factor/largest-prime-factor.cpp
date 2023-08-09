//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int n){
        long long int maxi=0;
        for(long long int i=2;i<=sqrt(n);i++)
        {
           if(n%i==0)
            {
                maxi=max(maxi,i);
                while(n%i==0)
                n=n/i;
            }
        }
        
        maxi=max(maxi,(long long int)n);
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends