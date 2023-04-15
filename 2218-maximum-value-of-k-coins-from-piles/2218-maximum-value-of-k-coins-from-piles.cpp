class Solution {
public:
    int solve(vector<vector<int>>& piles, int index, int coin, vector<vector<int>>& dp) {
        if(index == piles.size() || coin == 0){
            return 0;
        }

        if(dp[index][coin] != -1){
            return dp[index][coin];
        }

        // not pick
        int notpick = solve(piles, index + 1, coin, dp);

        int pick = 0;
        int curr_sum = 0;
        for(int i = 0; i < piles[index].size() && (i + 1) <= coin; i++){
            curr_sum += piles[index][i];
            // pick we have to take the msximum that omes from all the picks possible
            int val = curr_sum + solve(piles, index + 1, coin - (i + 1), dp);
            pick = max(val, pick);
        }

        return dp[index][coin] = max(pick, notpick);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        int m = piles[0].size();

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(piles, 0, k, dp);
    }
};
