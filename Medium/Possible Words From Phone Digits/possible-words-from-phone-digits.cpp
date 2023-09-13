//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int i,int a[],int n,vector<string>&v,string t){
        if(i==n)
        {
            return v.push_back(t);
        }
        if(a[i]==1||a[i]==0)
        solve(i+1,a,n,v,t);
      
        if(a[i]==2)
        {
            solve(i+1,a,n,v,t+'a');
        solve(i+1,a,n,v,t+'b');
        solve(i+1,a,n,v,t+'c');
        }
        if(a[i]==3)
        {
            solve(i+1,a,n,v,t+'d');
        solve(i+1,a,n,v,t+'e');
        solve(i+1,a,n,v,t+'f');
        }
         if(a[i]==4)
        {
            solve(i+1,a,n,v,t+'g');
        solve(i+1,a,n,v,t+'h');
        solve(i+1,a,n,v,t+'i');
        }
         if(a[i]==5)
        {
            solve(i+1,a,n,v,t+'j');
        solve(i+1,a,n,v,t+'k');
        solve(i+1,a,n,v,t+'l');
        }
         if(a[i]==6)
        {
            solve(i+1,a,n,v,t+'m');
        solve(i+1,a,n,v,t+'n');
        solve(i+1,a,n,v,t+'o');
        }
         if(a[i]==7)
        {
            solve(i+1,a,n,v,t+'p');
        solve(i+1,a,n,v,t+'q');
        solve(i+1,a,n,v,t+'r');
          solve(i+1,a,n,v,t+'s');
        }
         if(a[i]==8)
        {
            solve(i+1,a,n,v,t+'t');
        solve(i+1,a,n,v,t+'u');
        solve(i+1,a,n,v,t+'v');
        }
         if(a[i]==9)
        {
            solve(i+1,a,n,v,t+'w');
        solve(i+1,a,n,v,t+'x');
        solve(i+1,a,n,v,t+'y');
          solve(i+1,a,n,v,t+'z');
        }
    }
    vector<string> possibleWords(int a[], int n)
    {
        vector<string>v;
        string t;
        solve(0,a,n,v,t);
        return v;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends