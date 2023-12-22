//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        
        vector< pair<pair<int,int>, int> > vec;
        vector<int> ans;
        int end;
        for(int i=0; i<N; i++){
            vec.push_back(make_pair(make_pair(F[i],S[i]), i+1));
        }
        
        // Below we are sorting the vector named vec and it is by default sorted on the basis of its first element
        // and here the first element is the finishing or ending time, so the vector is sorted on the basis of its
        // finishing time.
        sort(vec.begin(), vec.end());
        ans.push_back(vec[0].second);
        end = vec[0].first.first;
        for(int i=1; i<N; i++){
            if(vec[i].first.second > end){
                ans.push_back(vec[i].second);
                end = vec[i].first.first;
            }
        }
        
        //sorting the answer vector (ans).
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends