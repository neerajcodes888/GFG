//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

// struct Node
// {
// 	int data;
// 	struct Node *next;
	
// 	Node(int x){
// 	    data =x;
// 	    next = NULL;
// 	}
// };

class Solution
{
    public:
Node*reverse(Node*head)
{
   Node*curr=head;
   Node*prev=NULL;
  while(curr!=NULL)
  {
     Node*next=curr->next;
     curr->next=prev;
     prev=curr;
     curr=next;
  }
  return prev; 
}


Node*mergesort(Node*head,Node*headh)
{
  Node*ans=new Node(-1);
  Node*temp=ans;
  while(head!=NULL&&headh!=NULL)
  {
     if(head->data<headh->data)
     { Node*new1=new Node(head->data);
         temp->next=new1;
         temp=temp->next;
         head=head->next;
     }
     
     else
     { Node*new1=new Node(headh->data);
         temp->next=new1;
         temp=temp->next;
         headh=headh->next;
         }
  }
  while(head!=NULL) 
  {    temp->next=head;
         temp=temp->next;
         head=head->next;
  }
    while(headh!=NULL) 
  {    temp->next=headh;
         temp=temp->next;
         headh=headh->next;
  }
  ans= ans->next;
  return ans;
}
void sort(Node **head)
{  Node*head1=(*head);
if (head1 == nullptr || head1->next == nullptr)
        return;
     Node*head2=(*head)->next;
     Node*headh=(*head)->next;
     while(head2->next!=NULL&&head2!=NULL)
     {
         head1->next=head1->next->next;
         head1=head1->next;
         
         if(head2->next->next==NULL)
         {
             head2->next=NULL;
         }else
         {
       head2->next  =head2->next->next;
        head2= head2->next;}
        
     }
     head1->next=NULL;
     Node*rev=reverse(headh);
    *head= mergesort(*head,rev);
}
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends