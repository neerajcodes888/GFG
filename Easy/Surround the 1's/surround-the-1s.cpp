//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
vector<pair<int,int>> movements={
        {1, 1}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    bool valid(int n, int m, int i, int j){
        if(i>=n or i<0 or j>=m or j<0) return false;
        return true;
    }
    
    int Count(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans=0;
        for(int i=0;i<n; i++){
            for(int j=0; j<m; j++){
                if (v[i][j] == 0) continue;
                int cnt=0;
                int x, y;
                
                for(auto pr: movements){
                    x = i+pr.first;
                    y = j+pr.second;
                    if(valid(n,m,x,y)) {
                        if (v[x][y] == 0) cnt++;
                    }
                }
                if(cnt%2 == 0 and cnt!=0) ans++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends