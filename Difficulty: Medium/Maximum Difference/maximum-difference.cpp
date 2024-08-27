//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        int n=arr.size();
        stack<int> st,stk1;
        st.push(arr[0]);
        
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        for(int i=1; i<n; i++){
            while(!st.empty() && arr[i]<=st.top()){
                st.pop();
            }
            if(!st.empty()){
                left[i]=st.top();
            }
            st.push(arr[i]);
        }
        
        stk1.push(arr[n-1]);
        for(int i=n-2; i>=0; i--){
            while(!stk1.empty() && arr[i]<=stk1.top()){
                stk1.pop();
            }
            
            if(!stk1.empty()){
                right[i]=stk1.top();
            }
            stk1.push(arr[i]);
        }
        
        int ans=INT_MIN;
        for(int i=0; i<n; i++){
            if(ans<(abs(left[i]-right[i]))){
                ans=abs(left[i]-right[i]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends