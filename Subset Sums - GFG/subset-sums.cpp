//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void solve(int index,vector<int>&arr, int N,int sum, vector<int>&ans, vector<int> &finalans){
        if(index == N){
            finalans.push_back(sum);
            sum = 0;
            return;
        }
        ans.push_back(arr[index]);
        sum += arr[index];
        solve(index+1,arr,N,sum ,ans, finalans);
        
        ans.pop_back();
        sum -= arr[index];
        solve(index+1,arr,N,sum ,ans, finalans);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> finalans;
        vector<int> ans;
        int index = 0;
        solve(index, arr,N, 0,ans, finalans);
        return finalans;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends