//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		     vector<string>ans;
		    int n=s.size();
		    int power=pow(2,n);
		    
		    for(int i=1;i<power;i++){
		        string k;
		        int num=i;
		        int j=0;
		        while(num!=0){
		            int a=(num&1);
		            if(a)
		                k.push_back(s[j]);		    
		            j++;
		            num=num>>1;
		        }
		        ans.push_back(k);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends