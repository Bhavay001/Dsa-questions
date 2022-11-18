//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        // we make the adjacency list it is 1 based index so we took n-1
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
            adj[x[1]].push_back({x[0],x[2]});
        }
        
        // we nwwd to store the parent to go back to the previous node later
        vector<int> parent(n+1);
        for(int i =1;i<=n;i++){
            parent[i] = i;
        }

        vector<int> distance(n+1,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        // initially we push the initial node 1 with distace 0
        // distance of source node 1 with 0
       
        pq.push({0,1});
        distance[1] = 0;

        // now we need to perform simple dijakstra's algorithm
        while(!pq.empty()){
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
        
            for(auto x:adj[node]){
                int newwt = x.second;
                int adjnode = x.first;
                
                if(wt + newwt < distance[adjnode]){
                    parent[adjnode] = node;
                    distance[adjnode] = wt + newwt;
                    pq.push({wt + newwt , adjnode});
                }
            }
        }
        
        // we go back to store the path form the last node to the source node
        vector<int> ans;
        if(distance[n]== INT_MAX){
           ans.push_back(-1);
           return ans;
        }
        int node = n;
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends