//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        string s;
       if(n==0)
       return 0;
        while(n)
        {
            if(n&1)
            s+='1';
            else
            s+='0';
            n=n>>1;
        }
        int ans=0;
     for(int i=0;i<s.size();i++)
     {
         if(s[i]=='1')
        {
            ans=i;
            break;
        }
      
     }
     return ans+1;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends