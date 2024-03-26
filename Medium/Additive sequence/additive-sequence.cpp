//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string res="";
        int i=0;
        int carry=0;
        while(i<min(num1.length(), num2.length())){
            int x=carry;
            x+=num1[i]-'0';
            x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(i<num1.length()){
            int x=carry;
            x+=num1[i]-'0';
            // x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(i<num2.length()){
            int x=carry;
            // x+=num1[i]-'0';
            x+=num2[i]-'0';
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
            i++;
        }
        while(carry){
            int x=carry;
            carry=x/10;
            x=x%10;
            res=res+to_string(x);
        }
        reverse(res.begin(), res.end());

        return res;

    }
    bool isAdditiveSequence(string n) {
        // Your code here
        int n1=n.length();
        if(n1<3) return false;
        for(int i=1;i<=n1/2;i++){
            for(int j=1;max(i,j)<=n1-i-j;j++){
                string first=n.substr(0,i);
                string second=n.substr(i,j);
                
                if(first.length()>1 && first[i]=='0'){
                    break;
                }
                if(second.length()>1 && second[i]=='0'){
                    break;
                }
                
                int start=i+j;
                string sum;
                while(start<n1){
                    sum=addStrings(first, second);
                    if(start+sum.length()>n1 || sum!=n.substr(start, sum.length())){
                        break;
                    }
                    first=second;
                    second=sum;
                    start+=sum.length();
                }
                if(start==n1){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends