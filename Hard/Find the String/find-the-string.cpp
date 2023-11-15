//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    unordered_map<string,bool>mp;
    string ans="-1";
    void findSubs(string s,int k,int n){
        if(s.length()==n){
            mp[s]=true;
            return;
        }
        for(int i=0;i<k;i++){
            findSubs(s+to_string(i),k,n);
        }
        return;
    }
    
    bool find(string s,int n,int k,int count){
        if(count==mp.size()){
            ans= ans=="-1" || ans.length()>s.length() ? s : ans;
            return true;
        }
        if(s.length()<n-1){
            for(int i=0;i<k;i++){
                if(find(to_string(i)+s,n,k,count))
                    return true;
            }
            return false;
        }
        
        string p=s.substr(0,n-1);
        
        for(int i=0;i<k;i++){
            if(mp[to_string(i)+p]){
                mp[to_string(i)+p]=false;
                if(find(to_string(i)+s,n,k,count+1))
                    return true;
                mp[to_string(i)+p]=true;
            }
        }
        return false;
        
        
    }
    
   
    string findString(int n, int k) {
       mp.clear();
       findSubs("",k,n);
       find("",n,k,0);
       return ans;
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends