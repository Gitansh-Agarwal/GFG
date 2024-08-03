//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>> vec;
        for(int i=0; i<n; i++){
            vec.push_back({end[i],start[i]});
        }
        sort(vec.begin(), vec.end());
        
        int maxNoOfMeetings=1;
        int endTime=vec[0].first;
        for(int i=1; i<n; i++){
            if(endTime < vec[i].second){
                maxNoOfMeetings++;
                endTime=vec[i].first;
            }
            // else 
                // maxNoOfMeetings=0;
        }
        return maxNoOfMeetings;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends