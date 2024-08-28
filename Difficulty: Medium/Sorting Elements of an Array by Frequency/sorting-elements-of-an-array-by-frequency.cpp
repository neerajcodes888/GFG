//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
   bool static comp(pair<int, int>&a, pair<int, int>&b){
        if(a.first>b.first) return 1;
        else if(a.first==b.first) return a.second<b.second;
        return 0;
    }
    
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int>mpp;
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        
        vector<pair<int, int>>v;
        for(auto &it:mpp){
            v.push_back({it.second, it.first});
        }
        
        sort(v.begin(), v.end(), comp);
        
        vector<int>ans;
        
        for(auto &it:v){
            for(int i=0; i<it.first; i++){
                ans.push_back(it.second);
            }
        }
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends