//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        //The below code is giving runtime error as the value is too large to be converted into int or
        // long long int.
        
        // long long int val = stoi(s);
        // if(val%8==0)
        //     return true;
        // return false;
        
        // For checking divisibility by 8 check if the number's last three digits are divisible by 8 or not.
        int n=s.size();
        if(n<3){
            while(n<3){
                s = '0' + s;
                n++;
            }
        }
        
        int number = 0;
        for(int i=n-3; i<=n-1; i++){
            number = number*10 + (s[i] - '0');
        }
        
        if(number%8 == 0)
            return 1;
        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends