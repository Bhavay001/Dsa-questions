class Solution {
public:
    long long solve(int ind,vector<vector<int>>& questions,int n,vector<long long> &dp){
        
        if(ind>=n){
            return 0;
        }
        if(ind == n-1){
            return questions[ind][0];
        }

        if(dp[ind]!=-1){
            return dp[ind];
        }
        // solve
        long long pick = questions[ind][0] + solve(ind+questions[ind][1]+1,questions,n,dp);
        
        // skip
        long long notpick = solve(ind+1,questions,n,dp);
        
        return dp[ind] = max(notpick,pick);
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n = questions.size();
        vector<long long> dp(n,-1);
        return solve(0,questions,n,dp);
    }
};