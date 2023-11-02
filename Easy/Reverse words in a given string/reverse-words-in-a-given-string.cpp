//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string str="";
        stack<string>st;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]!='.')
            {
                str+=S[i];
            }
            else{
                st.push(str);
                st.push(".");
                str="";
            }
        }
        while(!st.empty())
        {
            str+=st.top();
            st.pop();
        }
        return str;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends