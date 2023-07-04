//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
 
    long long int maximizeSum(long long int a[], int n, int k)
    {
     sort(a,a+n);
     int j=0;
     for(int i=0;i<n&&i<k;i++)
     {
         if(a[i]<0)
         {
             a[i]=(-1)*a[i];
        j++;
         }
     }
     sort(a,a+n);
 while(j<k)
 {
     a[0]=(-1)*a[0];
     j++;
 }
     long long int sum=0;
     for(int i=0;i<n;i++)
     {
         sum+=a[i];
     }
     return sum;
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends