//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
bool sameFreq(string s)
    {
        vector<int> vec1,vec2;
        unordered_map<char,int> mp1;
        unordered_map<int,int> mp2;
        int len = s.length();
        for(int i =0;i<len;i++)
        {
           mp1[s[i]]++; 
        }
        for(auto it:mp1)
        {
            mp2[it.second]++;
        }
        if(mp2.size()==1)
        {
            return true;
        }
        else if(mp2.size()==2)
        {
            for(auto it:mp2)
            {
               vec1.push_back(it.first);
               vec2.push_back(it.second);
            }
            int maxvec = max(vec1[0],vec1[1]);
            int minvec = min(vec1[0],vec1[1]);
            if(mp2[minvec]==1 && minvec==1)
            {
                return true;
            }
            else if((vec1[1]-vec1[0]==1 || vec1[0]-vec1[1]==1) && mp2[maxvec] ==1)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
       
      
    }


};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends