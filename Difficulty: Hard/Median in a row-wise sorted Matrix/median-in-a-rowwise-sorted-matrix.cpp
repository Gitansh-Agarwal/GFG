//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int upperBound(vector<int> arr, int m, int x){
        int ans=m;
        int low=0, high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid] > x){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
    int smallerEquals(vector<vector<int>> &matrix, int n, int m, int mid){
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=upperBound(matrix[i], m, mid);
        }
        return cnt;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0, high=0;
        int req=R*C/2;
        for(int i=0; i<n; i++){
            low=min(low, matrix[i][0]);
            high=max(high, matrix[i][m-1]);
        }
        
        while(low<=high){
            int mid=(low+high)/2;
            
            int smallEquals = smallerEquals(matrix, n, m, mid);
            if(smallEquals <= req){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
        
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends