//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
  int nodeLevel(int V, vector<int> adj[], int X) 
    {
        // code here
        
        queue<pair<int,int>>q;
        vector<int>vis(V,0);
        q.push({0,0});
        vis[0]=1;
        while(!q.empty()){
            int temp=q.front().first;
            int lvl=q.front().second;
            q.pop();
            for(auto it:adj[temp]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,lvl+1});
                }
                if(it==X){
                    return lvl+1;
                }
                
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends