//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfGasStationsRequired(vector<int>&stations, long double dist){
    	int cnt=0;
    	for(int i=1; i<stations.size(); i++){
    		int numberInBetween = (stations[i]-stations[i-1])/dist;
    		if(stations[i]-stations[i-1] == numberInBetween*dist){
    			numberInBetween--;
    		}
    		cnt+=numberInBetween;
    	}
    	return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        //Ist Method.
	//Total TC=O(k*n) + O(n)=O(n^2).
	//Total SC=O(n-1)=O(n).

	// int n=stations.size();
	// vector<int> howMany(n-1, 0);

//TC=O(k*n)=O(n^2)
	// for(int gasStations=1; gasStations<=k; gasStations++){
	// 	long double maxSection=-1;
	// 	int maxInd=-1;

	// 	for(int i=0; i<n-1; i++){
	// 		long double diff = stations[i+1]-stations[i];
	// 		long double sectionLength = diff/(long double)(howMany[i]+1);
			
	// 		if(sectionLength > maxSection){
	// 			maxSection=sectionLength;
	// 			maxInd=i;
	// 		}
	// 	}
	// 	howMany[maxInd]++;
	// }	

//TC=O(n);
	// long double maxSection=-1;
	// for(int i=0; i<n-1; i++){
	// 	long double diff=stations[i+1]-stations[i];
	// 	long double sectionLength= diff/(long double)(howMany[i]+1);

	// 	maxSection=max(maxSection, sectionLength);
	// }
	// return maxSection;






//IInd Method.
	//Total TC=O(nlogn)+O(klogn).
	//Total SC=O(2*(n-1))=O(n).
	
// 	int n=stations.size();
// 	vector<int> howMany(n-1, 0);
// 	priority_queue<pair<long double, int>> pq;
// 	//Filling the priority queue with required (distance, sectionIndex) pairs.
// //TC=O(n*logn) here logn for priority_queue.
// 	for(int i=0; i<n-1; i++){
// 		pq.push({stations[i+1]-stations[i], i});
// 	}
// //TC=O(k*logn)
// 	for(int gasStations=1; gasStations<=k; gasStations++){
// 		auto tp=pq.top();
// 		pq.pop();
		
// 		int secIndex=tp.second;
// 		howMany[secIndex]++;
// 		long double iniDiff = (stations[secIndex+1]-stations[secIndex]);
// 		long double sectionLength = iniDiff/(long double)(howMany[secIndex]+1);

// 		pq.push({sectionLength, secIndex});
// 	}	

	
// 	return pq.top().first;





//IIIrd Method
//using Binary Search-> this is somewhat different from the typical binary search.
//TC=O(nlog(range))+O(n);
	int n=stations.size();
	long double low=0;
	long double high=0;
//TC=O(n)
	for(int i=0; i<n-1; i++){
		high = max(high, (long double)(stations[i+1]-stations[i]));
	}

	long double diff=1e-6;//10^(-6).
//TC=O(nlogn).
	while(high-low > diff){
		long double mid = (low+high)/(2.0);
		int cnt = numberOfGasStationsRequired(stations, mid);

		if(cnt > k){
			low=mid;
		}
		else{
			high=mid;
		}
	}
	return high;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> stations(n);
        for (int i = 0; i < n; i++) {
            cin >> stations[i];
        }
        int k;
        cin >> k;
        Solution obj;
        cout << fixed << setprecision(2) << obj.findSmallestMaxDist(stations, k)
             << endl;
    }
    return 0;
}
// } Driver Code Ends