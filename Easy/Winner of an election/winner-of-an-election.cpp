//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got

        //Below code has a Time Complexity = O(nlogn) and Space Complexity = O(n) and so it gives TLE Error.
        // map<string, int> mp;
        // for(int i=0; i<n; i++){
        //     mp[arr[i]]++;
        // }
        // int max_votes = 0;
        // string ans;
        // vector<string> res;
        // for(auto i : mp){
        //     if(i.second > max_votes){
        //         ans = i.first;
        //         max_votes = i.second;
        //     }
        // }
        // res.push_back(ans);
        // res.push_back(to_string((mp[ans])));
        // return res;
        
        
        //Below code has a Time Complexity = O(n) and Space Complexity = O(n).
        unordered_map<string, int> ump;
        for(int i=0; i<n; i++){
            ump[arr[i]]++;
        }
        
        string ans = "";
        int vote = 0;
        vector<string> answer;
        
        for(int i=0; i<n; i++){
            if(ump[arr[i]] > vote){
                ans = arr[i];
                vote = ump[arr[i]];
            }
            else if(ump[arr[i]] == vote){
                ans = min(ans, arr[i]);
            }
        }
        
        string v = to_string(vote);
        answer.push_back(ans);
        answer.push_back(v);
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends