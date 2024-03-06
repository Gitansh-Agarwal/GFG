//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            //code here.
            // vector<int> ans;
            // int n=text.size();
            // for(int i=0; i<n; i++){
            //     if(text[i] == pattern[0]){
                    
                    
            //         int index=i+1;
            //         int k=0;
            //         while(text[i]==pattern[k] && k<pattern.size()){
            //             i++;
            //             k++;
            //         }
            //         if(text[i]==pattern[0] && text[i-1]==pattern[0]){
            //             i--;
            //         }
            //         if(k==pattern.size()){
            //             ans.push_back(index);
            //         }
            //     }
            // }
            // return ans;
            
            
            
            vector<int>res;
            int q=101;
            int d=26;
            int M=pattern.size();
            int N=text.size();
            int p=0;
            int t=0;
            int h=1;
            
            //h=pow(d,M-1)%q;
            for(int i=0;i<M-1;i++){
                h=(h*d)%q;
            }
            
            //calcualate the hash value of pattern and first window of text
            for(int i=0;i<M;i++){
                p=(d*p+pattern[i])%q;
                t=(d*t+text[i])%q;
            }
            
            //slide the pattern over thext one by one
            for(int i=0;i<=N-M;i++){
                //check the hash if they are equal
                if(p==t){
                    //check for characters one by one
                    int j=0;
                    for(j=0;j<M;j++){
                        if(text[i+j]!=pattern[j]){
                            break;
                        }
                    }
                    if(j==M){
                        res.push_back(i+1);
                    }
                    
                }
                if(i<N-M){
                    t=(d*(t-text[i]*h)+text[i+M])%q;
                    if(t<0){
                        t=t+q;
                    }
                }
            }
            return res;
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
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends