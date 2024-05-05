//{ Driver Code Starts
//Initial Template for C++

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
//User function Template for C++

/*struct Node
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
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        // your code here
        //TC=O(N*2*logN) or (N*2*1)
        //SC=O(N).
        unordered_set<Node*> st;
        
        if(head==nullptr || head->next==nullptr){
            return -1;
        }
        
        Node *temp=head;
        while(temp!=nullptr){
            if(st.find(temp)!=st.end()){
                break;
            }
            st.insert(temp);
            temp=temp->next;
        }
        if(temp==nullptr){
            return -1;
        }
        return temp->data;
        
        
        
        //Optimal Method
        //TC=O(N).
        //SC=O(1).
        // ListNode *slow=head, *fast=head;
        // while(fast!=nullptr && fast->next!=nullptr){
        //     slow=slow->next;
        //     fast=fast->next->next;
            
        //     if(slow==fast){
        //         slow=head;
        //         while(slow!=fast){
        //             slow=slow->next;
        //             fast=fast->next;
        //         }
        //         return slow;//Both fast and slow are standing at the starting point of loop in the linked list.
        //     }
        // }
        // return nullptr;
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
        int ans = ob.findFirstNode(head);
        cout<<ans<<"\n";
    }
	return 0;
}
// } Driver Code Ends