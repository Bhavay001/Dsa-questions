//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    // last means the the task among 0 1 2 3 preformed in previous day
    int solve(vector<vector<int>>& points,int n, int last,vector<vector<int>> &dp){
        if(n==0){
            int maxi = INT_MIN;
            for(int i =0;i<3;i++){
                if(i!=last){
                    maxi = max(points[0][i],maxi);
                }
            }
            return maxi;
        }
        if(dp[n][last]!=-1){
            return dp[n][last];
        }
        int maxi = INT_MIN;
        for(int i =0;i<3;i++){
            if(i!=last){
                int point = points[n][i] + solve(points,n-1,i,dp);
                maxi = max(maxi,point);
            }
            
        }
        return dp[n][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        // since there are 3 activites so we will take them as 0 1 2 
        // in the starting we can choose any actiivity so i sen index 3
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return solve(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends