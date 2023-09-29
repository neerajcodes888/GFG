//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    int mRows = 0;
    int mColumns = 0;
    
    void Check(vector<vector<int>> &grid, int x, int y)
    {
        stack<pair<int, int>> myStack;
        
        if (grid[x][y] == 1)
        {
            myStack.push(pair<int, int>(x, y));
        }
        
        while (!myStack.empty())
        {
            auto val = myStack.top();
            myStack.pop();
            
            if (val.first < 0 || val.first > (mRows - 1) || val.second < 0 || val.second > (mColumns - 1))
            {
                continue;
            }
            
            if (grid[val.first][val.second] != 1)
            {
                continue;
            }
            
            grid[val.first][val.second] = 2;

            myStack.push(pair<int, int>(val.first - 1, val.second));
            myStack.push(pair<int, int>(val.first + 1, val.second));
            myStack.push(pair<int, int>(val.first, val.second -  1));
            myStack.push(pair<int, int>(val.first, val.second + 1));

        }
        
    }
    
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int columns = grid[0].size();
        int rows = grid.size();
        
        mRows = rows;
        mColumns = columns;
        
        for (int i = 0; i < columns; i++)
        {
            Check(grid, 0, i);
        }
        
        for (int i = 0; i < columns; i++)
        {
            Check(grid, rows- 1, i);
        }
        
        for (int i = 0; i < rows; i++)
        {
            Check(grid, i, 0);
        }
        
        for (int i = 0; i < rows; i++)
        {
            Check(grid, i, columns - 1);
        }
        
        int result = 0;
        
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if(grid[i][j] == 1) result++;
            }
        }
        
        return result;

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends