class Solution {
public:
    
    int solve(int ind,vector<int> &coins, int amount,vector<vector<int>>&dp){
        if(ind==0){
        // if amount is divisible by arr[0] it means we can get the answer 
           if(amount % coins[ind] ==0){
               return 1;
           } 
            return 0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int notpick = solve(ind-1,coins,amount,dp);
        int pick = 0;
        // while picking we can pick it one more time so we stay at the same index
        if(coins[ind]<=amount){
            pick = solve(ind,coins,amount-coins[ind],dp);
        }
        // sum of all possibilities gives us the count
        return dp[ind][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        for(int i = 0;i<=amount;i++){
            dp[0][i] = (i % coins[0] ==0);
        } 

        for(int ind =1;ind<n;ind++){
            for(int target = 0;target<=amount;target++){
                int notpick = dp[ind-1][target];
                int pick = 0;
                // while picking we can pick it one more time so we stay at the same index
                if(coins[ind]<=target){
                    pick = dp[ind][target-coins[ind]];
                }
                // sum of all possibilities gives us the count
                dp[ind][target] = pick + notpick;
            }
        }
        return dp[n-1][amount];
    }
};