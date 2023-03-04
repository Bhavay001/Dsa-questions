//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
// this will be similar in all subsequences problem
    bool solve(int ind,int target, vector<int> &arr,vector<vector<int>> &dp){
        // base case 
        // if target == 0
        if(target==0){
            return true;
        }
        // when index reaches 0 we check if the 0th index in array is equal to the target left return true
        if(ind == 0){
            return arr[0] == target;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        // now the possibilities are either we take the element or not take the element
        // not take
        bool nottake = solve(ind-1,target,arr,dp);
        // take
        bool take = false;
        if(arr[ind]<=target){
            take = solve(ind - 1, target - arr[ind], arr,dp);
        }
        //if any of the one among take or not take returns true, we can return true
        return dp[ind][target] = nottake || take;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        //creating a dp array of dp[ind +1][target +1]
        vector<bool> prev(sum+1,0);
        vector<bool> curr(sum+1,0);
        // all 0th index of the rows are marked as true
        prev[0] = curr[0] = 1;
        
        // base case from the index
        if(arr[0]  <= sum){
            prev[arr[0]] = true;
        }
        
        // nested loops with first one for index and second one for target
        for(int ind = 1;ind<n;ind++){
            for(int target =1;target<=sum;target++){
                bool nottake = prev[target];
                // take
                bool take = false;
                if(arr[ind]<=target){
                    take = prev[target - arr[ind]];
                }
                //if any of the one among take or not take returns true, we can return true
                curr[target] = nottake || take;
            
            }
            prev = curr;
        }
        
        
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends