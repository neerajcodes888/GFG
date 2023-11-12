//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
       int n=str1.size(), m=str2.size();
        if(n!=m) return 0;
        bool res1=1, res2=1;
        for(int i=0; i<n; i++) {
            if(str2[i]!=str1[(i+2)%n]) {
                res1=0;
            }
        }
        for(int i=0; i<n; i++) {
            if(str1[i]!=str2[(i+2)%n]) {
                res2=0;
            }
        }
        return (res1||res2);
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends