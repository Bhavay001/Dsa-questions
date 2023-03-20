class Solution {
public:
    
    int solve(int ind1,int ind2 , string &s1, string &s2, vector<vector<int>>&dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        // matching
        if(s1[ind1]== s2[ind2]){
            return dp[ind1][ind2] = 1 + solve(ind1-1,ind2-1,s1,s2,dp);
        }
        else return dp[ind1][ind2] = max(solve(ind1-1,ind2,s1,s2,dp),solve(ind1,ind2-1,s1,s2,dp));
    }
    int longestPalindromeSubseq(string s) {
        // longest palindromic of substring can be found by finding lcs of the give string and string
        // formed by reversing it
        string s1 = s;
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp (n,vector<int>(m,-1));
        
        return solve(n-1,m-1,s1,s2,dp);
    }
};