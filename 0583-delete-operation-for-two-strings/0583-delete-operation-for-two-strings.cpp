class Solution {
public:
    int minDistance(string word1, string word2) {
        // tabulation where we have shifted all towards 1 right
        // we will find lcs and delete rest from s1 and s2 so we count s1 - lcs and s2 - lcs add them up
        
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i =0;i<=n;i++){
	        dp[i][0] = 0;
	    }
	    for(int j =0;j<=m;j++){
	        dp[0][j] = 0;
	    }
	    
	    for(int ind1 = 1;ind1<=n;ind1++){
	        for(int ind2=1 ; ind2<=m;ind2++){
	            // match 
	            if(word1[ind1-1]==word2[ind2-1]){
	                dp[ind1][ind2] = 1+ dp[ind1-1][ind2-1];
	            }
	            else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
	        }
	    }
	    int length = dp[n][m];
        
        int left = n - length;
        int right = m - length;
        return left + right;
    }
};