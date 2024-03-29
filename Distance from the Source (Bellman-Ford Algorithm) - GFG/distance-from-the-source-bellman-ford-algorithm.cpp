//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> distance(V,1e8);
        distance[S] = 0;
        // we traversed all the edges n-1 times and the that iteration we wil get the shortest path to each node 
        // rest finding the shorter path consition is same as dijaktras
        for(int i =0;i<V-1;i++){
            for(auto x:edges){
                int u = x[0];
                int v = x[1];
                int wt = x[2];
                if(distance[u]!= 1e8 && distance[u] + wt <distance[v]){
                        distance[v] = distance[u] + wt;
                }
            }
        }
        // ntgh iteration to check the negative cycle
        for(auto x:edges){
                if(distance[x[0]]!= 1e8 && distance[x[0]] + x[2] <distance[x[1]]){
                        return {-1};
                }
        }
        return distance;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends