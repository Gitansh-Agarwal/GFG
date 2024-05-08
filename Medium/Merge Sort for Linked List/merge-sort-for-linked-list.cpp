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
    //Function to sort the given linked list using Merge Sort.
    Node* middNode(Node* head){
        Node *slow=head, *fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    //OR Midlle node m1(even length LL) or simply middle node in LL can also be find out using the below method.
    // Node* middNode(Node* head){
    //     Node *slow=head, *fast=head;
    //     while(fast->next!=nullptr && fast->next->next!=nullptr){
    //         slow=slow->next;
    //         fast=fast->next->next;
    //     }
    //     return slow;
    // }
    
    
    Node* merge2SortedLL(Node* leftHead, Node* rightHead){
        Node *mergeHead=nullptr, *temp=nullptr;
        while(leftHead!=nullptr && rightHead!=nullptr){
            if(leftHead->data < rightHead->data){
                if(mergeHead==nullptr){
                    mergeHead=leftHead;
                    temp=leftHead;
                }
                else{
                    temp->next=leftHead;
                    temp=temp->next;
                }
                leftHead=leftHead->next;
            }
            else{
                if(mergeHead==nullptr){
                    mergeHead=rightHead;
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
        return mergeHead;
    }
    Node* mergeSort(Node* head) {
        // your code here
        //Method 1=Brute Force Method
        //TC=O(N + NlogN + N)
        //SC=O(N).
//         Node* temp=head;
//         vector<int> tempVec;
//         while(temp!=nullptr){
//             tempVec.push_back(temp->val);
//             temp=temp->next;
//         }
        
//         sort(tempVec.begin(), tempVec.end());
        
//         temp=head;
//         int i=0;
//         while(temp!=nullptr){
//             temp->val=tempVec[i++];
//             temp=temp->next;
//         }
//         return head;
        
        
        
        //Method 2
        //TC=O(logN*(N+N/2)) = O(NlogN).
        //SC=O(logN)//Recursive Stack Space.
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        
        Node *middleNode = middNode(head);//TC=O(N/2)
        Node *rightHead=middleNode->next;
        middleNode->next=nullptr;
        Node *leftHead=head;
        
        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);
        
        return merge2SortedLL(leftHead, rightHead);//O(N)
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