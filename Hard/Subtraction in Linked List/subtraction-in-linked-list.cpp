//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
Node* reverse(Node* head)
    {
        if(head==NULL || head->next == NULL)
        {
            return head;
        }
        Node* realhead = reverse(head->next);
        Node* temp = head->next;
        temp->next = head;
        head->next = NULL;
        return realhead;
    }
int len(Node* head)
{
    int len = 0;
    while(head)
    {
        len++;
        head = head->next;
    }
    return len;
}
void trailzero(Node* &head)
{
    while(head and head->data == 0)
    {
        head = head->next;
    }
}
int compare(Node* first, Node* second)
{
    trailzero(first);
    trailzero(second);
    int l1 = len(first);
    int l2 = len(second);
    if(l1>l2)
    {
        return 1;
    }
    else if(l2>l1)
    {
        return 2;
    }
    else
    {
        while(first)
        {
            if(first->data>second->data)
            {
                return 1;
            }
            else if(first->data<second->data)
            {
                return 2;
            }
            else
            {
                first = first->next;
                second = second->next;
            }
        }
    }
    return 3;
}
Node* subLinkedList(Node* first, Node* second)
{
    int l = compare(first,second);
        Node* head1 = new Node(-1);
        Node* tail1 = head1;
        Node* head2 = new Node(-1);
        Node* tail2 = head2;
        first = reverse(first);
        second = reverse(second);
    if(l == 1 || l == 3)
    {
        head1->next = first;
        head2->next = second;
    }
    else
    {
        head1->next = second;
        head2->next = first;        
    }
        if(tail1->next != NULL)
        tail1 = tail1->next;
        if(tail2->next != NULL)
        tail2 = tail2->next;
        while(tail1 != NULL and tail2 != NULL)
        {
            if(tail1->data < tail2->data)
            {
                tail1->data = tail1->data - tail2->data + 10;
                tail1->next->data = tail1->next->data -1;
            }
            else
            {
                tail1->data = tail1->data - tail2->data;
            }
            tail1 = tail1->next;
            tail2 = tail2->next;
        }
        while(tail1 and tail1->data == -1)
        {
            tail1->data = tail1->data + 10;
            tail1->next->data = tail1->next->data - 1;
            tail1 = tail1->next;
        }
        head1 = reverse(head1->next);
        while(head1->next != NULL and head1->data == 0)
        head1=head1->next;
        
        return head1;
}
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends