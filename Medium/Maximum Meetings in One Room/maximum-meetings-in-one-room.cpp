//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
      vector<tuple<int,int,int>>vp;
       for(int i=0;i<N;i++){
           vp.push_back(make_tuple(S[i],F[i],i+1));
       }
       sort(vp.begin(),vp.end(),[&](tuple<int,int,int>t1 , tuple<int,int,int>t2){
           return get<1>(t1)==get<1>(t2)?get<0>(t1)<get<0>(t2):get<1>(t1)<get<1>(t2);
       });
       int end=get<1>(vp[0]);
       vector<int>ans;
       ans.push_back(get<2>(vp[0]));
       int c=1;
       for(int i=1;i<N;i++){
           if(end<get<0>(vp[i])){
               c++;
               end=get<1>(vp[i]);
               ans.push_back(get<2>(vp[i]));
           }
       }
       sort(ans.begin(),ans.end());
       return ans;  
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends