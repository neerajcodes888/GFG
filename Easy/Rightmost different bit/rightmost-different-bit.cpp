//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    // string  bin(int x)
    // {
    //     string s="";
    //     for(int i=log(x)/log(2);i>=0;i--)
    //     {
    //         int k=x>>i;
    //         if(k&1)
    //         s+="1";
    //         else
    //         s+="0";
    //     }
    //     return s;
    // }
    // int posOfRightMostDiffBit(int m, int n)
    // {
    
    //   string s1 = bin(m);
    //   string s2 = bin(n);
    //       int ans=min(s2.size(),s1.size())+1;
    //   for(int i=0;i<max(m,n);i++)
    //   {
    //       if(s1[i]!=s2[i])
    //       {
    //           ans=i;
    //           break;
    //       }
    //   }
    //   return ans;
    int posOfRightMostDiffBit(int m, int n)
    {
        if(m==n) return -1;
        
        int xorr = m^n;
        int ans = 1;
        while(xorr)
        {
            if(xorr&1) return ans;
            
            ans++;
            xorr = xorr>>1;
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends