//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:

Node *mergeList(Node *root1,Node *root2)
{
    if(!root1)
    return root2;
   else if(!root2)
    return root1;
  else  if(!root1 && !root2)
    return NULL;
  else  if(root1->data<=root2->data)
    {
        root1->next=mergeList(root1->next,root2);
        return root1;
    }
    else{
        root2->next=mergeList(root1,root2->next);
        return root2;
    }
}
Node* mergeSort(Node* head) {
    if(!head || !head->next)
    return head;
    Node *temp=NULL;
    Node *slow=head,*fast=head;
    while(fast && fast->next)
    {
        temp=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    temp->next=NULL;
    Node *l1=mergeSort(head);
    Node *l2=mergeSort(slow);
    return mergeList(l1,l2);
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends