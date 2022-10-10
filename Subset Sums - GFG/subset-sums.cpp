//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    
    void solve(int index,vector<int>&arr, int N,int sum, vector<int> &finalans){
        if(index == N){
            finalans.push_back(sum);
            return;
        }
        // include
        solve(index+1,arr,N,sum +arr[index] ,finalans);
        
        //exclude
        solve(index+1,arr,N,sum , finalans);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> finalans;
        int index = 0;
        solve(index, arr,N, 0, finalans);
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