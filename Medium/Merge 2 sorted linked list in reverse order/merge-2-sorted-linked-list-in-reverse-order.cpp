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
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        //merging two sorted linked lists in sorted order.
        int flag = 0;
        Node* merge = nullptr;
        Node* p=merge;
        if(node1 == nullptr || node2 == nullptr){
            if(node1 == nullptr && node2 == nullptr)
                return merge;
            else if(node1 == nullptr){
                merge =  node2;
                flag = 1;
            }
            else{
                merge =  node1;
                flag =1;
            }
        }
        
        while(node1 && node2){
            if(!merge){
                if(node1->data < node2->data){
                    merge = node1;
                    p=merge;
                    node1=node1->next;
                }
                else{
                    merge = node2;
                    p=merge;
                    node2=node2->next;
                }
            }
            else if(node1->data < node2->data){
                p->next = node1;
                p=p->next;
                node1=node1->next;
            }
            else{
                p->next=node2;
                p=p->next;
                node2=node2->next;
            }
                
        }
         
        if(flag == 0){
            if(!node1)
                p->next = node2;
            else
                p->next = node1;
        }
            
        
        // reversing two linked lists
        Node* pt=merge;
        Node* q=nullptr;
        Node* r=nullptr;
        while(pt!=nullptr){
            r=q;
            q=pt;
            pt=pt->next;
            q->next=r;
        }
        merge = q;
        return merge;
        // return merge;
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