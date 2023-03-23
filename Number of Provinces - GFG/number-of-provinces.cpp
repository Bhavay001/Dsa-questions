//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void dfs(int node, vector<int> adj[],vector<int> &visited){
      visited[node] = 1;
      for(auto x:adj[node]){
          if(!visited[x])
            dfs(x,adj,visited);
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        // convert matrix into adjacency list
        
        int n = V;
        
        vector<int> adj1[n+1];
        for(int i =0;i<n;i++){
            for(int j =0;j<n;j++){
                if(adj[i][j] == 1 && i!=j){
                    adj1[i].push_back(j);
                }
            }
        }
            
            int count = 0;
            vector<int> visited(n,0);
            for(int i =0;i<n;i++){
                if(!visited[i]){
                    count++;
                    dfs(i,adj1,visited);
                }
            }
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends