class Solution {
public:
    
    int fibo(int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        
        if(dp[n]!=-1){
            return dp[n];
        }
        
        return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    }
    // top - down - memoization
    int fib(int n) {
        // by using memoization and creating a dp array which stores the values which we                have stored the values which we have calculation ones making it a o(n) approach
        vector<int> dp(n+1,-1);
        return fibo(n,dp);
    }
};