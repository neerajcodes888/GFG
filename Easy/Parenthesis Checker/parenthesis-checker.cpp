//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int it:x)
        {
            if(it=='('||it=='{'||it=='[')
            s.push(it);
            else{
                if(s.empty() || (s.top()=='(' && it!=')') || (s.top()=='{' && it!='}') || (s.top()=='[' && it!=']'))
                return false;
                s.pop();
            }
        }
        return s.empty();
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends