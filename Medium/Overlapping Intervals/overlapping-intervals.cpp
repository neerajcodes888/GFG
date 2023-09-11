//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>>v;
         sort(intervals.begin(),intervals.end());
         int l = intervals[0][0];
         int r = intervals[0][1];
         for(int i=1;i<intervals.size();i++)
         {
             if(intervals[i][0]<=r)
             {
                 r=max(intervals[i][1],r);
             }
             else{
                 v.push_back({l,r});
                 l = intervals[i][0];
                 r = intervals[i][1];
             }
             
         }
         v.push_back({l,r});
         return v;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends