//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
 vector<int> primeFactors(int n) 
{ 
    vector<int>ans;
    while (n % 2 == 0) 
    { 
        ans.push_back(2);
        n = n/2; 
    } 
 
    for (int i = 3; i <= sqrt(n); i = i + 2) 
    { 
        while (n % i == 0) 
        { 
            ans.push_back(i);
            n = n/i; 
        } 
    } 
 
    if (n > 2) 
        ans.push_back(n);
        
    return ans;
} 
 
    int solve(int n){
        vector<int>v=primeFactors(n);
        map<int, int>mp;
        for(int i=0; i<v.size(); i++){
            mp[v[i]]++;
        }
        int ans=0;
        for(auto it: mp){
            ans+=it.second;
        }
        return ans;
    }
 
int sumOfPowers(int a, int b){
    int ans=0;
    for(int i=a; i<=b; i++){
        ans+=solve(i);
    }
    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends