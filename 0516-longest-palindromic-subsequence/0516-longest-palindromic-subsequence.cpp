class Solution {
public:
    
    int solve(int i ,int j , string &s1, string &s2,vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // matching
        if(s1[i]== s2[j]){
            return dp[i][j] = 1+ solve(i-1,j-1,s1,s2,dp);
        }
        // not matching
        return dp[i][j] = max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s) {
    // longest palindromic of substring can be found by finding lcs of the give string and string
    // formed by reversing it
        
        string s1 = s;
        string s2 = s;
        
        reverse(s2.begin(),s2.end());
        int n = s1.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(n-1,n-1,s1,s2,dp);
        
    }
};