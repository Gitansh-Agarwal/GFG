//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        if(n==1)
            return 10;
        list<long long int> l[10];
        l[0].assign({0, 8});
        l[1].assign({1, 2, 4});
        l[2].assign({1, 2, 3, 5});
        l[3].assign({2, 3, 6});
        l[4].assign({1, 4, 5, 7});
        l[5].assign({2, 4, 5, 6, 8});
        l[6].assign({3, 5, 6, 9});
        l[7].assign({4, 7, 8});
        l[8].assign({5, 7, 8, 9, 0});
        l[9].assign({6, 8, 9});
        
        
        long long int count[10] = {1};
        for(int i=0; i<10; i++)
            count[i]=1;
        
        for(int i=2; i<=n; i++){
            
            long long int countTemp[10]={0};
            for(int j=0; j<10; j++){
                
                for(int x:l[j]){
                    countTemp[x]+=count[j];
                }
            }
            
            for(int j=0; j<10; j++){
                count[j]=countTemp[j];
            }
        }
        
        long long int total=0;
        for(int i=0; i<10; i++){
            total+=count[i];
        }
        
        return total;
       
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends