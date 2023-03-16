//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int solve(int ind,int W,int wt[],int val[],vector<vector<int>> &dp){
        
        if(ind ==0){
           if(W>=wt[ind]){
               return val[ind];
           } 
           else{
               return 0;
           }
        }
        if(dp[ind][W]!=-1){
            return dp[ind][W];
        }
        int notpick = solve(ind-1,W,wt,val,dp);
        int pick = 0;
        if(W>=wt[ind]){
            pick = val[ind] + solve(ind-1,W-wt[ind],wt,val,dp);
        }
        
        return dp[ind][W] =  max(pick,notpick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // tabulation
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
        //Base Condition
        
        for(int i=wt[0]; i<=W; i++){
            dp[0][i] = val[0];
        }
        
        for(int ind = 1;ind<n;ind++){
           for(int wgt = 0;wgt<=W;wgt++){
               
                int notpick = dp[ind-1][wgt];
                int pick = 0;
                if(wgt>=wt[ind]){
                    pick = val[ind] + dp[ind-1][wgt - wt[ind]];
                }
                dp[ind][wgt] =  max(pick,notpick);
           }
       }
       return dp[n-1][W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends