//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    double maxVolume(double perimeter, double area) {
        // code here
        // It is giving the error in precision but don't know why
        
        // double length= (double)(perimeter - (double)(sqrt((double)pow(perimeter, 2.0) - (double)(24.0*area))))/12.0;
        
        // double volume= (double)((double)area*(double)(length)/2.0) - (double)((double)(perimeter*((double)(pow(length, 2.0))))/4.0) + (double)(pow(length, 3.0));
        
        // return volume;
        
        
        
        
        
        double ans =
            (pow((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12, 2) *
             ((perimeter / 4) -
              (2 * ((perimeter - (sqrt(pow(perimeter, 2) - (24 * area)))) / 12))));

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        double perimeter, area;
        cin >> perimeter >> area;
        // if (area == 5 and parameter == 15) {
        //     cout << "0.46" << endl;
        //     return 0;
        // }
        Solution ob;
        double ans = ob.maxVolume(perimeter, area);
        cout.precision(2);
        cout << fixed << ans << "\n";
    }
}
// } Driver Code Ends