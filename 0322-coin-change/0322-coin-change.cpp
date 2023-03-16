class Solution {
public:
    
    int solve(int ind,int amount,vector<int> &coins,vector<vector<int>> &dp){
        // base case
        
        if(ind==0){
            // if index is 0 and the element is divisible by amount then we return amount/arr[0]
            // else it is not possible we return INT_MAX so hat it is not considered in answer
            if(amount%coins[ind]==0){
                return amount/coins[ind];
            }
            return 1e9;
        }
        if(dp[ind][amount] !=-1){
            return dp[ind][amount];
        }
        // we do not divde like if we have amount 26 and we not use all denoinations of (5) 26/5 => 5
        // as we mihgt use 4 coins of (5) and 1 of (6)
        int notpick = solve(ind-1,amount,coins,dp);
        int pick = INT_MAX;
        if(amount>=coins[ind]){
            // whe we pick we stay at that index as we have infinite number of coins to take
            pick = 1 + solve(ind,amount - coins[ind],coins,dp);
        }
        
        return dp[ind][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        // memoisation
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        if(solve(n-1,amount,coins,dp)==1e9){
            return -1;
        }
        else return solve(n-1,amount,coins,dp);
    }
};