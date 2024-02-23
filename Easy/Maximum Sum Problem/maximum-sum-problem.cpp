//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
        int maxSum(int n)
        {
                if(n<=0){
               return 0;
           }
           int t1 = maxSum(n/2);
           int t2 = maxSum(n/3);
           int t3 = maxSum(n/4);
           return max(n,t1+t2+t3);
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends