//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
string add(string n1,string n2)
{
     string temp="";
     int carry=0;
    int n1Size=n1.size()-1;
    int n2Size=n2.size()-1;
    while(n1Size>=0||n2Size>=0)
    {
        if(n1Size<0)
        {
             temp.push_back((n2[n2Size]-'0'+carry)%10+48);
            carry=(n2[n2Size]-'0'+carry)/10;
            n2Size--;
        }
        else if(n2Size<0)
        {
             temp.push_back((n1[n1Size]-'0'+carry)%10+48);
            carry=(n1[n1Size]-'0'+carry)/10;
            n1Size--;
        }
        else
        {
            temp.push_back((n1[n1Size]-'0'+n2[n2Size]-'0'+carry)%10+48);
            carry=(n1[n1Size]-'0'+n2[n2Size]-'0'+carry)/10;
            n1Size--;
            n2Size--;
        }
        
    }
    if(carry)
    temp.push_back(carry+48);
    reverse(temp.begin(),temp.end());
    return temp;
}
bool find_rec(string n1,string  n2,string s,bool found)
{
    if(s.length()==0 && found)
    return true;
    
    string n3=add(n1,n2);
   
    int idx=min(s.size(),n3.size());
    if(s.substr(0,idx)==n3)
    return find_rec(n2,n3,s.substr(idx),true);
    return false;
}
bool isAdditiveSequence(string s)
{
    //Your code here
    int n=s.size();
    if(s[0]=='0') return false;
    for(int i=1;i<n-1;i++)
    {
        string  n1=(s.substr(0,i));
        
        for(int j=i+1;j<n;j++)
        {
            string n2=(s.substr(i,j-i));
            bool found=find_rec(n1,n2,s.substr(j),false);
            if(found) return true;
        }
    }
    return false;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends