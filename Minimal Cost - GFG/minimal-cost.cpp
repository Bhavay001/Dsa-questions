//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  // we will use memoization top-dowm
    int solve(vector<int> &height , int n , int k,vector<int> &dp){
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int minCost = INT_MAX;
        for(int j = 1;j<=k;j++){
            if(n-j>=0){
                int jump = solve(height,n-j,k,dp) + abs(height[n] - height[n-j]);
                minCost = min(minCost,jump);
            }
        }
        return dp[n] = minCost;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n,-1);
        return solve(height,n-1,k,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends