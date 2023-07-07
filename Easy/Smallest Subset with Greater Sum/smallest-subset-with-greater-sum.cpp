//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int minSubset(vector<int> &a,int n){
        sort(a.begin(),a.end());
   long long total_sum=0;
   for(auto i:a)
   total_sum+=i;
   long long sum=0;
   int c=1;
   for(int i=n-1;i>=0;i--)
   {
       sum+=a[i];
       if(sum>(total_sum-sum))
       return c;
       c++;
   }
   return c;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        cout<<ob.minSubset(Arr,N)<<endl;
    }
    return 0;
}
// } Driver Code Ends