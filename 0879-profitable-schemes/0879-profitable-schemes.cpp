class Solution {
public:
    int MOD = 1e9 + 7;
   int solve(int n, int minProfit, vector<int>& group, vector<int>& profit, int index, int p, vector<vector<vector<int>>>& dp) {
        // base case
         if (index == group.size()) {
            if (p >= minProfit) {
                return 1;
            }
            else {
                return 0;
            }
        }
       // 3d DP memoization
        if (dp[index][p][n] != -1) {
            return dp[index][p][n];
        }
        // there can be two conditions either we pick the group element or not pick
        int notpick = solve(n, minProfit, group, profit, index + 1, p, dp);
       
        int pick = 0;
        //  min(p + profit[index], minProfit) to avoid overflow else could have done p + profit[index]
        // we will do only till n (number of members are greaer than 0)
        if (n - group[index] >= 0) {
            pick = solve(n - group[index], minProfit, group, profit, index + 1, min(p + profit[index], minProfit), dp);
        }
        return dp[index][p][n] = (pick + notpick) % MOD;
    }
    
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size(), vector<vector<int>>(minProfit + 1, vector<int>(n + 1, -1)));


        return solve(n,minProfit,group,profit,0,0,dp);
    }
};