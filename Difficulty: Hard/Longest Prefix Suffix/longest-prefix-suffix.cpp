//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int lps(string str) {
        // Your code goes here
        vector<int> lp(str.size(), 0);
        int length=0;
        int i=1;
        while(i<str.size()){
            if(str[i] == str[length]){
                length++;
                lp[i] = length;
                i++;
            }
            else{
                if(length!=0){
                    length = lp[length-1];
                }
                else{
                    i++;
                }
            }
        }
        return lp.back();
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}

// } Driver Code Ends