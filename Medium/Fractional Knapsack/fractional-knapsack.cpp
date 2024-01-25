//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    static double cmp(Item &a1,Item &a2){
        return ((double)a1.value/a1.weight)>((double)a2.value/a2.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
    sort(arr,arr+n,cmp);
    double total = 0.0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            total+=arr[i].value;
            W-=arr[i].weight;
        }
        else{
         total+=((double)W/arr[i].weight)*arr[i].value;
         W=0;
        }
    }
    return total;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends