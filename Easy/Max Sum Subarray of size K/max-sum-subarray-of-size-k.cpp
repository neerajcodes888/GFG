//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
     long long mini=INT_MIN,s=0;
     int i=0,j=0;
     while(j<N)
     {
         s+=Arr[j];
         if((j-i+1)==K)
         {
             mini=max(s,mini);
             s-=Arr[i];
             j++;
             i++;
         }
         else
         {
             j++;
         }
     }
     return mini;

    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends