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
        // code here
        Node *oddHead=nullptr, *evenHead=nullptr;
        Node *temp1, *temp2;
        Node *temp=head;
        while(temp!=nullptr){
            if((temp->data)%2 != 0){
                if(oddHead==nullptr){
                    oddHead=temp1=temp;
                }
                else{
                    temp1->next=temp;
                    temp1=temp1->next;
                }
                
            }
            else{
                if(evenHead==nullptr){
                    evenHead=temp2=temp;
                }
                else{
                    temp2->next=temp;
                    temp2=temp2->next;
                }
            }
            temp=temp->next;
        }
        if(oddHead==nullptr){
            return evenHead;
        }
        else if(evenHead==nullptr){
            return oddHead;
        }
        else{
            temp1->next=nullptr;
            temp2->next=oddHead;
            
            return evenHead;
        }
        
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