//{ Driver Code Starts
//Initial template code for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
//User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
         //TC=O(N),
        //SC=O(N).
        // if(head==nullptr || head->next==nullptr){
        //     return false;
        // }
        // ListNode *tempHead=head;
        // unordered_set<ListNode*> st;
        // while(tempHead!=nullptr && st.find(tempHead)==st.end()){
        //     st.insert(tempHead);
        //     tempHead=tempHead->next;
        // }
        // if(tempHead==nullptr){
        //     return false;
        // }
        // return true;
        
        
        
        //Optimal Solution= Floyd's Tortoise and Hare Algorithm.
        //TC=O(N)
        //SC=O(1).
        // if(head==nullptr || head->next==nullptr)
        //     return false;
        // ListNode *slow=head;
        // ListNode *fast=head;
        // do{
        //     slow=slow->next;
        //     fast=fast->next;
        //     if(fast)
        //         fast=fast->next;
        // }while(slow!=fast && fast!=nullptr);
        // if(slow==fast)
        //     return true;
        // return false;
        
        
        // or

        Node *slow=head, *fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast)
                return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        if(ob.detectLoop(head) )
            cout<< "True\n";
        else
            cout<< "False\n";
    }
	return 0;
}

// } Driver Code Ends