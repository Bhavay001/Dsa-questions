class Solution {
public:
    int MOD = 1e9 + 7;
    
    int solve(vector<vector<int>> &freq,string &target, vector<vector<int>> & dp, int colindex, int targetindex){
        // we have fpound the target word in the vector of string
        if(targetindex == target.size()){
            return 1;
        }
        // not found the word and reached the end index of a word
        if(colindex == freq[0].size()){
            return 0;
        }
        
        if(dp[colindex][targetindex]!=-1){
            return dp[colindex][targetindex];
        }
        int targetchar = target[targetindex] - 'a';
        
        int notpick = solve(freq,target,dp,colindex +1,targetindex)%MOD;
        
        int pick = 0;


        if (freq[targetchar][colindex] != 0){
            int currWays = freq[targetchar][colindex];
            int nextWays = solve(freq, target, dp, colindex + 1, targetindex + 1);
            // we will get the count of matching element from the strings at that index so we will multiply
        // with the recursive call to get the answer
            pick = (currWays%MOD * (long long)nextWays%MOD) % MOD;
        }
        
        return dp[colindex][targetindex] = (pick%MOD + notpick%MOD)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        int m = words.size();
        int n = words[0].size();
        // we will need to creae frequency of characters at that index for optiization
        vector<vector<int>>freq(26,vector<int>(n,0)); // freq of ch in jth col
        
        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){
                freq[words[i][j] - 'a'][j]++;
            }
        }
        vector<vector<int>>dp(n,vector<int>(target.size(),-1));
        return solve(freq,target,dp,0,0);
    }
};