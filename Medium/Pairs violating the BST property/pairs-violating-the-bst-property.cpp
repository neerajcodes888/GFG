//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
// User function Template for C++

/*// A Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};*/

class Solution {
  public:

  long long int merge(vector<int>&arr, long long s, long long mid, long long e){
        
        long long temp[e-s+1];
        long long int i = s;
        long long int j = mid+1;
        long long int k = 0;
        long long int inversion = 0;
        
        while(i<=mid && j<=e){
            if(arr[i]<=arr[j]){
                temp[k++] = arr[i++];
            }
            else{
                inversion+=(mid-i+1);
                temp[k++] = arr[j++];
            }
        }
        
        while(i<=mid){
            temp[k++] = arr[i++];
        }
        
        while(j<=e){
            temp[k++] = arr[j++];
        }
        
        for(int l = s;l<=e;l++){
            arr[l] = temp[l-s];
        }
        
        return inversion;
    }
    
    long long int mergeSort(vector<int>&arr, long long s, long long e){
        long long int inversion = 0;
        
        if(s<e){
            long long int mid = s + (e-s)/2;
            inversion+=mergeSort(arr,s,mid);
            inversion+=mergeSort(arr,mid+1,e);
            inversion+=merge(arr,s,mid,e);
        }
        
        return inversion;
    }
    int numberOfInversions(vector<int>&a, int n) {
        return mergeSort(a,0,n-1);
    }
    
    void inorder(Node *root, vector<int>&nodes){
        if(!root)return;
        inorder(root->left, nodes);
        nodes.push_back(root->data);
        inorder(root->right, nodes);
    }
    
    /*You are required to complete below function */
    int pairsViolatingBST(int n, Node *root) {
        vector<int>nodes;
        inorder(root,nodes);
        //for(auto it: nodes)cout<<it<<" ";
        return numberOfInversions(nodes,n);
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    getchar();

    while (t--) {

        int n;
        cin >> n;
        getchar();

        string inp;
        getline(cin, inp);

        struct Node* root = buildTree(inp);

        Solution ob;
        int ans = ob.pairsViolatingBST(n, root);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends