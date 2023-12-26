//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  vector<vector<int>> sumZeroMatrix(vector<vector<int>> a){
      //Code Here
      int m = a.size();
      int n = a[0].size();
      
      //Creating the prefix sum matrix(we are making the prefix sum matrix by calculating prefix sum row by row.)
      vector<vector<int>> sum(m , vector<int>(n,0));
      //Initializing the prefix sum matrix of rows(means each row's prefix sum array).
      for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
              sum[i][j]+=a[i][j] + (j>0?sum[i][j-1]:0);
          }
      }
      
      
      int max_area = 0, startRow = -1, endRow = -1, startColumn = -1, endColumn = -1;
      int area;
      //taking every subarray of columns.
      for(int c1=0; c1<n; c1++){
          for(int c2=c1; c2<n; c2++){
              
              //getting every submatrix one by one.
              vector<int> temp(m);
              for(int i=0; i<m; i++){
                  temp[i] = sum[i][c2] - (c1>0?sum[i][c1-1]:0);
              }
              int currSum = 0;//It calculates the prefix sum of choosen subarray of columns column-wise.
              
              
              
              unordered_map<int,int> mp;
              mp[0] = -1;
              for(int i=0; i<m; i++){
                  currSum+=temp[i];
                  
                  if(mp.find(currSum)!=mp.end()){
                      area = (i-mp[currSum])*(c2-c1+1);
                      if(area>max_area){
                          max_area = area;
                          startColumn = c1;
                          endColumn = c2;
                          startRow = mp[currSum]+1;
                          endRow = i;
                      }
                  }
                  else{
                      mp[currSum] = i;
                  }
              }
          }
      }
      
      //Storing the largest rectangular sub-matrix by area whose sum is (0).
      vector<vector<int>> ans;
      if(max_area = 0) return ans;
      for(int i=startRow; i<=endRow; i++){
          vector<int> t;
          for(int j=startColumn; j<=endColumn; j++){
              t.push_back(a[i][j]);
          }
          ans.push_back(t);
      }
      return ans;
  }
};


//{ Driver Code Starts.




int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        Solution ob;
        vector<vector<int>> ans = ob.sumZeroMatrix(a);
        if(ans.size() == 0){
            cout<<-1<<endl;
        }
        else{
            for(int i=0;i<ans.size();i++){
                for(int j=0;j<ans[0].size();j++){
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends