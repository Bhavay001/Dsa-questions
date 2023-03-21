class Solution {
public:
    
 
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
        int m = s2.length();
        vector<vector<int>> dp (n+1,vector<int>(m+1,-1));
        
        for(int i =0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int j=0;j<=m;j++){
            dp[0][j] = 0;
        }
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                 if(s1[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                 }
                 else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
        
            }
        }
        int length = dp[n][m];
        return n  - length;
    }
};