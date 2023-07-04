//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int maxSum(int arr[], int n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;++i)
			cin>>arr[i];
		cout<<maxSum(arr,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends


long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    vector<int>v;
 int i=0,j=n-1;
 while(i<=j)
 {
     v.push_back(arr[i]);
     v.push_back(arr[j]);
     i++;
     j--;
 }
// for(auto i:v)
// {
//     cout<<i<<" ";
// }
 long long int sum=0;
 for(int i=1;i<v.size();i++)
 {
     sum+=abs(v[i-1]-v[i]);
 }
 sum+=abs(v[n-1]-v[0]);
    return sum;
}