//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
//     bool solve(int ind,int target,int arr[],vector<vector<int>> &dp){
//   if(target==0){
//             return true;
//         }
//         // when index reaches 0 we check if the 0th index in array is equal to the target left return true
//         if(ind == 0){
//             return arr[0] == target;
//         }
//         if(dp[ind][target]!=-1){
//             return dp[ind][target];
//         }
//         // now the possibilities are either we take the element or not take the element
//         // not take
//         bool nottake = solve(ind-1,target,arr,dp);
//         // take
//         bool take = false;
//         if(arr[ind]<=target){
//             take = solve(ind - 1, target - arr[ind], arr,dp);
//         }
//         //if any of the one among take or not take returns true, we can return true
//         return dp[ind][target] = nottake || take;
//     }

	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i = 0;i<n;i++){
	        sum+=arr[i];
	    }
	    
	    vector<vector<bool>> dp(n,vector<bool>(sum+1, 0));
	    // if target == 0
	    
	    for(int i =0;i<n;i++){
	        dp[i][0] = true;
	    }
	    
	    // if index == 0
        if(arr[0]  <= sum){
            dp[0][arr[0]] = true;
        }
        
        for(int ind = 1;ind<n;ind++){
            for(int target = 1;target<sum;target++){
                bool nottake = dp[ind-1][target];
                // take
                bool take = false;
                if(arr[ind]<=target){
                    take = dp[ind - 1][target - arr[ind]];
                }
                //if any of the one among take or not take returns true, we can return true
                dp[ind][target] = nottake || take;
            }
        }
	    // we need to find the possible values of s1 will be from 0 to sum/2
	    int mini = INT_MAX;
	    for(int i =0;i<=sum/2;i++){
	        if(dp[n-1][i]== true){
	            int s1 = i;
	            int s2 = sum - i;
	            mini = min(mini,abs(s2-s1));
	        }
	    }
	    
	    return mini;
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends