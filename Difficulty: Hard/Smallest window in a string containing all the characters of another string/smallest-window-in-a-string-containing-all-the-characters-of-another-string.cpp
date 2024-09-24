//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    private:
    bool isSame(int *p, int *s){
        for(int i=0; i<26; i++){
            if(p[i] > s[i]){
                return false;
            }
        }
        return true;
    }
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int *cnt1 = new int[26];
        int *cnt2 = new int[26];
        
        for(int i=0; i<26; i++){
            cnt1[i] = 0;
            cnt2[i] = 0;
        }
        int n = s.length();
        int m = p.length();
        for(int i=0; i<m; i++){
            cnt1[p[i] - 'a']++;
        }
        
        int st=-1;
        int end=-1;
        int i=0; 
        int j=0;
        
        while(j<n){
            cnt2[s[j] - 'a']++;
            
            while(isSame(cnt1, cnt2)){
                if(st == -1){
                    st=i;
                    end = j;
                }
                else if(end-st+1 > j-i+1){
                    st=i;
                    end=j;
                }
                cnt2[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        
        if(st == -1){
            return "-1";
        }
        else{
            return s.substr(st, end-st+1);
        }
        
        
        
        
        
        
        
        
        //before returning 
        delete []cnt1;
        delete []cnt2;
        cnt1=nullptr;
        cnt2=nullptr;
        
        
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends