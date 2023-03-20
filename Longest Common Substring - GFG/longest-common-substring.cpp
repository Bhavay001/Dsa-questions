//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        // your code here

        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        // we consider a right shift of 1 as we cannot write abse case for index = -1 
        // initializing first row and first column as 0
        for(int i = 0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]= 0;
        }
        int ans = 0;
        for(int ind1 =1;ind1<=n;ind1++){
            for(int ind2 =1;ind2<=m;ind2++){
                // matching
                if(s1[ind1-1]==s2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                    ans = max(ans,dp[ind1][ind2]);
                }
    //we do not carry the previous baggage when the string does not match as we are finding lcs of substring 
                else{
                    dp[ind1][ind2] = 0;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends