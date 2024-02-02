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
        int temp = 0;
        int num = 0;
        int count = 0;
        int tCount = 0;
        for(auto it : s){
            tCount++;
            if(!(it == '-' || (it>=48 && it<=57)) || (it == '-' && tCount>1)){
                return -1;
            }
            else{
                if(it == '-'){
                    temp = 1;
                    count++;
                    if(count>1)
                        return -1;
                }
                else{
                    num = num*10 + (it - '0');
                }
            }
        }
        if(temp == 1)
            return -num;
        return num;
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
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends