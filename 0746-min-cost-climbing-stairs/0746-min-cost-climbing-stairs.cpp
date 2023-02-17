class Solution {
public:
    int minCost(int n, vector<int> & cost,vector<int> &dp){
        if(n==0 || n==1){
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int left = minCost(n-1,cost,dp) + cost[n];
        int right = minCost(n-2,cost,dp) + cost[n];
        return dp[n] = min(left,right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,-1);
        // beacause we can start from 0 step as well as 1st step
        return min(minCost(n-1,cost,dp),minCost(n-2,cost,dp));
    }
};