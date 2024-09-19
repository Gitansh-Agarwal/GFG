//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        string word="";
        string ans="";
        stack<string> stk;
        for(auto ch: str){
            if(ch == '.'){
                stk.push(word);
                word="";
            }
            else{
                word+=ch;
            }
        }
        stk.push(word);
        int sz=stk.size();
        for(int i=0; i<sz-1; i++){
            ans+=stk.top()+".";
            stk.pop();
        }
        ans+=stk.top();
        stk.pop();
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends