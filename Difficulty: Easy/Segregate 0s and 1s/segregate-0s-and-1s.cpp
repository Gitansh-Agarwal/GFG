//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void swap(int& a, int &b){
      a=a+b;
      b=a-b;
      a=a-b;
  }
    void segregate0and1(vector<int> &arr) {
        // code here
        int n=arr.size();
        int low=0; 
        int high=n-1;
        
        while(low<high){
            if(arr[low]==1){
                swap(arr[low], arr[high]);
                high--;
            }
            else if(arr[low]==0){
                low++;
            }
            else if(arr[high]==1){
                high--;
            }
            else if(arr[high]==0){
                swap(arr[low],arr[high]);
                low++;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends