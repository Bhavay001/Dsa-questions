//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int ind,int target,int price[],vector<vector<int>> &dp){
        // if index is 0 the left rod will be completed by taking 1,1,1 lengths increasing the total price
        if(ind == 0){
            return price[0]*target;
        }
        
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int nottake = solve(ind-1,target,price,dp);
        int take = INT_MIN;
        int rodlength = ind+1;
        if(target>=rodlength){
            take = price[ind] + solve(ind,target - rodlength,price,dp);
        }
        return dp[ind][target] = max(take,nottake);
    }
    // according to 1 based indexing the index of the price we be the rod length at that point 
    //we need to find maximum value. We can include a index multiple times 
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        // tabulation
        // we can go from 0 to the targe
        for(int i =0;i<=n;i++){
            dp[0][i] =  price[0]*i;
        }
        
        for(int ind =1 ;ind <n;ind++){
            for(int target = 0;target<=n;target++){
                
                int nottake = dp[ind-1][target];
                
                int take = INT_MIN;
                int rodlength = ind+1;
                if(target>=rodlength){
                    take = price[ind] + dp[ind][target - rodlength];
                }
                dp[ind][target] = max(take,nottake);  
            }
        }
        return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends