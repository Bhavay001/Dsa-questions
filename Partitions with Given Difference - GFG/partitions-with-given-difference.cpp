//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod =1e9+7;
    int solve(int ind,int target,vector<int> & arr,vector<vector<int>> &dp){
        
        if(ind == 0){
            if(target == 0 && arr[0]==0){
                return 2;
            }
            //arr[0] might might be some number not 0 so we do not pick
            //arr[0] migthbe equal to target we pick
            if(target == 0 || arr[0]==target){
                return 1;
            }
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target] % mod;
        }
        int notpick = solve(ind-1,target,arr,dp);
        int pick = 0;
        
        if(arr[ind]<=target){
            pick = solve(ind-1,target-arr[ind],arr,dp);
        }
        
        return dp[ind][target] = (pick + notpick)%mod;
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        
        // s1>=s2
        // s1 - s2 = d
        // let s1 = totalsum - s2
        // totalsum - s2 - s2 = d
        // (totalsum -d / 2)= s2
        // so we have to count the partitions where s2 is equal to the 
        
        int totalsum =0;
        for(int i =0;i<n;i++){
            totalsum += arr[i];
        }
        
        // base case s2 cannot be negative as subset sum will be possitive of possitive elements
        // s2 cannot be odd as all digits are whole numbers 
        if(totalsum -d < 0 || (totalsum -d) % 2 !=0 ){
            return 0;
        }
        
        int sum = (totalsum - d)/2;
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        
        return solve(n-1,sum,arr,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends