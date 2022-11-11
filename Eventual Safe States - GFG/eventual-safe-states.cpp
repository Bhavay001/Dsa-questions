//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int> adjrev[V];
        // we need to reverse the graph to perform in indegree of bfs algorithm 
        // terminal node is the node with outdegree 0
        // after reversing the node with indegreee 0 is the terminal node
        for(int i =0;i<V;i++){
            for(auto x:adj[i]){
                adjrev[x].push_back(i);
            }
        }
        vector<int> indegree(V,0);
        for(int i =0;i<V;i++){
            for(auto x:adjrev[i]){
                indegree[x]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> safenode;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            safenode.push_back(front);
            for(auto x:adjrev[front]){
                indegree[x]--;
                if(indegree[x]==0){
                    q.push(x);
                }
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends