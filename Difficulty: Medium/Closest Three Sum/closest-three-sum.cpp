//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int resultSum=arr[0]+arr[1]+arr[2];
        int minDifference=INT_MAX;
        int n=arr.size();
        
        for(int i=0; i<n-2; i++){
            int left=i+1;
            int right=n-1;
            
            while(left<right){
                int sum=arr[i]+arr[left]+arr[right];
                
                if(sum==target){
                    return sum;
                }
                else if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
                
                int diffToTarget=abs(sum-target);
                if(diffToTarget < minDifference){
                    resultSum=sum;
                    minDifference = diffToTarget;
                }
                else if(diffToTarget == minDifference){
                    resultSum=max(resultSum, sum);
                }
                
            }
        }
        return resultSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends