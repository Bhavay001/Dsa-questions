class Solution {
public:
    
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp){
        // if index goes negative in string s2 means we have found subsequence
        if(j<0){
            return 1;
        }
        // means string s2 is still not completed but index in s1 goes negative
        if(i<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            // either we take it or wait for the other occurance of same letter
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp) + solve(i-1,j,s1,s2,dp);
        }
        else return dp[i][j] = solve(i-1,j,s1,s2,dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1, s, t,dp);
    }
};