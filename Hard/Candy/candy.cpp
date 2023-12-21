//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &r) {
              vector<int>left(N, 0), right(N, 0);
        
        left[0] = 1;
        right[N - 1] = 1;
        
        for(int i = 1; i < N; i++){
            
            if(r[i] > r[i - 1])     left[i] = left[i - 1] + 1;
            
            else    left[i] = 1;
        }
        
        for(int i = N - 2; i >= 0; i--){
            
            if(r[i] > r[i + 1])     right[i] = right[i + 1] + 1;
            
            else    right[i] = 1;
            
        }
        
        int res = 0;
        
        for(int i = 0; i < N; i++){
            res += max(left[i], right[i]);
        }
        
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends