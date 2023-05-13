class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int ind,int zero,int one,vector<long long> &dp){
        if(ind<0){
            return 0;
        }
        if(ind==0){
            return 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        // add zeroe
        long long sum = (solve(ind-zero,zero,one,dp) + solve(ind - one,zero,one,dp))%mod;
        return dp[ind] = sum;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
       vector<long long> dp(high + 1, -1);
        for(int i = low;i<=high;i++){
            ans = (ans + solve(i,zero,one,dp))%mod;
        }
        return ans;
    }
};