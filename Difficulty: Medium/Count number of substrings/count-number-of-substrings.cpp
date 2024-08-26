//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  private:
    long long int upto(string s, int k){
        int n=s.length();
    	int l=0, r=0;
    	long long int ans=0;
    	int cnt=0;//It will count distinct characters in the present substring from l to r.
    	vector<int> mp(26, 0);
    	while(r<n){
    	    mp[s[r]-'a']++;
    	    if(mp[s[r]-'a'] == 1)   cnt++;
    	    
    	    while(cnt>k){
    	        mp[s[l]-'a']--;
    	        if(mp[s[l]-'a'] == 0)
    	            cnt--;
    	        l++;
    	    }
    	    
    	    ans+=(r-l+1);
    	    r++;
    	}
    	return ans;
    }
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	return upto(s, k)-upto(s, k-1);
    }
};

//{ Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends