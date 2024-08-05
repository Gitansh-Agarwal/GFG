//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
public:
    int cntt=0;
Node* merge(Node* root, Node* second){
	Node* temp=nullptr;
	Node* first=root;
	
	// //make both root's node next as nullptr.
	first->next=nullptr;
	second->next=nullptr;
    		if(first->data < second->data){
    			root=first;
    			temp=root;//temp=first;
    			first=first->bottom;
    // 			temp->next=nullptr;
    		}
    		else{
    			root=second;
    			temp=root;//temp=second;
    			second=second->bottom;
    // 			temp->next=nullptr;
    		}
    
    		while(first!=nullptr && second!=nullptr){
    			if(first->data < second->data){
    				temp->bottom=first;
    				temp=first;
    				first=first->bottom;
    				// temp->next=nullptr;
    			}
    			else{
    				temp->bottom=second;
    				temp=second;
    				second=second->bottom;
    				// temp->next=nullptr;
    			}
    		}
    		if(first!=nullptr){
    		    temp->bottom=first;
    		}
    		else{
    		    temp->bottom=second;
    		}
	    return root;
	
    }
    Node *flatten(Node *root)
    {
        // Your code here
        if(root->next==nullptr){
		    return root;
    	}
    	
    	else{
    		Node* third=root->next;
    		Node* second=nullptr;
    		// int cnt=0;
    		
    		while(third!=nullptr && third->next!=nullptr){
    			second = third;
    			third = third->next;
    			
    			// second->next=nullptr;
    			cntt++;
    			root = merge(root,second);
    			// cnt++;
    // 			if(cntt==1){
    // 				return root;
    // 			}
    		}
    		if(third!=nullptr && third->next==nullptr){
    			cntt++;
    			root = merge(root, third);
    		}
    	}
    	return root;
    }
};


//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends