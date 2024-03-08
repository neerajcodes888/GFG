//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
    long long int previous=0;
        long long int next;
        int power=int(pow(2,r))-1;
        int i;
        for( i=0;i<n;i++)
        {
            next=previous+power;
            if(n>=previous && n<=next)
            break;
            previous=next+1;
        }
        
        string temp;
        temp.push_back(s[i]);
        for(int j=0;j<r;j++)
        {
            string temp1;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]=='0')
                {
                    temp1.push_back('0');
                    temp1.push_back('1');
                }
                else
                {
                    temp1.push_back('1');
                    temp1.push_back('0');
                }
            }
            temp.clear();
            temp=temp1;
            temp1.clear();
        }
       
        return temp[n-previous];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends