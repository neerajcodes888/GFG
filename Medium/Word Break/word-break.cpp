//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:


  int wordBreak(int n, string s, vector<string> &dictionary) {
        
        unordered_map<string,bool>mapp;
        for(auto it:dictionary)mapp[it]++;
        string a="";
        bool flag1=false,flag2=false;
        if(mapp.count(s))return 1;
        for(int i=0;i<s.size();i++){
             string a=s.substr(0,i+1);
             string b=s.substr(i+1);
             if(mapp.count(a)){
                 flag1=true;
             }
             if(mapp.count(b)){
                 flag2=true;
             }
             if(flag1 and flag2)return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends