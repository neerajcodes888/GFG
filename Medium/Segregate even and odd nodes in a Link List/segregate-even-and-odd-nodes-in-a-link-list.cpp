//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int N, Node *head){
      Node *evenStart=new Node(-1);
      Node *evenEnd=evenStart;
      Node *oddStart=new Node(-1);
      Node *oddEnd=oddStart;
       Node *curr=head;
    //   while(curr!=NULL)
    //   {
    //       int val = curr->data;
    //       if(val%2==0)
    //       {
    //           if(evenStart==NULL)
    //           {
    //               evenStart=curr;
    //               evenEnd=evenStart;
    //           }
    //           else{
    //               evenEnd->next=curr;
    //               evenEnd=evenEnd->next;
    //           }
    //       }
    //       else{
    //           if(oddStart==NULL)
    //           {
    //               oddStart=curr;
    //               oddEnd=oddStart;
    //           }
    //           else{
    //               oddEnd->next=curr;
    //               oddEnd=oddEnd->next;
    //           }
    //       }
    //       curr=curr->next;
    //   }
    //   evenEnd->next=oddStart;
    //   oddEnd->next=NULL;
    //   head=evenStart;
    //   return head;
    while(curr!=NULL)
    {
        if(curr->data%2==0)
        {
            evenEnd->next=curr;
            evenEnd=evenEnd->next;
        }
        else{
            oddEnd->next=curr;
            oddEnd=oddEnd->next;
        }
        curr=curr->next;
    }
    evenEnd->next=oddStart->next;
    oddEnd->next=NULL;
    head=evenStart->next;
    return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends