//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
      vector<int> ans(S.size() + 1);
        int no = 1;
    
        for (int i = 0; i <= S.size(); i++) {
            if (i == S.size() || S[i] == 'I') {
                ans[i] = no++;
                for (int j = i - 1; j >= 0 && S[j] == 'D'; j--) {
                    ans[j] = no++;
                }
            }
        }
    
        string result = "";
        for (int i = 0; i < ans.size(); i++) {
            result += to_string(ans[i]);
        }
    
        return result;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends