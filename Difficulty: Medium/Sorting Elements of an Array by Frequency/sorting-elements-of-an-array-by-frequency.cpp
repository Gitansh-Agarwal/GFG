//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    static bool sortbyCond(const pair<int, int>& a, const pair<int, int>& b)
    {
        if(a.second != b.second){
            return a.second > b.second;
        }
        else{
            return a.first < b.first;
        }
    }
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        map<int, int> mpp;
        int n=arr.size();
        for(int i=0; i<n; i++){
            mpp[arr[i]]++;
        }
        vector<pair<int, int> > pairs;
        for (auto& it : mpp) { 
            pairs.push_back(it); 
        } 
        sort(pairs.begin(), pairs.end(), sortbyCond);
        // for(auto it:pairs){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        vector<int> ans(n);
        int i=0;
        for(auto it: pairs){
            while(it.second){
                ans[i++]=it.first;
                it.second--;
            }
        }
        return ans;
        // return {};
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends