class Solution {
public:
    
    int solve(int ind1,int ind2,string &s1,string &s2,vector<vector<int>>&dp){
        // indexes cannot be negative and if it is negative lcs will be 0
        if(ind1<0 || ind2<0){
            return 0;
        }
        
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        
    // if the characters match we move both the indexes backwards add 1 to the answer
    //if not matching we take max of trying to move either of indexes backwards max((ind1-1,ind2),(ind1,ind2-1))
        
        if(s1[ind1]==s2[ind2]){  
            return dp[ind1][ind2] = 1 + solve(ind1-1,ind2-1, s1, s2,dp);
        }
        // not matching we move either ind1 or ind2 and return the maximum among them
        else return dp[ind1][ind2] = max(solve(ind1-1,ind2,s1,s2,dp),solve(ind1,ind2-1,s1,s2,dp));
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // memoization the depending parameters were ind1 and ind2 so we make dp of size dp[n][m]
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,text1,text2,dp); 
    }
};