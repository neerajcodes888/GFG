//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
     
        vector<int> range(n,-1);
        for(int i = 0; i<n; i++){
            if(gallery[i] != -1){
                range[max(0,i-gallery[i])] = max(range[max(0,i-gallery[i])],min(n-1,i+gallery[i]));
            }
        }
        int ans = 0;
        int maxy = -1;
        for(int i = 0; i<n; i++){
            maxy = max(maxy,range[i]);
            if(maxy < i) return -1;
            ans++;
            int cur = -1;
            while(i<maxy){
                cur = max(cur,range[i]);
                i++;
            }
            cur = max(cur,range[i]);
            maxy = max(cur,maxy);
        }
        return ans;
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
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends