//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    struct Node *merge(Node *n1,Node *n2)
    {
        if(!n1 && !n2)
        return NULL;
        else if(!n1)
        return n2;
        else if(!n2)
        return n1;
        else if(n1->data <= n2->data)
        {
            n1->next = merge(n1->next,n2);
            return n1;
        }
        else{
            n2->next=merge(n1,n2->next);
            return n2;
        }
    }
    
    Node *rev(Node *root)
    {
           Node* prev = NULL;
        while(root) {
            Node* nxt = root->next;
            root ->next = prev;
            prev = root;
            root = nxt;
        }
        
        return prev;
    }
    struct Node * mergeResult(Node *node1,Node *node2)
    {
         Node *root = merge(node1, node2);
        root = rev(root);
        return root;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends