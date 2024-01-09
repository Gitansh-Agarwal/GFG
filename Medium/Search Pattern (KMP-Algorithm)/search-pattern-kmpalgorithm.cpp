//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            int temp;
            vector<int> ans;
            if(pat.size()>txt.size()){
                ans.push_back(-1);
            }
            else{
                for(int i=0; i<txt.size(); i++){
                    int temp = i;
                    int j=0;
                    if(txt[i] == pat[j]){
                        i++;
                        j++;
                        while(j!=pat.size() && txt[i] == pat[j]){
                            i++;
                            j++;
                        }
                        if(j==pat.size()){
                            ans.push_back(temp+1);
                        }
                        // i--;
                    }
                    i=temp;
                    
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