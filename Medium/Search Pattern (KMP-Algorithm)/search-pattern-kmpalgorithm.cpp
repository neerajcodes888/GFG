//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
       void computeLPS(string pat, vector<int> &lps){
        int m = pat.size();
        if(m == 1) return ;
        int len = 0 , i = 1;
        
        while(i < m){
            if(pat[i] == pat[len]){
                lps[i] = len + 1;
                len++; i++;
            }
            else{
                if(len != 0){
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
    }
        vector <int> search(string pat, string txt)
        {
            //code hee.
            int m = pat.size() , n = txt.size();
            vector<int> lps(m,0);
            vector<int> ans;
            computeLPS(pat, lps);
            int i = 0 , j = 0;
            while(i < n){
                if(pat[j] == txt[i]){
                    i++;
                    j++;
                }
                else{
                    if(j != 0){
                        j = lps[j-1];
                    }
                    else{
                        i++;
                    }
                }
                if(j == m){
                    ans.push_back(i-j+1);
                    j = lps[j-1];
                }
            }
            if(ans.size() == 0) return {-1};
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends