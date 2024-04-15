//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
     vector<int>prefMini(n,INT_MAX),suffMaxi(n,INT_MIN);
        vector<int>suffMini(n,INT_MAX),prefMaxi(n,INT_MIN);
        prefMaxi[0] = prefMini[0] = arr[0];
        suffMaxi[n-1] = suffMini[n-1] = arr[n-1];
        
        for(int i=1;i<n;i++){
            prefMaxi[i] = max(arr[i],prefMaxi[i-1]);
            prefMini[i] = min(arr[i],prefMini[i-1]);
            suffMaxi[n-i-1] = max(arr[n-i-1],suffMaxi[n-i]);
            suffMini[n-i-1] = min(arr[n-i-1],suffMini[n-i]);
        }
        
        
        int ans = INT_MAX, i = 0, j = k-1;

        while(j<n){
            int mini = INT_MAX, maxi = INT_MIN;
            
            if(i>0){
                mini = min(mini,prefMini[i-1]);
                maxi = max(maxi,prefMaxi[i-1]);
            }
            if(j<n-1){
                mini = min(mini,suffMini[j+1]);
                maxi = max(maxi,suffMaxi[j+1]);
            }
            
            ans = min(ans,maxi-mini);
            j++,i++;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends