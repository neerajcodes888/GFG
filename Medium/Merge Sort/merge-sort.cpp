//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         int nap1 = m-l+1;
         int nap2 = r-m;
         int *a = new int[nap1];
         int *b = new int[nap2];
         int index = l;
         for(int i=0;i<nap1;i++)
         {
             a[i]=arr[index++];
         }
         index=m+1;
         for(int i=0;i<nap2;i++)
         {
             b[i]=arr[index++];
         }
         index=l;
         int x1=0,x2=0;
         while(x1<nap1 && x2<nap2)
         {
             if(a[x1]<b[x2])
             arr[index++]=a[x1++];
             else
             arr[index++]=b[x2++];
         }
         while(x1<nap1)
         arr[index++]=a[x1++];
         while(x2<nap2)
         arr[index++]=b[x2++];
         delete[] a;
         delete[] b;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l>=r)
        return;
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends