//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
           int s1=0;int s2=0;
        int b1=INT_MAX;
        int b2=INT_MAX;
        for(int i=0;i<price.size();i++){
            int cur=price[i];
            b1=min(b1,cur);
            s1=max(s1,cur-b1);
            b2=min(b2,cur-s1);
            s2=max(s2,cur-b2);
            
        }
        return s2;
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends