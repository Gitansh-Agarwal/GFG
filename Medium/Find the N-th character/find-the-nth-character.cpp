//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        //TC=O(r*|s|* 2^r)
        //Below code is giving TLE Error.
        // for(int i=0; i<r; i++){
        //     string temp="";
        //     for(auto it:s){
        //         if(it == '0'){
        //             temp+="01";
        //         }
        //         else{
        //             temp+="10";
        //         }
        //     }
        //     s=temp;
        // }
        // return s[n];
        
        
        
        //Optimized Approach 
        //TC=O(r) {no. of recursive calls}
        //SC=O(r) {recursion calls Stack Space}.
        
        if(r==0) return s[n];
        
        char c=nthCharacter(s, r-1, n/2);
        
        if(n%2==1){
            if(c=='0'){
                return '1';
            }
            else{
                return '0';
            }
        }
        else{
            if(c=='0'){
                return '0';
            }
            else{
                return '1';
            }
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends