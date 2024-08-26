//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int num=0;
    int sign=1;//1 for positive and -1 for negative.
    int n=s.size();
    int i=0;
    while(i<n && s[i]==' '){
        i++;
    } 

    //i is at a non-white space character.
    //try to read the sign if present.
    if(s[i]=='-'){
        sign=-1;
        i++;
    }
    else if(s[i]=='+'){
        sign=1;
        i++;
    }

    for(; i<n; i++){
        
        if(s[i]>=48 && s[i]<=57){
            int digit=s[i]-'0';
            if(sign == 1 && (num> (INT_MAX/10) || (num==(INT_MAX/10) && digit>=7))){
                return INT_MAX;
            }
            if(sign == -1 && (num>(INT_MAX/10) || num==(INT_MAX/10) && digit>=8)){
                return INT_MIN;
            }

            num=num*10+digit;
        }
        else {
            // break;
            return -1;
        }

    }
    return num*sign;
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
		Solution ob;
		int ans=ob.atoi(s);
		cout<<ans<<endl;
	}
}
// } Driver Code Ends