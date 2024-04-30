//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
   Node *Reverse(Node* head){ 
        
        if(head==NULL || head->next==NULL){
            return head;
        } 
        
        Node* curr=head; 
        Node* prev=NULL; 
        
        while(curr!=NULL){
             
             Node* nextNode=curr->next; 
             curr->next=prev; 
             prev=curr; 
             curr=nextNode;
        }
        
        
       return prev;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {  
        
       
        
        num1=Reverse(num1); 
        num2=Reverse(num2); 
       
       int c=0;  
       Node* prev=NULL; 
       Node* head=NULL; 
       
       while(num1!=NULL || num2!=NULL || c!=0){ 
           int d1=0;
            if(num1!=NULL){
              d1=num1->data;  
            } 
            
           int d2=0;  
           if(num2!=NULL){
              d2=num2->data;  
            } 
           
           int d=d1+d2+c; 
           int r=d%10; 
             c=d/10;
           Node* newNode=new Node(r);  
           if(prev!=NULL){
           prev->next=newNode; 
           }else{
               head=newNode;
           }
           prev=newNode; 
           
           if(num1!=NULL){
               num1=num1->next; 
           }
           if(num2!=NULL){
              num2=num2->next;  
           }
          
       } 
       
       
       head=Reverse(head); 
       
        while(head != NULL && head->data == 0){
            head = head->next;
        } 
        
        if(head == NULL){
            return new Node(0);
        }
      
       return head;
       
    }

};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends