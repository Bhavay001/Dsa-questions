class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(string &s, int k ,int ind , vector<int>&dp){
        if(ind == s.size()){
            return 1;
        }
        if(s[ind]== '0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        
        int ans = 0;
        long num = 0;
        
        for(int j = ind;j<s.size();j++){
            num = num * 10 + s[j] - '0';
            if(num > k){
                break;
            }
            ans = (ans + solve(s,k,j+1,dp))%MOD;
        }
        return dp[ind] = ans;
    }
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<int> dp(n,-1);
        return solve(s,k,0,dp);
    }
};