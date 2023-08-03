//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
               vector<pair<int, int>>adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v, d});
        }
        vector<int>distance(N, INT_MAX);
        distance[0]= 0 ;
        queue<int>q;
        q.push(0);
        while(q.empty()==false){
            int curr = q.front();
            q.pop();
            int d = distance[curr];
            for(auto it : adj[curr]){
                int node = it.first;
                int dis = it.second;
                
                if(distance[node] > d + dis){
                    distance[node] = d +dis;
                    q.push(node);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(distance[i]==INT_MAX){
                distance[i] = -1;
            }
        }
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends