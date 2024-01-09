//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector<int> prefix_function(string s) {
            int n = (int)s.length();
            vector<int> pi(n);
            for (int i = 1; i < n; i++) {
                int j = pi[i-1];
                while (j > 0 && s[i] != s[j])
                    j = pi[j-1];
                if (s[i] == s[j])
                    j++;
                pi[i] = j;
            }
            return pi;
        }
        vector <int> search(string pat, string txt)
        {
            //code here
            // int temp;
            // vector<int> ans;
            // if(pat.size()>txt.size()){
            //     ans.push_back(-1);
            // }
            // else{
            //     for(int i=0; i<txt.size(); i++){
            //         int temp = i;
            //         int j=0;
            //         if(txt[i] == pat[j]){
            //             i++;
            //             j++;
            //             while(j!=pat.size() && txt[i] == pat[j]){
            //                 i++;
            //                 j++;
            //             }
            //             if(j==pat.size()){
            //                 ans.push_back(temp+1);
            //             }
            //             // i--;
            //         }
            //         i=temp;
                    
            //     }
            // }
            
            // return ans;
            
            // OR
            //Using substr() function
            // vector<int> ans;
            // int n = txt.size();
            // int m = pat.size();
            // if(m>n)
            //     return {-1};
            // for(int i=0; i<n-m+1; i++){
            //     if(txt[i] == pat[0]){
            //         if(txt.substr(i,m) == pat){
            //             ans.push_back(i+1);
            //         }
            //     }
            // }
            // return ans;
            
            //OR
            //Using KMP- Algorithm
            
            string look = pat + '?' + txt;
            
            vector<int> kmp = prefix_function(look);
            
            vector<int> ans;
            
            int start = 2*pat.size();
            
            for(int i=start; i<look.size(); i++){
                if(kmp[i] == pat.size()){
                    ans.push_back(i-start+1);
                }
            }
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends