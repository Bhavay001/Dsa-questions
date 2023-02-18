class Solution {
public:

    // bottom- up tabulation
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        for(int i=2;i<n;i++){
            int left = dp[i-1] + cost[i];
            int right = dp[i-2] + cost[i];
            dp[i] = min(left,right);
        }

        
        // beacause we can start from 0 step as well as 1st step
        return min(dp[n-1],dp[n-2]);
    }
};