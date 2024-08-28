//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  private:
    Node* findMiddle(Node* head){
        Node* slow=head;
        Node* fast=head;
        
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    Node* mergedList(Node* leftHead, Node* rightHead){
        Node *mergedHead=nullptr, *temp=nullptr;
        while(leftHead!=nullptr && rightHead!=nullptr){
            if(leftHead->data < rightHead->data){
                if(mergedHead==nullptr){
                    mergedHead=leftHead;
                    temp=leftHead;
                }
                else{
                    temp->next=leftHead;
                    temp=temp->next;//temp=leftHead;
                }
                leftHead=leftHead->next;
            }
            else{
                if(mergedHead==nullptr){
                    mergedHead=rightHead;
                    temp=rightHead;
                }
                else{
                    temp->next=rightHead;
                    temp=temp->next;
                }
                rightHead=rightHead->next;
            }
        }
        
        if(leftHead==nullptr){
            temp->next=rightHead;
        }
        else{
            temp->next=leftHead;
        }
        
        return mergedHead;
    }
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

        // Add code here
        //Using Extra Space.
        //TC=O(2*N).
        //SC=O(3) = O(1).
        // int hash[3]={0};
        // Node* temp=head;
        // while(temp!=nullptr){
        //     hash[temp->data]++;
        //     temp=temp->next;
        // }
        
        // int i=0;
        // temp=head;
        // while(temp!=nullptr){
        //     if(hash[i]>0){
        //         temp->data=i;
        //         temp=temp->next;
        //         hash[i]--;
        //         if(hash[i]==0){
        //             i++;
        //         }
        //     }
        //     else{
        //         i++;
        //     }
        // }
        // return head;
        
        
        
        
        //Using merge Sort on Linked List to sort the list.
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        Node *middleNode=findMiddle(head);
        Node *rightHead= middleNode->next;
        middleNode->next=nullptr;
        Node *leftHead=head;
        
        leftHead=segregate(leftHead);
        rightHead=segregate(rightHead);
        
        return mergedList(leftHead, rightHead);
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends