class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        // we will create a dp array that we create for finding the lcs
        //now similar to printing the lcs in tis question we will not just print the same char but 
        //also while going left or up we will print that character
        vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        
        for(int i =0;i<=n;i++){
            dp[i][0] = 0;
        }
        
        for(int j =0;j<=m;j++){
            dp[0][j] = 0;
        }
        
        for(int ind1= 1;ind1<=n;ind1++){
            for(int ind2 = 1;ind2<=m;ind2++){
                if(str1[ind1-1]== str2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2 -1];
                }
                else dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        // 1) if the string is equal we add that character once
        //2) if we go left the str2 character gets removed so we add that
        // 3) when we go up the str1 character gets removed so we add that
    // 4) we will get reversed string in answer as we go from last to first so we reverse the string at the end
        string ans = "";
        
        int i = n;
        int j = m;
        while(i>0 && j>0){
            if(str1[i-1]== str2[j-1]){
                ans += str1[i-1];
                i--;
                j--;
            }
            // up
            else if(dp[i-1][j] > dp[i][j-1]){
                ans +=str1[i-1];
                i--;
            }
            else{
                ans+= str2[j-1];
                j--;
            }
        }
        
        while(i>0){
            ans+=str1[i-1];
            i--;
        }
        while(j>0){
            ans += str2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};