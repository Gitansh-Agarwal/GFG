//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node* reverse(Node* head){
        Node *prev=nullptr, *curr=nullptr, *front=head; 
        while(front!=nullptr){
            prev=curr;
            curr=front;
            front=front->next;
            curr->next=prev;
        }
        head=curr;
        
        return head;
    }

    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *slow=head, *fast=head;
        //Here slow will point to middle node m1 and not on middle node m2.
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node *newHead=reverse(slow->next);
        Node *first=head, *second=newHead;
        while(second!=nullptr){
            if(first->data!=second->data){
                //restoring the original linked list.
                reverse(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverse(newHead);
        return true;  
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends