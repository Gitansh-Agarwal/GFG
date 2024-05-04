//{ Driver Code Starts
import java.util.*;
import java.io.*;

class Node{
    int data;
    Node next;
    
    Node(int x){
        data = x;
        next = null;
    }
    
}
class GFG{
	static void printList(Node node) 
	{ 
		while (node != null) 
		{ 
			System.out.print(node.data + " "); 
			node = node.next; 
		} 
		System.out.println(); 
	}
    public static void main(String args[]) throws IOException { 
        
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t > 0){
        
        	int n = sc.nextInt();
        
            Node head = new Node(sc.nextInt());
            Node tail = head;
        
            for(int i=0; i<n-1; i++)
            {
                tail.next = new Node(sc.nextInt());
                tail = tail.next;
            }
        
            Solution ob = new Solution();
            head = ob.reverseList(head);
            printList(head); 
            t--;
        }
    } 
} 
   
// } Driver Code Ends


//function Template for Java

/* linked list node class:

class Node {
    int data;
    Node next;
    Node(int value) {
        this.value = value;
    }
}

*/

class Solution
{
    //Function to reverse a linked list.
    Node reverseList(Node head)
    {
        // code here
        //TC=O(N), SC=O(1).
        //Using three Pointers
        // ListNode prev=null, curr=null, front=head;
        // while(front!=null){
        //     prev=curr;
        //     curr=front;
        //     front=front.next;
        //     curr.next=prev;
        // }
        // head=curr;
        // return head;
        
        
        //TC=O(N), SC=O(N){recursion stack space.}
        //Using Recursion.
        if(head==null || head.next==null){
            return head;
        }
        Node newHead = reverseList(head.next);
        Node front = head.next;
        front.next=head;
        head.next=null;
        
        return newHead;
    }
}
