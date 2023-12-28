//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
   if(n%k!=0) {
            return 0;
        }
        string ans;
        int val =0;
       unordered_map<string,bool> count;
       for(int i=0; i< n; i+=k) {
           if(!count.count(s.substr(i,k))) {
               val++;
           }
           count[s.substr(i,k)] = true;
       }
       if(val >2) {
           return 0;
       }
       
       return 1;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends