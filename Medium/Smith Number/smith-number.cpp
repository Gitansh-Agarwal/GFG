//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    int sumDigits(int x){
        int sum=0;
        while(x!=0){
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    
    bool isPrime(int x){
        if(x==1){
            return 0;
        }
        
        for(int i=2; i<=sqrt(x); i++){
            
            if(x%i==0){
                return 0;
            }
        }
        return 1;
    }
    
    int smithNum(int n) {
        // code here
        
        // int temp=n;
        // int sum1=0,sum2=0;
        // int digit;
        // if(isPrime(n) || n==1){
        //     return 0;
        // }
        // while(temp!=0){
        //     digit=temp%10;
        //     sum1+=digit;
        //     temp=temp/10;
        // }
        
        // int i=2;
        // while(n>1){
            
        //     while(n%i==0){
        //         sum2+=i;
        //         n=n/i;
        //     }
        //     i++;
        // }
        
        // if(sum1==sum2){
        //     return 1;
        // }
        // return 0;
        if(isPrime(n)){
            return 0;
        }
        int sum = sumDigits(n);
        int sum2 = 0;
        int s;
        
        for(int i=2; i<=n; i++){
            
            if(n%i == 0){
                s = sumDigits(i);
                while(n%i == 0){
                    sum2+= s;
                    n = n/i;
                }
            }
        }
        if(sum == sum2){
            return 1;
        }
        return 0;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends