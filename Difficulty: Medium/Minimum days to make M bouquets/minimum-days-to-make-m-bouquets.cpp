//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    int isPossible(vector<int>&bloomDay, int n, int day, int m, int k){
    	int noOfBouquets=0;
    	int cnt=0;
    
    	for(int i=0; i<n; i++){
    		if(bloomDay[i]<=day){
    			cnt++;
    		}
    		else{
    			noOfBouquets+=(cnt/k);
    			cnt=0;
    		}
    	}
    	noOfBouquets+=(cnt/k);
    
    	return noOfBouquets >= m;
    }

    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      //Using Binary Search
	//TC=O(n* log(maxi-mini+1)).

	int n=bloomDay.size();
	long long int val=(K*1ll) * (M*1ll);
	if(val > n)
		return -1;


	int mini=INT_MAX;
	int maxi=INT_MIN;

	for(int i=0; i<n; i++){	
		if(bloomDay[i]<mini){
			mini=bloomDay[i];
		}

		if(bloomDay[i]>maxi){
			maxi=bloomDay[i];
		}
	}

	int low=mini;
	int high=maxi;
	// int ans=-1;

	while(low<=high){
		long long int mid=(low+high)/2;
		if(isPossible(bloomDay, n, mid, M, K) == true){
			// ans=mid;
			high=mid-1;
		}
		else{
			low=mid+1;
		}
	}
	//return ans;
	return low;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends