class Solution {
public:
    
    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp){
        if (i <0 || j< 0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // matching
        if(s1[i]==s2[j]){
            return dp[i][j] = 1 + solve(s1,s2,i-1,j-1,dp);
        }
        // not matching
        else return dp[i][j] = max(solve(s1,s2,i-1,j,dp),solve(s1,s2,i,j-1,dp));
    }
    
    int minInsertions(string s) {
        // we will find the longest palidromic subsequence from the string 
        //s1 = mbadm
        //s2 = mdabm
        //lps = mam   so we will keep this as it is as we need to find the minium insertions to mske string  
        // palindrome so we insert the characters that are not in lps to make it a palindrome string 
        // so the answer will be length - lps length
        
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s1.length();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        int lps = solve(s1,s2,n-1,n-1,dp);
        
        return n- lps;
    }
};